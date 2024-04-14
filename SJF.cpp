#include<bits/stdc++.h>
using namespace std;

struct Process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

bool compareByBurstTime(const Process& a, const Process& b) {
    return a.burst_time < b.burst_time;
}

void calculateWaitingTime(vector<Process>& processes) {
    processes[0].waiting_time = 0;
    for (size_t i = 1; i < processes.size(); ++i) {
        processes[i].waiting_time = processes[i - 1].burst_time + processes[i - 1].waiting_time;
    }
}

void calculateTurnaroundTime(vector<Process>& processes) {
    for (size_t i = 0; i < processes.size(); ++i) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter burst time for process P" << i + 1 << ": ";
        cin >> processes[i].burst_time;
        processes[i].id = i + 1;
    }

    // Sort processes by burst time (Shortest Job First)
    sort(processes.begin(), processes.end(), compareByBurstTime);

    calculateWaitingTime(processes);
    calculateTurnaroundTime(processes);

    float total_waiting_time = 0;
    float total_turnaround_time = 0;

    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (const auto& p : processes) {
        total_waiting_time += p.waiting_time;
        total_turnaround_time += p.turnaround_time;
        cout << "P" << p.id << "\t\t" << p.burst_time << "\t\t" << p.waiting_time << "\t\t" << p.turnaround_time << "\n";
    }

    float avg_waiting_time = total_waiting_time / n;
    float avg_turnaround_time = total_turnaround_time / n;
    cout << "Average Waiting Time: " << avg_waiting_time << std::endl;
    cout << "Average Turnaround Time: " << avg_turnaround_time << std::endl;

    return 0;
}
