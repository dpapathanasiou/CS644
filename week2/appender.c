#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage:\n\n%s \"file pathname\" \"text to append\"\n", argv[0]);
    }

    int fd = open(argv[1], O_CREAT | O_APPEND | O_WRONLY, 0644);
    if (fd < 0)
    {
        printf("File (%s) cannot be opened for writing: %d code\n", argv[1], fd);
        return fd;
    }

    // get the size of the input string w/o using strlen() from <string.h>
    ssize_t bytes = 0;
    const char *p = (const char *)argv[2];
    while (*p++ != '\0')
    {
        ++bytes;
    }

    if (write(fd, argv[2], bytes) != bytes)
    {
        printf("Error appending to file (%s)\n", argv[1]);
        return -1;
    }

    int cl = close(fd);
    if (cl < 0)
    {
        printf("Error closing file (%s): %d code\n", argv[1], cl);
        return cl;
    }

    return 0;
}