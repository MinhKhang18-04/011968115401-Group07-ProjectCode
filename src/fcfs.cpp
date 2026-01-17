#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct Process {
    string pid;
    int arrival;
    int burst;
    int waiting;
    int turnaround;
};

int main() {
    ifstream file("input.csv");
    if (!file) {
        cout << "Cannot open input.csv\n";
        return 1;
    }

    vector<Process> p;
    string line;

    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        Process pr;
        string temp;

        getline(ss, pr.pid, ',');
        getline(ss, temp, ','); pr.arrival = stoi(temp);
        getline(ss, temp, ','); pr.burst = stoi(temp);

        p.push_back(pr);
    }

    int time = 0;
    for (int i = 0; i < p.size(); i++) {
        if (time < p[i].arrival)
            time = p[i].arrival;

        p[i].waiting = time - p[i].arrival;
        time += p[i].burst;
        p[i].turnaround = p[i].waiting + p[i].burst;
    }

    cout << "FCFS Scheduling Result\n";
    cout << "PID\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (auto pr : p) {
        cout << pr.pid << "\t"
             << pr.arrival << "\t"
             << pr.burst << "\t"
             << pr.waiting << "\t"
             << pr.turnaround << "\n";
    }

    return 0;
}
