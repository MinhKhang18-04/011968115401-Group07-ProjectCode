PROJECT README – CHECK PROGRESS

Course: Operating Systems
Project Title: CPU Scheduling Algorithms Demonstration
Algorithms: FCFS and SJF (Non-preemptive)

Group: OS_Group7
Submission: Check progress of project
--------------------------------------------------

1. Project Description
This project aims to build a C++ console application to demonstrate CPU scheduling algorithms, including:
- First Come First Served (FCFS)
- Shortest Job First (SJF) – Non-preemptive

The application reads process data from a CSV file, simulates CPU scheduling, displays basic results on the console, and will export detailed results and visualization in later stages.

--------------------------------------------------

2. Current Progress (at Check Progress stage)

Completed:
- Created GitHub repository and initialized project structure
- Designed CSV input format for process data
- Implemented FCFS scheduling algorithm (basic version)
- Program can read input from CSV file
- Display scheduling results on console
- Initial testing and verification with textbook examples

In Progress:
- Gantt chart visualization
- Output detailed result to CSV file

--------------------------------------------------

3. Input Format

Input file: input.csv

Format:
PID,Arrival,Burst

Example:
P1,0,5
P2,1,3
P3,2,8
P4,3,6

--------------------------------------------------

4. Output (Current)

- Console output:
  + Process table (PID, Arrival Time, Burst Time, Waiting Time, Turnaround Time)
  + Scheduling order

- Output CSV and full Gantt chart will be implemented in the next phase.

--------------------------------------------------

5. Group Members and Task Distribution

Member 1 (Leader):
- Create and manage GitHub repository
- Implement FCFS scheduling algorithm (initial version)

Member 2 (Developer):
- Implement SJF non-preemptive scheduling logic (in progress)
- Design CSV input format and sample input file

Member 3 (Tester):
- Test FCFS and SJF results
- Compare outputs with textbook examples and provide proof of correctness

Member 4 (Designer):
- Design console UI mockup
- Draft Gantt chart visualization concept for CPU scheduling

Member 5 (Writer):
- Collect GitHub links, commit history, and screenshots
- Write project progress report for submission

--------------------------------------------------

6. Next Plan
- Implement Gantt chart visualization
- Export detailed scheduling result to CSV file
- Conduct stress test and performance test
- Record demonstration video
- Write final report and presentation slides

--------------------------------------------------

End of README
