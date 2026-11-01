# Dining Philosophers problem 

#include <stdio.h>      // For printf()
#include <pthread.h>    // For creating threads
#include <semaphore.h>  // For using semaphores
#include <unistd.h>     // For sleep()
#define N 5             // Number of philosophers and forks
sem_t forks[N];         // Semaphore for each fork
sem_t room;             // Controls entry of philosophers

// Function executed by each philosopher thread
void *philosopher(void *arg)
{
    int id = *(int *)arg;       // Get philosopher ID

    int left = id;              // Left fork number
    int right = (id + 1) % N;   // Right fork number

    // Philosopher starts thinking
    printf("Philosopher %d is thinking\n", id);

    // Allow only four philosophers to try to get forks
    sem_wait(&room);

    // Pick up the left fork
    sem_wait(&forks[left]);
    printf("Philosopher %d picked up left fork\n", id);

    // Pick up the right fork
    sem_wait(&forks[right]);
    printf("Philosopher %d picked up right fork\n", id);

    // Eat after acquiring both forks
    printf("Philosopher %d is eating\n", id);
    sleep(1);                   // Simulate eating for one second

    // Release the right fork
    sem_post(&forks[right]);

    // Release the left fork
    sem_post(&forks[left]);

    printf("Philosopher %d released both forks\n", id);

    // Allow another philosopher to enter
    sem_post(&room);

    // Philosopher finishes eating
    printf("Philosopher %d finished eating\n", id);

    return NULL;                // End the thread
}

int main()
{
    pthread_t t[N];             // Array to store thread IDs
    int id[N];                  // Array to store philosopher IDs

    // Initialize room semaphore with 4 permits
    sem_init(&room, 0, 4);

    // Initialize each fork semaphore with 1 permit
    for (int i = 0; i < N; i++)
    {
        sem_init(&forks[i], 0, 1);
    }

    // Create five philosopher threads
    for (int i = 0; i < N; i++)
    {
        id[i] = i;              // Assign philosopher ID
        pthread_create(&t[i], NULL, philosopher, &id[i]);
    }

    // Wait for all philosophers to finish
    for (int i = 0; i < N; i++)
    {
        pthread_join(t[i], NULL);
    }

    // Destroy all fork semaphores
    for (int i = 0; i < N; i++)
    {
        sem_destroy(&forks[i]);
    }

    // Destroy the room semaphore
    sem_destroy(&room);

    return 0;                   // End the main program
}
