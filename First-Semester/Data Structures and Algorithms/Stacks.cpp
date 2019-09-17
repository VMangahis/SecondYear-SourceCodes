// Syntax Parsing through push and pop function(getline command)

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct Stack{

	char *cm;
	int size;
	bool correctSyntax = false;
	void push(string command)
	{
			size = command.length();
			cm = new char[size];
			for(int x = 0; x < command.length() ; x++)
			{
				cm[x] = command[x];
			}

	}


	void pop(){
		int counter = 0;
		char getString[] = {'g','e','t','l','i','n','e', '(','c','i','n',',' };

        if(cm[size-1] != ';' || cm[size-2] != ')')
        {
            correctSyntax = false;
            return;
        }


		for(int a = 0; a < 12; a++)
		{
                if(cm[a] != getString[a])
                {

                    correctSyntax = false;
                    return;

                }
        }

        correctSyntax = true;



	}











};



int main()
{
	Stack command;
	string com;
	cout << "Input getline commmand" << endl;
	getline( cin, com  );
	com.erase(remove(com.begin(),com.end(), ' '), com.end());
	command.push(com);
	command.pop();
	if(command.correctSyntax)
    {
        cout << "Valid Syntax" << endl;
    }
    else{
        cout << "Syntax Error " << endl;
    }

}


