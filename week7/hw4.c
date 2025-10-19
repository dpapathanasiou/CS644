#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg)
{
    char *message = (char *)arg;
    for (int i = 0; i < 10; i++)
    {
        printf("%s - Iteration %d\n", message, i);
        sleep(10);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread_id; 
    char *message = "Hello from a new thread!";
    int result = pthread_create(&thread_id, NULL, thread_function, (void *)message);

    if (result != 0)
    {
        perror("Error creating thread");
        return 1;
    }

    // main thread executes faster relative to the thread
    for (int i = 0; i < 10; i++)
    {
        printf("Hello from the main thread - Iteration %d\n", i);
        sleep(1);
    }

    // normally would do this, to wait on thread to finish
    // either keep or comment out, to produce hw4-with-join and hw4-no-join respectively
    //pthread_join(thread_id, NULL);

    printf("Main thread exiting.\n");
    return 0;
}
