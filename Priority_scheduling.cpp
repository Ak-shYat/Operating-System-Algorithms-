#include<bits/stdc++.h>
using namespace std;

struct Process {
    int pid;        // Process ID
    int bt;         // CPU Burst time required
    int priority;   // Priority of this process
};

// Function to sort the Process acc. to priority
bool comparePriority(const Process& a, const Process& b) {
    return (a.priority < b.priority);
}

// Function to find the waiting time for all processes
void calculateWaitingTime(Process proc[], int n, int wt[]) {
    // Waiting time for the first process is 0
    wt[0] = 0;

    // Calculating waiting time
    for (int i = 1; i < n; i++)
        wt[i] = proc[i - 1].bt + wt[i - 1];
}

// Function to calculate turn around time
void calculateTurnAroundTime(Process proc[], int n, int wt[], int tat[]) {
    // Calculating turnaround time by adding bt[i] + wt[i]
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}

// Function to calculate average time
void calculateAvgTime(Process proc[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Function to find waiting time of all processes
    calculateWaitingTime(proc, n, wt);

    // Function to find turn around time for all processes
    calculateTurnAroundTime(proc, n, wt, tat);

    // Display processes along with all details
    cout << "\nProcesses  Burst time  Waiting time  Turn around time\n";

    // Calculate total waiting time and total turn around time
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << " " << proc[i].pid << "\t\t" << proc[i].bt << "\t " << wt[i] << "\t\t " << tat[i] << endl;
    }

    cout << "\nAverage waiting time = " << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}

void priorityScheduling(Process proc[], int n) {
    // Sort processes by priority
    sort(proc, proc + n, comparePriority);

    cout << "Order in which processes get executed: \n";
    for (int i = 0; i < n; i++)
        cout << proc[i].pid << " ";

    calculateAvgTime(proc, n);
}

int main() {
    Process proc[] = { { 1, 10, 2 }, { 2, 5, 0 }, { 3, 8, 1 } };
    int n = sizeof(proc) / sizeof(proc[0]);
    priorityScheduling(proc, n);
    return 0;
}
