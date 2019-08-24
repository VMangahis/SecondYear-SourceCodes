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
	int total_headMovement = 0;
	int trackRequest[10];
	int seekTime = 0;
	cout << "Input location of R/W Head" << endl;
	cin >> pos;

	cout << "Input seek rate " << endl;
	cin >> seekTime;

	for(int input = 0; input < 8; input++)
	{
		cout << "Input track # " << input+1 << ": ";
		cin >> trackRequest[input];
	}

	for(int out = 0 ; out < 8 ; out++)
	{
		cout << trackRequest[out] << ", ";
	}

	// Calculation
	for(int cal = 0; cal < 8 ; cal ++)
    {
        if(cal == 0)
        {
            if(pos > trackRequest[cal])
            {
                total_headMovement+=(pos - trackRequest[cal]);
            }
            else{
                total_headMovement+=(trackRequest[cal]-pos);

            }
            continue;
        }
        if(trackRequest[cal-1]> trackRequest[cal])
            total_headMovement+=(trackRequest[cal-1]- trackRequest[cal]);

        else
            total_headMovement+=(trackRequest[cal] - trackRequest[cal-1]);
    }

    cout << "Total head movement: " << total_headMovement << endl;
    cout << "Seek Time " << seekTime * total_headMovement << " ms" << endl;
    cout << "Insert GUI";
    return 0;



}



