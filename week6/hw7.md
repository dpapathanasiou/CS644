> What's the difference between close and shutdown?

The shutdown operation represents a way to block the communication of a socket without destroying it. 

The close operation blocks the communication of a socket and destroys it. In other words, closing a socket represents terminating its connections (if there are any) and then close the file descriptor that enables the message exchanging. In this way, after executing a close operation, the process can neither read either write the socket. 

source: [Sockets: Close vs. Shutdown](https://www.baeldung.com/cs/sockets-close-vs-shutdown)