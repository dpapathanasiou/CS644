> Modify your program from in-class exercise 3 to count the number of whitespace characters in the file. Try it out on /usr/share/cs644/bigfile.txt. Experiment with different chunk sizes. How does it affect the performance of your program? (Tip: Run time ./myprogram to measure the running time of your program.)

Using [whitespace_reader.c](whitespace_reader.c) with different values for `size_t buffer_size` in line 20


```sh
$ time ./whitespace_reader /usr/share/cs644/bigfile.txt
File (/usr/share/cs644/bigfile.txt) has 12379278 bytes (using 2 BUFSIZ) -> 1650748 spaces

real	0m3.780s
user	0m0.558s
sys	0m3.222s

$ time ./whitespace_reader /usr/share/cs644/bigfile.txt
File (/usr/share/cs644/bigfile.txt) has 12379278 bytes (using 512 BUFSIZ) -> 1650748 spaces

real	0m0.084s
user	0m0.073s
sys	0m0.010s

$ time ./whitespace_reader /usr/share/cs644/bigfile.txt
File (/usr/share/cs644/bigfile.txt) has 12379278 bytes (using 1024 BUFSIZ) -> 1650748 spaces

real	0m0.077s
user	0m0.064s
sys	0m0.012s

$ time ./whitespace_reader /usr/share/cs644/bigfile.txt
File (/usr/share/cs644/bigfile.txt) has 12379278 bytes (using 8192 BUFSIZ) -> 1650748 spaces

real	0m0.069s
user	0m0.067s
sys	0m0.002s

```