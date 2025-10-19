> If a thread acquires a lock and then calls pthread_exit, will the OS release the lock automatically?

As the result from [hw5.c](hw5.c) shows, the OS will *not* release the lock, and the program will remain deadlocked, unable to complete:

```sh
$ gcc -Wall -o hw5 hw5.c
$ ./hw5
Hello from the main thread - Iteration 0
Hello from thread one! - mutex locked
Hello from the main thread - Iteration 1
Hello from the main thread - Iteration 2
Hello from the main thread - Iteration 3
Hello from the main thread - Iteration 4
Hello from the main thread - Iteration 5
Hello from the main thread - Iteration 6
Hello from the main thread - Iteration 7
Hello from the main thread - Iteration 8
Hello from the main thread - Iteration 9
...
[never returns]
```