#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Process {
    string id;
    int at, bt, st, et;
    bool done = false;
};

struct Gantt {
    string id;
    int s, e;
};

void showGantt(vector<Gantt> g) {
    cout << "\nGantt Chart:\n|";
    for (auto x : g) cout << " " << x.id << " |";
    cout << "\n" << g[0].s;
    for (auto x : g) {
        for (int i = 0; i < x.id.length() + 2; i++) cout << " ";
        cout << x.e;
    }
    cout << "\n";
}

void doFCFS(vector<Process> p) {
    sort(p.begin(), p.end(), [](Process a, Process b) { return a.at < b.at; });
    vector<Gantt> g;
    int cur = 0;
    for (auto &x : p) {
        if (cur < x.at) {
            g.push_back({"IDLE", cur, x.at});
            cur = x.at;
        }
        g.push_back({x.id, cur, cur + x.bt});
        cur += x.bt;
    }
    showGantt(g);
}

void doSJF(vector<Process> p) {
    vector<Gantt> g;
    int cur = 0, completed = 0, n = p.size();
    while (completed < n) {
        int idx = -1, minB = 1e9;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= cur && !p[i].done && p[i].bt < minB) {
                minB = p[i].bt;
                idx = i;
            }
        }
        if (idx != -1) {
            g.push_back({p[idx].id, cur, cur + p[idx].bt});
            cur += p[idx].bt;
            p[idx].done = true;
            completed++;
        } else {
            int next = 1e9;
            for (auto x : p) if (!x.done) next = min(next, x.at);
            g.push_back({"IDLE", cur, next});
            cur = next;
        }
    }
    showGantt(g);
}

int main() {
    int n, choice;
    cout << "So luong process: "; cin >> n;
    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        p[i].id = "P" + to_string(i + 1);
        cout << p[i].id << " (Arrival Burst): ";
        cin >> p[i].at >> p[i].bt;
    }
    cout << "1. FCFS | 2. SJF: "; cin >> choice;
    if (choice == 1) doFCFS(p);
    else doSJF(p);
    return 0;
}