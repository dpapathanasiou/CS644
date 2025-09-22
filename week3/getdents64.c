#define _GNU_SOURCE // Required for SYS_getdents64
#include <sys/syscall.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

/* Build and run:

$ gcc -Wall -o getdents64 getdents64.c
$ ./getdents64 $(pwd)
Contents of directory '/home/denis/repos/repos-git/CS644/week3':
  Inode: 6701140 Name: README.md            Type: regular file
  Inode: 6701757 Name: getdents64.c         Type: regular file
  Inode: 6688761 Name: .                    Type: directory
  Inode: 6553909 Name: ..                   Type: directory
  Inode: 6701749 Name: getdents64           Type: regular file
  
*/

// based on `man 2 getdents64`
struct linux_dirent64
{
    ino64_t d_ino;           /* Inode number */
    off64_t d_off;           /* Not an offset; see below */
    unsigned short d_reclen; /* Length of this dirent */
    unsigned char d_type;    /* File type */
    char d_name[];           /* Filename (null-terminated) */
};

int main(int argc, char *argv[])
{
    int fd, nread;
    char buf[BUFSIZ];
    struct linux_dirent64 *d;
    int bpos;
    char d_type;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s [path to directory]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY | O_DIRECTORY);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    printf("Contents of directory '%s':\n", argv[1]);

    while (1)
    {
        nread = syscall(SYS_getdents64, fd, buf, BUFSIZ);
        if (nread == -1)
        {
            perror("getdents64");
            exit(EXIT_FAILURE);
        }
        if (nread == 0)
        { // End of directory
            break;
        }

        for (bpos = 0; bpos < nread;)
        {
            d = (struct linux_dirent64 *)(buf + bpos);
            d_type = d->d_type;

            printf("  Inode: %lld Name: %-20s Type: %s\n",
                   (long long)d->d_ino,
                   d->d_name,
                   (d_type == DT_REG) ? "regular file" : (d_type == DT_DIR) ? "directory"
                                                     : (d_type == DT_FIFO)  ? "FIFO"
                                                     : (d_type == DT_SOCK)  ? "socket"
                                                     : (d_type == DT_LNK)   ? "symlink"
                                                     : (d_type == DT_BLK)   ? "block dev"
                                                     : (d_type == DT_CHR)   ? "char dev"
                                                                            : "?");

            bpos += d->d_reclen;
        }
    }

    close(fd);
    exit(EXIT_SUCCESS);
}