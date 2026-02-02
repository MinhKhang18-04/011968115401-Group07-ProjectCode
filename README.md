
# CPU Scheduling Algorithms Demonstration (FCFS & SJF Non-preemptive)

**Course:** Operating Systems
**Group:** 011968115401 - Group07
**Project:** CPU Scheduling Algorithms Demonstration
**Language:** C++ (Console Application)

This project is a C++ console program that demonstrates two CPU scheduling algorithms:

* **FCFS (First Come First Served)**
* **SJF (Shortest Job First) – Non-preemptive**

The program reads process data from a CSV file, simulates scheduling, prints results (WT/TAT/Start/End), and generates output CSV files. It also prints a simple **Gantt Chart** on the console (including IDLE segments if the CPU is waiting).

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
> `src/fcfs.cpp` and `src/sjf.cpp` can be used as standalone versions for each algorithm (each file contains its own `main()`).

---

## 2. How to Run (Windows)

### Option A — Run the prebuilt executable `cpu.exe` (recommended)

**Important:** The program reads **`input.csv` from the CURRENT WORKING DIRECTORY**.

Recommended way to run with the provided project structure:

```bash
cd src
..\cpu.exe
```

Because you are inside `src/`, the program can find `src/input.csv` correctly.

### Option B — Run `src/main.exe` (if available)

```bash
cd src
.\main.exe
```

---

## 3. Build from Source

### Build the integrated program (main app)

Compile **only `src/main.cpp`** (because `fcfs.cpp` and `sjf.cpp` also contain `main()`, compiling all together will cause a “multiple definition of main” error).

```bash
cd src
g++ -std=c++17 -O2 main.cpp -o cpu
.\cpu
```

### Build standalone FCFS / SJF (optional)

If you want to run each algorithm separately:

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
The program skips the first line as a header, then reads rows with 3 columns:

* Process ID
* Arrival time
* Burst time

Example (`src/input.csv`):

```csv
Process,ArrivalTime,BurstTime
P1,0,5
P2,1,3
P3,2,8
P4,3,6
```

---

## 5. Program Menu & Console Output

When running, the program shows a menu like:

```
CPU Scheduling Demo
1) FCFS
2) SJF (Non-preemptive)
Choose:
```

After simulation, it prints:

* A process table including: **Arrival, Burst, Start, End, WT, TAT**
* **Average WT** and **Average TAT**
* **Gantt Chart** in console (format: `| P1 | P2 | ... |` and time markers)
* Exports results to CSV

---

## 6. Exported CSV Files

Depending on the chosen algorithm, the program exports:

* **`output_fcfs.csv`** (FCFS results)
* **`output_sjf.csv`** (SJF non-preemptive results)

Output format:

```csv
PID,Arrival,Burst,Start,Completion,Waiting,Turnaround
...
```

---

## 7. Algorithms Summary

### FCFS (First Come First Served)

* Processes are executed in order of arrival time (non-preemptive).
* If the CPU becomes free before the next process arrives, the CPU stays **IDLE** until the next arrival time.

### SJF (Shortest Job First) — Non-preemptive

* At each decision point, select among **arrived and not completed** processes the one with the **smallest burst time**.
* If no process is ready, the CPU becomes **IDLE** until the next process arrives.

---

## 8. Testing & Proof

Correctness was verified by comparing program output with textbook examples.

Proof images:

* `assets/FCFS tested photo.jpg`
* `assets/SJF tested photo.jpg`

Gantt chart design concept:

* `assets/design,gantt.jpg`

Collaborators evidence:

* `assets/Colloborators.jpg`

Project report:

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

---
