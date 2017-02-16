#include <iostream>	
#include <fstream>	//to read file
#include "CPU.h"

using namespace std;
using namespace CPU;

int main()
{
	process incProc;														//incoming Process
	char c;																	//temp var to store ',' from file

	ifstream inf("job.txt");
	if(inf.is_open()){
		inf >>incProc.id>>c>>incProc.arrivalTime>>c>>incProc.cpuBurst;		//pull next proc from file
		if(!inf.eof() && inf.fail())
			cout<<"check input values for errors"<<endl;
	} else
		cout<<"Couldn't open Dictionary file"<<endl;						//handle missing file
	
	//scenario where 1 incProc remains but the file is at eof and there are no queuedProcesses
	while(incProc.id!=-1 || !inf.eof() || !CPU::noQueuedProcs()){	//loop until all processes are ran
		//simulate a scheduler - look for incoming processes and queue if arrived
		while(incProc.id!=-1 && incProc.arrivalTime<=CPU::getSysTime()){
			CPU::scheduleProcess(incProc);
			incProc.id=-1;													//no new procs flag
			inf >>incProc.id>>c>>incProc.arrivalTime>>c>>incProc.cpuBurst;	//pull next proc from file
			if(!inf.eof() && inf.fail())
				cout<<"check input values for errors"<<endl;
		}
		CPU::runProcess();														//how long cpu runs
	}
	cin.get();																//pause - wait for user action
}