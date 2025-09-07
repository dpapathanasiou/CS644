Explanation of how the [PyOS_mystrnicmp(const char *s1, const char *s2, Py_ssize_t size)](https://github.com/python/cpython/blob/3.13/Python/pystrcmp.c#L6-L19) function from the c source for python ([Python/pystrcmp.c](https://github.com/python/cpython/blob/3.13/Python/pystrcmp.c)) works:

This function takes two pointers to strings (as `char *` sequences), along with the `size_t` definition for the current runtime (which is defined via the `#include "Python.h"`), and uses pointer iteration[^1] to go through each character of both strings at the same position, stopping only if the max `size_t` has been exceeded, or if either char is undefined, or if the two chars fail to match on case (using `Py_TOLOWER` to make them both lower case, also defined via the `#include "Python.h"`).

At the end of the loop, it returns the difference of the case match at the last char reached: for equal sized strings which matched every char, it will be a success, whereas for any conditions which caused the loop to break early, it will fail.

The only difference between the first and second functions in `Python/pystrcmp.c` is that the second only does not take `size_t` into account.

[^1] Pointer iteration on strings is described in [K&R Chapter 5 - Pointers](https://archive.org/details/cprogramminglang0000kern_2ed), with the [strlen](https://icarus.cs.weber.edu/~dab/cs1410/textbook/8.Strings/strlen.html) and [strcpy](https://web.eecs.umich.edu/gasm/tutorial/sectionstar3_8.html) examples in a similar "pointer arithmetic" style.