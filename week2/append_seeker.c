#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage:\n\n%s \"file pathname\" \"text to append\"\n", argv[0]);
    }

    int fd = open(argv[1], O_CREAT | O_WRONLY, 0644);
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

    // lseek here b/c we did not use O_APPEND in open()
    off_t pos = lseek(fd, 0, SEEK_END);
    if (pos < 0)
    {
        printf("Error moving to end of file (%s): %ld code\n", argv[1], pos);
        return -1;
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