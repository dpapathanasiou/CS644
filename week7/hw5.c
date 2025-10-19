#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t lock;

void *thread_function(void *arg)
{
    pthread_mutex_lock(&lock);
    char *message = (char *)arg;

    printf("%s - mutex locked\n", message);
    sleep(10);

    // exit w/o releasing the lock!
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread_id; 
    char *message1 = "Hello from thread one!";

    pthread_mutex_init(&lock, NULL);
    int result = pthread_create(&thread_id, NULL, thread_function, (void *)message1);
    if (result != 0)
    {
        perror("Error creating thread one");
        return 1;
    }

    char *message2 = "Hello from thread two!";
    result = pthread_create(&thread_id, NULL, thread_function, (void *)message2);
    if (result != 0)
    {
        perror("Error creating thread two");
        return 1;
    }

    // main thread executes faster relative to the thread
    for (int i = 0; i < 10; i++)
    {
        printf("Hello from the main thread - Iteration %d\n", i);
        sleep(1);
    }

    pthread_join(thread_id, NULL);
    pthread_mutex_destroy(&lock);

    printf("Main thread exiting.\n");
    return 0;
}
