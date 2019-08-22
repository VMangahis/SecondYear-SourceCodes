/*
 *
 * SCAN Scheduling Algo - Disk Sched
 *
 */

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int pos = 0;
	int prevPos = 0;
	int tempValue = 0;
	int total_headMovement = 0;
	int trackRequest[8];
	int seekTime = 0;
	int index = 0;
	int indexCounter = 0;
	int fastestReqTime = 0;

	cout << "Input current location of R/W Head" << endl;
	cin >> pos;

	cout << "Input previous location of R/W Head" << endl;
	cin >> prevPos;

	cout << "Input seek rate " << endl;
	cin >> seekTime;

	for(int input = 0; input < 8; input++)
	{
		cout << "Input track # " << input+1 << ": ";
		cin >> trackRequest[input];
	}
    for(int mov = 0 ;mov < 8 ; mov++)
    {
        if(pos< prevPos)
        {
            if(mov == 0)
            {
                tempValue = trackRequest[mov];
                fastestReqTime = abs(pos-trackRequest[mov]);
                while(indexCounter <8 )
                {
                    if(fastestReqTime < abs(pos- trackRequest[indexCounter+1]) && pos < trackRequest[indexCounter+1])
                    {
                        fastestReqTime =abs(pos- trackRequest[indexCounter+1]) ;
                        index = indexCounter;
                    }
                }
                trackRequest[mov] = trackRequest[index];
                trackRequest[index] = tempValue;
            }
            else{

            }
        }
    }






    for(int print = 0; print < 8 ; print++)
    {
        cout << trackRequest[print] << ", ";
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



