#pragma once
#include "process.h"

namespace CPU{
	int dispatchProcess();
	void runProcess();
	void scheduleProcess(process schedProc);
	bool noQueuedProcs();
	int getSysTime();
}
