As explained in class, and from [wikipedia](https://en.wikipedia.org/wiki/C_data_types#stddef.h):

> The C language specification includes the typedefs size_t and ptrdiff_t to represent memory-related quantities. Their size is defined according to the target processor's arithmetic capabilities, not the memory capabilities, such as available address space. Both of these types are defined in the <stddef.h> header (cstddef in C++). 

> size_t is an unsigned integer type used to represent the size of any object (including arrays) in the particular implementation. The operator sizeof yields a value of the type size_t. The maximum size of size_t is provided via SIZE_MAX, a macro constant which is defined in the <stdint.h> header (cstdint header in C++). size_t is guaranteed to be at least 16 bits wide. Additionally, POSIX includes ssize_t, which is a signed integer type of the same width as size_t. 

> ptrdiff_t is a signed integer type used to represent the difference between pointers. It is guaranteed to be valid only against pointers of the same type; subtraction of pointers consisting of different types is implementation-defined. 
