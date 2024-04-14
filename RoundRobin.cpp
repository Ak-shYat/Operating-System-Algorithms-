#include <bits/stdc++.h>
using namespace std;

// Function to calculate the average waiting time and turnaround time
void roundRobinScheduling(const vector<int>& processes, const vector<int>& burst_time, int quantum) {
    int n = processes.size();
    vector<int> remaining_time(burst_time.begin(), burst_time.end());
    vector<int> waiting_time(n, 0);
    vector<int> turnaround_time(n, 0);

    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int current_time = 0;

    while (true) {
        bool all_processes_completed = true;

        for (int i = 0; i < n; ++i) {
            if (remaining_time[i] > 0) {
                all_processes_completed = false;

                if (remaining_time[i] > quantum) {
                    current_time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    current_time += remaining_time[i];
                    waiting_time[i] = current_time - burst_time[i];
                    turnaround_time[i] = current_time;
                    remaining_time[i] = 0;
                }
            }
        }

        if (all_processes_completed) {
            break;
        }
    }

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; ++i) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
        cout << "Process " << processes[i] << ": Burst Time = " << burst_time[i] << ", Waiting Time = " << waiting_time[i] << ", Turnaround Time = " << turnaround_time[i] << endl;
    }

    // Calculate average waiting time and average turnaround time
    cout << "Average Waiting Time = " << (float)total_waiting_time / n << endl;
    cout << "Average Turnaround Time = " << (float)total_turnaround_time / n << endl;
}

int main() {
    // Process IDs
    vector<int> processes = {1, 2, 3};
    // Burst time of all processes
    vector<int> burst_time = {10, 5, 8};
    // Time quantum
    int quantum = 2;

    // Perform Round Robin Scheduling
    roundRobinScheduling(processes, burst_time, quantum);

    return 0;
}
