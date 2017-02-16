#include <iostream>	
#include <queue>		//queue to store scheduled processes
#include "CPU.h"
#include "process.h"
#include "globals.h"

using namespace std;

namespace CPU{
	std::queue<process> queuedProcesses;	//holds procs in wait
	int sysTime = 0;				//current "system" time in milliseconds

	//simulate cpu dispatcher
	int dispatchProcess(){	
		process runProc;
		runProc = queuedProcesses.front();					//dispatch next queued Process
		queuedProcesses.pop();
		runProc.run();

		//cout<<sysTime+execTime<<": Job " <<runProc.id<<", scheduled for " <<runProc.cpuBurst<<"ms, has ran for a total of "<<runProc.execTime<<"ms"<<endl;
		if(runProc.runTime==runProc.cpuBurst)				//if proc completed
			cout<<sysTime+runProc.execTime<<": Job " <<runProc.id<<", scheduled for " <<runProc.cpuBurst<<"ms, completed"<<endl;
		else
			queuedProcesses.push(runProc);					//if proc did not complete push to back of queue
		return runProc.execTime;							//increment sysTime by how long the process ran
	}

	void runProcess(){
		int execTime;						//how long CPU runs
		if(!queuedProcesses.empty()){
			execTime=dispatchProcess();
		}
		else{
			execTime=cpuSpeed;				//move forward and wait for new processes
		}
		sysTime+=execTime;					//increment "system" time
	}

	void scheduleProcess(process schedProc){
		cout<<sysTime<<": Job " <<schedProc.id<<", scheduled for " <<schedProc.cpuBurst<<"ms"<<endl;
		queuedProcesses.push(schedProc);	//queue proc
	}

	bool noQueuedProcs(){
		return queuedProcesses.empty();
	}
	
	int getSysTime(){
		return sysTime;
	}
}

