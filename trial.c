#include <stdio.h>
#include <pthread.h>

pthread_mutex_t firstLock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t secondLock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t thirdLock = PTHREAD_MUTEX_INITIALIZER;

void* firstTHread(void* arg) {
    pthread_mutex_lock(&firstLock);
    printf("Thread 1: Locked firstLock\n");
    sleep(1);
    pthread_mutex_lock(&secondLock);
    printf("Thread 1: Locked secondLock\n");
    pthread_mutex_unlock(&secondLock);
    pthread_mutex_unlock(&firstLock);
    return NULL;
}

void* secondThread(void* arg) {
    pthread_mutex_lock(&secondLock);
    printf("Thread 2: Locked secondLock\n");
    sleep(1);
    pthread_mutex_lock(&thirdLock);
    printf("Thread 2: Locked thirdLock\n");
    pthread_mutex_unlock(&thirdLock);
    pthread_mutex_unlock(&secondLock);
    return NULL;
}

void* thirdThread(void* arg) {
    pthread_mutex_lock(&thirdLock);
    printf("Thread 3: Locked thirdLock\n");
    sleep(1);
    pthread_mutex_lock(&firstLock);
    printf("Thread 3: Locked firstLock\n");
    pthread_mutex_unlock(&firstLock);
    pthread_mutex_unlock(&thirdLock);
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;
    pthread_create(&t1, NULL, firstTHread, NULL);
    pthread_create(&t2, NULL, secondThread, NULL);
    pthread_create(&t3, NULL, thirdThread, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}