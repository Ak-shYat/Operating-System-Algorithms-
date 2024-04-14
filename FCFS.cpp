#include<bits/stdc++.h>
using namespace std;


void findWaitingTime(vector<int>& bt,vector<int>& wt) {
    wt[0] = 0; // Waiting time for the first process is always 0

    for (size_t i = 1; i < bt.size(); ++i) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void findTurnAroundTime(vector<int>& bt, vector<int>& wt, vector<int>& tat) {
    for (size_t i = 0; i < bt.size(); ++i) {
        tat[i] = bt[i] + wt[i];
    }
}

void findavgTime(vector<int>& at, vector<int>& bt) {
    size_t n = bt.size();
    vector<int> wt(n, 0);
    vector<int> tat(n, 0);

    findWaitingTime(bt, wt);
    findTurnAroundTime(bt, wt, tat);

    int total_wt = 0;
    int total_tat = 0;

    cout << "Processes\tArrival time\tBurst time\tWaiting time\tTurnaround time\n";
    for (size_t i = 0; i < n; ++i) {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << i + 1 << "\t\t" << at[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\n";
    }

    cout << "Average waiting time = " << static_cast<double>(total_wt) / n << endl;
    cout << "Average turnaround time = " << static_cast<double>(total_tat) / n << endl;
}

int main() {
    // Example usage
    vector<int> arrival_time = {0, 2, 4, 5};
    vector<int> burst_time = {6, 8, 7, 3};

    findavgTime(arrival_time, burst_time);

    return 0;
}
