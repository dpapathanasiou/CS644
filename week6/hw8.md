> You can pass an open file descriptor from one process to another via a socket. What syscall allows you to do this? 

UNIX domain socket (AF_UNIX) can do this, using a pair of system calls: sendmsg and recvmsg

> When might this technique be useful? 

- Privilege Separation and Sandboxing:
A privileged process can open a file or create a resource and then pass the corresponding file descriptor to a less privileged, sandboxed process. This allows the sandboxed process to access the resource without having the necessary permissions to open it directly, enhancing security. For example, a web server might open a log file and pass the descriptor to a child process that only has permission to write to that specific log file, not to create or delete files in the same directory.

- Resource Management:
A central "resource manager" process can manage a pool of resources (e.g., database connections, network sockets) and distribute them to other processes as needed by passing their file descriptors. This can help prevent resource exhaustion and simplify resource allocation logic in client processes.

- Process Handover:
In scenarios where a long-running service needs to be updated or restarted without interrupting active connections, a new process can be started, and the existing connections (represented by socket file descriptors) can be passed from the old process to the new one. This enables "graceful restarts" or "hot upgrades."

- Complex IPC with Existing Resources:
When building complex inter-process communication (IPC) mechanisms, passing file descriptors can be a more efficient and direct way to share access to open files, pipes, or sockets compared to passing data that needs to be re-interpreted or re-opened by the receiving process.

sources:

- [Passing file descriptors between processes via UNIX domain sockets](https://www.sobyte.net/post/2022-01/pass-fd-over-domain-socket/)
- [UNIX Domain Properties](https://www.ibm.com/docs/en/aix/7.3.0?topic=domains-unix-domain-properties)