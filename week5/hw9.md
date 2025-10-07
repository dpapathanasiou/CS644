> Shared memory is often used for high-performance concurrent applications. Implement a [ring buffer](https://en.wikipedia.org/wiki/Circular_buffer) in shared memory with one producer process putting work into the buffer, and multiple consumer processes reading from it. 

Starting with the [simple example](simple_ring_buffer.c), adapted from the [wikipedia article](https://en.wikipedia.org/wiki/Circular_buffer), which has these design principles, we have a blueprint for the type of struct and operations needed:

- Rather than overwrite when full, exits w/o error
- Reads are destructive, removing the value from memory

Next, adapting the [class example](shared_mem_semaphore.c), which provides a way for a single writer and multiple readers to access a single int value in an mmap'ed struct.

Putting the two together, results in a [ring buffer with shared memory](shared_mem_semaphore_ring_buffer.c) application, based on this struct definition, which required a [flexible array member](https://www.gnu.org/software/c-intro-and-ref/manual/html_node/Flexible-Array-Fields.html) in its definition, and the corresponding [tweak to the size calculation](https://stackoverflow.com/a/2061038):

```c
struct my_ring_buffer
{
    size_t w_index;
    size_t r_index;
    int32_t buffer[]; // flexible array member (must come at end of struct declaration)
};
```

The other importance nuances were related to the file and mmap permissions, since the reader also needed to be able to write to shared memory, in order to update the `r_index` value, for the ring buffer to work.