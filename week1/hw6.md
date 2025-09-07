Write a C program, [redact.c](redact.c), that takes a string argument and prints out the string with all digits replaced by the character 'X':

```sh
$ gcc -Wall -o redact redact.c
$ ./redact
Usage:

./redact "string" "string" ... 
$ ./redact "Secret007Identity"
SecretXXXIdentity
$ ./redact "Secret007Identity" "Nothing To Change Here"
SecretXXXIdentity
Nothing To Change Here
```
