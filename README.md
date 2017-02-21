# Round_Robin_CPU_scheduling_Simulation

This project is a simulation of the Round Robin CPU scheduling algorithm coded in c++. 

For more information on the Round Robin CPU scheduling algorithm see [Round Robin scheduling Algorithm Description.md](Round Robin scheduling Algorithm Description.md)


## Install and Run
### Github Extension for Visual Studio
In the "Team Explorer" window of Visual Studio, clone a copy of this repository to your local drive using the URL, https://github.com/munix24/Round_Robin_CPU_scheduling_Simulation.git. Open, build, and run the solution.

### Visual Studio (with c++ compatibility)
Clone or Download all project files to a local directory. Open the Solution in Visual Studio: "Round Robin CPU scheduling.sln". Build and run the solution.

### g++ compiler
Clone or Download all project files to a local directory. Compile reference cpp files using "g++ -c CPU.cpp process.cpp". Compile the whole project using "g++ main.cpp CPU.o process.o". Run the compiled executeable, "./a.out".


## Program
### Input
job.txt is the input file. Each line contains the number of the job, requesting time (millisecond since computer started) and duration (millisecond). For example:

1, 20, 50

means a job for CPU with number 1 is requested to run at 20ms since CPU started, and the duration of the job is 50ms.

### Output
Schedule job order similar to the following format:

$>Job 1, scheduled for 4ms

$>Job 2, scheduled for 3ms

$>Job 1, scheduled for 5ms

$>Job 3, scheduled for 5ms

$>Job 2, scheduled for 3ms, completed

$>job 1, scheduled for 2ms, completed

Because round robin is deterministic, you should see the same job scheduling result every time you run your code.

##Approach:
Global variables cpuSpeed and quantum are defined as milliseconds of how often CPU checks for new processes and milliseconds time each proc is allowed to run per context switch, respectively.

A process struct is defined as having an id, arrivalTime, cpuBurst, and runTime. The CPU namespace contains a queue of processes and all CPU methods such as dispatchProcess, runProcess, and scheduleProcess. 

1. While there are still unread lines in the input file and queued processes, call on CPU::scheduleProcess() to schedule arrived processes. 
2. If there are no more processes arrived, call CPU::runProcess() to "run" the next scheduled process. 
3. Increment sysTime by the set quantum as processes are ran. 
4. Repeat above 3 steps untill all processes in the input file have been fully completed.
