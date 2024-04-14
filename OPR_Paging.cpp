#include <iostream>
#include <vector>
using namespace std;

// Function to check if a page exists in a frame
bool isPageInFrame(int key, vector<int>& frame) {
    for (int i = 0; i < frame.size(); ++i) {
        if (frame[i] == key) {
            return true;
        }
    }
    return false;
}

// Function to predict the page that will not be used recently
int predictPage(int pages[], vector<int>& frame, int page_count, int index) {
    int result = -1, farthest = index;
    for (int i = 0; i < frame.size(); ++i) {
        int j;
        for (j = index; j < page_count; ++j) {
            if (frame[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    result = i;
                }
                break;
            }
        }
        if (j == page_count) {
            return i;
        }
    }
    return (result == -1) ? 0 : result;
}

// Function to implement the optimal page replacement algorithm
void optimalPageReplacement(int pages[], int page_count, int frame_count) {
    vector<int> frame;
    int hits = 0;
    for (int i = 0; i < page_count; ++i) {
        if (isPageInFrame(pages[i], frame)) {
            ++hits;
            continue;
        }
        if (frame.size() < frame_count) {
            frame.push_back(pages[i]);
        } else {
            int j = predictPage(pages, frame, page_count, i + 1);
            frame[j] = pages[i];
        }
    }
    cout << "Number of hits: " << hits << endl;
    cout << "Number of misses: " << page_count - hits << endl;
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int page_count = sizeof(pages) / sizeof(pages[0]);
    int frame_count = 4;
    optimalPageReplacement(pages, page_count, frame_count);
    return 0;
}
