#include "globals.h"
#include "process.h"

//constructor define
process::process()
{
	id=0;
	arrivalTime=0;
	cpuBurst=0;
	runTime=0;
}

void process::run()
{
	//if running causes it to complete otherwise run for quantum
	if(runTime+quantum>cpuBurst){
		runTime= cpuBurst;			//set to complete
		execTime=cpuBurst-runTime;	//time ran	
	}
	else{
		runTime+=quantum;			//increment by quantum
		execTime=quantum;			//time ran	
	}
}