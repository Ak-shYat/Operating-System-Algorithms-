#include <iostream>
#include <thread>
#include <mutex>
#include <semaphore.h>
#include <chrono>
#include <vector>

using namespace std;

// Shared variables
mutex mtx;
sem_t writeLock, readLock;
int readersCount = 0;

// Function declarations
void writer(int id);
void reader(int id);

int main() {
    // Initialize semaphores
    sem_init(&writeLock, 0, 1);
    sem_init(&readLock, 0, 1);

    // Create threads for writers and readers
    vector<thread> threads;
    for (int i = 1; i <= 3; ++i) {
        threads.push_back(thread(writer, i));
        threads.push_back(thread(reader, i));
    }

    // Join threads
    for (auto& th : threads) {
        th.join();
    }

    // Destroy semaphores
    sem_destroy(&writeLock);
    sem_destroy(&readLock);

    return 0;
}

// Writer function
void writer(int id) {
    while (true) {
        // Simulate writing process
        this_thread::sleep_for(chrono::milliseconds(1000));

        // Acquire write lock
        sem_wait(&writeLock);

        // Write data
        cout << "Writer " << id << " is writing." << endl;

        // Release write lock
        sem_post(&writeLock);
    }
}

// Reader function
void reader(int id) {
    while (true) {
        // Simulate reading process
        this_thread::sleep_for(chrono::milliseconds(500));

        // Acquire read lock
        sem_wait(&readLock);
        readersCount++;
        if (readersCount == 1) {
            // Acquire write lock to block writers
            sem_wait(&writeLock);
        }
        sem_post(&readLock);

        // Read data
        cout << "Reader " << id << " is reading." << endl;

        // Release read lock
        sem_wait(&readLock);
        readersCount--;
        if (readersCount == 0) {
            // Release write lock to allow writers
            sem_post(&writeLock);
        }
        sem_post(&readLock);
    }
}
