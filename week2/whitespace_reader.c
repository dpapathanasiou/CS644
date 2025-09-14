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

    size_t buffer_size = 8192; // configurable alternative to built-in BUFSIZ
    char buf[buffer_size];

    ssize_t n;
    size_t i, bytes, spaces;

    bytes = 0;
    spaces = 0;
    while ((n = read(fd, buf, buffer_size)) > 0)
    {
        bytes += n;
        for (i = 0; i < n; i++)
        {
            if (isspace(buf[i]))
            {
                spaces += 1;
            }
        }
    }
    printf("File (%s) has %ld bytes (using %ld BUFSIZ) -> %ld spaces\n", argv[1], bytes, buffer_size, spaces);

    int cl = close(fd);
    if (cl < 0)
    {
        printf("Error closing file (%s): %d code\n", argv[1], cl);
        return cl;
    }

    return 0;
}