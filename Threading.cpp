#include<bits/stdc++.h>
using namespace std;

// Function to be executed by the first thread
void task1(string msg) {
    cout << "Thread 1 says: " << msg <<endl;
}

// Function to be executed by the second thread
void task2(string msg) {
    cout << "Thread 2 says: " << msg <<endl;
}

int main() {
    // Create two threads and start executing the specified functions
    thread t1(task1, "Hello from Thread 1!");
    thread t2(task2, "Hello from Thread 2!");

    // Wait for both threads to finish (join them)
    t1.join();
    t2.join();

    cout << "Main thread continues..." << endl;

    return 0;
}
