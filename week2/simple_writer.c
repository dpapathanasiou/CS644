#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage:\n\n%s \"file pathname\" \"text to write\" [overwrite start? (default: false)]\n", argv[0]);
    }

    int fd;
    if (argc == 4)
    {
        // 'overwrite start' flag received: do not open with O_APPEND
        fd = open(argv[1], O_CREAT | O_WRONLY, 0644);
    }
    else
    {
        fd = open(argv[1], O_CREAT | O_APPEND | O_WRONLY, 0644);
    }

    if (fd < 0)
    {
        printf("[writer] file (%s) cannot be opened for writing: %d code\n", argv[1], fd);
        return fd;
    }

    // get the size of the input string w/o using strlen() from <string.h>
    ssize_t bytes = 0;
    const char *p = (const char *)argv[2];
    while (*p++ != '\0')
    {
        ++bytes;
    }

    if (argc == 4)
    {
        // 'overwrite start' flag received: rewind to the beginning before attempting to write
        off_t pos = lseek(fd, 0, SEEK_SET);
        if (pos < 0)
        {
            printf("[writer] error moving to start of file (%s): %ld code\n", argv[1], pos);
            return -1;
        }
    }

    if (write(fd, argv[2], bytes) != bytes)
    {
        printf("[writer] error appending to file (%s)\n", argv[1]);
        return -1;
    }
    printf("[writer] wrote to file (%s) %ld bytes -> %s\n", argv[1], bytes, argv[2]);

    int cl = close(fd);
    if (cl < 0)
    {
        printf("[writer] error closing file (%s): %d code\n", argv[1], cl);
        return cl;
    }

    return 0;
}