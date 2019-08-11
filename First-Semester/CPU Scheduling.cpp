// Program by Vince Baron Mangahis and Raphael Christopher Redondo (BSIT 2-1)

#include<iostream>
using namespace std;

int main()
{
    int cols = 9;
    int row = 5;
    int temp = 0;

    string header ="";

    int counter = 0;
    int arraycounter = 0;
    int response=0;

    int final_time = 0;

    int idle = 0;
    int idle_counter= 0  ;

    int average_wt = 0;
    int average_bt = 0;
    int average_tt = 0 ;
    int average_at = 0;


    int temp_var = 0;

    cout << "Choose your CPU Scheduling Policy(1- FCFS\t2- SJF\t\t3- Priority)" << endl;
    cin >> response;
    while(cin.fail()|| response < 1 || response > 3)
    {
    	cin.clear();
    	cin.ignore(512,'\n');
    	cout << "Invalid Input. Please try again." << endl;
    	 cout << "Choose your CPU Scheduling(1- FCFS\t2- SJF\t\t3- Priority )" << endl;
    	 cin>> response;
	}
	switch(response)
	{
		case 1:
			header = "First Come, First Serve Scheduling";
			break;

		case 2:
			header = "Shortest Job First Scheduling";
			break;

		case 3:
			header = "Priority Scheduling";
			break;
	}


  	cout  << header   <<endl;
	cout << "--------------------------------------------------------------------------------" << endl;
    cout << "Input number of processes" << endl;
    cin >> row;

    while(cin.fail())
            {
                cin.clear();
                cin.ignore(512, '\n');
                cout << "Input error " << endl;
                cout << "Input number of processes" << endl;
                cin >> row;
            }

    while(row>10 || row <= 0)
    {
        cout << "Processes cannot be more than 10 or less than 1. Please input another value." << endl;
        cin >> row;
        while(cin.fail())
            {
                cin.clear();
                cin.ignore(512, '\n');
                cout << "Input error " << endl;
                cout << "Input number of processes" << endl;
                cin >> row;
            }
    }
    /*  Indexes~
    *	0 - PID
    *	1 - Arv Time
    *	2 - Burst Time
    *	3 - Waiting Time
    *	4 - Turnaround Time
    *	5 - End Time
    *	6 - Start Time
    *	7 - Idle Time
    *	8 - Priority (conditional)
    *
    */

    int cpuTime[row][cols] = {{0,0,0,0,0,0,0,0,0}};

    cout << endl;
    cout << "==============================" << endl;
    cout << "Arrival Time" << endl;
    cout << "Input arrival time of process of: " << endl;
    for(int input = 0 ; input < row ; input++)
    {


            cpuTime[input][0] = input+1;

             cout << " Process "  << cpuTime[input][0] << ":";
            cin >> cpuTime[input][1];

            while(!cin)
            {
                cin.clear();
                cin.ignore(512, '\n');
                cout << "Input error" << endl;
                cout << "Input arrival time of process of " << " Process "  << cpuTime[input][0]  << endl;
                cin >> cpuTime[input][1];
            }
            cout << endl;
    }

    cout << endl;
    cout << "==============================" << endl;
    cout << "Burst Time" << endl;
    cout << "Input the burst time of:" << endl;
    for(int secondinput = 0 ; secondinput < row; secondinput++)
    {

            cout  << " Process " << cpuTime[secondinput][0] << ":";
            cin >> cpuTime[secondinput][2];

            while(!cin)
            {
                cin.clear();
                cin.ignore(512, '\n');
                cout << "Input error" << endl;
                cout << "Input the burst time  " << endl;
                cin >> cpuTime[secondinput][2];
            }
            cout << endl;

	}

	if(response == 3)
	{
	     cout << "==============================" << endl;
        cout << "Priority" << endl;
		for(int prio = 0 ; prio < row ; prio++)
		{
			cout << "Input Priority level of Process " << cpuTime[prio][0] << ":";
			cin >> cpuTime[prio][8];
			cout << endl;
		}
	}




    for(int sortvar = 0 ; sortvar < row - 1 ; sortvar++)
    {
        for(int sort2 = 0; sort2 < row-sortvar-1 ; sort2++)
        {
            if(cpuTime[sort2][1] > cpuTime[sort2+1][1])        // according to arrival time
            {
                temp_var = cpuTime[sort2][0];
                cpuTime[sort2][0] = cpuTime[sort2+1][0];            // Process Number Swap
                cpuTime[sort2+1][0] = temp_var;

                temp_var = cpuTime[sort2][1];
                cpuTime[sort2][1] = cpuTime[sort2+1][1];            // Arrival Time Swap
                cpuTime[sort2+1][1] =  temp_var;

                temp_var = cpuTime[sort2][2];
                 cpuTime[sort2][2] =  cpuTime[sort2+1][2];          // Burst Time Swap
                 cpuTime[sort2+1][2] = temp_var;

                 temp_var = cpuTime[sort2][8];
                 cpuTime[sort2][8]= cpuTime[sort2+1][8];
                 cpuTime[sort2+1][8] = temp_var;

            }
        }
    }


    cout << "Sorted(Acc. Arrival Time)" << endl;
    cout << "==============================" << endl;
    cout << "Process\t" << "Arrival Time\t"  << "Burst Time\t";
	cout << endl;
    for(int print = 0; print < row ; print++)
    {
        cout << cpuTime[print][0] << "\t" << cpuTime[print][1] << "\t\t\t" << cpuTime[print][2] << "\t";
		cout << endl;
    }



    if(response == 2) 								// if user chooses SJF
    {

    	for(int sortvar = 0; sortvar < row - 1; sortvar++)	// starts with the first index cause the first process would already be the lowest arrival time
    	{
    		for(int sort2 = 1; sort2< row-sortvar-1; sort2++)
    		{
    			if(cpuTime[sort2][2]> cpuTime[sort2+1][2])
    			{
    				 temp_var = cpuTime[sort2][0];
                cpuTime[sort2][0] = cpuTime[sort2+1][0];            // Process Number Swap
                cpuTime[sort2+1][0] = temp_var;

                temp_var = cpuTime[sort2][1];
                cpuTime[sort2][1] = cpuTime[sort2+1][1];            // Arrival Time Swap
                cpuTime[sort2+1][1] =  temp_var;

                temp_var = cpuTime[sort2][2];
                 cpuTime[sort2][2] =  cpuTime[sort2+1][2];          // Burst Time Swap
                 cpuTime[sort2+1][2] = temp_var;


				}
			}
		}



	cout << "Sorted(Acc. Burst Time)" << endl;
    cout << "==============================" << endl;
    cout << "Process\t" << "Arrival Time\t"  << "Burst Time\t" << endl;

		for(int print = 0 ; print < row; print++)
		{
			cout << cpuTime[print][0] << "\t" << cpuTime[print][1] << "\t\t\t" << cpuTime[print][2] << endl;
		}
	}

	   if(response == 3) // Fixed proper Prio scheduling within a given end time
    {
        if(cpuTime[0][1] > 0)
        {
            cpuTime[0][7] = cpuTime[0][1];
        }
        cpuTime[0][6] = cpuTime[0][1];
        cpuTime[0][5] = cpuTime[0][1] + cpuTime[0][2];

        for(int cal = 1 ; cal < row ; cal++)
        {
            if(cpuTime[cal-1][5] >= cpuTime[cal][1])
            {
                for(int mov = cal+1; mov < row ; mov++)
                {
                    if(cpuTime[cal][8] > cpuTime[mov][8] && cpuTime[mov][1] < cpuTime[cal-1][5])
                    {
                        temp = cpuTime[cal][0];
                        cpuTime[cal][0] = cpuTime[mov][0];
                        cpuTime[mov][0] = temp;

                        temp = cpuTime[cal][1];
                        cpuTime[cal][1] = cpuTime[mov][1];
                        cpuTime[mov][1] = temp;

                        temp = cpuTime[cal][2];
                        cpuTime[cal][2] = cpuTime[mov][2];
                        cpuTime[mov][2] = temp;

                        temp = cpuTime[cal][8];
                        cpuTime[cal][8] = cpuTime[mov][8];
                        cpuTime[mov][8] = temp;
                    }
                }
                cpuTime[cal][6] = cpuTime[cal-1][5];
            }
            else{
                cpuTime[cal][6] = cpuTime[cal][1];
                cpuTime[cal][7] = cpuTime[cal][1]- cpuTime[cal-1][5];
            }


                cpuTime[cal][5] = cpuTime[cal][6] + cpuTime[cal][2];
                cpuTime[cal][3] = cpuTime[cal][6] - cpuTime[cal][1];
                cpuTime[cal][4] = cpuTime[cal][5] - cpuTime[cal][1];




        }
        cout << "Sorted (Acc. Priority Level and Presented in Gantt Chart)" << endl;
        cout << "==============================" << endl;
        cout << "Process\t" << "Arrival Time\t"  << "Burst Time\t" << endl;
        for(int print =0 ; print < row; print++)
        {
            cout << cpuTime[print][0] << "\t\t" << cpuTime[print][1] << "\t\t\t" << cpuTime[print][2] << "\t\t" << cpuTime[print][8] << endl;
        }
    }

	/*  Indexes~
    *	0 - PID
    *	1 - Arv Time
    *	2 - Burst Time
    *	3 - Waiting Time
    *	4 - Turnaround Time
    *	5 - End Time
    *	6 - Start Time
    *	7 - Idle Time
    *	8 - Priority (conditional)
    *
    */




	for(int cal = 0; cal < row; cal++)  		//Getting the start time, end time, waiting time, turnaround time of each process
    {
        if(cal == 0)
        {
                cpuTime[cal][6] = cpuTime[cal][1]; // start time would be the arrival time of first proc
                if(cpuTime[cal][1]>0)
                {
                    cpuTime[cal][7] = cpuTime[cal][1];

                }
                cpuTime[cal][5] = cpuTime[cal][1] + cpuTime[cal][2]; // et = at + bt
                cpuTime[cal][3] = cpuTime[cal][6] - cpuTime[cal][1]; // wt = st - at
                cpuTime[cal][4] = cpuTime[cal][5] - cpuTime[cal][1]; // tt = et - at
                average_at+= cpuTime[cal][1];
                average_bt+= cpuTime[cal][2];
                average_wt+= cpuTime[cal][3];
                average_tt+= cpuTime[cal][4];

                continue;
        }

        if(cpuTime[cal][1] - cpuTime[cal-1][5] > 0) // if curr arv time - previous end time > 0 then implement idle time
        {

            cpuTime[cal][7] = cpuTime[cal][1] - cpuTime[cal-1][5];
            cpuTime[cal][6] = cpuTime[cal][1];
        }

        else{
            cpuTime[cal][6] = cpuTime[cal-1][5];
        }
        cpuTime[cal][5] = cpuTime[cal][6] + cpuTime[cal][2]; // et = at + bt
        cpuTime[cal][3] = cpuTime[cal][6] - cpuTime[cal][1]; // wt = st - at
        cpuTime[cal][4] = cpuTime[cal][5] - cpuTime[cal][1];
        average_at+= cpuTime[cal][1];
        average_bt+= cpuTime[cal][2];
        average_wt+= cpuTime[cal][3];
        average_tt+= cpuTime[cal][4];
        if(cal == row - 1)
        {
            final_time = cpuTime[cal][5];
        }

    }






    average_at/=row;
    average_bt/= row;
    average_wt/= row;
    average_tt/= row;
    cout << endl << endl << endl;

    cout << "With Calculated Waiting Time and Turn Around Time" << endl;
    cout << "+---------------------------------------------------------------------------+" << endl;
    cout << "PID\t" << "Arrival Time\t" << "Burst Time\t" << "Waiting Time\t" << "Turn Around Time\t";

	cout << endl;
    for(int print = 0 ; print < row ; print++)
    {
        cout << cpuTime[print][0] << "\t     " << cpuTime[print][1] << "\t\t " << cpuTime[print][2] << "\t\t\t" << cpuTime[print][3] << "\t\t"<< cpuTime[print][4] << "\t\t\t";
		cout << endl;
    }
    cout << "+---------------------------------------------------------------------------+" << endl;
    cout << "Type of Scheduling: " << header << endl;
    cout << "Total Number of Process/es: " << row << endl;
    cout << "Average Arrival Time: " << average_at << endl;
    cout << "Average Waiting Time: " << average_wt << endl;
    cout << "Average Burst Time: " << average_bt << endl;
    cout << "Average Turnaround Time: " << average_tt << endl;
    cout << "Process Endtime: " << final_time << endl;

    /*  Indexes~
    *	0 - PID
    *	1 - Arv Time
    *	2 - Burst Time
    *	3 - Waiting Time
    *	4 - Turnaround Time
    *	5 - End Time
    *	6 - Start Time
    *	7 - Idle Time
    *	8 - Priority (conditional)
    *
    */






	cout << "-----------------------------------------------------------------------------" << endl;
	cout<< "\t\t\t\tGantt Chart" << endl;



                                                                                // Gantt Chart Start
     for(int a = 0 ; a < 78; a++)
    {
    	cout << "-";
	}
	cout << endl;
	cout << "|";
	for(int a = 0; a <row ; a++)
    {

        if(cpuTime[a][7] > 0 )
        {
            cout << "I";

        }
        cout << "|";
        for(int spaces = 0 ; spaces < cpuTime[a][2]; spaces++)
        {
            if(spaces == 5)
            {
                break;
            }
            cout << " ";
        }
        cout <<"P"<< cpuTime[a][0];
        for(int space = 0 ; space < cpuTime[a][2]; space ++)
        {
            if(space == 5)
            {
                break;
            }
            cout << " ";
        }
        cout << "|";
    }
    cout << endl;



	for(int a = 0 ; a < 78; a++)
    {
    	cout << "-";
	}                                                                       // Gantt Chart End


    cout << endl;
	idle_counter = 0;

                                                                            // Label below gantt chart start
	cout << "0 ";
    for(int k = 0; k < row ; k ++)
    {
        if(cpuTime[k][7] > 0)
        {
            cout << " ";
        }
        if(cpuTime[k-1][5] == cpuTime[k][6])
        {
            cout << " ";
        }
        else{
            cout << cpuTime[k][6];
        }
        for(int a = 0 ; a< cpuTime[k][2]*2 ; a++)
        {

            cout << " ";
            if(a == 9)
            break;
        }
        cout << cpuTime[k][5] << " ";
    }


	cout << endl;
	cout << endl;

                                                                            //label below gantt chart end

	while(idle < row-1)
	{
		if(idle == 0)
		{
			cout << "Idle time before Process " << cpuTime[idle][0]  << " starts: " << cpuTime[idle_counter][7] << " ms" << endl;
			idle_counter++;
		}

		cout << "Idle time between Process " << cpuTime[idle][0] << " and " << cpuTime[idle+1][0] << " is: " << cpuTime[idle_counter][7] << " ms" << endl;
		idle++;
		idle_counter++;
		}

     for(int sortvar = 0 ; sortvar < row - 1 ; sortvar++)
    {
        for(int sort2 = 0; sort2 < row-sortvar-1 ; sort2++)
        {
            if(cpuTime[sort2][0] > cpuTime[sort2+1][0])        // according to arrival time
            {
                temp_var = cpuTime[sort2][0];
                cpuTime[sort2][0] = cpuTime[sort2+1][0];            // Process Number Swap
                cpuTime[sort2+1][0] = temp_var;

                temp_var = cpuTime[sort2][1];
                cpuTime[sort2][1] = cpuTime[sort2+1][1];            // Arrival Time Swap
                cpuTime[sort2+1][1] =  temp_var;

                temp_var = cpuTime[sort2][2];
                 cpuTime[sort2][2] =  cpuTime[sort2+1][2];          // Burst Time Swap
                 cpuTime[sort2+1][2] = temp_var;

                 temp_var = cpuTime[sort2][3];
                 cpuTime[sort2][3]= cpuTime[sort2+1][3];
                 cpuTime[sort2+1][3] = temp_var;

                 temp_var = cpuTime[sort2][4];
                 cpuTime[sort2][4]= cpuTime[sort2+1][4];
                 cpuTime[sort2+1][4] = temp_var;

            }
        }
    }
    cout << endl;
    cout << "+---------------------------------------------------------------------------+" << endl;
    cout << "Process ID Sorted With Calculated Waiting Time and Turn Around Time" << endl;
    cout << "+---------------------------------------------------------------------------+" << endl;
    cout << "PID\t" << "Arrival Time\t" << "Burst Time\t" << "Waiting Time\t" << "Turn Around Time\t";

	cout << endl;
    for(int print = 0 ; print < row ; print++)
    {
        cout << cpuTime[print][0] << "\t     " << cpuTime[print][1] << "\t\t " << cpuTime[print][2] << "\t\t\t" << cpuTime[print][3] << "\t\t"<< cpuTime[print][4] << "\t\t\t";

		cout << endl;
    }
    cout << "+---------------------------------------------------------------------------+" << endl;
}
