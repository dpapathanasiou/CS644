#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define PRINTON 1 // 0 is false, anything else is true

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage:\n\n%s \"file pathname\"\n", argv[0]);
    }

    int fd = open(argv[1], O_RDONLY, 0);
    if (fd < 0)
    {
        printf("[reader] file (%s) does not exist or cannot be opened for reading: %d code\n", argv[1], fd);
        return fd;
    }

    char buf[BUFSIZ];

    ssize_t n;
    size_t i, bytes, lines;

    bytes = 0;
    lines = 0;

    if (PRINTON)
    {
        printf("[reader] %ld: ", lines);
    }

    while ((n = read(fd, buf, BUFSIZ)) > 0)
    {
        bytes += n;
        for (i = 0; i < n; i++)
        {
            if (PRINTON)
            {
                printf("%c", buf[i]);
            }

            if (buf[i] == '\n')
            {
                lines += 1;

                if (PRINTON)
                {
                    printf("[reader] %ld: ", lines);
                }
            }
        }
    }
    printf("\n[reader] file (%s) has %ld bytes -> %ld lines\n", argv[1], bytes, lines);

    int cl = close(fd);
    if (cl < 0)
    {
        printf("[reader] error closing file (%s): %d code\n", argv[1], cl);
        return cl;
    }

    return 0;
}