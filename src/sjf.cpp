#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

struct Process {
    string id;
    int arrivalTime;
    int burstTime;
    int finishTime;
    int waitingTime;
    int turnaroundTime;
    bool isCompleted = false;
};

void solveSJF(string filename) {
    vector<Process> proc;
    ifstream file(filename);
    string line, word;

    // Đọc file CSV (bỏ qua dòng header)
    getline(file, line); 
    while (getline(file, line)) {
        stringstream ss(line);
        Process p;
        getline(ss, p.id, ',');
        getline(ss, word, ','); p.arrivalTime = stoi(word);
        getline(ss, word, ','); p.burstTime = stoi(word);
        proc.push_back(p);
    }

    int currentTime = 0, completed = 0;
    int n = proc.size();

    cout << "\n--- KET QUA THUAT TOAN SJF ---\n";
    cout << "PID\tArrival\tBurst\tFinish\tWait\tTurnaround\n";

    while (completed < n) {
        int idx = -1;
        int minBurst = 1e9;

        // Tìm tiến trình có Burst Time nhỏ nhất trong các tiến trình đã đến
        for (int i = 0; i < n; i++) {
            if (proc[i].arrivalTime <= currentTime && !proc[i].isCompleted) {
                if (proc[i].burstTime < minBurst) {
                    minBurst = proc[i].burstTime;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            proc[idx].finishTime = currentTime + proc[idx].burstTime;
            proc[idx].turnaroundTime = proc[idx].finishTime - proc[idx].arrivalTime;
            proc[idx].waitingTime = proc[idx].turnaroundTime - proc[idx].burstTime;
            proc[idx].isCompleted = true;
            
            currentTime = proc[idx].finishTime;
            completed++;

            cout << proc[idx].id << "\t" << proc[idx].arrivalTime << "\t" 
                 << proc[idx].burstTime << "\t" << proc[idx].finishTime << "\t" 
                 << proc[idx].waitingTime << "\t" << proc[idx].turnaroundTime << endl;
        } else {
            currentTime++; // Nếu không có tiến trình nào sẵn sàng, tăng thời gian
        }
    }
}

int main() {
    // Đảm bảo file input.csv nằm cùng thư mục hoặc đúng đường dẫn src/
    solveSJF("input.csv"); 
    return 0;
}
