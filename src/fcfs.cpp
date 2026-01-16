#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    string id;
    int at, bt, ct, wt, tat;
};

int main() {
    int n;
    cout << "Nhap so luong tien trinh: ";
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        cout << "Nhap ID, Arrival Time, Burst Time cho P" << i + 1 << ": ";
        cin >> p[i].id >> p[i].at >> p[i].bt;
    }

    // Sap xep theo thoi gian den (Arrival Time)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                swap(p[i], p[j]);
            }
        }
    }

    int current_time = 0;
    float sumWT = 0, sumTAT = 0;

    for (int i = 0; i < n; i++) {
        if (current_time < p[i].at) {
            current_time = p[i].at;
        }
        p[i].ct = current_time + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        
        current_time = p[i].ct;
        
        sumWT += p[i].wt;
        sumTAT += p[i].tat;
    }

    // In ket qua ra man hinh
    cout << "\nKQS: First-Come First-Served\n";
    cout << "ID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].id << "\t" << p[i].at << "\t" << p[i].bt << "\t" 
             << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << endl;
    }

    cout << "\nThoi gian cho trung binh: " << sumWT / n;
    cout << "\nThoi gian hoan thanh trung binh: " << sumTAT / n << endl;

    return 0;
}
