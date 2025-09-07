#include <stdio.h>
#include <stddef.h>


int main() {
    unsigned long s = sizeof(size_t);
    printf("sizeof size_t on my machine: %lu\n", s);

    return 0;
};

/*

$ gcc -Wall -o hw1 hw1.c
$ ./hw1
sizeof size_t on my machine: 8

*/