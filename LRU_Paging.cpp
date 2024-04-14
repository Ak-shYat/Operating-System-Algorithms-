#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <climits>
using namespace std;

// Function to find page faults using LRU algorithm
int pageFaultsLRU(int pages[], int n, int capacity) {
    unordered_set<int> pageSet; // Set to represent current pages in memory
    unordered_map<int, int> pageIndexes; // Map to store the indexes of recently used pages

    int page_faults = 0; // Counter to track the number of page faults
    for (int i = 0; i < n; ++i) {
        if (pageSet.size() < capacity) {
            if (pageSet.find(pages[i]) == pageSet.end()) {
                pageSet.insert(pages[i]); // Insert the page into the set if it's not already present
                ++page_faults; // Increment page fault count
            }
            pageIndexes[pages[i]] = i; // Update the index of the page
        } else {
            if (pageSet.find(pages[i]) == pageSet.end()) {
                int lru_index = INT_MAX, lru_page;
                for (auto it = pageSet.begin(); it != pageSet.end(); ++it) {
                    if (pageIndexes[*it] < lru_index) {
                        lru_index = pageIndexes[*it];
                        lru_page = *it;
                    }
                }
                pageSet.erase(lru_page); // Remove the least recently used page
                pageSet.insert(pages[i]); // Insert the current page
                ++page_faults; // Increment page fault count
            }
            pageIndexes[pages[i]] = i; // Update the index of the page
        }
    }
    return page_faults;
}

// Driver code
int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 4;
    cout <<"Page Faults: "<< pageFaultsLRU(pages, n, capacity);
    return 0;
}
