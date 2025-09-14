> What happens when one program is reading from a file while another program is writing? Formulate a hypothesis, then write a pair of programs to test it.

Simple append writes and reads should work just fine, even if they happen to be simultaneous, but writes that target the beginning of an existing file should fail in upredicatable ways, depending on which program can claim the file handle first

Using [simple_reader.c](simple_reader.c) and [simple_writer.c](simple_writer.c) in a [script](chaos.sh) which executes simultaneous writes, including some that start overwriting the existing file, the results are non-deterministic, though checking the return codes from the syscalls enforces relatively clean program exits when the calls conflict:

```sh
$ sh chaos.sh
[writer] wrote to file (foo.txt) 12 bytes -> Life is good
[writer] wrote to file (foo.txt) 6 bytes -> muhaha
[writer] wrote to file (foo.txt) 17 bytes -> oh no, not again!
[reader] 0: oh no, not again!
[reader] file (foo.txt) has 17 bytes -> 0 lines

$ sh chaos.sh
[writer] wrote to file (foo.txt) 12 bytes -> Life is good
[writer] wrote to file (foo.txt) 17 bytes -> oh no, not again!
[writer] wrote to file (foo.txt) 6 bytes -> muhaha
[reader] 0: muhaha not again!
[reader] file (foo.txt) has 17 bytes -> 0 lines

$ sh chaos.sh
[writer] wrote to file (foo.txt) 12 bytes -> Life is good
[writer] wrote to file (foo.txt) 6 bytes -> muhaha
[reader] 0: muhahas good
[reader] file (foo.txt) has 12 bytes -> 0 lines
[writer] wrote to file (foo.txt) 17 bytes -> oh no, not again!

$ sh chaos.sh
[writer] wrote to file (foo.txt) 12 bytes -> Life is good
[writer] wrote to file (foo.txt) 6 bytes -> muhaha
[reader] 0: muhahas goodgain!
[reader] file (foo.txt) has 17 bytes -> 0 lines
[writer] wrote to file (foo.txt) 17 bytes -> oh no, not again!

$ sh chaos.sh
[reader] file (foo.txt) does not exist or cannot be opened for reading: -1 code
[writer] wrote to file (foo.txt) 12 bytes -> Life is good
[writer] wrote to file (foo.txt) 6 bytes -> muhaha
[writer] wrote to file (foo.txt) 17 bytes -> oh no, not again!
```