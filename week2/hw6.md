> Why does read return the number of bytes read? Why doesn't it just set buf to a null-terminated string, like other C functions?

Because this would be incorrect for binary files