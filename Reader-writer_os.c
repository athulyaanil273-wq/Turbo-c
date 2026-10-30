#Implement Reader-Writer problem. 

#include <stdio.h>      // For printf()
#include <stdlib.h>     // Standard library functions
#include <pthread.h>    // For threads and mutex locks
#include <semaphore.h>  // For semaphores
#include <unistd.h>     // For sleep()

sem_t rw_mutex;         // Controls access to shared data
pthread_mutex_t mutex;  // Protects the reader count

int read_count = 0;     // Number of readers currently reading
int shared_data = 0;    // Shared data

// Reader thread function
void *reader(void *arg)
{
    int id = *(int *)arg; // Get reader ID

    pthread_mutex_lock(&mutex); // Lock reader count
    read_count++;               // Increase reader count

    if (read_count == 1)        // If this is the first reader
        sem_wait(&rw_mutex);    // Prevent writers from entering

    pthread_mutex_unlock(&mutex); // Unlock reader count

    // Reading section
    printf("Reader %d is reading data = %d\n",
           id, shared_data);
    sleep(1); // Simulate reading

    pthread_mutex_lock(&mutex); // Lock reader count
    read_count--;               // Decrease reader count

    if (read_count == 0)        // If this is the last reader
        sem_post(&rw_mutex);    // Allow writers to enter

    pthread_mutex_unlock(&mutex); // Unlock reader count

    printf("Reader %d finished reading\n", id);
    return NULL; // End reader thread
}

// Writer thread function
void *writer(void *arg)
{
    int id = *(int *)arg; // Get writer ID

    sem_wait(&rw_mutex); // Request exclusive access

    shared_data++; // Update shared data

    printf("Writer %d is writing data = %d\n",
           id, shared_data);
    sleep(1); // Simulate writing

    sem_post(&rw_mutex); // Release shared data

    printf("Writer %d finished writing\n", id);
    return NULL; // End writer thread
}

int main(void)
{
    pthread_t readers[5], writers[2]; // Five readers, two writers
    int rid[5], wid[2];               // Thread ID variables
    int i;                            // Loop variable

    sem_init(&rw_mutex, 0, 1); // Initialize semaphore to 1
    pthread_mutex_init(&mutex, NULL); // Initialize mutex

    // Create five reader threads
    for (i = 0; i < 5; i++)
    {
        rid[i] = i + 1; // Assign reader ID
        pthread_create(&readers[i], NULL,
                       reader, &rid[i]);
    }

    // Create two writer threads
    for (i = 0; i < 2; i++)
    {
        wid[i] = i + 1; // Assign writer ID
        pthread_create(&writers[i], NULL,
                       writer, &wid[i]);
    }

    // Wait for all readers to finish
    for (i = 0; i < 5; i++)
        pthread_join(readers[i], NULL);

    // Wait for all writers to finish
    for (i = 0; i < 2; i++)
        pthread_join(writers[i], NULL);

    pthread_mutex_destroy(&mutex); // Destroy mutex
    sem_destroy(&rw_mutex);        // Destroy semaphore

    printf("All reader and writer threads completed.\n");

    return 0; // End program
}


