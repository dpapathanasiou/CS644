> EACCES, EEXIST, and ENOENT are three common errors that open can return. Read the description of these errors in man 2 open, and write a program that demonstrates each of them.

Using [hw4.c](hw4.c) shows the results:

```sh
$ ./hw4
/root cannot be opened for reading: -1 error
./hw4 cannot be re-created, it already exists: -1 error
no-such-file cannot be opened w/o O_CREAT, it does not exist: -1 error
```