> Look up the "self-pipe trick". What is it? When would you use it? 

The self-pipe trick involves creating a non-blocking pipe, where the signal handler writes a byte when a signal is received, which is then read by the main program loop, ensuring immediate and safe signal handling.

The tricky part about signals is that they can interrupt your program at any time. While any of your code is executing, a signal can arrive and interrupt it. While one signal is being handled, another signal (or the same signal!), can arrive a second time and interrupt the first handler.

The problem with most signal handlers is that they are not re-entrant. This means that it's not safe for this block of code to be interrupted, then re-started before the first invocation is finished. This is not a good thing for signal handlers. You need your signal handlers to be re-entrant because you never know when the next signal is going to arrive and re-start the handler.


references:

- [The Self-Pipe Trick Explained](https://www.sitepoint.com/the-self-pipe-trick-explained/)
- [The self-pipe trick](https://cr.yp.to/docs/selfpipe.html)
- [altio/self_pipe.c](https://man7.org/tlpi/code/online/dist/altio/self_pipe.c.html)