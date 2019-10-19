// Syntax Parsing through push and pop function(getline command)

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/*struct Stack{

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











};*/



int main()
{
	//Stack command;
	
	
	string com;
	string correct = "getline(cin,";
	cout << "Input getline commmand" << endl;
	getline(cin, com);
	com.erase(remove(com.begin(),com.end(), ' '), com.end());
	
	if(com[com.length()-1] != ';' || com[com.length()-2] != ')')
	{
		cout << "Invalid syntax" << endl;
		return 0;
	}

	for(int a = 0; a < com.length(); a++)
	{
		if(com[a] != correct[a])
		{
			cout << "Invalid Syntax" << endl;
			return 0;
		}
	}
	
        cout << "Valid Syntax" << endl;
    
    

}


//getline    ( ci  n , x ) ;   ==  getline(cin,x);





