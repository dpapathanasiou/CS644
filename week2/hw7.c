#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage:\n\n%s \"file pathname\" \"text to append\"\n", argv[0]);
    }

    int fd = open(argv[1], O_CREAT | O_APPEND | O_RDWR, 0644);
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
    printf("Wrote to file (%s) %ld bytes -> %s\n", argv[1], bytes, argv[2]);

    // rewind to the beginning of the file
    off_t pos = lseek(fd, 0, SEEK_SET);
    if (pos < 0)
    {
        printf("Error moving to start of file (%s): %ld code\n", argv[1], pos);
        return -1;
    }
    printf("Cursor position now %ld -> file contents are:\n\n", pos);

    ssize_t n;
    size_t i;
    char buf[BUFSIZ];

    // read the file again, from the new pos (start of file)
    bytes = 0; // reset the byte counter too
    while ((n = read(fd, buf, BUFSIZ)) > 0)
    {
        bytes += n;
        for (i = 0; i < n; i++)
        {
            printf("%c", buf[i]);
        }
    }
    printf("\n\nFile (%s) has %ld bytes (using %d BUFSIZ)\n", argv[1], bytes, BUFSIZ);

    int cl = close(fd);
    if (cl < 0)
    {
        printf("Error closing file (%s): %d code\n", argv[1], cl);
        return cl;
    }

    return 0;
}