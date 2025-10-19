> Write a program that demonstrates a deadlock due to acquiring locks in different orders

[hw7.c](hw7.c) shows what happens:

```sh
$ gcc -Wall -o hw7 hw7.c
$ ./hw7
** 1 lock1 applied
** 2 lock2 applied
^C
```