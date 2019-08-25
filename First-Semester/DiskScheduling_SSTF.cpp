/*
 *
 * FCFS Scheduling Algo - Disk Sched
 *
 */

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int pos = 0;
	int total_headMovement = 0;
	int tempValue = 0;
	int tempSwap = 0;
	int counter = 0;
	int index = 0;
	int lowestRequestTime = 0;
	int diskReq = 0;
	int seekTime = 0;
	int *trackRequest;

	cout << "Input number of disk request" << endl;
	cin >> diskReq;

	trackRequest = new int[diskReq];

	cout << "Input location of R/W Head" << endl;
	cin >> pos;

	cout << "Input seek rate " << endl;
	cin >> seekTime;

	for(int input = 0; input < diskReq; input++)
	{
		cout << "Input track # " << input+1 << ": ";
		cin >> trackRequest[input];
	}

	for(int swp = 0; swp < diskReq ; swp++)
    {
        if(swp == 0)
        {
            tempValue = trackRequest[swp];
            lowestRequestTime = abs(pos-trackRequest[swp]);
            while(counter < diskReq)
            {
                if(lowestRequestTime > abs(pos-trackRequest[counter+1]))
                {
                        lowestRequestTime = abs(trackRequest[counter+1]-pos);
                        index = counter+1;

                }



                counter++;
            }
            trackRequest[swp] = trackRequest[index];
            trackRequest[index] = tempValue;
        }

       else{
            tempValue = trackRequest[swp];
            index = swp;
            counter = swp;
            lowestRequestTime = abs(trackRequest[swp-1]-trackRequest[swp]);

            while(counter < diskReq)
            {
                if(lowestRequestTime > abs(trackRequest[swp-1]- trackRequest[counter]))
                {

                    lowestRequestTime = abs(trackRequest[swp-1]-trackRequest[counter]);
                    index = counter;
                }
                counter++;
            }
            trackRequest[swp] = trackRequest[index];
            trackRequest[index] = tempValue;
        }


    }

	for(int out = 0 ; out < diskReq ; out++)
	{
		cout << trackRequest[out] << ", ";
	}

	// Calculation
	for(int cal = 0; cal < diskReq ; cal ++)
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
    cout << "Seek Time : " << seekTime * total_headMovement << endl;
    return 0;



}


