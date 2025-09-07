Research the concept of the stack and the heap for memory allocation. 

Summary of this blog post, [Stack vs Heap Allocation in C: Pros and Cons](https://www.matecdev.com/posts/c-heap-vs-stack-allocation.html):

## Stack allocation

- The stack is a small section of memory that is managed by the operating system
- When you declare a scalar variable inside a function or a block, it is typically allocated on the stack.
- The stack is a region of memory managed by the compiler, and stack allocation and deallocation happen automatically as you enter and exit the scope of the variable.

In order to allocate an array on the stack in C, the notation is pretty straightforward:

```c
double numbers[ARRAY_SIZE]; 
```

where `ARRAY_SIZE` could be a constant known at compile time, or, by relying on a feature of the C99 standard known as variable-length arrays (VLA), could also be a run-time variable.


## Heap Allocation

- Heap allocation involves manually managing memory on the heap, a larger region of memory available to the program.
- Memory allocation on the heap is typically done using functions like `malloc()` and `calloc()` (to force contiguous allocation) and must be explicitly deallocated using `free()` when it is no longer needed.

For example, we could allocate our numbers variable on the heap in C with the following line:

```c
double* numbers = (double*)malloc(ARRAY_SIZE * sizeof(double)); 
```

When not required anymore, the memory has to bee manually freed using `free()`

```c
free(numbers)
```