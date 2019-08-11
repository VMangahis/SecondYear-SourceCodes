#include<iostream>


 using namespace std;
 
 struct student{

     string nameData;
     double grading;
     student *nextNode;

 };

 student  *first_entry = NULL;  // head 
 


 void pushData(string naming, double gr)
 {		
     student* newData = new student;  // allocate new node
     
     newData->grading   = gr; 
     newData->nameData = naming;

     //point to a blank 
     newData->nextNode = first_entry;
     
     first_entry = newData;
     


 }



 void printData(double limit, char res)
 {
        student* tempPointer = first_entry;
        if(toupper(res) == 'A')
        {
            while(tempPointer!=NULL  )
            {
            if( tempPointer->grading == limit)
                {
                cout << " " << tempPointer->nameData << "\t" <<  tempPointer->grading << endl;
                }
            tempPointer = tempPointer ->nextNode;
            }
        }

        else if(toupper(res) == 'B')
        {
            while(tempPointer!=NULL )
            {
                if( tempPointer->grading > limit)
                {
            cout << " " << tempPointer->nameData << "\t" <<  tempPointer->grading << endl;
            }
            tempPointer = tempPointer ->nextNode;
            }
        }

        else if(toupper(res) == 'C')
        {
            while(tempPointer!=NULL  )
            {
            if( tempPointer->grading < limit)
                {


            cout << " " << tempPointer->nameData << "\t" <<  tempPointer->grading << endl;
            }
            tempPointer = tempPointer ->nextNode;
            }
        }

        else if(toupper(res) == 'D')
        {
            while(tempPointer!=NULL)
            {
            cout << " " << tempPointer->nameData << "\t" <<  tempPointer->grading << endl;
            tempPointer = tempPointer ->nextNode;
            }
        }



 }





 int main()
 {
     int lim =0 ;
     char response='Y';
     char prompt = 'X';

     double grade = 0.0;
     string name = " ";


     while(toupper(response) == 'Y')
     {
            cout << "Input name" << endl;
            cin >> name;



            cout << "Input grade" << endl;
            cin >> grade;


            pushData(name, grade);
           



            cout << "More entry(Y/N)" << endl;
            cin >> response;
     }

     cout << endl;
    
	while(toupper(prompt) == 'X') 
	{
	
     cout << "Input your choice of displaying data(A- ==  , B - > , C - < , D - Display all data) " << endl;
 	cin >> prompt;


	

     switch(toupper(prompt))
     {
         case 'A':
         case 'B':
         case 'C':

            cout << "Input grade " << endl;
            cin >> lim;
            printData(lim , toupper(prompt));
            break;
         case 'D':
             printData(lim, toupper(prompt));
             break;
            
        default:
        	prompt = 'X';
        	break;

        
     }
     
     }
 }



