Có nhé — mình đã mở file `.zip` và đọc được code/structure. Dưới đây là bản **README.md “chuẩn theo đúng dự án hiện tại”** (khớp với `src/main.cpp`, `src/input.csv`, và file output thật `output_fcfs.csv`, `output_sjf.csv`). Bạn chỉ cần copy dán đè vào `README.md`.

---

# CPU Scheduling Algorithms Demonstration (FCFS & SJF Non-preemptive)

**Course:** Operating Systems
**Group:** 011968115401 - Group07
**Project:** CPU Scheduling Algorithms Demonstration
**Language:** C++ (Console Application)

This project is a C++ console program that demonstrates two CPU scheduling algorithms:

* **FCFS (First Come First Served)**
* **SJF (Shortest Job First) – Non-preemptive**

The program reads process data from a CSV file, simulates scheduling, prints results (WT/TAT/Start/End) and generates output CSV files. It also prints a simple **Gantt Chart** on the console (including IDLE segments if CPU is waiting).

---

## 1. Folder Structure

```
011968115401-Group07-ProjectCode/
├── assets/
│   ├── Colloborators.jpg
│   ├── FCFS tested photo.jpg
│   ├── SJF tested photo.jpg
│   └── design,gantt.jpg
│
├── docs/
│   └── Operating System.docx
│
├── src/
│   ├── fcfs.cpp
│   ├── sjf.cpp
│   ├── main.cpp
│   └── input.csv
│
├── README.md
├── cpu.exe
├── output_fcfs.csv
└── output_sjf.csv
```

> **Note:** The final integrated application is implemented in **`src/main.cpp`**.
> `src/fcfs.cpp` và `src/sjf.cpp` là các file chạy độc lập theo từng thuật toán (mỗi file có `main()` riêng).

---

## 2. How to Run (Windows)

### Option A — Run prebuilt executable `cpu.exe` (recommended)

**Important:** Program always reads **`input.csv` in the CURRENT WORKING DIRECTORY**.

Cách chạy đúng với repo hiện tại:

```bash
cd src
..\cpu.exe
```

Vì bạn đang đứng trong `src/`, file `input.csv` sẽ được đọc đúng.

### Option B — Run `src/main.exe` (if available)

```bash
cd src
.\main.exe
```

---

## 3. Build from Source

### Build the integrated program (main app)

⚠️ Chỉ compile **`src/main.cpp`** (vì `fcfs.cpp` và `sjf.cpp` cũng có `main()`, compile chung sẽ lỗi “multiple definition of main”).

```bash
cd src
g++ -std=c++17 -O2 main.cpp -o cpu
.\cpu
```

### Build standalone FCFS / SJF (optional)

Nếu muốn chạy riêng từng thuật toán:

```bash
cd src
g++ -std=c++17 -O2 fcfs.cpp -o fcfs
g++ -std=c++17 -O2 sjf.cpp -o sjf
```

Run:

```bash
.\fcfs
.\sjf
```

---

## 4. Input CSV Format

**Default input file:** `src/input.csv`
The program skips the first line as header, then reads rows with 3 columns:

* Process ID
* Arrival time
* Burst time

Current `src/input.csv`:

```csv
Process,ArrivalTime,BurstTime
P1,0,5
P2,1,3
P3,2,8
P4,3,6
```

---

## 5. Program Menu & Output

When running, the program shows:

```
CPU Scheduling Demo
1) FCFS
2) SJF (Non-preemptive)
Choose:
```

After simulation, it prints:

* Process table with: **Arrival, Burst, Start, End, WT, TAT**
* **Average WT** and **Average TAT**
* **Gantt Chart** in console (format: `| P1 | P2 | ... |` and time markers)
* Exports result to CSV

---

## 6. Exported CSV Files

Depending on the chosen algorithm, the program exports:

* **`output_fcfs.csv`** (FCFS result)
* **`output_sjf.csv`** (SJF non-preemptive result)

Output format:

```csv
PID,Arrival,Burst,Start,Completion,Waiting,Turnaround
...
```

---

## 7. Algorithms Summary

### FCFS (First Come First Served)

* Sort processes by arrival time (ascending).
* Execute in that order (non-preemptive).
* If CPU is free and next process hasn’t arrived yet → CPU becomes **IDLE** until next arrival.

### SJF (Non-preemptive)

* At each time point, choose among **arrived & not completed** processes the one with **smallest burst**.
* Tie-breakers in code:

  * smaller burst time first
  * if equal burst → earlier arrival first
* If no process is ready → CPU **IDLE** and jumps to next arrival time.

---

## 8. Testing & Proof

We validated correctness by comparing results with textbook examples.

Proof images are stored in:

* `assets/FCFS tested photo.jpg`
* `assets/SJF tested photo.jpg`

Gantt chart design concept:

* `assets/design,gantt.jpg`

Team collaborators evidence:

* `assets/Colloborators.jpg`

Project report document:

* `docs/Operating System.docx`

---

## 9. Group Members & Task Distribution

**Lê Hoàng Minh Khang (Leader)**

* Manage repository structure
* Implement FCFS logic / integration

**Nguyễn Nhật Toàn (Developer)**

* Implement SJF non-preemptive logic

**Lương Minh Hiếu (Tester)**

* Verify results with textbook examples
* Collect proof images

**Lê Thế Huy (Designer)**

* Console UI / Gantt chart visualization concept

**Phạm Nguyễn Gia Bảo (Writer)**

* Write README and organize documentation/submission materials
