#pragma once
#include "process.h"

namespace CPU{
	//std::queue<process> queuedProcesses;	//holds procs in wait
	//int sysTime=0;				//current "system" time in milliseconds

	int dispatchProcess();
	void runProcess();
	void scheduleProcess(process schedProc);
	bool noQueuedProcs();
	int getSysTime();
}