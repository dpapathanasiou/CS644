> fork is the classic Unix system call, but Linux also offers something called clone. Read man 2 clone. What are the differences from fork? 

Excerpts from [clone(2) - Linux man page](https://linux.die.net/man/2/clone):

The main use of clone() is to implement threads: multiple threads of control in a program that run concurrently in a shared memory space. 

Unlike [fork(2)](https://linux.die.net/man/2/fork), these calls allow the child process to share parts of its execution context with the calling process, such as the memory space, the table of file descriptors, and the table of signal handlers. 