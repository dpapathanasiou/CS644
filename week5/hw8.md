> We used mmap for shared memory, but the system call is more versatile than just that. Read the man page and find out what else it can be used for. 

In addition to shared memory as we have used it here, mmap can attach to files and other devices, bypassing explicit read and write system calls.

Those capabilities are more notably useful for high performance file i/o applications, such as databases and queues, and also streaming media apps.

Sources

- https://en.wikipedia.org/wiki/Mmap
- https://en.wikipedia.org/wiki/Mmap
- https://en.wikipedia.org/wiki/Mmap