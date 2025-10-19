#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t lock1;
pthread_mutex_t lock2;

void *thread_function1(void *arg)
{
    pthread_mutex_lock(&lock1);
    printf("** 1 lock1 applied\n");
    sleep(1);

    // none of the remaining statements will execute
    pthread_mutex_lock(&lock2);
    printf("** 1 lock2 applied\n");

    printf("** 1 lock1 and lock2 work done\n");

    pthread_mutex_unlock(&lock2);
    pthread_mutex_unlock(&lock1);

    pthread_exit(NULL);
}

void *thread_function2(void *arg)
{
    pthread_mutex_lock(&lock2);
    printf("** 2 lock2 applied\n");
    sleep(1);

    // none of the remaining statements will execute
    pthread_mutex_lock(&lock1);
    printf("** 2 lock1 applied\n");

    printf("** 2 lock2 and lock1 work done\n");

    pthread_mutex_unlock(&lock1);
    pthread_mutex_unlock(&lock2);
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread_id;

    pthread_mutex_init(&lock1, NULL);
    pthread_mutex_init(&lock2, NULL);

    int result = pthread_create(&thread_id, NULL, thread_function1, NULL);
    if (result != 0)
    {
        perror("Error creating thread one");
        return 1;
    }

    result = pthread_create(&thread_id, NULL, thread_function2, NULL);
    if (result != 0)
    {
        perror("Error creating thread two");
        return 1;
    }

    pthread_join(thread_id, NULL);

    printf("You will not see this statement\n");
    return 0;
}