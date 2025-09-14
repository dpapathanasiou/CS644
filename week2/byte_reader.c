#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage:\n\n%s \"file pathname\" size\n", argv[0]);
    }

    int fd = open(argv[1], O_RDONLY, 0);
    if (fd < 0)
    {
        printf("File (%s) does not exist or cannot be opened for reading: %d code\n", argv[1], fd);
        return fd;
    }

    char buf[BUFSIZ];
    ssize_t n, bytes;

    bytes = 0;
    while ((n = read(fd, buf, BUFSIZ)) > 0)
    {
        bytes += n;
    }
    printf("File (%s) has %ld bytes (using %d BUFSIZ)\n", argv[1], bytes, BUFSIZ);

    int cl = close(fd);
    if (cl < 0)
    {
        printf("Error closing file (%s): %d code\n", argv[1], cl);
        return cl;
    }

    return 0;
}