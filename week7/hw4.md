> What happens if main returns (without calling exit) while other threads are still active? 

Commenting out the `pthread_join` call in [hw4.c](hw4.c) produces two binaries which we can use to compare:

```sh
$ gcc -Wall -o hw4-with-join hw4.c
$ ./hw4-with-join
Hello from the main thread - Iteration 0
Hello from a new thread! - Iteration 0
Hello from the main thread - Iteration 1
Hello from the main thread - Iteration 2
Hello from the main thread - Iteration 3
Hello from the main thread - Iteration 4
Hello from the main thread - Iteration 5
Hello from the main thread - Iteration 6
Hello from the main thread - Iteration 7
Hello from the main thread - Iteration 8
Hello from the main thread - Iteration 9
Hello from a new thread! - Iteration 1
Hello from a new thread! - Iteration 2
Hello from a new thread! - Iteration 3
Hello from a new thread! - Iteration 4
Hello from a new thread! - Iteration 5
Hello from a new thread! - Iteration 6
Hello from a new thread! - Iteration 7
Hello from a new thread! - Iteration 8
Hello from a new thread! - Iteration 9
Main thread exiting.
```

versus 

```sh
$ gcc -Wall -o hw4-no-join hw4.c
$ ./hw4-no-join
Hello from the main thread - Iteration 0
Hello from a new thread! - Iteration 0
Hello from the main thread - Iteration 1
Hello from the main thread - Iteration 2
Hello from the main thread - Iteration 3
Hello from the main thread - Iteration 4
Hello from the main thread - Iteration 5
Hello from the main thread - Iteration 6
Hello from the main thread - Iteration 7
Hello from the main thread - Iteration 8
Hello from the main thread - Iteration 9
Hello from a new thread! - Iteration 1
Main thread exiting.
```

i.e., any threads still running when main exits are extinguished prematurely