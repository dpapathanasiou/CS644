> What happens if a client calls connect before the server has called bind? 

If a client attempts to call connect before the server has called bind, the connection will fail, because the address is not yet available

> What about after the server has called bind, but before it has called listen?

The server is not yet ready to accept incoming connections, and the connection will again fail, since while the server is bound, it's not yet listening nor ready to handle a connection

sources 

- [Know your TCP system call sequences](https://developer.ibm.com/articles/au-tcpsystemcalls/)
- [Bind System Call in C](https://thelinuxcode.com/bind-system-call-c/)