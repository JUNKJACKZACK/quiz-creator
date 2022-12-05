#include <iostream>
#include <fstream>
#include <string>
using namespace std;


//Step 1. Welcome user and explain how to use the quiz maker
//step 2. Begin with asking what type of question it will be.
	//- multiple choice
	//- short written answer
	//- connect defintion to word
	//- True or False
//step 3.


int main()
{
	fstream file; //This library creates and manages files using c++
	file.open("quiz.txt", ios::out); //ios::out is write mode

	if (!file)
	{
		cout << "Error when creating file.";
		return 0;
	}

	cout << "File was successfully created.";

	file.close();

	int user_choice;
	string user_question;

	cout << "Welcome to the Quiz Maker!\n";
	cout << "What type of question would you like to create?\n";
	cout << "1. Multiple choice\n";

	cin >> user_choice;
	
	if (user_choice == 1)
	{
		cout << "What is your question?\n";
		getline(cin, user_question);
		
		file.open("quiz.txt", ios::out);

		if (file.is_open())
		{
			file << user_question;
			file.close();
		}
	}


	cin.get();
	return 0;
}	