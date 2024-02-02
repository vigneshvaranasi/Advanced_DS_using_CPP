#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int processId;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

bool compareByBurstTime( Process& a,  Process& b) {
    return a.burstTime < b.burstTime;
}

void calculateWaitingTime(vector<Process>& processes) {
    processes[0].waitingTime = 0;

    for (size_t i = 1; i < processes.size(); ++i) {
        processes[i].waitingTime = 0;
        for (size_t j = 0; j < i; ++j) {
            processes[i].waitingTime += processes[j].burstTime;
        }
    }
}

void calculateTurnaroundTime(vector<Process>& processes) {
    for (auto& process : processes) {
        process.turnaroundTime = process.burstTime + process.waitingTime;
    }
}

void printResults( vector<Process>& processes, float avgWaitingTime, float avgTurnaroundTime) {
    cout << "P\tBT\tWT\tTAT" << endl;
    for ( auto& process : processes) {
        cout << process.processId << "\t" << process.burstTime << "\t" << process.waitingTime << "\t" << process.turnaroundTime << endl;
    }
    cout << "Average Waiting Time= " << avgWaitingTime << endl;
    cout << "Average Turnaround Time= " << avgTurnaroundTime << endl;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    cout << "Enter Burst Time for each process:" << endl;
    for (int i = 0; i < n; ++i) {
        processes[i].processId = i + 1;
        cout << "P" << processes[i].processId << ": ";
        cin >> processes[i].burstTime;
    }

    sort(processes.begin(), processes.end(), compareByBurstTime);

    calculateWaitingTime(processes);
    calculateTurnaroundTime(processes);

    float avgWaitingTime = 0.0, avgTurnaroundTime = 0.0;
    for ( auto& process : processes) {
        avgWaitingTime += process.waitingTime;
        avgTurnaroundTime += process.turnaroundTime;
    }

    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    printResults(processes, avgWaitingTime, avgTurnaroundTime);

    return 0;
}
