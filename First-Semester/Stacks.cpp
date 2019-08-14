#include<iostream>
#include<string>
using namespace std;

struct Stack{
	
	char cm[150];
	int size;
	void push(string command)
	{
			size = command.length();
				char getString[] = {'g','e','t','l','i','n','e', '(','c','i','n',',' };
			for(int x = 0; x < command.length() ; x++)
			{
				if(command[x] == ' ')
				{
					cm[x] = getString[x];
				}
				cm[x] = command[x];
			}
		
	}	
	
	
	void pop(){
		int counter = 0;
		char getString[] = {'g','e','t','l','i','n','e', '(','c','i','n',',' };
	
		for(int a = 0; a < size; a++)
		{
			if(cm[a] != getString[counter] && counter < 12)
			{
				if(cm[a] == ' ')
				{
					cm[a] = getString[counter];
					counter=0;
					a=-1;
					if(counter < 0)
					{
						counter = 0;
					}
					continue;
					
				}
				
				
				
				
				else{
					cout << "Syntax Error" << endl;
					break;
					}
			}
			
			
			

			
			
			
			
			if(a== size-1 && cm[a] == ';'){
				cout << "Correct Syntax" << endl;
				break;
			}
			
			counter++;
		}
			
			
			
			
		}
	
};



int main()
{
	Stack command;
	string com;
	cout << "Input getline commmand" << endl;
	getline( cin, com  );
	command.push(com);
	command.pop();
	
	
	
	
	
	/*
	getline(cin, com);
	command.push(com);
	
	
	//push(command);
	push(command);
	pop(command);*/
	
}


