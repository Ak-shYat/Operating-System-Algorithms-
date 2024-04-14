#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

// Function to find page faults using FIFO
int pageFaults(int pages[], int n, int capacity) {
    // Set to represent current pages
    unordered_set<int> pageSet;

    // Queue to store pages in FIFO manner
    queue<int> pageQueue;

    // Start counting page faults
    int page_faults = 0;

    // Iterate through each page
    for (int i = 0; i < n; ++i) {
        // Check if the set can hold more pages
        if (pageSet.size() < capacity) {
            // If page is not in set, insert it
            if (pageSet.find(pages[i]) == pageSet.end()) {
                pageSet.insert(pages[i]);
                page_faults++;
                pageQueue.push(pages[i]);
            }
        }
        // If set is full, perform FIFO
        else {
            // If page is not in set, replace the first page in the queue
            if (pageSet.find(pages[i]) == pageSet.end()) {
                int val = pageQueue.front();
                pageQueue.pop();
                pageSet.erase(val);
                pageSet.insert(pages[i]);
                pageQueue.push(pages[i]);
                page_faults++;
            }
        }
    }

    return page_faults;
}

int main() {
    // Array of page references
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    
    // Capacity of the page frame
    int capacity = 4;
    
    // Calculate and display the number of page faults
    cout << "Page faults using FIFO: " << pageFaults(pages, n, capacity) << endl;
    
    return 0;
}
