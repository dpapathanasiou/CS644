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
#include <errno.h>

// found in example: man 2 mmap
#define handle_error(msg)   \
    do                      \
    {                       \
        perror(msg);        \
        exit(EXIT_FAILURE); \
    } while (0)

#define SHARED_MEM "/ring_buffer_program_shared_memory"
#define SEMAPHORE "/ring_buffer_program_semaphore"

const size_t RING_BUFFER_SIZE = 10;

struct my_ring_buffer
{
    size_t w_index;
    size_t r_index;
    int32_t buffer[]; // flexible array member (must come at end of struct declaration)
};

void writer(int32_t item)
{
    int fd = shm_open(SHARED_MEM, O_CREAT | O_EXCL | O_RDWR, 0600);
    if (fd < 0)
    {
        handle_error("shm_open");
    }

    int r = ftruncate(fd, sizeof(struct my_ring_buffer));
    if (r < 0)
    {
        handle_error("ftruncate");
    }

    struct my_ring_buffer alignas(max_align_t) * s;
    // flexible array member: compute the size based on expected array length (https://stackoverflow.com/a/2061038)
    s = mmap(NULL, sizeof(struct my_ring_buffer) + (RING_BUFFER_SIZE * sizeof(int32_t)), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
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

    printf("<enter> to add the next value to the buffer, any other key to exit");
    while (getchar() == '\n')
    {
        // wait on the semaphore
        r = sem_wait(sem);
        if (r < 0)
        {
            handle_error("sem_wait");
        }

        // see if there is any more space
        if ((s->w_index + 1) % RING_BUFFER_SIZE == s->r_index)
        {
            // buffer is full, avoid overflow
            printf("(write) buffer full!\n");
            break;
        }
        s->buffer[s->w_index] = item;
        printf("(write) posted %d (at pos %zu)\n", item, s->w_index);
        s->w_index = (s->w_index + 1) % RING_BUFFER_SIZE;
        item += 1;

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

    // free(s);
    // s = NULL;
}

void reader()
{
    int fd = shm_open(SHARED_MEM, O_RDWR, 0);
    if (fd < 0)
    {
        handle_error("shm_open");
    }

    struct my_ring_buffer alignas(max_align_t) * s;
    // flexible array member: compute the size based on expected array length (https://stackoverflow.com/a/2061038)
    s = mmap(NULL, sizeof(struct my_ring_buffer) + (RING_BUFFER_SIZE * sizeof(int32_t)), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
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

    // try reading the value at `r_index`
    if (s->r_index == s->w_index)
    {
        printf("(read) buffer empty!\n");
    }
    else
    {
        printf("(read) read %d (at pos %zu)\n", s->buffer[s->r_index], s->r_index);
        s->r_index = (s->r_index + 1) % RING_BUFFER_SIZE;
    }

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
    sprintf(usage, "Usage:\n\n%s <write|read> <starting int value (write)>\n", argv[0]);

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
        char *endptr;
        errno = 0;
        long value = strtol(argv[2], &endptr, 10);
        if (errno != 0 || *endptr != '\0')
        {
            handle_error(usage);
        }
        else
        {
            writer(value);
        }
    }
    else
    {
        handle_error(usage);
    }

    exit(EXIT_SUCCESS);
}
