#include <bits/stdc++.h>
using namespace std;

struct Task {
    int id;          // Task ID
    int burst_time;  // Burst Time
    int arrival_time; // Arrival Time
};

void SRJFScheduling(const vector<Task>& tasks) {
    int n = tasks.size();
    vector<int> remaining_time(n);
    vector<int> completion_time(n);
    vector<int> waiting_time(n);

    for (int i = 0; i < n; ++i) {
        remaining_time[i] = tasks[i].burst_time;
    }

    int completed = 0;
    int time = 0;
    while (completed < n) {
        int min_remaining = numeric_limits<int>::max();
        int shortest_task = -1;

        for (int i = 0; i < n; ++i) {
            if (tasks[i].arrival_time <= time && remaining_time[i] < min_remaining && remaining_time[i] > 0) {
                min_remaining = remaining_time[i];
                shortest_task = i;
            }
        }

        if (shortest_task == -1) {
            ++time;
            continue;
        }

        --remaining_time[shortest_task];
        if (remaining_time[shortest_task] == 0) {
            ++completed;
            completion_time[shortest_task] = time + 1;
            waiting_time[shortest_task] = completion_time[shortest_task] - tasks[shortest_task].burst_time - tasks[shortest_task].arrival_time;
            if (waiting_time[shortest_task] < 0) {
                waiting_time[shortest_task] = 0;
            }
        }
        ++time;
    }

    float total_waiting_time = 0;
    float total_turnaround_time = 0;
    cout << "Task\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; ++i) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += completion_time[i] - tasks[i].arrival_time;
        cout << tasks[i].id << "\t" << tasks[i].burst_time << "\t" << waiting_time[i] << "\t" << completion_time[i] - tasks[i].arrival_time << endl;
    }

    cout << "\nAverage waiting time = " << total_waiting_time / n << endl;
    cout << "Average turnaround time = " << total_turnaround_time / n << endl;
}

int main() {
    vector<Task> tasks = { { 1, 6, 2 }, { 2, 2, 5 }, { 3, 8, 1 }, { 4, 3, 0}, {5, 4, 4} };
    SRJFScheduling(tasks);
    return 0;
}
