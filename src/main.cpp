#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <climits>

using namespace std;

struct Process {
    string pid;
    int arrival;
    int burst;

    // result
    int start;
    int finish;
    int waiting;
    int tat;
};

struct Segment {
    string name; // PID or "IDLE"
    int start;
    int end;
};

int main() {
    // ===== 1) Read CSV =====
    ifstream fin("input.csv");
    if (!fin) {
        cout << "ERROR: Cannot open input.csv\n";
        return 1;
    }

    vector<Process> ps;
    string line;
    getline(fin, line); // skip header

    while (getline(fin, line)) {
        if (line.size() == 0) continue;

        stringstream ss(line);
        string pid, a, b;

        getline(ss, pid, ',');
        getline(ss, a, ',');
        getline(ss, b, ',');

        Process p;
        p.pid = pid;
        p.arrival = stoi(a);
        p.burst = stoi(b);

        // init result
        p.start = p.finish = p.waiting = p.tat = 0;

        ps.push_back(p);
    }

    if (ps.empty()) {
        cout << "ERROR: No process in input.csv\n";
        return 1;
    }

    // ===== 2) Choose algorithm =====
    cout << "CPU Scheduling Demo\n";
    cout << "1) FCFS\n";
    cout << "2) SJF (Non-preemptive)\n";
    cout << "Choose: ";
    int choice;
    cin >> choice;

    vector<Segment> gantt;

    // ===== 3) FCFS =====
    if (choice == 1) {
        // sort by arrival (simple bubble sort to keep it easy)
        for (int i = 0; i < (int)ps.size(); i++) {
            for (int j = i + 1; j < (int)ps.size(); j++) {
                if (ps[j].arrival < ps[i].arrival) {
                    swap(ps[i], ps[j]);
                }
            }
        }

        int time = 0;
        for (int i = 0; i < (int)ps.size(); i++) {
            if (time < ps[i].arrival) {
                gantt.push_back({"IDLE", time, ps[i].arrival});
                time = ps[i].arrival;
            }
            ps[i].start = time;
            ps[i].finish = time + ps[i].burst;
            gantt.push_back({ps[i].pid, ps[i].start, ps[i].finish});
            time = ps[i].finish;

            ps[i].tat = ps[i].finish - ps[i].arrival;
            ps[i].waiting = ps[i].tat - ps[i].burst;
        }

        // export CSV
        ofstream fout("output_fcfs.csv");
        fout << "PID,Arrival,Burst,Start,Completion,Waiting,Turnaround\n";
        for (auto &p : ps) {
            fout << p.pid << "," << p.arrival << "," << p.burst << ","
                 << p.start << "," << p.finish << "," << p.waiting << "," << p.tat << "\n";
        }
        fout.close();
        cout << "\nExported: output_fcfs.csv\n";
    }

    // ===== 4) SJF Non-preemptive =====
    else if (choice == 2) {
        int n = (int)ps.size();
        vector<int> done(n, 0);
        int finished = 0;
        int time = 0;

        while (finished < n) {
            int chosen = -1;

            // find process ready & shortest burst
            for (int i = 0; i < n; i++) {
                if (done[i] == 0 && ps[i].arrival <= time) {
                    if (chosen == -1) chosen = i;
                    else if (ps[i].burst < ps[chosen].burst) chosen = i;
                    else if (ps[i].burst == ps[chosen].burst && ps[i].arrival < ps[chosen].arrival) chosen = i;
                }
            }

            if (chosen == -1) {
                // no ready -> jump to next arrival (IDLE)
                int nextArr = INT_MAX;
                for (int i = 0; i < n; i++) {
                    if (done[i] == 0 && ps[i].arrival < nextArr) nextArr = ps[i].arrival;
                }
                gantt.push_back({"IDLE", time, nextArr});
                time = nextArr;
                continue;
            }

            ps[chosen].start = time;
            ps[chosen].finish = time + ps[chosen].burst;
            gantt.push_back({ps[chosen].pid, ps[chosen].start, ps[chosen].finish});
            time = ps[chosen].finish;

            ps[chosen].tat = ps[chosen].finish - ps[chosen].arrival;
            ps[chosen].waiting = ps[chosen].tat - ps[chosen].burst;

            done[chosen] = 1;
            finished++;
        }

        // export CSV
        ofstream fout("output_sjf.csv");
        fout << "PID,Arrival,Burst,Start,Completion,Waiting,Turnaround\n";
        for (auto &p : ps) {
            fout << p.pid << "," << p.arrival << "," << p.burst << ","
                 << p.start << "," << p.finish << "," << p.waiting << "," << p.tat << "\n";
        }
        fout.close();
        cout << "\nExported: output_sjf.csv\n";
    }

    else {
        cout << "Invalid choice.\n";
        return 0;
    }
    // ===== 5) Print Table =====
    cout << "\nPID     Arr   Burst  Start  End    WT     TAT\n";
    double avgWT = 0, avgTAT = 0;
    for (auto &p : ps) {
        cout << left << setw(8) << p.pid
             << setw(6) << p.arrival
             << setw(7) << p.burst
             << setw(7) << p.start
             << setw(7) << p.finish
             << setw(7) << p.waiting
             << setw(7) << p.tat << "\n";
        avgWT += p.waiting;
        avgTAT += p.tat;
    }
    avgWT /= ps.size();
    avgTAT /= ps.size();
    cout << "\nAverage WT = " << avgWT << "\n";
    cout << "Average TAT = " << avgTAT << "\n";

    return 0;
}
