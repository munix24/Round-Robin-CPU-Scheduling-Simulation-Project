#pragma once

struct process {
	int id;
	int arrivalTime;
	int cpuBurst;
	int runTime;
	int execTime;

	//constructor
	process();

	void run();
};