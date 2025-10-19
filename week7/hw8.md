> Read the list of thread-unsafe functions in man 7 pthreads. Are there any surprises on the list? Why would a function not be thread-safe? 

According to the [man page](https://www.man7.org/linux/man-pages/man7/pthreads.7.html), a thread safe function is defined as one that will deliver the same results regardless of whether it is called from multiple threads at the same time.

Some surprising non-safe functions include:

- gethostbyaddr()
- gethostbyname()
- setenv()
- strtok()

references:

- [Thread Safety](https://w3.cs.jmu.edu/bernstdh/web/common/lectures/summary_unix_pthreads_thread-safety.php)
- [Pthreads: more examples and Systems Concepts](https://courses.grainger.illinois.edu/cs241/sp2013/lecture/15-Pthread-Examples_sol.pdf)