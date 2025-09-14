#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage:\n\n%s \"file pathname\"\n", argv[0]);
    }

    int fd = open(argv[1], O_RDONLY, 0);
    if (fd < 0)
    {
        printf("File (%s) does not exist or cannot be opened for reading: %d code\n", argv[1], fd);
        return fd;
    }

    char buf[BUFSIZ];
    ssize_t n;
    size_t bytes, spaces;

    bytes = 0;
    spaces = 0;
    while ((n = read(fd, buf, BUFSIZ)) > 0)
    {
        bytes += n;
        const char *p = (const char *)buf;
        while (*p++ != '\0')
        {
            if (isspace(*p))
            {
                spaces += 1;
            }
        }
    }
    printf("File (%s) has %ld bytes (using %d BUFSIZ) -> %ld spaces\n", argv[1], bytes, BUFSIZ, spaces);

    int cl = close(fd);
    if (cl < 0)
    {
        printf("Error closing file (%s): %d code\n", argv[1], cl);
        return cl;
    }

    return 0;
}