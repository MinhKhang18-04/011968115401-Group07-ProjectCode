#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Process {
    string id;
    int at; // Arrival Time
    int bt; // Burst Time
    int wt; // Waiting Time
    int tat; // Turnaround Time
    int ct; // Completion Time
};

void calculateFCFS(vector<Process>& procs) {
    // Sắp xếp theo Arrival Time (AT)
    sort(procs.begin(), procs.end(), [](Process a, Process b) {
        return a.at < b.at;
    });

    int current_time = 0;
    for (int i = 0; i < procs.size(); i++) {
        if (current_time < procs[i].at) {
            current_time = procs[i].at;
        }
        procs[i].ct = current_time + procs[i].bt;
        procs[i].tat = procs[i].ct - procs[i].at;
        procs[i].wt = procs[i].tat - procs[i].bt;
        current_time = procs[i].ct;
    }
}

void display(const vector<Process>& procs) {
    cout << "\nID\tAT\tBT\tCT\tTAT\tWT\n";
    for (const auto& p : procs) {
        cout << p.id << "\t" << p.at << "\t" << p.bt << "\t" 
             << p.ct << "\t" << p.tat << "\t" << p.wt << endl;
    }
}

int main() {
    // Dữ liệu mẫu (Member 2 sẽ thay thế bằng việc đọc file CSV sau)
    vector<Process> procs = {
        {"P1", 0, 5},
        {"P2", 2, 3},
        {"P3", 4, 1}
    };

    calculateFCFS(procs);
    display(procs);

    return 0;
}
