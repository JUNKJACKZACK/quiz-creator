#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int number_of_questions;
int current_numbered_question = 0;
int user_choice;
int counter = 0;

string user_question;
string user_answer;
string multiple_choice_ABCD;

string user_word;
string user_def;

string connectword1;
string connectword2;
string connectword3;
string connectword4;

string connectdef1;
string connectdef2;
string connectdef3;
string connectdef4;

void quizBuilder();


//Step 1. Welcome user and explain how to use the quiz maker
//Step 2. How many questions would you like to ask?
	/* 
	* all the question options and records answers and kills program
	* once they have met the number of questions
	*/ 
//step 3. Begin with asking what type of question it will be.
	//- multiple choice
	//- short written answer
	//- connect defintion to word
	//- True or False
//step 3.


void multipleChoice() {

	fstream file;

	if (!file)
	{
		cout << "Error when opening file.";
	}

		file.open("quiz.txt", ios::app);

		
		

		if (file.is_open()) {
			counter = 0;
			cout << "What is your question?\n";
			cin.ignore();
			file << "\n\n"; //new
			getline(cin, user_question);
			file << current_numbered_question << ".) " << user_question;
			file << "\n\n";
			//file << user_question;
			while (counter != 4) {
				
				
				cout << "What is the multiple choice answer you would like?\n";
				getline(cin, user_answer);
				counter++;


				if (counter == 1) {
					multiple_choice_ABCD = "a";
				}
				if (counter == 2) {
					multiple_choice_ABCD = "b";
				}
				if (counter == 3) {
					multiple_choice_ABCD = "c";
				}
				if (counter == 4) {
					multiple_choice_ABCD = "d";
				}


				file << "    " << multiple_choice_ABCD << ".) " << user_answer;
				file << "\n";
				

			}
			file << "\n";
		}

		return;
}


void shortAnswer() {

	fstream file;

	if (!file)
	{
		cout << "Error when opening file.";
	}

	file.open("quiz.txt", ios::app);

	cout << "What is your question?\n";
	cin.ignore();
	file << "\n\n"; //new
	getline(cin, user_question);
	file << current_numbered_question << ".) " << user_question;
	file << "\n\n";
	file << "    _________________________________________________________\n";
	file << "    _________________________________________________________\n";
	file << "    _________________________________________________________\n";
	file << "    _________________________________________________________\n";
	file << "    _________________________________________________________\n";

	return;
}


void connectDefinitions() {

	string words[4] = { "Volvo", "BMW", "Ford", "Mazda" };
	string defintions[4] = { "Volvo", "BMW", "Ford", "Mazda" };

	fstream file;

	if (!file)
	{
		cout << "Error when opening file.";
	}

	file.open("quiz.txt", ios::app);

	if (file.is_open()) {

		file << current_numbered_question << ".) Connect the definitions to the word.";
		file << "\n\n";

		for (int i = 0; i == 4; i++) { //you need for loop so you can ask the questions
			//four times and store data in array. Scramble data later and then you can print.

			string definitions[4]{ "","","","" };
			string words[4]{ "","","","" };

			cout << "What is the word you would like to add?\n";
			cin.ignore();
			getline(cin, words[i]);

			cout << "What is the definition of the word you added?\n\n";
			cin.ignore();
			getline(cin, definitions[i]); //everytime it iterates through it grabs the current value
			// of i and makes the the certain array block to grab 
		}
		cout << words[3];
	}
	return;
}


void quizBuilder() {
	
	do {

		cout << "What type of question would you like to create? Enter 1, 2, 3, or 4.\n";
		cout << "1. multiple choice\n";
		cout << "2. short written answer\n";
		cout << "3. Connect word to defintion\n";
		cout << "Type of question: ";
		cin >> user_choice;
		cout << "\n\n";

		current_numbered_question++;

		if (user_choice == 1) {
			multipleChoice();
		}
		else if (user_choice == 2) {
			shortAnswer();
		}
		else if (user_choice == 3) {
			connectDefinitions();
		}
		else {
			cout << "Issues";
		}
	} while (current_numbered_question != number_of_questions);
}


string greeting() {

	cout << "Welcome to the Quiz Maker!\n";
	cout << "How many questions would you like to make for this quiz?\n\n";
	cout << "Number of questions: ";
	cin >> number_of_questions;
	cout << "\n\n";

	quizBuilder();
	
	return 0;
}



int main()
{
	
	fstream file; //This library creates and manages files using c++
	file.open("quiz.txt", ios::out); //ios::out is write mode

	cout << "File was successfully created.\n\n";

	file.close();

	greeting();

	return 0;
}	