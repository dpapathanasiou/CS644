> Modify your program from exercise 3 to read a file line-by-line.

Using [line_reader.c](line_reader.c) on the same large file:

```sh
$ time ./line_reader /usr/share/cs644/bigfile.txt
File (/usr/share/cs644/bigfile.txt) has 12379278 bytes (using 8192 BUFSIZ) -> 39999 lines

real	0m0.021s
user	0m0.018s
sys	0m0.003s
```

Comparing results with `wc`:

```sh
 wc -l /usr/share/cs644/bigfile.txt
39999 /usr/share/cs644/bigfile.txt

$ wc -c /usr/share/cs644/bigfile.txt
12379278 /usr/share/cs644/bigfile.txt
```