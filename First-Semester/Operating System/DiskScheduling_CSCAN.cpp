/*
 *
 * CSCAN Scheduling Algo - Disk Sched
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
	int *trackRequest;
	int *lessCurr;
	int *moreCurr;
	int higherCurr = 0;
	int lowerCurr = 0;
	int seekTime = 0;
	int counter =0 ;
	int alpha = 5;
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
	
	cout << "Input alpha value" << endl;
	cin >> alpha;

	for(int input = 0; input < diskReq; input++)
	{
		cout << "Input track # " << input+1 << ": ";
		cin >> trackRequest[input];
		if(trackRequest[input] > pos)
		{
			higherCurr++;
		}
		else{
			lowerCurr++;
		}
		
	}
	
	
		lessCurr = new int[lowerCurr+1];
		moreCurr = new int[higherCurr+1];
	

	
	for(int a = 0; a <diskReq; a++)
	{
		if(trackRequest[a] < pos)
		{
			lessCurr[counter] = trackRequest[a];
			counter++;
			
		}
		if(a == diskReq-1)
		{
			lessCurr[counter] = 0;
		}
		
	}
	
	counter = 0;
	
	for(int b= 0 ; b< diskReq; b++)
	{
		if(trackRequest[b] >= pos)
		{
			moreCurr[counter] = trackRequest[b];
			counter++;
		}
		
		if(b == diskReq -1)
		{
			moreCurr[counter] = 199;
			
		}
		
	}

	
	
	cout << "Separted" << endl;
	for(int a  = 0; a < lowerCurr+1; a++)
	{
		cout << lessCurr[a] << ',';
	}
	cout << " B" << endl;
	for(int b= 0 ; b < higherCurr+1; b++)
	{
		cout << moreCurr[b ] << ',';
	}
	cout << endl;
	
	for(int a = 0; a < diskReq  ; a++)
	{
		for(int b = 0; b < diskReq - a  ; b++)
		{
			
				if(b<higherCurr)
				if(moreCurr[b] > moreCurr[b+1])
				{
					tempValue = moreCurr[b];
					moreCurr[b] = moreCurr[b+1];
					moreCurr[b+1]= tempValue;
				}
				
				if(b<lowerCurr)
				if(lessCurr[b] <  lessCurr[b+1])
				{
					tempValue = lessCurr[b];
					lessCurr[b] = lessCurr[b+1];
					lessCurr[b+1] = tempValue;
				}
			
			
		}
	}

	    

    if(pos < prevPos)   //downward
    {
    	for(int a = 0; a < lowerCurr+1 ; a++ )
    	{
    		if(a == 0)
    		{
    			cout << pos << ", ";
			}
    		cout << lessCurr[a] << ", ";
		}
		
		
		
		for(int b = 0; b < higherCurr+1 ; b++)
		{
			cout << moreCurr[b]  << ", ";
		}
	}
	
	else
	{
			for(int a = 0; a < higherCurr+1 ; a++ )
    	{
    		if(a == 0)
    		{
    			cout << pos << ",";
			}
    		cout << moreCurr[a] << ", ";
		}
		
		cout << alpha << ", ";
		
		for(int b = 0; b < lowerCurr+1 ; b++)
		{
			cout << lessCurr[b]  << ", ";
		}
	}
	
	total_headMovement += alpha;
	if(pos < prevPos)
	{
		total_headMovement += pos;
		total_headMovement += (199 - moreCurr[0]);
	}
	else{
		total_headMovement += (199 - pos);
		total_headMovement += lessCurr[lowerCurr];
	}
	
    cout << "Total head movement: " << total_headMovement << endl;
    cout << "Seek Time " << seekTime * total_headMovement << " ms" << endl;
    cout << "Insert GUI";
    return 0;
}



