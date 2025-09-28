> It's important to follow execve with a call to _exit. What could go wrong if you don't? 

If the child process `execve` fails, the child process may interfere with the parent process, so it's desirable to use `_exit` to terminates the calling process immediately, and notify the parent.

sources:
 - [_exit(2) - Linux man page](https://linux.die.net/man/2/_exit)
 - [exit(3) - Linux man page](https://linux.die.net/man/3/exit)
 - [What is the difference between using _exit() & exit() in a conventional Linux fork-exec?](https://stackoverflow.com/q/5422831)
 - [Why should a child of a vfork or fork call _exit() instead of exit()?](https://unix.stackexchange.com/q/5364)