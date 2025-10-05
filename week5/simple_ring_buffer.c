#include <stdio.h>

/*
Simple example, adapted from: https://en.wikipedia.org/wiki/Circular_buffer

- Rather than overwrite when full, exits w/o error
- Reads are destructive, removing the value from memory

$ gcc -Wall -o simple_ring_buffer simple_ring_buffer.c
$ ./simple_ring_buffer
Buffer loaded: 9 values, starting at 1001
read 1001
read 1002
read 1003
read 1004
read 1005
read 1006
read 1007
read 1008
read 1009

*/

enum
{
    N = 10
}; // size of circular buffer

int buffer[N]; // note: only (N - 1) elements can be stored at a given time
int writeIndx = 0;
int readIndx = 0;

int put(int item)
{
    if ((writeIndx + 1) % N == readIndx)
    {
        // buffer is full, avoid overflow
        return 0;
    }
    buffer[writeIndx] = item;
    writeIndx = (writeIndx + 1) % N;
    return 1;
}

int get(int *value)
{
    if (readIndx == writeIndx)
    {
        // buffer is empty
        return 0;
    }

    *value = buffer[readIndx];
    readIndx = (readIndx + 1) % N;
    return 1;
}

int main()
{
    // test circular buffer
    int value = 1001;

    // keep writing until buffer rejects (exits w/o error) when full
    while (put(value++));

    printf("Buffer loaded: %d values, starting at %d\n", N-1, value-N);

    // attempt to read back all N values
    while (get(&value))
        printf("read %d\n", value);

    return 0;
}