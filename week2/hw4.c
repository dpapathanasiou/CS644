#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int eacces = open("/root", O_RDONLY, 0);
    if (eacces)
    {
        printf("/root cannot be opened for reading: %d error\n", eacces);
    }

    int eexist = open(argv[0], O_CREAT | O_EXCL, 0);
    if (eexist)
    {
        printf("%s cannot be re-created, it already exists: %d error\n", argv[0], eexist);
    }

    int enoent = open("no-such-file", O_RDONLY, 0);
    if (enoent)
    {
        printf("no-such-file cannot be opened w/o O_CREAT, it does not exist: %d error\n", enoent);
    }
}