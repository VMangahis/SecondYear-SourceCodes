/*
 *
 * FCFS Scheduling Algo - Disk Sched
 *
 */

#include<iostream>

using namespace std;

int main()
{
	int pos = 0;
	int trackRequest[10];
	cout << "Input location of R/W Head" << endl;
	cin >> pos;

	for(int input = 0; input < 10; input++)
	{
		cout << "Input track # " << input+1 << ": ";
		cin >> trackRequest[input];
	}

	for(int out = 0 ; out < 10 ; out++)
	{
		cout << trackRequest[out] << ", ";
	}



}



