> Many programming languages have a high-level way to run a child process, such as Python's subprocess.run. Write a simple program to demonstrate it, then use strace to determine what syscalls it makes. (The -f flag lets you see syscalls in child processes as well.) 

Using [hw7.py](hw7.py) as the `subprocess` example:

```sh
strace -f python3 hw7.py
execve("/usr/bin/python3", ["python3", "hw7.py"], 0x7ffcb69126f0 /* 51 vars */) = 0
brk(NULL)                               = 0xa279000
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7bab9b088000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=76499, ...}) = 0
mmap(NULL, 76499, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7bab9b075000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libm.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0644, st_size=952616, ...}) = 0
mmap(NULL, 950296, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7bab9af8c000
mmap(0x7bab9af9c000, 520192, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x10000) = 0x7bab9af9c000
mmap(0x7bab9b01b000, 360448, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x8f000) = 0x7bab9b01b000
mmap(0x7bab9b073000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0xe7000) = 0x7bab9b073000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libz.so.1", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0644, st_size=113000, ...}) = 0
mmap(NULL, 110744, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7bab9af70000
mmap(0x7bab9af72000, 73728, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x2000) = 0x7bab9af72000
mmap(0x7bab9af84000, 24576, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x14000) = 0x7bab9af84000
mmap(0x7bab9af8a000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1a000) = 0x7bab9af8a000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libexpat.so.1", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0644, st_size=174336, ...}) = 0
mmap(NULL, 176256, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7bab9af44000
mmap(0x7bab9af48000, 118784, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x4000) = 0x7bab9af48000
mmap(0x7bab9af65000, 32768, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x21000) = 0x7bab9af65000
mmap(0x7bab9af6d000, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x7bab9af6d000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\220\243\2\0\0\0\0\0"..., 832) = 832
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
fstat(3, {st_mode=S_IFREG|0755, st_size=2125328, ...}) = 0
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
mmap(NULL, 2170256, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7bab9ac00000
mmap(0x7bab9ac28000, 1605632, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x7bab9ac28000
mmap(0x7bab9adb0000, 323584, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1b0000) = 0x7bab9adb0000
mmap(0x7bab9adff000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1fe000) = 0x7bab9adff000
mmap(0x7bab9ae05000, 52624, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7bab9ae05000
close(3)                                = 0
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7bab9af42000
arch_prctl(ARCH_SET_FS, 0x7bab9af43080) = 0
set_tid_address(0x7bab9af43350)         = 25902
set_robust_list(0x7bab9af43360, 24)     = 0
rseq(0x7bab9af439a0, 0x20, 0, 0x53053053) = 0
mprotect(0x7bab9adff000, 16384, PROT_READ) = 0
mprotect(0x7bab9af6d000, 8192, PROT_READ) = 0
mprotect(0x7bab9af8a000, 4096, PROT_READ) = 0
mprotect(0x7bab9b073000, 4096, PROT_READ) = 0
mprotect(0xa28000, 4096, PROT_READ)     = 0
mprotect(0x7bab9b0c0000, 8192, PROT_READ) = 0
prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
munmap(0x7bab9b075000, 76499)           = 0
getrandom("\x3f\x6e\x3d\x4f\xcc\xe9\x81\xc3", 8, GRND_NONBLOCK) = 8
brk(NULL)                               = 0xa279000
brk(0xa29a000)                          = 0xa29a000
openat(AT_FDCWD, "/usr/lib/locale/locale-archive", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=5719296, ...}) = 0
mmap(NULL, 5719296, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7bab9a600000
close(3)                                = 0
openat(AT_FDCWD, "/usr/lib/x86_64-linux-gnu/gconv/gconv-modules.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=27028, ...}) = 0
mmap(NULL, 27028, PROT_READ, MAP_SHARED, 3, 0) = 0x7bab9b081000
close(3)                                = 0
futex(0x7bab9ae0472c, FUTEX_WAKE_PRIVATE, 2147483647) = 0
getcwd("/home/denis/repos/repos-git/CS644/week4", 4096) = 40
getrandom("\xb5\xe0\x97\x82\xce\x23\x1e\xb2\xb2\xbe\xad\x64\x44\x63\x1b\xdb\xac\x2d\x85\xbc\x0c\x6b\x8d\xf1", 24, GRND_NONBLOCK) = 24
gettid()                                = 25902
mmap(NULL, 1048576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7bab9ae42000
mmap(NULL, 266240, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7bab9abbf000
mmap(NULL, 135168, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7bab9ae21000
brk(0xa2bb000)                          = 0xa2bb000
mmap(NULL, 16384, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7bab9b07d000
brk(0xa2dc000)                          = 0xa2dc000
newfstatat(AT_FDCWD, "/home/denis/.sdkman/candidates/java/current/bin/python3", 0x7ffe297a7440, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/home/denis/.cargo/bin/python3", 0x7ffe297a7440, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/home/denis/.local/bin/python3", 0x7ffe297a7440, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/usr/local/sbin/python3", 0x7ffe297a7440, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/usr/local/bin/python3", 0x7ffe297a7440, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/usr/sbin/python3", 0x7ffe297a7440, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/usr/bin/python3", {st_mode=S_IFREG|0755, st_size=8021824, ...}, 0) = 0
openat(AT_FDCWD, "/usr/pyvenv.cfg", O_RDONLY) = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/usr/bin/pyvenv.cfg", O_RDONLY) = -1 ENOENT (No such file or directory)
readlink("/usr/bin/python3", "python3.12", 4096) = 10
readlink("/usr/bin/python3.12", 0x7ffe297a2460, 4096) = -1 EINVAL (Invalid argument)
openat(AT_FDCWD, "/usr/bin/python3._pth", O_RDONLY) = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/usr/bin/python3.12._pth", O_RDONLY) = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/usr/bin/pybuilddir.txt", O_RDONLY) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/usr/bin/Modules/Setup.local", 0x7ffe297a7440, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/usr/bin/lib/python312.zip", 0x7ffe297a7200, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/usr/lib/python312.zip", 0x7ffe297a7260, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/usr/bin/lib/python3.12/os.py", 0x7ffe297a7260, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/usr/bin/lib/python3.12/os.pyc", 0x7ffe297a7260, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/usr/lib/python3.12/os.py", {st_mode=S_IFREG|0644, st_size=39786, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/bin/lib/python3.12/lib-dynload", 0x7ffe297a7260, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/usr/lib/python3.12/lib-dynload", {st_mode=S_IFDIR|0755, st_size=16384, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/lib-dynload", {st_mode=S_IFDIR|0755, st_size=16384, ...}, 0) = 0
brk(0xa2fd000)                          = 0xa2fd000
openat(AT_FDCWD, "/etc/localtime", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=3552, ...}) = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=3552, ...}) = 0
read(3, "TZif2\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\6\0\0\0\6\0\0\0\0"..., 4096) = 3552
lseek(3, -2260, SEEK_CUR)               = 1292
read(3, "TZif2\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\6\0\0\0\6\0\0\0\0"..., 4096) = 2260
close(3)                                = 0
newfstatat(AT_FDCWD, "/usr/lib/python312.zip", 0x7ffe297a6c90, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/usr/lib", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python312.zip", 0x7ffe297a7010, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/usr/lib/python3.12", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12", O_RDONLY|O_NONBLOCK|O_CLOEXEC|O_DIRECTORY) = 3
fstat(3, {st_mode=S_IFDIR|0755, st_size=20480, ...}) = 0
getdents64(3, 0xa2de990 /* 203 entries */, 32768) = 6792
getdents64(3, 0xa2de990 /* 0 entries */, 32768) = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/encodings/__init__.cpython-312-x86_64-linux-gnu.so", 0x7ffe297a7010, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/usr/lib/python3.12/encodings/__init__.abi3.so", 0x7ffe297a7010, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/usr/lib/python3.12/encodings/__init__.so", 0x7ffe297a7010, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/usr/lib/python3.12/encodings/__init__.py", {st_mode=S_IFREG|0644, st_size=5884, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/encodings/__init__.py", {st_mode=S_IFREG|0644, st_size=5884, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/encodings/__pycache__/__init__.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fcntl(3, F_GETFD)                       = 0x1 (flags FD_CLOEXEC)
fstat(3, {st_mode=S_IFREG|0644, st_size=5790, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a6c50)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=5790, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0)!\236h\374\26\0\0\343\0\0\0\0\0\0\0\0\0\0\0\0\6\0\0"..., 5791) = 5790
read(3, "", 1)                          = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/encodings", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/encodings", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/encodings", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/encodings", O_RDONLY|O_NONBLOCK|O_CLOEXEC|O_DIRECTORY) = 3
fstat(3, {st_mode=S_IFDIR|0755, st_size=20480, ...}) = 0
getdents64(3, 0xa2e8150 /* 125 entries */, 32768) = 4224
getdents64(3, 0xa2e8150 /* 0 entries */, 32768) = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/encodings/aliases.py", {st_mode=S_IFREG|0644, st_size=15677, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/encodings/aliases.py", {st_mode=S_IFREG|0644, st_size=15677, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/encodings/__pycache__/aliases.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=12408, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a61d0)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=12408, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0)!\236h==\0\0\343\0\0\0\0\0\0\0\0\0\0\0\0\5\0\0"..., 12409) = 12408
read(3, "", 1)                          = 0
close(3)                                = 0
brk(0xa31e000)                          = 0xa31e000
newfstatat(AT_FDCWD, "/usr/lib/python3.12/encodings", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/encodings/utf_8.py", {st_mode=S_IFREG|0644, st_size=1005, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/encodings/utf_8.py", {st_mode=S_IFREG|0644, st_size=1005, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/encodings/__pycache__/utf_8.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=2147, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a6ce0)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=2147, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0)!\236h\355\3\0\0\343\0\0\0\0\0\0\0\0\0\0\0\0\5\0\0"..., 2148) = 2147
read(3, "", 1)                          = 0
close(3)                                = 0
rt_sigaction(SIGPIPE, {sa_handler=SIG_IGN, sa_mask=[], sa_flags=SA_RESTORER|SA_ONSTACK, sa_restorer=0x7bab9ac45330}, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGXFSZ, {sa_handler=SIG_IGN, sa_mask=[], sa_flags=SA_RESTORER|SA_ONSTACK, sa_restorer=0x7bab9ac45330}, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
mmap(NULL, 1048576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7bab9a500000
rt_sigaction(SIGHUP, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGINT, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGQUIT, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGILL, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGTRAP, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGABRT, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGBUS, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGFPE, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGKILL, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGUSR1, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGSEGV, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGUSR2, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGPIPE, NULL, {sa_handler=SIG_IGN, sa_mask=[], sa_flags=SA_RESTORER|SA_ONSTACK, sa_restorer=0x7bab9ac45330}, 8) = 0
rt_sigaction(SIGALRM, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGTERM, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGSTKFLT, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGCHLD, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGCONT, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGSTOP, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGTSTP, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGTTIN, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGTTOU, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGURG, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGXCPU, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGXFSZ, NULL, {sa_handler=SIG_IGN, sa_mask=[], sa_flags=SA_RESTORER|SA_ONSTACK, sa_restorer=0x7bab9ac45330}, 8) = 0
rt_sigaction(SIGVTALRM, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGPROF, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGWINCH, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGIO, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGPWR, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGSYS, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_2, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_3, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_4, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_5, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_6, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_7, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_8, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_9, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_10, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_11, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_12, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_13, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_14, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_15, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_16, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_17, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_18, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_19, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_20, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_21, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_22, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_23, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_24, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_25, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_26, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_27, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_28, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_29, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_30, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_31, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGRT_32, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGINT, {sa_handler=0x6e6b20, sa_mask=[], sa_flags=SA_RESTORER|SA_ONSTACK, sa_restorer=0x7bab9ac45330}, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
fstat(0, {st_mode=S_IFCHR|0620, st_rdev=makedev(0x88, 0x3), ...}) = 0
fcntl(0, F_GETFD)                       = 0
fstat(0, {st_mode=S_IFCHR|0620, st_rdev=makedev(0x88, 0x3), ...}) = 0
ioctl(0, TCGETS, {c_iflag=ICRNL|IXON|IUTF8, c_oflag=NL0|CR0|TAB0|BS0|VT0|FF0|OPOST|ONLCR, c_cflag=B38400|CS8|CREAD, c_lflag=ISIG|ICANON|ECHO|ECHOE|ECHOK|IEXTEN|ECHOCTL|ECHOKE, ...}) = 0
lseek(0, 0, SEEK_CUR)                   = -1 ESPIPE (Illegal seek)
ioctl(0, TCGETS, {c_iflag=ICRNL|IXON|IUTF8, c_oflag=NL0|CR0|TAB0|BS0|VT0|FF0|OPOST|ONLCR, c_cflag=B38400|CS8|CREAD, c_lflag=ISIG|ICANON|ECHO|ECHOE|ECHOK|IEXTEN|ECHOCTL|ECHOKE, ...}) = 0
fcntl(1, F_GETFD)                       = 0
fstat(1, {st_mode=S_IFCHR|0620, st_rdev=makedev(0x88, 0x3), ...}) = 0
ioctl(1, TCGETS, {c_iflag=ICRNL|IXON|IUTF8, c_oflag=NL0|CR0|TAB0|BS0|VT0|FF0|OPOST|ONLCR, c_cflag=B38400|CS8|CREAD, c_lflag=ISIG|ICANON|ECHO|ECHOE|ECHOK|IEXTEN|ECHOCTL|ECHOKE, ...}) = 0
lseek(1, 0, SEEK_CUR)                   = -1 ESPIPE (Illegal seek)
ioctl(1, TCGETS, {c_iflag=ICRNL|IXON|IUTF8, c_oflag=NL0|CR0|TAB0|BS0|VT0|FF0|OPOST|ONLCR, c_cflag=B38400|CS8|CREAD, c_lflag=ISIG|ICANON|ECHO|ECHOE|ECHOK|IEXTEN|ECHOCTL|ECHOKE, ...}) = 0
fcntl(2, F_GETFD)                       = 0
fstat(2, {st_mode=S_IFCHR|0620, st_rdev=makedev(0x88, 0x3), ...}) = 0
ioctl(2, TCGETS, {c_iflag=ICRNL|IXON|IUTF8, c_oflag=NL0|CR0|TAB0|BS0|VT0|FF0|OPOST|ONLCR, c_cflag=B38400|CS8|CREAD, c_lflag=ISIG|ICANON|ECHO|ECHOE|ECHOK|IEXTEN|ECHOCTL|ECHOKE, ...}) = 0
lseek(2, 0, SEEK_CUR)                   = -1 ESPIPE (Illegal seek)
ioctl(2, TCGETS, {c_iflag=ICRNL|IXON|IUTF8, c_oflag=NL0|CR0|TAB0|BS0|VT0|FF0|OPOST|ONLCR, c_cflag=B38400|CS8|CREAD, c_lflag=ISIG|ICANON|ECHO|ECHOE|ECHOK|IEXTEN|ECHOCTL|ECHOKE, ...}) = 0
newfstatat(AT_FDCWD, "/usr/bin/pyvenv.cfg", 0x7ffe297a6c50, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/usr/pyvenv.cfg", 0x7ffe297a6cb0, 0) = -1 ENOENT (No such file or directory)
geteuid()                               = 1000
getuid()                                = 1000
getegid()                               = 1000
getgid()                                = 1000
newfstatat(AT_FDCWD, "/home/denis/.local/lib/python3.12/site-packages", 0x7ffe297a6e80, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/usr/local/lib/python3.12/dist-packages", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
openat(AT_FDCWD, "/usr/local/lib/python3.12/dist-packages", O_RDONLY|O_NONBLOCK|O_CLOEXEC|O_DIRECTORY) = 3
fstat(3, {st_mode=S_IFDIR|0755, st_size=4096, ...}) = 0
getdents64(3, 0xa30b960 /* 2 entries */, 32768) = 48
getdents64(3, 0xa30b960 /* 0 entries */, 32768) = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/usr/lib/python3/dist-packages", {st_mode=S_IFDIR|0755, st_size=12288, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3/dist-packages", O_RDONLY|O_NONBLOCK|O_CLOEXEC|O_DIRECTORY) = 3
fstat(3, {st_mode=S_IFDIR|0755, st_size=12288, ...}) = 0
getdents64(3, 0xa30b960 /* 245 entries */, 32768) = 9888
getdents64(3, 0xa30b960 /* 0 entries */, 32768) = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/dist-packages", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/dist-packages", O_RDONLY|O_NONBLOCK|O_CLOEXEC|O_DIRECTORY) = 3
fstat(3, {st_mode=S_IFDIR|0755, st_size=4096, ...}) = 0
getdents64(3, 0xa30b960 /* 3 entries */, 32768) = 96
getdents64(3, 0xa30b960 /* 0 entries */, 32768) = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/sitecustomize.py", {st_mode=S_IFREG|0644, st_size=155, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/sitecustomize.py", {st_mode=S_IFREG|0644, st_size=155, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/__pycache__/sitecustomize.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=300, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a67c0)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=300, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0\273$\26f\233\0\0\0\343\0\0\0\0\0\0\0\0\0\0\0\0\4\0\0"..., 301) = 300
read(3, "", 1)                          = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/lib-dynload", {st_mode=S_IFDIR|0755, st_size=16384, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/lib-dynload", {st_mode=S_IFDIR|0755, st_size=16384, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/lib-dynload", {st_mode=S_IFDIR|0755, st_size=16384, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/lib-dynload", O_RDONLY|O_NONBLOCK|O_CLOEXEC|O_DIRECTORY) = 3
fstat(3, {st_mode=S_IFDIR|0755, st_size=16384, ...}) = 0
getdents64(3, 0xa30b960 /* 49 entries */, 32768) = 3104
getdents64(3, 0xa30b960 /* 0 entries */, 32768) = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/usr/local/lib/python3.12/dist-packages", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/local/lib/python3.12/dist-packages", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/local/lib/python3.12/dist-packages", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
openat(AT_FDCWD, "/usr/local/lib/python3.12/dist-packages", O_RDONLY|O_NONBLOCK|O_CLOEXEC|O_DIRECTORY) = 3
fstat(3, {st_mode=S_IFDIR|0755, st_size=4096, ...}) = 0
getdents64(3, 0xa30c170 /* 2 entries */, 32768) = 48
getdents64(3, 0xa30c170 /* 0 entries */, 32768) = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/usr/lib/python3/dist-packages", {st_mode=S_IFDIR|0755, st_size=12288, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3/dist-packages", {st_mode=S_IFDIR|0755, st_size=12288, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3/dist-packages", {st_mode=S_IFDIR|0755, st_size=12288, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3/dist-packages", O_RDONLY|O_NONBLOCK|O_CLOEXEC|O_DIRECTORY) = 3
fstat(3, {st_mode=S_IFDIR|0755, st_size=12288, ...}) = 0
getdents64(3, 0xa30c170 /* 245 entries */, 32768) = 9888
getdents64(3, 0xa30c170 /* 0 entries */, 32768) = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/usr/lib/python3/dist-packages/apport_python_hook.py", {st_mode=S_IFREG|0644, st_size=8695, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3/dist-packages/apport_python_hook.py", {st_mode=S_IFREG|0644, st_size=8695, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3/dist-packages/__pycache__/apport_python_hook.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=8876, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a6150)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=8876, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0\247\22!f\367!\0\0\343\0\0\0\0\0\0\0\0\0\0\0\0\2\0\0"..., 8877) = 8876
read(3, "", 1)                          = 0
close(3)                                = 0
getcwd("/home/denis/repos/repos-git/CS644/week4", 1024) = 40
newfstatat(AT_FDCWD, "/usr/lib/python3.12", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/lib-dynload", {st_mode=S_IFDIR|0755, st_size=16384, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/local/lib/python3.12/dist-packages", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3/dist-packages", {st_mode=S_IFDIR|0755, st_size=12288, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/dist-packages", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/dist-packages", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/dist-packages", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/dist-packages", O_RDONLY|O_NONBLOCK|O_CLOEXEC|O_DIRECTORY) = 3
fstat(3, {st_mode=S_IFDIR|0755, st_size=4096, ...}) = 0
getdents64(3, 0xa3131e0 /* 3 entries */, 32768) = 96
getdents64(3, 0xa3131e0 /* 0 entries */, 32768) = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4/hw7.py", {st_mode=S_IFREG|0664, st_size=332, ...}, 0) = 0
openat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4/hw7.py", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0664, st_size=332, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a7320)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, -22, SEEK_END)                 = 310
lseek(3, 0, SEEK_CUR)                   = 310
read(3, "** stderr: {stderr}')\n", 4096) = 22
lseek(3, 0, SEEK_END)                   = 332
lseek(3, 0, SEEK_CUR)                   = 332
lseek(3, 0, SEEK_SET)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0664, st_size=332, ...}) = 0
read(3, "import subprocess\n\nls_thread = s"..., 333) = 332
read(3, "", 1)                          = 0
lseek(3, 0, SEEK_SET)                   = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4/hw7.py", {st_mode=S_IFREG|0664, st_size=332, ...}, 0) = 0
readlink("hw7.py", 0x7ffe29796ac0, 4096) = -1 EINVAL (Invalid argument)
getcwd("/home/denis/repos/repos-git/CS644/week4", 1024) = 40
readlink("/home/denis/repos/repos-git/CS644/week4/hw7.py", 0x7ffe29796660, 1023) = -1 EINVAL (Invalid argument)
openat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4/hw7.py", O_RDONLY) = 3
ioctl(3, FIOCLEX)                       = 0
fstat(3, {st_mode=S_IFREG|0664, st_size=332, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a7a50)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0664, st_size=332, ...}) = 0
read(3, "import subprocess\n\nls_thread = s"..., 4096) = 332
lseek(3, 0, SEEK_SET)                   = 0
read(3, "import subprocess\n\nls_thread = s"..., 4096) = 332
brk(0xa340000)                          = 0xa340000
read(3, "", 4096)                       = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4", {st_mode=S_IFDIR|0775, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4", {st_mode=S_IFDIR|0775, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4", {st_mode=S_IFDIR|0775, st_size=4096, ...}, 0) = 0
openat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4", O_RDONLY|O_NONBLOCK|O_CLOEXEC|O_DIRECTORY) = 3
fstat(3, {st_mode=S_IFDIR|0775, st_size=4096, ...}) = 0
getdents64(3, 0xa31f610 /* 5 entries */, 32768) = 144
getdents64(3, 0xa31f610 /* 0 entries */, 32768) = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/subprocess.py", {st_mode=S_IFREG|0644, st_size=88725, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/subprocess.py", {st_mode=S_IFREG|0644, st_size=88725, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/__pycache__/subprocess.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=79187, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a7020)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=79187, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0)!\236h\225Z\1\0\343\0\0\0\0\0\0\0\0\0\0\0\0\5\0\0"..., 79188) = 79187
read(3, "", 1)                          = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4", {st_mode=S_IFDIR|0775, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/locale.py", {st_mode=S_IFREG|0644, st_size=78562, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/locale.py", {st_mode=S_IFREG|0644, st_size=78562, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/__pycache__/locale.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=59536, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a69b0)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=59536, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0)!\236h\3422\1\0\343\0\0\0\0\0\0\0\0\0\0\0\0\f\0\0"..., 59537) = 59536
read(3, "", 1)                          = 0
close(3)                                = 0
brk(0xa362000)                          = 0xa362000
newfstatat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4", {st_mode=S_IFDIR|0775, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/re/__init__.cpython-312-x86_64-linux-gnu.so", 0x7ffe297a66a0, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/usr/lib/python3.12/re/__init__.abi3.so", 0x7ffe297a66a0, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/usr/lib/python3.12/re/__init__.so", 0x7ffe297a66a0, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/usr/lib/python3.12/re/__init__.py", {st_mode=S_IFREG|0644, st_size=16315, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/re/__init__.py", {st_mode=S_IFREG|0644, st_size=16315, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/re/__pycache__/__init__.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=17938, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a6340)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=17938, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0)!\236h\273?\0\0\343\0\0\0\0\0\0\0\0\0\0\0\0\10\0\0"..., 17939) = 17938
read(3, "", 1)                          = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4", {st_mode=S_IFDIR|0775, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/enum.py", {st_mode=S_IFREG|0644, st_size=81636, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/enum.py", {st_mode=S_IFREG|0644, st_size=81636, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/__pycache__/enum.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=80708, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a5cd0)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=80708, ...}) = 0
brk(0xa395000)                          = 0xa395000
read(3, "\313\r\r\n\0\0\0\0)!\236h\344>\1\0\343\0\0\0\0\0\0\0\0\0\0\0\0\10\0\0"..., 80709) = 80708
read(3, "", 1)                          = 0
close(3)                                = 0
brk(0xa381000)                          = 0xa381000
newfstatat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4", {st_mode=S_IFDIR|0775, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/types.py", {st_mode=S_IFREG|0644, st_size=10993, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/types.py", {st_mode=S_IFREG|0644, st_size=10993, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/__pycache__/types.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=14939, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a5660)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=14939, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0)!\236h\361*\0\0\343\0\0\0\0\0\0\0\0\0\0\0\0\6\0\0"..., 14940) = 14939
read(3, "", 1)                          = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4", {st_mode=S_IFDIR|0775, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/operator.py", {st_mode=S_IFREG|0644, st_size=10965, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/operator.py", {st_mode=S_IFREG|0644, st_size=10965, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/__pycache__/operator.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=17364, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a5660)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=17364, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0)!\236h\325*\0\0\343\0\0\0\0\0\0\0\0\0\0\0\0\4\0\0"..., 17365) = 17364
read(3, "", 1)                          = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4", {st_mode=S_IFDIR|0775, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/functools.py", {st_mode=S_IFREG|0644, st_size=38126, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/functools.py", {st_mode=S_IFREG|0644, st_size=38126, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/__pycache__/functools.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=40506, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a5660)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=40506, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0)!\236h\356\224\0\0\343\0\0\0\0\0\0\0\0\0\0\0\0\7\0\0"..., 40507) = 40506
read(3, "", 1)                          = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4", {st_mode=S_IFDIR|0775, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/collections/__init__.cpython-312-x86_64-linux-gnu.so", 0x7ffe297a5350, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/usr/lib/python3.12/collections/__init__.abi3.so", 0x7ffe297a5350, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/usr/lib/python3.12/collections/__init__.so", 0x7ffe297a5350, 0) = -1 ENOENT (No such file or directory)
newfstatat(AT_FDCWD, "/usr/lib/python3.12/collections/__init__.py", {st_mode=S_IFREG|0644, st_size=52378, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/collections/__init__.py", {st_mode=S_IFREG|0644, st_size=52378, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/collections/__pycache__/__init__.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=73089, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a4ff0)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=73089, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0)!\236h\232\314\0\0\343\0\0\0\0\0\0\0\0\0\0\0\0\5\0\0"..., 73090) = 73089
read(3, "", 1)                          = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4", {st_mode=S_IFDIR|0775, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/keyword.py", {st_mode=S_IFREG|0644, st_size=1073, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/keyword.py", {st_mode=S_IFREG|0644, st_size=1073, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/__pycache__/keyword.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=1041, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a4980)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=1041, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0)!\236h1\4\0\0\343\0\0\0\0\0\0\0\0\0\0\0\0\3\0\0"..., 1042) = 1041
read(3, "", 1)                          = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4", {st_mode=S_IFDIR|0775, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/reprlib.py", {st_mode=S_IFREG|0644, st_size=6569, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/reprlib.py", {st_mode=S_IFREG|0644, st_size=6569, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/__pycache__/reprlib.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=9909, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a4980)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=9909, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0)!\236h\251\31\0\0\343\0\0\0\0\0\0\0\0\0\0\0\0\4\0\0"..., 9910) = 9909
read(3, "", 1)                          = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/re", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/re", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/re", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/re", O_RDONLY|O_NONBLOCK|O_CLOEXEC|O_DIRECTORY) = 3
fstat(3, {st_mode=S_IFDIR|0755, st_size=4096, ...}) = 0
getdents64(3, 0xa372870 /* 8 entries */, 32768) = 248
getdents64(3, 0xa372870 /* 0 entries */, 32768) = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/re/_compiler.py", {st_mode=S_IFREG|0644, st_size=26089, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/re/_compiler.py", {st_mode=S_IFREG|0644, st_size=26089, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/re/__pycache__/_compiler.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=26516, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a5860)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=26516, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0)!\236h\351e\0\0\343\0\0\0\0\0\0\0\0\0\0\0\0\10\0\0"..., 26517) = 26516
read(3, "", 1)                          = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/re", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/re/_parser.py", {st_mode=S_IFREG|0644, st_size=41201, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/re/_parser.py", {st_mode=S_IFREG|0644, st_size=41201, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/re/__pycache__/_parser.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=42007, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a4d80)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=42007, ...}) = 0
brk(0xa3ab000)                          = 0xa3ab000
read(3, "\313\r\r\n\0\0\0\0)!\236h\361\240\0\0\343\0\0\0\0\0\0\0\0\0\0\0\0\v\0\0"..., 42008) = 42007
read(3, "", 1)                          = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/re", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/re/_constants.py", {st_mode=S_IFREG|0644, st_size=5930, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/re/_constants.py", {st_mode=S_IFREG|0644, st_size=5930, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/re/__pycache__/_constants.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=5296, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a4710)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=5296, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0)!\236h*\27\0\0\343\0\0\0\0\0\0\0\0\0\0\0\0\24\0\0"..., 5297) = 5296
read(3, "", 1)                          = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/re", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/re/_casefix.py", {st_mode=S_IFREG|0644, st_size=5446, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/re/_casefix.py", {st_mode=S_IFREG|0644, st_size=5446, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/re/__pycache__/_casefix.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=1816, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a51f0)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=1816, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0)!\236hF\25\0\0\343\0\0\0\0\0\0\0\0\0\0\0\0\4\0\0"..., 1817) = 1816
read(3, "", 1)                          = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4", {st_mode=S_IFDIR|0775, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/copyreg.py", {st_mode=S_IFREG|0644, st_size=7614, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/copyreg.py", {st_mode=S_IFREG|0644, st_size=7614, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/__pycache__/copyreg.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=7414, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a5cd0)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=7414, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0)!\236h\276\35\0\0\343\0\0\0\0\0\0\0\0\0\0\0\0\6\0\0"..., 7415) = 7414
read(3, "", 1)                          = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4", {st_mode=S_IFDIR|0775, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/signal.py", {st_mode=S_IFREG|0644, st_size=2495, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/signal.py", {st_mode=S_IFREG|0644, st_size=2495, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/__pycache__/signal.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=4448, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a69b0)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=4448, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0)!\236h\277\t\0\0\343\0\0\0\0\0\0\0\0\0\0\0\0\5\0\0"..., 4449) = 4448
read(3, "", 1)                          = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4", {st_mode=S_IFDIR|0775, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/threading.py", {st_mode=S_IFREG|0644, st_size=60123, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/threading.py", {st_mode=S_IFREG|0644, st_size=60123, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/__pycache__/threading.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=65346, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a69b0)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=65346, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0)!\236h\333\352\0\0\343\0\0\0\0\0\0\0\0\0\0\0\0\5\0\0"..., 65347) = 65346
read(3, "", 1)                          = 0
close(3)                                = 0
mmap(NULL, 1048576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7bab9a400000
newfstatat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4", {st_mode=S_IFDIR|0775, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/_weakrefset.py", {st_mode=S_IFREG|0644, st_size=5893, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/_weakrefset.py", {st_mode=S_IFREG|0644, st_size=5893, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/__pycache__/_weakrefset.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=11751, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a6340)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=11751, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0)!\236h\5\27\0\0\343\0\0\0\0\0\0\0\0\0\0\0\0\4\0\0"..., 11752) = 11751
read(3, "", 1)                          = 0
close(3)                                = 0
gettid()                                = 25902
newfstatat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4", {st_mode=S_IFDIR|0775, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/warnings.py", {st_mode=S_IFREG|0644, st_size=21760, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/warnings.py", {st_mode=S_IFREG|0644, st_size=21760, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/__pycache__/warnings.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=23792, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a69b0)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=23792, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0)!\236h\0U\0\0\343\0\0\0\0\0\0\0\0\0\0\0\0\6\0\0"..., 23793) = 23792
read(3, "", 1)                          = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4", {st_mode=S_IFDIR|0775, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/contextlib.py", {st_mode=S_IFREG|0644, st_size=27637, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/contextlib.py", {st_mode=S_IFREG|0644, st_size=27637, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/__pycache__/contextlib.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=30376, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a69b0)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=30376, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0)!\236h\365k\0\0\343\0\0\0\0\0\0\0\0\0\0\0\0\7\0\0"..., 30377) = 30376
read(3, "", 1)                          = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4", {st_mode=S_IFDIR|0775, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/lib-dynload", {st_mode=S_IFDIR|0755, st_size=16384, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/local/lib/python3.12/dist-packages", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3/dist-packages", {st_mode=S_IFDIR|0755, st_size=12288, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/dist-packages", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/home/denis/repos/repos-git/CS644/week4", {st_mode=S_IFDIR|0775, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12", {st_mode=S_IFDIR|0755, st_size=20480, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/selectors.py", {st_mode=S_IFREG|0644, st_size=19671, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/selectors.py", {st_mode=S_IFREG|0644, st_size=19671, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/__pycache__/selectors.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=26128, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a69b0)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=26128, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0)!\236h\327L\0\0\343\0\0\0\0\0\0\0\0\0\0\0\0\5\0\0"..., 26129) = 26128
read(3, "", 1)                          = 0
close(3)                                = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/collections", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/collections", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/collections", {st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/collections", O_RDONLY|O_NONBLOCK|O_CLOEXEC|O_DIRECTORY) = 3
fstat(3, {st_mode=S_IFDIR|0755, st_size=4096, ...}) = 0
brk(0xa3d2000)                          = 0xa3d2000
getdents64(3, 0xa3a9d40 /* 5 entries */, 32768) = 144
getdents64(3, 0xa3a9d40 /* 0 entries */, 32768) = 0
brk(0xa3ca000)                          = 0xa3ca000
close(3)                                = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/collections/abc.py", {st_mode=S_IFREG|0644, st_size=119, ...}, 0) = 0
newfstatat(AT_FDCWD, "/usr/lib/python3.12/collections/abc.py", {st_mode=S_IFREG|0644, st_size=119, ...}, 0) = 0
openat(AT_FDCWD, "/usr/lib/python3.12/collections/__pycache__/abc.cpython-312.pyc", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=249, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a6340)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = 0
lseek(3, 0, SEEK_CUR)                   = 0
fstat(3, {st_mode=S_IFREG|0644, st_size=249, ...}) = 0
read(3, "\313\r\r\n\0\0\0\0)!\236hw\0\0\0\343\0\0\0\0\0\0\0\0\0\0\0\0\2\0\0"..., 250) = 249
read(3, "", 1)                          = 0
close(3)                                = 0
epoll_create1(EPOLL_CLOEXEC)            = 3
close(3)                                = 0
pipe2([3, 4], O_CLOEXEC)                = 0
fstat(3, {st_mode=S_IFIFO|0600, st_size=0, ...}) = 0
ioctl(3, TCGETS, 0x7ffe297a7230)        = -1 ENOTTY (Inappropriate ioctl for device)
lseek(3, 0, SEEK_CUR)                   = -1 ESPIPE (Illegal seek)
pipe2([5, 6], O_CLOEXEC)                = 0
rt_sigprocmask(SIG_BLOCK, ~[RTMIN RT_1], [], 8) = 0
vfork(strace: Process 25903 attached
 <unfinished ...>
[pid 25903] close(3)                    = 0
[pid 25903] close(5)                    = 0
[pid 25903] dup2(4, 1)                  = 1
[pid 25903] rt_sigaction(SIGPIPE, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=SA_RESTORER|SA_ONSTACK, sa_restorer=0x7bab9ac45330}, {sa_handler=SIG_IGN, sa_mask=[], sa_flags=SA_RESTORER|SA_ONSTACK, sa_restorer=0x7bab9ac45330}, 8) = 0
[pid 25903] rt_sigaction(SIGXFSZ, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=SA_RESTORER|SA_ONSTACK, sa_restorer=0x7bab9ac45330}, {sa_handler=SIG_IGN, sa_mask=[], sa_flags=SA_RESTORER|SA_ONSTACK, sa_restorer=0x7bab9ac45330}, 8) = 0
[pid 25903] rt_sigaction(SIGHUP, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGINT, NULL, {sa_handler=0x6e6b20, sa_mask=[], sa_flags=SA_RESTORER|SA_ONSTACK, sa_restorer=0x7bab9ac45330}, 8) = 0
[pid 25903] rt_sigaction(SIGINT, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=SA_RESTORER, sa_restorer=0x7bab9ac45330}, NULL, 8) = 0
[pid 25903] rt_sigaction(SIGQUIT, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGILL, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGTRAP, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGABRT, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGBUS, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGFPE, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGUSR1, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGSEGV, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGUSR2, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGPIPE, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=SA_RESTORER|SA_ONSTACK, sa_restorer=0x7bab9ac45330}, 8) = 0
[pid 25903] rt_sigaction(SIGALRM, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGTERM, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGSTKFLT, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGCHLD, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGCONT, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGTSTP, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGTTIN, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGTTOU, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGURG, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGXCPU, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGXFSZ, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=SA_RESTORER|SA_ONSTACK, sa_restorer=0x7bab9ac45330}, 8) = 0
[pid 25903] rt_sigaction(SIGVTALRM, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGPROF, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGWINCH, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGIO, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGPWR, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGSYS, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_2, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_3, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_4, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_5, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_6, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_7, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_8, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_9, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_10, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_11, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_12, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_13, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_14, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_15, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_16, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_17, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_18, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_19, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_20, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_21, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_22, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_23, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_24, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_25, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_26, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_27, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_28, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_29, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_30, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_31, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigaction(SIGRT_32, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rt_sigprocmask(SIG_SETMASK, [], NULL, 8) = 0
[pid 25903] close_range(3, 5, 0)        = 0
[pid 25903] close_range(7, 2147483647, 0) = 0
[pid 25903] execve("/home/denis/.sdkman/candidates/java/current/bin/ls", ["ls", "-l"], 0x7ffe297a7dd0 /* 51 vars */) = -1 ENOENT (No such file or directory)
[pid 25903] execve("/home/denis/.cargo/bin/ls", ["ls", "-l"], 0x7ffe297a7dd0 /* 51 vars */) = -1 ENOENT (No such file or directory)
[pid 25903] execve("/home/denis/.local/bin/ls", ["ls", "-l"], 0x7ffe297a7dd0 /* 51 vars */) = -1 ENOENT (No such file or directory)
[pid 25903] execve("/usr/local/sbin/ls", ["ls", "-l"], 0x7ffe297a7dd0 /* 51 vars */) = -1 ENOENT (No such file or directory)
[pid 25903] execve("/usr/local/bin/ls", ["ls", "-l"], 0x7ffe297a7dd0 /* 51 vars */) = -1 ENOENT (No such file or directory)
[pid 25903] execve("/usr/sbin/ls", ["ls", "-l"], 0x7ffe297a7dd0 /* 51 vars */) = -1 ENOENT (No such file or directory)
[pid 25903] execve("/usr/bin/ls", ["ls", "-l"], 0x7ffe297a7dd0 /* 51 vars */ <unfinished ...>
[pid 25902] <... vfork resumed>)        = 25903
[pid 25902] rt_sigprocmask(SIG_SETMASK, [], NULL, 8) = 0
[pid 25902] close(6)                    = 0
[pid 25903] <... execve resumed>)       = 0
[pid 25902] close(4 <unfinished ...>
[pid 25903] brk(NULL <unfinished ...>
[pid 25902] <... close resumed>)        = 0
[pid 25903] <... brk resumed>)          = 0x64844b05c000
[pid 25902] read(5,  <unfinished ...>
[pid 25903] mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0 <unfinished ...>
[pid 25902] <... read resumed>"", 50000) = 0
[pid 25903] <... mmap resumed>)         = 0x74e7e89ec000
[pid 25902] close(5 <unfinished ...>
[pid 25903] access("/etc/ld.so.preload", R_OK <unfinished ...>
[pid 25902] <... close resumed>)        = 0
[pid 25903] <... access resumed>)       = -1 ENOENT (No such file or directory)
[pid 25902] pipe2( <unfinished ...>
[pid 25903] openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC <unfinished ...>
[pid 25902] <... pipe2 resumed>[4, 5], O_CLOEXEC) = 0
[pid 25903] <... openat resumed>)       = 3
[pid 25902] fstat(4,  <unfinished ...>
[pid 25903] fstat(3,  <unfinished ...>
[pid 25902] <... fstat resumed>{st_mode=S_IFIFO|0600, st_size=0, ...}) = 0
[pid 25903] <... fstat resumed>{st_mode=S_IFREG|0644, st_size=76499, ...}) = 0
[pid 25902] ioctl(4, TCGETS <unfinished ...>
[pid 25903] mmap(NULL, 76499, PROT_READ, MAP_PRIVATE, 3, 0 <unfinished ...>
[pid 25902] <... ioctl resumed>, 0x7ffe297a7290) = -1 ENOTTY (Inappropriate ioctl for device)
[pid 25903] <... mmap resumed>)         = 0x74e7e89d9000
[pid 25902] lseek(4, 0, SEEK_CUR <unfinished ...>
[pid 25903] close(3 <unfinished ...>
[pid 25902] <... lseek resumed>)        = -1 ESPIPE (Illegal seek)
[pid 25903] <... close resumed>)        = 0
[pid 25902] pipe2( <unfinished ...>
[pid 25903] openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libselinux.so.1", O_RDONLY|O_CLOEXEC <unfinished ...>
[pid 25902] <... pipe2 resumed>[6, 7], O_CLOEXEC) = 0
[pid 25903] <... openat resumed>)       = 3
[pid 25902] rt_sigprocmask(SIG_BLOCK, ~[RTMIN RT_1],  <unfinished ...>
[pid 25903] read(3,  <unfinished ...>
[pid 25902] <... rt_sigprocmask resumed>[], 8) = 0
[pid 25903] <... read resumed>"\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
[pid 25902] vfork( <unfinished ...>
[pid 25903] fstat(3, strace: Process 25904 attached
{st_mode=S_IFREG|0644, st_size=174472, ...}) = 0
[pid 25904] close(4 <unfinished ...>
[pid 25903] mmap(NULL, 181960, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0 <unfinished ...>
[pid 25904] <... close resumed>)        = 0
[pid 25903] <... mmap resumed>)         = 0x74e7e89ac000
[pid 25904] close(6 <unfinished ...>
[pid 25903] mmap(0x74e7e89b2000, 118784, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x6000 <unfinished ...>
[pid 25904] <... close resumed>)        = 0
[pid 25903] <... mmap resumed>)         = 0x74e7e89b2000
[pid 25904] dup2(3, 0 <unfinished ...>
[pid 25903] mmap(0x74e7e89cf000, 24576, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x23000 <unfinished ...>
[pid 25904] <... dup2 resumed>)         = 0
[pid 25903] <... mmap resumed>)         = 0x74e7e89cf000
[pid 25904] dup2(5, 1 <unfinished ...>
[pid 25903] mmap(0x74e7e89d5000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x29000 <unfinished ...>
[pid 25904] <... dup2 resumed>)         = 1
[pid 25903] <... mmap resumed>)         = 0x74e7e89d5000
[pid 25904] rt_sigaction(SIGPIPE, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=SA_RESTORER|SA_ONSTACK, sa_restorer=0x7bab9ac45330},  <unfinished ...>
[pid 25903] mmap(0x74e7e89d7000, 5832, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0 <unfinished ...>
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_IGN, sa_mask=[], sa_flags=SA_RESTORER|SA_ONSTACK, sa_restorer=0x7bab9ac45330}, 8) = 0
[pid 25903] <... mmap resumed>)         = 0x74e7e89d7000
[pid 25904] rt_sigaction(SIGXFSZ, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=SA_RESTORER|SA_ONSTACK, sa_restorer=0x7bab9ac45330}, {sa_handler=SIG_IGN, sa_mask=[], sa_flags=SA_RESTORER|SA_ONSTACK, sa_restorer=0x7bab9ac45330}, 8) = 0
[pid 25903] close(3 <unfinished ...>
[pid 25904] rt_sigaction(SIGHUP, NULL,  <unfinished ...>
[pid 25903] <... close resumed>)        = 0
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC <unfinished ...>
[pid 25904] rt_sigaction(SIGINT, NULL,  <unfinished ...>
[pid 25903] <... openat resumed>)       = 3
[pid 25904] <... rt_sigaction resumed>{sa_handler=0x6e6b20, sa_mask=[], sa_flags=SA_RESTORER|SA_ONSTACK, sa_restorer=0x7bab9ac45330}, 8) = 0
[pid 25903] read(3,  <unfinished ...>
[pid 25904] rt_sigaction(SIGINT, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=SA_RESTORER, sa_restorer=0x7bab9ac45330},  <unfinished ...>
[pid 25903] <... read resumed>"\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\220\243\2\0\0\0\0\0"..., 832) = 832
[pid 25904] <... rt_sigaction resumed>NULL, 8) = 0
[pid 25903] pread64(3,  <unfinished ...>
[pid 25904] rt_sigaction(SIGQUIT, NULL,  <unfinished ...>
[pid 25903] <... pread64 resumed>"\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] fstat(3,  <unfinished ...>
[pid 25904] rt_sigaction(SIGILL, NULL,  <unfinished ...>
[pid 25903] <... fstat resumed>{st_mode=S_IFREG|0755, st_size=2125328, ...}) = 0
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] pread64(3,  <unfinished ...>
[pid 25904] rt_sigaction(SIGTRAP, NULL,  <unfinished ...>
[pid 25903] <... pread64 resumed>"\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] mmap(NULL, 2170256, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0 <unfinished ...>
[pid 25904] rt_sigaction(SIGABRT, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] <... mmap resumed>)         = 0x74e7e8600000
[pid 25904] rt_sigaction(SIGBUS, NULL,  <unfinished ...>
[pid 25903] mmap(0x74e7e8628000, 1605632, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000 <unfinished ...>
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] <... mmap resumed>)         = 0x74e7e8628000
[pid 25904] rt_sigaction(SIGFPE, NULL,  <unfinished ...>
[pid 25903] mmap(0x74e7e87b0000, 323584, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1b0000 <unfinished ...>
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] <... mmap resumed>)         = 0x74e7e87b0000
[pid 25904] rt_sigaction(SIGUSR1, NULL,  <unfinished ...>
[pid 25903] mmap(0x74e7e87ff000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1fe000 <unfinished ...>
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] <... mmap resumed>)         = 0x74e7e87ff000
[pid 25904] rt_sigaction(SIGSEGV, NULL,  <unfinished ...>
[pid 25903] mmap(0x74e7e8805000, 52624, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0 <unfinished ...>
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] <... mmap resumed>)         = 0x74e7e8805000
[pid 25904] rt_sigaction(SIGUSR2, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] close(3 <unfinished ...>
[pid 25904] rt_sigaction(SIGPIPE, NULL,  <unfinished ...>
[pid 25903] <... close resumed>)        = 0
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=SA_RESTORER|SA_ONSTACK, sa_restorer=0x7bab9ac45330}, 8) = 0
[pid 25903] openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libpcre2-8.so.0", O_RDONLY|O_CLOEXEC <unfinished ...>
[pid 25904] rt_sigaction(SIGALRM, NULL,  <unfinished ...>
[pid 25903] <... openat resumed>)       = 3
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] read(3,  <unfinished ...>
[pid 25904] rt_sigaction(SIGTERM, NULL,  <unfinished ...>
[pid 25903] <... read resumed>"\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] fstat(3,  <unfinished ...>
[pid 25904] rt_sigaction(SIGSTKFLT, NULL,  <unfinished ...>
[pid 25903] <... fstat resumed>{st_mode=S_IFREG|0644, st_size=625344, ...}) = 0
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] mmap(NULL, 627472, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0 <unfinished ...>
[pid 25904] rt_sigaction(SIGCHLD, NULL,  <unfinished ...>
[pid 25903] <... mmap resumed>)         = 0x74e7e8912000
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] mmap(0x74e7e8914000, 450560, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x2000 <unfinished ...>
[pid 25904] rt_sigaction(SIGCONT, NULL,  <unfinished ...>
[pid 25903] <... mmap resumed>)         = 0x74e7e8914000
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] mmap(0x74e7e8982000, 163840, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x70000 <unfinished ...>
[pid 25904] rt_sigaction(SIGTSTP, NULL,  <unfinished ...>
[pid 25903] <... mmap resumed>)         = 0x74e7e8982000
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] mmap(0x74e7e89aa000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x97000 <unfinished ...>
[pid 25904] rt_sigaction(SIGTTIN, NULL,  <unfinished ...>
[pid 25903] <... mmap resumed>)         = 0x74e7e89aa000
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] close(3 <unfinished ...>
[pid 25904] rt_sigaction(SIGTTOU, NULL,  <unfinished ...>
[pid 25903] <... close resumed>)        = 0
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0 <unfinished ...>
[pid 25904] rt_sigaction(SIGURG, NULL,  <unfinished ...>
[pid 25903] <... mmap resumed>)         = 0x74e7e890f000
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] arch_prctl(ARCH_SET_FS, 0x74e7e890f800 <unfinished ...>
[pid 25904] rt_sigaction(SIGXCPU, NULL,  <unfinished ...>
[pid 25903] <... arch_prctl resumed>)   = 0
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] set_tid_address(0x74e7e890fad0 <unfinished ...>
[pid 25904] rt_sigaction(SIGXFSZ, NULL,  <unfinished ...>
[pid 25903] <... set_tid_address resumed>) = 25903
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=SA_RESTORER|SA_ONSTACK, sa_restorer=0x7bab9ac45330}, 8) = 0
[pid 25903] set_robust_list(0x74e7e890fae0, 24 <unfinished ...>
[pid 25904] rt_sigaction(SIGVTALRM, NULL,  <unfinished ...>
[pid 25903] <... set_robust_list resumed>) = 0
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] rseq(0x74e7e8910120, 0x20, 0, 0x53053053 <unfinished ...>
[pid 25904] rt_sigaction(SIGPROF, NULL,  <unfinished ...>
[pid 25903] <... rseq resumed>)         = 0
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] mprotect(0x74e7e87ff000, 16384, PROT_READ <unfinished ...>
[pid 25904] rt_sigaction(SIGWINCH, NULL,  <unfinished ...>
[pid 25903] <... mprotect resumed>)     = 0
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] mprotect(0x74e7e89aa000, 4096, PROT_READ <unfinished ...>
[pid 25904] rt_sigaction(SIGIO, NULL,  <unfinished ...>
[pid 25903] <... mprotect resumed>)     = 0
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25904] rt_sigaction(SIGPWR, NULL,  <unfinished ...>
[pid 25903] mprotect(0x74e7e89d5000, 4096, PROT_READ <unfinished ...>
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] <... mprotect resumed>)     = 0
[pid 25904] rt_sigaction(SIGSYS, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25904] rt_sigaction(SIGRT_2, NULL,  <unfinished ...>
[pid 25903] mprotect(0x6484455af000, 8192, PROT_READ <unfinished ...>
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] <... mprotect resumed>)     = 0
[pid 25904] rt_sigaction(SIGRT_3, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25904] rt_sigaction(SIGRT_4, NULL,  <unfinished ...>
[pid 25903] mprotect(0x74e7e8a24000, 8192, PROT_READ <unfinished ...>
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25904] rt_sigaction(SIGRT_5, NULL,  <unfinished ...>
[pid 25903] <... mprotect resumed>)     = 0
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25904] rt_sigaction(SIGRT_6, NULL,  <unfinished ...>
[pid 25903] prlimit64(0, RLIMIT_STACK, NULL,  <unfinished ...>
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] <... prlimit64 resumed>{rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
[pid 25904] rt_sigaction(SIGRT_7, NULL,  <unfinished ...>
[pid 25903] munmap(0x74e7e89d9000, 76499 <unfinished ...>
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] <... munmap resumed>)       = 0
[pid 25904] rt_sigaction(SIGRT_8, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] statfs("/sys/fs/selinux",  <unfinished ...>
[pid 25904] rt_sigaction(SIGRT_9, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25904] rt_sigaction(SIGRT_10, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] <... statfs resumed>0x7ffdb0d812d0) = -1 ENOENT (No such file or directory)
[pid 25904] rt_sigaction(SIGRT_11, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25904] rt_sigaction(SIGRT_12, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25904] rt_sigaction(SIGRT_13, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] statfs("/selinux",  <unfinished ...>
[pid 25904] rt_sigaction(SIGRT_14, NULL,  <unfinished ...>
[pid 25903] <... statfs resumed>0x7ffdb0d812d0) = -1 ENOENT (No such file or directory)
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] getrandom( <unfinished ...>
[pid 25904] rt_sigaction(SIGRT_15, NULL,  <unfinished ...>
[pid 25903] <... getrandom resumed>"\xb3\x1a\x22\xd3\x43\x22\xf1\xa0", 8, GRND_NONBLOCK) = 8
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] brk(NULL <unfinished ...>
[pid 25904] rt_sigaction(SIGRT_16, NULL,  <unfinished ...>
[pid 25903] <... brk resumed>)          = 0x64844b05c000
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] brk(0x64844b07d000 <unfinished ...>
[pid 25904] rt_sigaction(SIGRT_17, NULL,  <unfinished ...>
[pid 25903] <... brk resumed>)          = 0x64844b07d000
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] openat(AT_FDCWD, "/proc/filesystems", O_RDONLY|O_CLOEXEC <unfinished ...>
[pid 25904] rt_sigaction(SIGRT_18, NULL,  <unfinished ...>
[pid 25903] <... openat resumed>)       = 3
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] fstat(3,  <unfinished ...>
[pid 25904] rt_sigaction(SIGRT_19, NULL,  <unfinished ...>
[pid 25903] <... fstat resumed>{st_mode=S_IFREG|0444, st_size=0, ...}) = 0
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] read(3,  <unfinished ...>
[pid 25904] rt_sigaction(SIGRT_20, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] <... read resumed>"nodev\tsysfs\nnodev\ttmpfs\nnodev\tbd"..., 1024) = 400
[pid 25904] rt_sigaction(SIGRT_21, NULL,  <unfinished ...>
[pid 25903] read(3,  <unfinished ...>
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] <... read resumed>"", 1024) = 0
[pid 25904] rt_sigaction(SIGRT_22, NULL,  <unfinished ...>
[pid 25903] close(3 <unfinished ...>
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] <... close resumed>)        = 0
[pid 25904] rt_sigaction(SIGRT_23, NULL,  <unfinished ...>
[pid 25903] access("/etc/selinux/config", F_OK <unfinished ...>
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] <... access resumed>)       = -1 ENOENT (No such file or directory)
[pid 25904] rt_sigaction(SIGRT_24, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] openat(AT_FDCWD, "/usr/lib/locale/locale-archive", O_RDONLY|O_CLOEXEC <unfinished ...>
[pid 25904] rt_sigaction(SIGRT_25, NULL,  <unfinished ...>
[pid 25903] <... openat resumed>)       = 3
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] fstat(3,  <unfinished ...>
[pid 25904] rt_sigaction(SIGRT_26, NULL,  <unfinished ...>
[pid 25903] <... fstat resumed>{st_mode=S_IFREG|0644, st_size=5719296, ...}) = 0
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] mmap(NULL, 5719296, PROT_READ, MAP_PRIVATE, 3, 0 <unfinished ...>
[pid 25904] rt_sigaction(SIGRT_27, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] <... mmap resumed>)         = 0x74e7e8000000
[pid 25904] rt_sigaction(SIGRT_28, NULL, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] close(3 <unfinished ...>
[pid 25904] rt_sigaction(SIGRT_29, NULL,  <unfinished ...>
[pid 25903] <... close resumed>)        = 0
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] ioctl(1, TCGETS <unfinished ...>
[pid 25904] rt_sigaction(SIGRT_30, NULL,  <unfinished ...>
[pid 25903] <... ioctl resumed>, 0x7ffdb0d81170) = -1 ENOTTY (Inappropriate ioctl for device)
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] openat(AT_FDCWD, "/usr/share/locale/locale.alias", O_RDONLY|O_CLOEXEC <unfinished ...>
[pid 25904] rt_sigaction(SIGRT_31, NULL,  <unfinished ...>
[pid 25903] <... openat resumed>)       = 3
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] fstat(3,  <unfinished ...>
[pid 25904] rt_sigaction(SIGRT_32, NULL,  <unfinished ...>
[pid 25903] <... fstat resumed>{st_mode=S_IFREG|0644, st_size=2996, ...}) = 0
[pid 25904] <... rt_sigaction resumed>{sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
[pid 25903] read(3,  <unfinished ...>
[pid 25904] rt_sigprocmask(SIG_SETMASK, [],  <unfinished ...>
[pid 25903] <... read resumed>"# Locale name alias data base.\n#"..., 4096) = 2996
[pid 25904] <... rt_sigprocmask resumed>NULL, 8) = 0
[pid 25903] read(3,  <unfinished ...>
[pid 25904] close_range(3, 6, 0 <unfinished ...>
[pid 25903] <... read resumed>"", 4096) = 0
[pid 25904] <... close_range resumed>)  = 0
[pid 25903] close(3 <unfinished ...>
[pid 25904] close_range(8, 2147483647, 0 <unfinished ...>
[pid 25903] <... close resumed>)        = 0
[pid 25904] <... close_range resumed>)  = 0
[pid 25903] openat(AT_FDCWD, "/usr/share/locale/en_US/LC_TIME/coreutils.mo", O_RDONLY <unfinished ...>
[pid 25904] execve("/home/denis/.sdkman/candidates/java/current/bin/grep", ["grep", "md"], 0x7ffe297a7dd0 /* 51 vars */ <unfinished ...>
[pid 25903] <... openat resumed>)       = -1 ENOENT (No such file or directory)
[pid 25904] <... execve resumed>)       = -1 ENOENT (No such file or directory)
[pid 25903] openat(AT_FDCWD, "/usr/share/locale/en/LC_TIME/coreutils.mo", O_RDONLY <unfinished ...>
[pid 25904] execve("/home/denis/.cargo/bin/grep", ["grep", "md"], 0x7ffe297a7dd0 /* 51 vars */ <unfinished ...>
[pid 25903] <... openat resumed>)       = -1 ENOENT (No such file or directory)
[pid 25904] <... execve resumed>)       = -1 ENOENT (No such file or directory)
[pid 25903] openat(AT_FDCWD, "/usr/lib/x86_64-linux-gnu/gconv/gconv-modules.cache", O_RDONLY|O_CLOEXEC <unfinished ...>
[pid 25904] execve("/home/denis/.local/bin/grep", ["grep", "md"], 0x7ffe297a7dd0 /* 51 vars */ <unfinished ...>
[pid 25903] <... openat resumed>)       = 3
[pid 25904] <... execve resumed>)       = -1 ENOENT (No such file or directory)
[pid 25903] fstat(3,  <unfinished ...>
[pid 25904] execve("/usr/local/sbin/grep", ["grep", "md"], 0x7ffe297a7dd0 /* 51 vars */ <unfinished ...>
[pid 25903] <... fstat resumed>{st_mode=S_IFREG|0644, st_size=27028, ...}) = 0
[pid 25904] <... execve resumed>)       = -1 ENOENT (No such file or directory)
[pid 25903] mmap(NULL, 27028, PROT_READ, MAP_SHARED, 3, 0 <unfinished ...>
[pid 25904] execve("/usr/local/bin/grep", ["grep", "md"], 0x7ffe297a7dd0 /* 51 vars */ <unfinished ...>
[pid 25903] <... mmap resumed>)         = 0x74e7e89e5000
[pid 25904] <... execve resumed>)       = -1 ENOENT (No such file or directory)
[pid 25903] close(3 <unfinished ...>
[pid 25904] execve("/usr/sbin/grep", ["grep", "md"], 0x7ffe297a7dd0 /* 51 vars */ <unfinished ...>
[pid 25903] <... close resumed>)        = 0
[pid 25904] <... execve resumed>)       = -1 ENOENT (No such file or directory)
[pid 25903] futex(0x74e7e880472c, FUTEX_WAKE_PRIVATE, 2147483647 <unfinished ...>
[pid 25904] execve("/usr/bin/grep", ["grep", "md"], 0x7ffe297a7dd0 /* 51 vars */ <unfinished ...>
[pid 25903] <... futex resumed>)        = 0
[pid 25903] openat(AT_FDCWD, ".", O_RDONLY|O_NONBLOCK|O_CLOEXEC|O_DIRECTORY <unfinished ...>
[pid 25902] <... vfork resumed>)        = 25904
[pid 25903] <... openat resumed>)       = 3
[pid 25902] rt_sigprocmask(SIG_SETMASK, [],  <unfinished ...>
[pid 25904] <... execve resumed>)       = 0
[pid 25902] <... rt_sigprocmask resumed>NULL, 8) = 0
[pid 25903] fstat(3,  <unfinished ...>
[pid 25902] close(7 <unfinished ...>
[pid 25904] brk(NULL <unfinished ...>
[pid 25902] <... close resumed>)        = 0
[pid 25903] <... fstat resumed>{st_mode=S_IFDIR|0775, st_size=4096, ...}) = 0
[pid 25904] <... brk resumed>)          = 0x6281e8ac9000
[pid 25903] getdents64(3,  <unfinished ...>
[pid 25902] close(5)                    = 0
[pid 25904] mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0 <unfinished ...>
[pid 25902] read(6,  <unfinished ...>
[pid 25903] <... getdents64 resumed>0x64844b064ab0 /* 5 entries */, 32768) = 144
[pid 25902] <... read resumed>"", 50000) = 0
[pid 25904] <... mmap resumed>)         = 0x7567fb3bc000
[pid 25902] close(6 <unfinished ...>
[pid 25903] statx(AT_FDCWD, "README.md", AT_STATX_SYNC_AS_STAT|AT_SYMLINK_NOFOLLOW|AT_NO_AUTOMOUNT, STATX_MODE|STATX_NLINK|STATX_UID|STATX_GID|STATX_MTIME|STATX_SIZE,  <unfinished ...>
[pid 25902] <... close resumed>)        = 0
[pid 25904] access("/etc/ld.so.preload", R_OK <unfinished ...>
[pid 25903] <... statx resumed>{stx_mask=STATX_BASIC_STATS|STATX_MNT_ID, stx_attributes=0, stx_mode=S_IFREG|0664, stx_size=68, ...}) = 0
[pid 25902] lseek(4, 0, SEEK_CUR <unfinished ...>
[pid 25904] <... access resumed>)       = -1 ENOENT (No such file or directory)
[pid 25902] <... lseek resumed>)        = -1 ESPIPE (Illegal seek)
[pid 25903] lgetxattr("README.md", "security.selinux",  <unfinished ...>
[pid 25902] fstat(4,  <unfinished ...>
[pid 25904] openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC <unfinished ...>
[pid 25902] <... fstat resumed>{st_mode=S_IFIFO|0600, st_size=0, ...}) = 0
[pid 25903] <... lgetxattr resumed>0x64844b05dea0, 255) = -1 ENODATA (No data available)
[pid 25902] read(4,  <unfinished ...>
[pid 25904] <... openat resumed>)       = 3
[pid 25903] listxattr("README.md",  <unfinished ...>
[pid 25904] fstat(3,  <unfinished ...>
[pid 25903] <... listxattr resumed>"", 152) = 0
[pid 25904] <... fstat resumed>{st_mode=S_IFREG|0644, st_size=76499, ...}) = 0
[pid 25903] socket(AF_UNIX, SOCK_STREAM|SOCK_CLOEXEC|SOCK_NONBLOCK, 0 <unfinished ...>
[pid 25904] mmap(NULL, 76499, PROT_READ, MAP_PRIVATE, 3, 0 <unfinished ...>
[pid 25903] <... socket resumed>)       = 4
[pid 25904] <... mmap resumed>)         = 0x7567fb3a9000
[pid 25903] connect(4, {sa_family=AF_UNIX, sun_path="/var/run/nscd/socket"}, 110 <unfinished ...>
[pid 25904] close(3 <unfinished ...>
[pid 25903] <... connect resumed>)      = -1 ENOENT (No such file or directory)
[pid 25904] <... close resumed>)        = 0
[pid 25903] close(4 <unfinished ...>
[pid 25904] openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libpcre2-8.so.0", O_RDONLY|O_CLOEXEC <unfinished ...>
[pid 25903] <... close resumed>)        = 0
[pid 25904] <... openat resumed>)       = 3
[pid 25903] socket(AF_UNIX, SOCK_STREAM|SOCK_CLOEXEC|SOCK_NONBLOCK, 0 <unfinished ...>
[pid 25904] read(3,  <unfinished ...>
[pid 25903] <... socket resumed>)       = 4
[pid 25904] <... read resumed>"\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
[pid 25903] connect(4, {sa_family=AF_UNIX, sun_path="/var/run/nscd/socket"}, 110 <unfinished ...>
[pid 25904] fstat(3,  <unfinished ...>
[pid 25903] <... connect resumed>)      = -1 ENOENT (No such file or directory)
[pid 25904] <... fstat resumed>{st_mode=S_IFREG|0644, st_size=625344, ...}) = 0
[pid 25903] close(4 <unfinished ...>
[pid 25904] mmap(NULL, 627472, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0 <unfinished ...>
[pid 25903] <... close resumed>)        = 0
[pid 25904] <... mmap resumed>)         = 0x7567fb30f000
[pid 25903] newfstatat(AT_FDCWD, "/etc/nsswitch.conf",  <unfinished ...>
[pid 25904] mmap(0x7567fb311000, 450560, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x2000 <unfinished ...>
[pid 25903] <... newfstatat resumed>{st_mode=S_IFREG|0644, st_size=569, ...}, 0) = 0
[pid 25904] <... mmap resumed>)         = 0x7567fb311000
[pid 25903] newfstatat(AT_FDCWD, "/",  <unfinished ...>
[pid 25904] mmap(0x7567fb37f000, 163840, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x70000 <unfinished ...>
[pid 25903] <... newfstatat resumed>{st_mode=S_IFDIR|0755, st_size=4096, ...}, 0) = 0
[pid 25904] <... mmap resumed>)         = 0x7567fb37f000
[pid 25903] openat(AT_FDCWD, "/etc/nsswitch.conf", O_RDONLY|O_CLOEXEC <unfinished ...>
[pid 25904] mmap(0x7567fb3a7000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x97000 <unfinished ...>
[pid 25903] <... openat resumed>)       = 4
[pid 25904] <... mmap resumed>)         = 0x7567fb3a7000
[pid 25903] fstat(4, {st_mode=S_IFREG|0644, st_size=569, ...}) = 0
[pid 25904] close(3 <unfinished ...>
[pid 25903] read(4,  <unfinished ...>
[pid 25904] <... close resumed>)        = 0
[pid 25903] <... read resumed>"# /etc/nsswitch.conf\n#\n# Example"..., 4096) = 569
[pid 25904] openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC <unfinished ...>
[pid 25903] read(4,  <unfinished ...>
[pid 25904] <... openat resumed>)       = 3
[pid 25903] <... read resumed>"", 4096) = 0
[pid 25904] read(3,  <unfinished ...>
[pid 25903] fstat(4,  <unfinished ...>
[pid 25904] <... read resumed>"\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\220\243\2\0\0\0\0\0"..., 832) = 832
[pid 25903] <... fstat resumed>{st_mode=S_IFREG|0644, st_size=569, ...}) = 0
[pid 25904] pread64(3,  <unfinished ...>
[pid 25903] close(4 <unfinished ...>
[pid 25904] <... pread64 resumed>"\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
[pid 25903] <... close resumed>)        = 0
[pid 25904] fstat(3,  <unfinished ...>
[pid 25903] openat(AT_FDCWD, "/etc/passwd", O_RDONLY|O_CLOEXEC <unfinished ...>
[pid 25904] <... fstat resumed>{st_mode=S_IFREG|0755, st_size=2125328, ...}) = 0
[pid 25903] <... openat resumed>)       = 4
[pid 25904] pread64(3,  <unfinished ...>
[pid 25903] fstat(4,  <unfinished ...>
[pid 25904] <... pread64 resumed>"\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
[pid 25903] <... fstat resumed>{st_mode=S_IFREG|0644, st_size=2848, ...}) = 0
[pid 25904] mmap(NULL, 2170256, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0 <unfinished ...>
[pid 25903] lseek(4, 0, SEEK_SET <unfinished ...>
[pid 25904] <... mmap resumed>)         = 0x7567fb000000
[pid 25903] <... lseek resumed>)        = 0
[pid 25904] mmap(0x7567fb028000, 1605632, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000 <unfinished ...>
[pid 25903] read(4, "root:x:0:0:root:/root:/bin/bash\n"..., 4096) = 2848
[pid 25904] <... mmap resumed>)         = 0x7567fb028000
[pid 25903] close(4 <unfinished ...>
[pid 25904] mmap(0x7567fb1b0000, 323584, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1b0000 <unfinished ...>
[pid 25903] <... close resumed>)        = 0
[pid 25904] <... mmap resumed>)         = 0x7567fb1b0000
[pid 25903] socket(AF_UNIX, SOCK_STREAM|SOCK_CLOEXEC|SOCK_NONBLOCK, 0 <unfinished ...>
[pid 25904] mmap(0x7567fb1ff000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1fe000 <unfinished ...>
[pid 25903] <... socket resumed>)       = 4
[pid 25904] <... mmap resumed>)         = 0x7567fb1ff000
[pid 25903] connect(4, {sa_family=AF_UNIX, sun_path="/var/run/nscd/socket"}, 110 <unfinished ...>
[pid 25904] mmap(0x7567fb205000, 52624, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0 <unfinished ...>
[pid 25903] <... connect resumed>)      = -1 ENOENT (No such file or directory)
[pid 25904] <... mmap resumed>)         = 0x7567fb205000
[pid 25903] close(4 <unfinished ...>
[pid 25904] close(3 <unfinished ...>
[pid 25903] <... close resumed>)        = 0
[pid 25904] <... close resumed>)        = 0
[pid 25903] socket(AF_UNIX, SOCK_STREAM|SOCK_CLOEXEC|SOCK_NONBLOCK, 0 <unfinished ...>
[pid 25904] mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0 <unfinished ...>
[pid 25903] <... socket resumed>)       = 4
[pid 25904] <... mmap resumed>)         = 0x7567fb30c000
[pid 25903] connect(4, {sa_family=AF_UNIX, sun_path="/var/run/nscd/socket"}, 110 <unfinished ...>
[pid 25904] arch_prctl(ARCH_SET_FS, 0x7567fb30c740) = 0
[pid 25904] set_tid_address(0x7567fb30ca10 <unfinished ...>
[pid 25903] <... connect resumed>)      = -1 ENOENT (No such file or directory)
[pid 25904] <... set_tid_address resumed>) = 25904
[pid 25904] set_robust_list(0x7567fb30ca20, 24) = 0
[pid 25904] rseq(0x7567fb30d060, 0x20, 0, 0x53053053 <unfinished ...>
[pid 25903] close(4 <unfinished ...>
[pid 25904] <... rseq resumed>)         = 0
[pid 25903] <... close resumed>)        = 0
[pid 25903] newfstatat(AT_FDCWD, "/etc/nsswitch.conf", {st_mode=S_IFREG|0644, st_size=569, ...}, 0) = 0
[pid 25904] mprotect(0x7567fb1ff000, 16384, PROT_READ <unfinished ...>
[pid 25903] openat(AT_FDCWD, "/etc/group", O_RDONLY|O_CLOEXEC <unfinished ...>
[pid 25904] <... mprotect resumed>)     = 0
[pid 25903] <... openat resumed>)       = 4
[pid 25904] mprotect(0x7567fb3a7000, 4096, PROT_READ <unfinished ...>
[pid 25903] fstat(4,  <unfinished ...>
[pid 25904] <... mprotect resumed>)     = 0
[pid 25903] <... fstat resumed>{st_mode=S_IFREG|0644, st_size=1139, ...}) = 0
[pid 25903] lseek(4, 0, SEEK_SET)       = 0
[pid 25904] mprotect(0x6281acbb5000, 8192, PROT_READ <unfinished ...>
[pid 25903] read(4,  <unfinished ...>
[pid 25904] <... mprotect resumed>)     = 0
[pid 25903] <... read resumed>"root:x:0:\ndaemon:x:1:\nbin:x:2:\ns"..., 4096) = 1139
[pid 25904] mprotect(0x7567fb3f4000, 8192, PROT_READ <unfinished ...>
[pid 25903] close(4 <unfinished ...>
[pid 25904] <... mprotect resumed>)     = 0
[pid 25903] <... close resumed>)        = 0
[pid 25904] prlimit64(0, RLIMIT_STACK, NULL,  <unfinished ...>
[pid 25903] statx(AT_FDCWD, "hw7.py", AT_STATX_SYNC_AS_STAT|AT_SYMLINK_NOFOLLOW|AT_NO_AUTOMOUNT, STATX_MODE|STATX_NLINK|STATX_UID|STATX_GID|STATX_MTIME|STATX_SIZE,  <unfinished ...>
[pid 25904] <... prlimit64 resumed>{rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
[pid 25903] <... statx resumed>{stx_mask=STATX_BASIC_STATS|STATX_MNT_ID, stx_attributes=0, stx_mode=S_IFREG|0664, stx_size=332, ...}) = 0
[pid 25904] munmap(0x7567fb3a9000, 76499 <unfinished ...>
[pid 25903] lgetxattr("hw7.py", "security.selinux",  <unfinished ...>
[pid 25904] <... munmap resumed>)       = 0
[pid 25903] <... lgetxattr resumed>0x64844b06cf30, 255) = -1 ENODATA (No data available)
[pid 25904] getrandom( <unfinished ...>
[pid 25903] listxattr("hw7.py",  <unfinished ...>
[pid 25904] <... getrandom resumed>"\xb7\x76\x8d\x0d\x23\x5a\x40\x52", 8, GRND_NONBLOCK) = 8
[pid 25903] <... listxattr resumed>"", 152) = 0
[pid 25904] brk(NULL <unfinished ...>
[pid 25903] statx(AT_FDCWD, "hw5.md", AT_STATX_SYNC_AS_STAT|AT_SYMLINK_NOFOLLOW|AT_NO_AUTOMOUNT, STATX_MODE|STATX_NLINK|STATX_UID|STATX_GID|STATX_MTIME|STATX_SIZE,  <unfinished ...>
[pid 25904] <... brk resumed>)          = 0x6281e8ac9000
[pid 25903] <... statx resumed>{stx_mask=STATX_BASIC_STATS|STATX_MNT_ID, stx_attributes=0, stx_mode=S_IFREG|0664, stx_size=606, ...}) = 0
[pid 25904] brk(0x6281e8aea000 <unfinished ...>
[pid 25903] lgetxattr("hw5.md", "security.selinux",  <unfinished ...>
[pid 25904] <... brk resumed>)          = 0x6281e8aea000
[pid 25903] <... lgetxattr resumed>0x64844b06d060, 255) = -1 ENODATA (No data available)
[pid 25904] openat(AT_FDCWD, "/usr/lib/locale/locale-archive", O_RDONLY|O_CLOEXEC <unfinished ...>
[pid 25903] listxattr("hw5.md",  <unfinished ...>
[pid 25904] <... openat resumed>)       = 3
[pid 25903] <... listxattr resumed>"", 152) = 0
[pid 25904] fstat(3,  <unfinished ...>
[pid 25903] getdents64(3,  <unfinished ...>
[pid 25904] <... fstat resumed>{st_mode=S_IFREG|0644, st_size=5719296, ...}) = 0
[pid 25903] <... getdents64 resumed>0x64844b064ab0 /* 0 entries */, 32768) = 0
[pid 25904] mmap(NULL, 5719296, PROT_READ, MAP_PRIVATE, 3, 0 <unfinished ...>
[pid 25903] close(3 <unfinished ...>
[pid 25904] <... mmap resumed>)         = 0x7567faa00000
[pid 25903] <... close resumed>)        = 0
[pid 25904] close(3)                    = 0
[pid 25903] openat(AT_FDCWD, "/usr/share/locale/en_US/LC_MESSAGES/coreutils.mo", O_RDONLY <unfinished ...>
[pid 25904] openat(AT_FDCWD, "/usr/lib/x86_64-linux-gnu/gconv/gconv-modules.cache", O_RDONLY|O_CLOEXEC <unfinished ...>
[pid 25903] <... openat resumed>)       = -1 ENOENT (No such file or directory)
[pid 25904] <... openat resumed>)       = 3
[pid 25903] openat(AT_FDCWD, "/usr/share/locale/en/LC_MESSAGES/coreutils.mo", O_RDONLY <unfinished ...>
[pid 25904] fstat(3,  <unfinished ...>
[pid 25903] <... openat resumed>)       = -1 ENOENT (No such file or directory)
[pid 25904] <... fstat resumed>{st_mode=S_IFREG|0644, st_size=27028, ...}) = 0
[pid 25903] openat(AT_FDCWD, "/usr/share/locale-langpack/en_US/LC_MESSAGES/coreutils.mo", O_RDONLY <unfinished ...>
[pid 25904] mmap(NULL, 27028, PROT_READ, MAP_SHARED, 3, 0 <unfinished ...>
[pid 25903] <... openat resumed>)       = -1 ENOENT (No such file or directory)
[pid 25904] <... mmap resumed>)         = 0x7567fb3b5000
[pid 25903] openat(AT_FDCWD, "/usr/share/locale-langpack/en/LC_MESSAGES/coreutils.mo", O_RDONLY <unfinished ...>
[pid 25904] close(3 <unfinished ...>
[pid 25903] <... openat resumed>)       = 3
[pid 25904] <... close resumed>)        = 0
[pid 25903] fstat(3,  <unfinished ...>
[pid 25904] futex(0x7567fb20472c, FUTEX_WAKE_PRIVATE, 2147483647 <unfinished ...>
[pid 25903] <... fstat resumed>{st_mode=S_IFREG|0644, st_size=613, ...}) = 0
[pid 25904] <... futex resumed>)        = 0
[pid 25903] mmap(NULL, 613, PROT_READ, MAP_PRIVATE, 3, 0 <unfinished ...>
[pid 25904] openat(AT_FDCWD, "/usr/share/locale/locale.alias", O_RDONLY|O_CLOEXEC <unfinished ...>
[pid 25903] <... mmap resumed>)         = 0x74e7e89e4000
[pid 25904] <... openat resumed>)       = 3
[pid 25903] close(3 <unfinished ...>
[pid 25904] fstat(3,  <unfinished ...>
[pid 25903] <... close resumed>)        = 0
[pid 25904] <... fstat resumed>{st_mode=S_IFREG|0644, st_size=2996, ...}) = 0
[pid 25903] fstat(1,  <unfinished ...>
[pid 25904] read(3,  <unfinished ...>
[pid 25903] <... fstat resumed>{st_mode=S_IFIFO|0600, st_size=0, ...}) = 0
[pid 25904] <... read resumed>"# Locale name alias data base.\n#"..., 4096) = 2996
[pid 25903] openat(AT_FDCWD, "/etc/localtime", O_RDONLY|O_CLOEXEC <unfinished ...>
[pid 25904] read(3,  <unfinished ...>
[pid 25903] <... openat resumed>)       = 3
[pid 25904] <... read resumed>"", 4096) = 0
[pid 25903] fstat(3,  <unfinished ...>
[pid 25904] close(3 <unfinished ...>
[pid 25903] <... fstat resumed>{st_mode=S_IFREG|0644, st_size=3552, ...}) = 0
[pid 25904] <... close resumed>)        = 0
[pid 25903] fstat(3,  <unfinished ...>
[pid 25904] openat(AT_FDCWD, "/usr/share/locale/en_US/LC_MESSAGES/grep.mo", O_RDONLY <unfinished ...>
[pid 25903] <... fstat resumed>{st_mode=S_IFREG|0644, st_size=3552, ...}) = 0
[pid 25904] <... openat resumed>)       = -1 ENOENT (No such file or directory)
[pid 25903] read(3,  <unfinished ...>
[pid 25904] openat(AT_FDCWD, "/usr/share/locale/en/LC_MESSAGES/grep.mo", O_RDONLY <unfinished ...>
[pid 25903] <... read resumed>"TZif2\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\6\0\0\0\6\0\0\0\0"..., 4096) = 3552
[pid 25904] <... openat resumed>)       = -1 ENOENT (No such file or directory)
[pid 25903] lseek(3, -2260, SEEK_CUR <unfinished ...>
[pid 25904] openat(AT_FDCWD, "/usr/share/locale-langpack/en_US/LC_MESSAGES/grep.mo", O_RDONLY <unfinished ...>
[pid 25903] <... lseek resumed>)        = 1292
[pid 25904] <... openat resumed>)       = -1 ENOENT (No such file or directory)
[pid 25903] read(3,  <unfinished ...>
[pid 25904] openat(AT_FDCWD, "/usr/share/locale-langpack/en/LC_MESSAGES/grep.mo", O_RDONLY <unfinished ...>
[pid 25903] <... read resumed>"TZif2\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\6\0\0\0\6\0\0\0\0"..., 4096) = 2260
[pid 25904] <... openat resumed>)       = -1 ENOENT (No such file or directory)
[pid 25903] close(3 <unfinished ...>
[pid 25904] openat(AT_FDCWD, "/proc/self/maps", O_RDONLY <unfinished ...>
[pid 25903] <... close resumed>)        = 0
[pid 25904] <... openat resumed>)       = 3
[pid 25904] mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0 <unfinished ...>
[pid 25903] write(1, "total 12\n-rw-rw-r-- 1 denis deni"..., 159 <unfinished ...>
[pid 25904] <... mmap resumed>)         = 0x7567fb3b3000
[pid 25903] <... write resumed>)        = 159
[pid 25904] lseek(3, 0, SEEK_SET <unfinished ...>
[pid 25903] close(1 <unfinished ...>
[pid 25904] <... lseek resumed>)        = 0
[pid 25903] <... close resumed>)        = 0
[pid 25904] read(3,  <unfinished ...>
[pid 25903] close(2 <unfinished ...>
[pid 25904] <... read resumed>"6281acb89000-6281acb8d000 r--p 0"..., 8192) = 3059
[pid 25903] <... close resumed>)        = 0
[pid 25904] read(3, "", 5133)           = 0
[pid 25903] exit_group(0 <unfinished ...>
[pid 25904] close(3 <unfinished ...>
[pid 25903] <... exit_group resumed>)   = ?
[pid 25904] <... close resumed>)        = 0
[pid 25903] +++ exited with 0 +++
[pid 25904] munmap(0x7567fb3b3000, 8192 <unfinished ...>
[pid 25902] <... read resumed>0xa3ac370, 8192) = ? ERESTARTSYS (To be restarted if SA_RESTART is set)
[pid 25904] <... munmap resumed>)       = 0
[pid 25902] --- SIGCHLD {si_signo=SIGCHLD, si_code=CLD_EXITED, si_pid=25903, si_uid=1000, si_status=0, si_utime=0, si_stime=0} ---
[pid 25904] sigaltstack({ss_sp=0x6281acbb77c0, ss_flags=0, ss_size=65536},  <unfinished ...>
[pid 25902] read(4,  <unfinished ...>
[pid 25904] <... sigaltstack resumed>NULL) = 0
[pid 25904] rt_sigaction(SIGSEGV, {sa_handler=0x6281acbae990, sa_mask=[HUP INT QUIT USR1 USR2 PIPE ALRM TERM CHLD URG XCPU XFSZ VTALRM PROF WINCH IO PWR], sa_flags=SA_RESTORER|SA_ONSTACK|SA_SIGINFO, sa_restorer=0x7567fb045330}, NULL, 8) = 0
[pid 25904] rt_sigaction(SIGSEGV, {sa_handler=0x6281acbae990, sa_mask=[HUP INT QUIT USR1 USR2 PIPE ALRM TERM CHLD URG XCPU XFSZ VTALRM PROF WINCH IO PWR], sa_flags=SA_RESTORER|SA_ONSTACK|SA_SIGINFO, sa_restorer=0x7567fb045330}, NULL, 8) = 0
[pid 25904] fstat(1, {st_mode=S_IFIFO|0600, st_size=0, ...}) = 0
[pid 25904] fstat(0, {st_mode=S_IFIFO|0600, st_size=0, ...}) = 0
[pid 25904] lseek(0, 0, SEEK_CUR)       = -1 ESPIPE (Illegal seek)
[pid 25904] read(0, "total 12\n-rw-rw-r-- 1 denis deni"..., 98304) = 159
[pid 25904] fstat(1, {st_mode=S_IFIFO|0600, st_size=0, ...}) = 0
[pid 25904] brk(0x6281e8b0b000)         = 0x6281e8b0b000
[pid 25904] read(0, "", 98304)          = 0
[pid 25904] write(1, "-rw-rw-r-- 1 denis denis 606 Sep"..., 101) = 101
[pid 25902] <... read resumed>"-rw-rw-r-- 1 denis denis 606 Sep"..., 8192) = 101
[pid 25904] close(1 <unfinished ...>
[pid 25902] read(4,  <unfinished ...>
[pid 25904] <... close resumed>)        = 0
[pid 25902] <... read resumed>"", 8091) = 0
[pid 25904] brk(0x6281e8b0a000 <unfinished ...>
[pid 25902] close(4 <unfinished ...>
[pid 25904] <... brk resumed>)          = 0x6281e8b0a000
[pid 25902] <... close resumed>)        = 0
[pid 25904] close(2 <unfinished ...>
[pid 25902] wait4(25904,  <unfinished ...>
[pid 25904] <... close resumed>)        = 0
[pid 25904] exit_group(0)               = ?
[pid 25904] +++ exited with 0 +++
<... wait4 resumed>[{WIFEXITED(s) && WEXITSTATUS(s) == 0}], 0, NULL) = 25904
--- SIGCHLD {si_signo=SIGCHLD, si_code=CLD_EXITED, si_pid=25904, si_uid=1000, si_status=0, si_utime=0, si_stime=0} ---
write(1, "Trying:\n\nls -l | grep *.md\n\n** s"..., 156Trying:

ls -l | grep *.md

** stdout:
-rw-rw-r-- 1 denis denis 606 Sep 28 12:00 hw5.md
-rw-rw-r-- 1 denis denis  68 Sep 28 11:50 README.md

** stderr: None) = 156
write(1, "\n", 1
)                       = 1
rt_sigaction(SIGINT, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=SA_RESTORER|SA_ONSTACK, sa_restorer=0x7bab9ac45330}, {sa_handler=0x6e6b20, sa_mask=[], sa_flags=SA_RESTORER|SA_ONSTACK, sa_restorer=0x7bab9ac45330}, 8) = 0
wait4(25903, [{WIFEXITED(s) && WEXITSTATUS(s) == 0}], WNOHANG, NULL) = 25903
close(3)                                = 0
munmap(0x7bab9b07d000, 16384)           = 0
exit_group(0)                           = ?
+++ exited with 0 +++
```