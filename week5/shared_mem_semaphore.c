#include <stdio.h>
#include <stddef.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdalign.h>

// found in example: man 2 mmap
#define handle_error(msg)   \
    do                      \
    {                       \
        perror(msg);        \
        exit(EXIT_FAILURE); \
    } while (0)

#define SHARED_MEM "/program_shared_memory"
#define SEMAPHORE "/program_semaphore"

struct mydata
{
    int counter;
};

void writer()
{
    int fd = shm_open(SHARED_MEM, O_CREAT | O_EXCL | O_RDWR, 0600);
    if (fd < 0)
    {
        handle_error("shm_open");
    }

    int r = ftruncate(fd, sizeof(struct mydata));
    if (r < 0)
    {
        handle_error("ftruncate");
    }

    struct mydata alignas(max_align_t) * s;
    s = mmap(NULL, sizeof(struct mydata), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (s == MAP_FAILED)
    {
        handle_error("mmap");
    }

    // After we `mmap`, we can close the shared-memory file descriptor.
    r = close(fd);
    if (r < 0)
    {
        handle_error("close");
    }

    sem_t *sem = sem_open(SEMAPHORE, O_CREAT | O_EXCL, 0600, 1);
    if (sem == SEM_FAILED)
    {
        handle_error("sem_open");
    }

    printf("<enter> to increment current value, any other key to exit");
    while (getchar() == '\n')
    {
        // wait on the semaphore
        r = sem_wait(sem);
        if (r < 0)
        {
            handle_error("sem_wait");
        }

        // use the shared data structure,
        // by incrementing its counter
        s->counter += 1;
        printf("(write) counter = %d\n", s->counter);

        // release the semaphore
        r = sem_post(sem);
        if (r < 0)
        {
            handle_error("sem_post");
        }
    }

    // unlink the semaphore
    r = sem_unlink(SEMAPHORE);
    if (r < 0)
    {
        handle_error("sem_unlink");
    }

    // unlink the shared memory
    r = shm_unlink(SHARED_MEM);
    if (r < 0)
    {
        handle_error("shm_unlink");
    }
}

void reader()
{
    int fd = shm_open(SHARED_MEM, O_RDONLY, 0);
    if (fd < 0)
    {
        handle_error("shm_open");
    }

    struct mydata alignas(max_align_t) * s;
    s = mmap(NULL, sizeof(struct mydata), PROT_READ, MAP_SHARED, fd, 0);
    if (s == MAP_FAILED)
    {
        handle_error("mmap");
    }

    // After we `mmap`, we can close the shared-memory file descriptor.
    int r = close(fd);
    if (r < 0)
    {
        handle_error("close");
    }

    sem_t *sem = sem_open(SEMAPHORE, O_EXCL, 0600, 1);
    if (sem == SEM_FAILED)
    {
        handle_error("sem_open");
    }

    r = sem_wait(sem);
    if (r < 0)
    {
        handle_error("sem_wait");
    }

    // use the shared data structure,
    // by reading its current counter
    printf("(read) counter = %d\n", s->counter);

    // release the semaphore
    r = sem_post(sem);
    if (r < 0)
    {
        handle_error("sem_post");
    }
}

int main(int argc, char *argv[])
{
    char usage[BUFSIZ];
    sprintf(usage, "Usage:\n\n%s <write|read> \n", argv[0]);

    if (argc < 2)
    {
        handle_error(usage);
    }

    if (strcmp(argv[1], "read") == 0)
    {
        printf("<enter> to read current value, any other key to exit");
        while (getchar() == '\n')
        {
            reader();
        }
    }
    else if (strcmp(argv[1], "write") == 0)
    {
        writer();
    }
    else
    {
        handle_error(usage);
    }

    exit(EXIT_SUCCESS);
}
