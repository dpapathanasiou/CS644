False!

Removing the semicolons from [hw1.c](hw1.c), for example, results in:

```sh
hw1.c: In function ‘main’:
hw1.c:7:5: error: expected ‘,’ or ‘;’ before ‘printf’
    7 |     printf("sizeof size_t on my machine: %lu\n", s)
      |     ^~~~~~
hw1.c:10:1: error: expected declaration or statement at end of input
   10 | }
      | ^
hw1.c:6:19: warning: unused variable ‘s’ [-Wunused-variable]
    6 |     unsigned long s = sizeof(size_t)
      |                   ^
```
