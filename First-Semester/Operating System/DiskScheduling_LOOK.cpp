/*
 *
 * LOOK Scheduling Algo - Disk Sched (Barely different code niya sa SCAN)
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
            if(pos < prevPos)                                       // If downward direction then sort in ascending order
            {
                if(trackRequest[mv_a] > trackRequest[mv_a+1])
                {
                    tempValue=trackRequest[mv_a];
                    trackRequest[mv_a] = trackRequest[mv_a+1];
                    trackRequest[mv_a+1]= tempValue;
                }

            }
            else{
                if(trackRequest[mv_a] < trackRequest[mv_a+1])      // If upward direction then sort in descending order
                {
                    tempValue=trackRequest[mv_a];
                    trackRequest[mv_a] = trackRequest[mv_a+1];
                    trackRequest[mv_a+1]= tempValue;
                }
            }

        }
    }


        while(counter < diskReq)                                    // Loop that will count on until what index will be bubble sorted later
        {
            if(pos < prevPos)                                       // downward direction
            {
                if(trackRequest[counter] < pos)
                {
                sweep_a++;
                }

            }

            else{                                                   //upward direction
                if(trackRequest[counter] > pos)
                {
                    sweep_a++;
                }
            }

            counter++;
        }

        for(int firstSweep = 0 ; firstSweep < sweep_a-1; firstSweep++ )                 // sweep_a - for the limit on until what index will only be sorted.
        {
            for(int firstSweep_a = 0; firstSweep_a < sweep_a -firstSweep - 1; firstSweep_a++)
            {
                if(pos < prevPos)                                                       // if downward direction, then sort in descending order
                {
                         if(trackRequest[firstSweep_a] < trackRequest[firstSweep_a+1])
                    {
                    tempValue = trackRequest[firstSweep_a];
                    trackRequest[firstSweep_a] = trackRequest[firstSweep_a+1];
                    trackRequest[firstSweep_a+1] = tempValue;
                    }

                }

                else{                                                                   // if upward direction, then sort in ascending order
                     if(trackRequest[firstSweep_a] > trackRequest[firstSweep_a+1])
                    {
                    tempValue = trackRequest[firstSweep_a];
                    trackRequest[firstSweep_a] = trackRequest[firstSweep_a+1];
                    trackRequest[firstSweep_a+1] = tempValue;
                    }
                }


            }
            firstSweepEnd++;                                                           // firstSweepEnd for indicating at what index will the next sorting start after sorting in ascending or desc order
        }
        for(int up =  firstSweepEnd; up < diskReq - 1  ; up++ )
        {
            for(int up_a = firstSweepEnd; up_a < diskReq- up-1 ;up_a++)
            {
                if(pos< prevPos)
                {
                    if(trackRequest[up_a] > trackRequest[up_a+1])                      // (Downward direction)after sorting in descending order, then sort in ascending order starting from index "firstSweepEnd"
                    {
                    tempValue = trackRequest[up_a];
                    trackRequest[up_a] = trackRequest[up_a+1];
                    trackRequest[up_a+1] = tempValue;
                    }

                }

                else{
                    if(trackRequest[up_a] < trackRequest[up_a+1])                       // (upward direction) after sorting in ascending order, then sort in descending order
                    {
                    tempValue = trackRequest[up_a];
                    trackRequest[up_a] = trackRequest[up_a+1];
                    trackRequest[up_a+1] = tempValue;
                    }
                }



            }
        }
        if(pos< prevPos)                                    //thm calculation in downward direction
        total_headMovement = pos + trackRequest[diskReq-1];

        else                                                // thm calc in upward direction
        total_headMovement = (199 - pos) + (199 - trackRequest[diskReq-1]);

    for(int print = 0; print < diskReq ; print++)
    {
        cout << trackRequest[print] << ", ";

    }

    cout << "Total head movement: " << total_headMovement << endl;
    cout << "Seek Time " << seekTime * total_headMovement << " ms" << endl;
    cout << "Insert GUI";
    return 0;
}








