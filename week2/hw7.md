> If you call write, use lseek to rewind, and call read again, are you guaranteed to see the data you just wrote? Write a program to demonstrate it.

Using [hw7.c](hw7.c) proves it, but it only works if `O_RDWR` is among the flags in `open()`, as I found out the hard way (i.e., my initial attempt used `O_CREAT | O_APPEND | O_WRONLY`, copy-pasting from [appender.c](appender.c), and while the write worked, the read failed)

```sh
$ ./hw7 foo.txt "Something to write and read back"
Wrote to file (foo.txt) 32 bytes -> Something to write and read back
Cursor position now 0 -> file contents are:

Something to write and read back

File (foo.txt) has 32 bytes (using 8192 BUFSIZ)
```

> Find the place in the man pages that describes Linux's behavior. 

```sh
man 2 lseek
```
