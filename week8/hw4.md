> Write a program that shows what happens when the same signal is delivered twice before the program can handle it. Is the signal handler invoked twice, or only once? 

Linux is *supposed* to invoke it only once, but could not replicate with [hw4.c](hw4.c):

```sh
$ ./hw4
PID is 4066
Signal handler invoked for signal 10
Signal handler invoked for signal 10
waiting for signals to complete
```
