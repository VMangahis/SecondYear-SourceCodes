/*
 *
 * SCAN Scheduling Algo - Disk Sched
 *
 */

#include<iostream>
using namespace std;

int main()
{
	int pos = 0;
	int prevPos = 0;
	int tempValue = 0;
	int total_headMovement = 0;
    int sweep_a = 0;
    int firstSweepEnd = 0;
    int upSweepstart = 0;
	int *trackRequest;
	int seekTime = 0;
	int counter =0 ;
	int diskReq = 0;

	cout << "Input number of disk request " << endl;
	cin >> diskReq;

	trackRequest = new int[diskReq];

	cout << "Input current location of R/W Head" << endl;
	cin >> pos;

	cout << "Input previous location of R/W Head" << endl;
	cin >> prevPos;

	cout << "Input seek rate " << endl;
	cin >> seekTime;

	for(int input = 0; input < diskReq; input++)
	{
		cout << "Input track # " << input+1 << ": ";
		cin >> trackRequest[input];
	}

	    for(int mv = 0 ; mv < diskReq-1 ; mv++)
    {
        for(int mv_a = 0 ; mv_a < diskReq - mv - 1; mv_a++)
        {
            if(pos < prevPos)
            {
                if(trackRequest[mv_a] > trackRequest[mv_a+1])
                {
                    tempValue=trackRequest[mv_a];
                    trackRequest[mv_a] = trackRequest[mv_a+1];
                    trackRequest[mv_a+1]= tempValue;
                }

            }
            else{
                if(trackRequest[mv_a] < trackRequest[mv_a+1])
                {
                    tempValue=trackRequest[mv_a];
                    trackRequest[mv_a] = trackRequest[mv_a+1];
                    trackRequest[mv_a+1]= tempValue;
                }
            }

        }
    }

        // downward direction
        while(counter < diskReq)
        {
            if(pos < prevPos)
            {
                if(trackRequest[counter] < pos)
                {
                sweep_a++;
                }

            }

            else{
                if(trackRequest[counter] > pos)
                {
                    sweep_a++;
                }
            }

            counter++;
        }

        for(int firstSweep = 0 ; firstSweep < sweep_a-1; firstSweep++ )
        {
            for(int firstSweep_a = 0; firstSweep_a < sweep_a -firstSweep - 1; firstSweep_a++)
            {
                if(pos < prevPos)
                {
                         if(trackRequest[firstSweep_a] < trackRequest[firstSweep_a+1])
                    {
                    tempValue = trackRequest[firstSweep_a];
                    trackRequest[firstSweep_a] = trackRequest[firstSweep_a+1];
                    trackRequest[firstSweep_a+1] = tempValue;
                    }

                }

                else{
                     if(trackRequest[firstSweep_a] > trackRequest[firstSweep_a+1])
                    {
                    tempValue = trackRequest[firstSweep_a];
                    trackRequest[firstSweep_a] = trackRequest[firstSweep_a+1];
                    trackRequest[firstSweep_a+1] = tempValue;
                    }
                }


            }
            firstSweepEnd++;
        }
        for(int up =  firstSweepEnd; up < diskReq - 1  ; up++ )
        {
            for(int up_a = firstSweepEnd; up_a < diskReq- up-1 ;up_a++)
            {
                if(pos< prevPos)
                {
                    if(trackRequest[up_a] > trackRequest[up_a+1])
                    {
                    tempValue = trackRequest[up_a];
                    trackRequest[up_a] = trackRequest[up_a+1];
                    trackRequest[up_a+1] = tempValue;
                    }

                }

                else{
                    if(trackRequest[up_a] < trackRequest[up_a+1])
                    {
                    tempValue = trackRequest[up_a];
                    trackRequest[up_a] = trackRequest[up_a+1];
                    trackRequest[up_a+1] = tempValue;
                    }
                }



            }
        }
        if(pos< prevPos)
        total_headMovement = pos + trackRequest[diskReq-1];

        else
        total_headMovement = (199 - pos) + (199 - trackRequest[diskReq-1]);

    for(int print = 0; print < diskReq ; print++)
    {
        cout << trackRequest[print] << ", ";
        if(pos < prevPos)
        {
            if(trackRequest[print] < trackRequest[print+1] && trackRequest[print] < pos)
            {
                cout << " 0 ";
            }
        }
        else{
            if(trackRequest[print] > trackRequest[print+1] && trackRequest[print] > pos)
            {
                cout << " 199 ";
            }
        }

    }

    cout << "Total head movement: " << total_headMovement << endl;
    cout << "Seek Time " << seekTime * total_headMovement << " ms" << endl;
    cout << "Insert GUI";
    return 0;
}



