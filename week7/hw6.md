> What syscalls do pthreads locks use under the hood? Write a program and run it under strace to find out. 

More interesting ones were [futex](https://www.man7.org/linux/man-pages/man2/futex.2.html) and [clone3](https://www.man7.org/linux/man-pages/man2/clone.2.html):

```sh
$ strace ./hw4-with-join
execve("./hw4-with-join", ["./hw4-with-join"], 0x7fff0125df50 /* 51 vars */) = 0
brk(NULL)                               = 0x61d401377000
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f54fbffb000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=76499, ...}) = 0
mmap(NULL, 76499, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f54fbfe8000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\220\243\2\0\0\0\0\0"..., 832) = 832
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
fstat(3, {st_mode=S_IFREG|0755, st_size=2125328, ...}) = 0
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
mmap(NULL, 2170256, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f54fbc00000
mmap(0x7f54fbc28000, 1605632, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x7f54fbc28000
mmap(0x7f54fbdb0000, 323584, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1b0000) = 0x7f54fbdb0000
mmap(0x7f54fbdff000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1fe000) = 0x7f54fbdff000
mmap(0x7f54fbe05000, 52624, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f54fbe05000
close(3)                                = 0
mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f54fbfe5000
arch_prctl(ARCH_SET_FS, 0x7f54fbfe5740) = 0
set_tid_address(0x7f54fbfe5a10)         = 20792
set_robust_list(0x7f54fbfe5a20, 24)     = 0
rseq(0x7f54fbfe6060, 0x20, 0, 0x53053053) = 0
mprotect(0x7f54fbdff000, 16384, PROT_READ) = 0
mprotect(0x61d3e5b5e000, 4096, PROT_READ) = 0
mprotect(0x7f54fc033000, 8192, PROT_READ) = 0
prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
munmap(0x7f54fbfe8000, 76499)           = 0
rt_sigaction(SIGRT_1, {sa_handler=0x7f54fbc99530, sa_mask=[], sa_flags=SA_RESTORER|SA_ONSTACK|SA_RESTART|SA_SIGINFO, sa_restorer=0x7f54fbc45330}, NULL, 8) = 0
rt_sigprocmask(SIG_UNBLOCK, [RTMIN RT_1], NULL, 8) = 0
mmap(NULL, 8392704, PROT_NONE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_STACK, -1, 0) = 0x7f54fb3ff000
mprotect(0x7f54fb400000, 8388608, PROT_READ|PROT_WRITE) = 0
getrandom("\xe6\x1a\x84\x77\x19\x03\xff\xa1", 8, GRND_NONBLOCK) = 8
brk(NULL)                               = 0x61d401377000
brk(0x61d401398000)                     = 0x61d401398000
rt_sigprocmask(SIG_BLOCK, ~[], [], 8)   = 0
clone3({flags=CLONE_VM|CLONE_FS|CLONE_FILES|CLONE_SIGHAND|CLONE_THREAD|CLONE_SYSVSEM|CLONE_SETTLS|CLONE_PARENT_SETTID|CLONE_CHILD_CLEARTID, child_tid=0x7f54fbbff990, parent_tid=0x7f54fbbff990, exit_signal=0, stack=0x7f54fb3ff000, stack_size=0x7fff80, tls=0x7f54fbbff6c0} => {parent_tid=[20793]}, 88) = 20793
rt_sigprocmask(SIG_SETMASK, [], NULL, 8) = 0
Hello from a new thread! - Iteration 0
futex(0x7f54fbe05710, FUTEX_WAIT_PRIVATE, 2, NULL) = -1 EAGAIN (Resource temporarily unavailable)
write(1, "Hello from the main thread - Ite"..., 41Hello from the main thread - Iteration 0
) = 41
futex(0x7f54fbe05710, FUTEX_WAKE_PRIVATE, 1) = 0
clock_nanosleep(CLOCK_REALTIME, 0, {tv_sec=1, tv_nsec=0}, 0x7ffe270f34f0) = 0
write(1, "Hello from the main thread - Ite"..., 41Hello from the main thread - Iteration 1
) = 41
clock_nanosleep(CLOCK_REALTIME, 0, {tv_sec=1, tv_nsec=0}, 0x7ffe270f34f0) = 0
write(1, "Hello from the main thread - Ite"..., 41Hello from the main thread - Iteration 2
) = 41
clock_nanosleep(CLOCK_REALTIME, 0, {tv_sec=1, tv_nsec=0}, 0x7ffe270f34f0) = 0
write(1, "Hello from the main thread - Ite"..., 41Hello from the main thread - Iteration 3
) = 41
clock_nanosleep(CLOCK_REALTIME, 0, {tv_sec=1, tv_nsec=0}, 0x7ffe270f34f0) = 0
write(1, "Hello from the main thread - Ite"..., 41Hello from the main thread - Iteration 4
) = 41
clock_nanosleep(CLOCK_REALTIME, 0, {tv_sec=1, tv_nsec=0}, 0x7ffe270f34f0) = 0
write(1, "Hello from the main thread - Ite"..., 41Hello from the main thread - Iteration 5
) = 41
clock_nanosleep(CLOCK_REALTIME, 0, {tv_sec=1, tv_nsec=0}, 0x7ffe270f34f0) = 0
write(1, "Hello from the main thread - Ite"..., 41Hello from the main thread - Iteration 6
) = 41
clock_nanosleep(CLOCK_REALTIME, 0, {tv_sec=1, tv_nsec=0}, 0x7ffe270f34f0) = 0
write(1, "Hello from the main thread - Ite"..., 41Hello from the main thread - Iteration 7
) = 41
clock_nanosleep(CLOCK_REALTIME, 0, {tv_sec=1, tv_nsec=0}, 0x7ffe270f34f0) = 0
write(1, "Hello from the main thread - Ite"..., 41Hello from the main thread - Iteration 8
) = 41
clock_nanosleep(CLOCK_REALTIME, 0, {tv_sec=1, tv_nsec=0}, 0x7ffe270f34f0) = 0
write(1, "Hello from the main thread - Ite"..., 41Hello from the main thread - Iteration 9
) = 41
clock_nanosleep(CLOCK_REALTIME, 0, {tv_sec=1, tv_nsec=0}, Hello from a new thread! - Iteration 1
0x7ffe270f34f0) = 0
futex(0x7f54fbbff990, FUTEX_WAIT_BITSET|FUTEX_CLOCK_REALTIME, 20793, NULL, FUTEX_BITSET_MATCH_ANYHello from a new thread! - Iteration 2
Hello from a new thread! - Iteration 3
Hello from a new thread! - Iteration 4
Hello from a new thread! - Iteration 5
Hello from a new thread! - Iteration 6
Hello from a new thread! - Iteration 7
Hello from a new thread! - Iteration 8
Hello from a new thread! - Iteration 9
) = 0
write(1, "Main thread exiting.\n", 21Main thread exiting.
)  = 21
exit_group(0)                           = ?
+++ exited with 0 +++
```