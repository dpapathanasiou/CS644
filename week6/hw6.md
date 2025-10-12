> If I open a socket with SOCK_DGRAM, will recv always return a single packet at a time? 

SOCK_DGRAM corresponds to UDP: it needs a buffer large enough to hold the biggest packet that your application-level protocol ever sends. 

If you're using UDP, then in general your application-level protocol shouldn't be sending packets larger than about 1400 bytes, because they'll certainly need to be fragmented and reassembled.

A single recv call always returns a single datagram.

> What happens if the buffer is too small to fit the packet?

The excess bytes are discarded.

source: [SO](https://stackoverflow.com/a/2862176)