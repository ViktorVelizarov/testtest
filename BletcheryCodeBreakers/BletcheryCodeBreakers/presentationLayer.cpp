#include <iostream>
#include <string> 
#include <time.h>  
#include <iomanip>   
#include <vector>
#include <stdlib.h>
#include "dataLayer.h";
#include "presentationLayer.h";

// --------------------------------------------------------------------PRESENTATION LAYER----------------------------------------------------------

void inputGuessNumbers(int userNumbers[])
{
	string arrayNumbers;
	bool b = true;
	cout << " Input 4 numbers :";
	for (int i = 0; i < 4; i++)
	{
		cin >> arrayNumbers;
		if (checkInteger(arrayNumbers) == false)
		{
			if (b = true)
			{
				system("CLS");
				cout << "The value you entered was not an integer. Please enter a whole number : ";
				b = false;
			}

			do {
				cin >> arrayNumbers;

				checkInteger(arrayNumbers);
			} while (checkInteger(arrayNumbers) == false);


		}
		userNumbers[i] = stoi(arrayNumbers);
		if (userNumbers[i] < 0 || userNumbers[i] > 7)
		{

			do {
				system("CLS");
				cout << "Your number must be between 0 and 7" << endl;
				cin >> userNumbers[i];
			} while (userNumbers[i] < 0 || userNumbers[i] > 7);
		}
	}
	system("CLS");
	cout << endl;
}
void outputVector(vector<int> guessedNumAndPos[], int numberOfGuesses, vector<int> arrayOfGuesses[], vector<int> guessedNumbers[])
{
	vector<int>::iterator it;
	vector<int>::iterator it2;
	for (int i = 0; i < numberOfGuesses; i++)
	{
		int guessedNumAndPosCount = 0;
		int guessedNumCount = 0;
		cout << setw(10) << setiosflags(ios::right) << " ";
		cout << "|";
		for (it = guessedNumAndPos[i].begin();
			it < guessedNumAndPos[i].end(); it++)
		{
			guessedNumAndPosCount++;
			cout << *it << " ";
		}
		for (int i = 0; i < 4 - guessedNumAndPosCount; i++)
		{
			cout << "  ";
		}
		cout << "|";
		cout << setw(36) << setiosflags(ios::right) << " ";
		cout << "|";
		for (it2 = arrayOfGuesses[i].begin();
			it2 < arrayOfGuesses[i].end(); it2++) {
			cout << *it2 << " ";
		}
		cout << "|";
		cout << setw(30) << setiosflags(ios::right) << " ";
		cout << "|";
		for (it = guessedNumbers[i].begin();
			it < guessedNumbers[i].end(); it++) {

			guessedNumCount++;
			cout << *it << " ";
		}
		for (int i = 0; i < 4 - guessedNumCount; i++)
		{
			cout << "  ";
		}
		cout << "|";
		cout << endl;
	}
}
int GameOver()
{
	string levelChoice;
	int level;
	cout << "+------------+" << endl;
	cout << "|1.Play again|" << endl;
	cout << "|2.Exit Game |" << endl;
	cout << "+------------+" << endl;
	cin >> levelChoice;
	if (checkInteger(levelChoice) == false)
	{
		do {
			system("CLS");
			cout << "The value you entered was not an integer. Please enter a whole number : ";
			cin >> levelChoice;
			checkInteger(levelChoice);
		} while (checkInteger(levelChoice) == false);
	}
	level = stoi(levelChoice);
	switch (level)
	{
	case 1:
		break;
	case 2:
		exit(1);
		break;
	default:
		system("CLS");
		cout << "The number you chose was not valid!" << endl;
		GameOver();
		break;
	}

}

void levelMenu(int numbers[], int userNumbers[], int numberOfGuesses, int& wins, int& loses)
{
	string levelChoice;
	string DuplicateChoice;
	int choice;
	int level;
	cout << "+--------------+" << endl;
	cout << "|Choose a level|" << endl;
	cout << "+--------------+" << endl;
	cout << "1. LEVEL 1 - Two players" << endl;
	cout << "1. LEVEL 2 - Against the computer" << endl;
	cout << "3. Exit Game" << endl;
	cin >> levelChoice;
	if (checkInteger(levelChoice) == false)
	{
		do {
			system("CLS");
			cout << "The value you entered was not an integer. Please enter a whole number : ";
			cin >> levelChoice;
			checkInteger(levelChoice);
		} while (checkInteger(levelChoice) == false);
	}
	level = stoi(levelChoice);
	switch (level)
	{
	case 1:
		system("CLS");
		cout << "+----------------------------+" << endl;
		cout << "|With or without duplicates ?|" << endl;
		cout << "+----------------------------+" << endl;
		cout << "1.With duplicates" << endl;
		cout << "2.Without duplicates" << endl;
		cin >> DuplicateChoice;
		if (checkInteger(DuplicateChoice) == false)
		{
			do {
				system("CLS");
				cout << "The value you entered was not an integer. Please enter a whole number : ";
				cin >> DuplicateChoice;
				checkInteger(DuplicateChoice);
			} while (checkInteger(DuplicateChoice) == false);
		}
		choice = stoi(DuplicateChoice);
		switch (choice)
		{
		case 1:
			setNumWithDuplicates(numbers);
			compareNumbers(numbers, userNumbers, numberOfGuesses, wins, loses);
			break;
		case 2:
			setNumNoDuplicates(numbers);
			compareNumbers(numbers, userNumbers, numberOfGuesses, wins, loses);
			break;
		default:
			cout << "The number you chose was not valid!" << endl;
			levelMenu(numbers, userNumbers, numberOfGuesses, wins, loses);
			break;
		}
		break;
	case 2:
		system("CLS");
		cout << "+----------------------------+" << endl;
		cout << "|With or without duplicates ?|" << endl;
		cout << "+----------------------------+" << endl;
		cout << "1.With duplicates" << endl;
		cout << "2.Without duplicates" << endl;

		cin >> DuplicateChoice;
		if (checkInteger(DuplicateChoice) == false)
		{
			do {
				system("CLS");
				cout << "The value you entered was not an integer. Please enter a whole number : ";
				cin >> DuplicateChoice;
				checkInteger(DuplicateChoice);
			} while (checkInteger(DuplicateChoice) == false);
		}
		choice = stoi(DuplicateChoice);
		switch (choice)
		{
		case 1:
			generateNumWithDuplicates(numbers);
			compareNumbers(numbers, userNumbers, numberOfGuesses, wins, loses);
			break;
		case 2:
			generateNumNoDuplicates(numbers);
			compareNumbers(numbers, userNumbers, numberOfGuesses, wins, loses);
			break;
		default:
			levelMenu(numbers, userNumbers, numberOfGuesses, wins, loses);
			break;
		}
		break;
	case 3:
		exit(1);
		break;
	default:
		system("CLS");
		levelMenu(numbers, userNumbers, numberOfGuesses, wins, loses);
		break;
	}
}
void mainMenu(int numbers[], int userNumbers[], int numberOfGuesses, int& wins, int& loses)
{
	string startingMenu;
	int startingChoice;
	system("CLS");
	cout << "+----------------------------------+" << endl;
	cout << "|Welcome to Bletchley code breakers|" << endl;
	cout << "+----------------------------------+" << endl;
	cout << "1. Rules of the game" << endl;
	cout << "2. Play game" << endl;
	cout << "3. Exit Game" << endl;
	cin >> startingMenu;
	if (checkInteger(startingMenu) == false)
	{
		do {
			system("CLS");
			cout << "The value you entered was not an integer. Please enter a whole number : ";
			cin >> startingMenu;
			checkInteger(startingMenu);
		} while (checkInteger(startingMenu) == false);
	}
	startingChoice = stoi(startingMenu);
	switch (startingChoice)
	{
	case 1:
		system("CLS");
		cout << "+-----------------+" << endl;
		cout << "|Rules of the game|" << endl;
		cout << "+-----------------+" << endl;
		cout << "1. A player or computer place a 4 digit combination from numbers from 0-7." << endl;
		cout << "2. You have 13 attempts to guess the positions and the correct numbers of the combination." << endl;
		cout << "3. Depending on the second player's guesses the first player gives feedback whether a number is correct or a number and positions are correct." << endl;
		cout << "4. If you guess the 4 numbers and their positions you win the game but if you don't complete it withing 13 tries you lose." << endl;
		cout << endl;

	case 2:
		levelMenu(numbers, userNumbers, numberOfGuesses, wins, loses);
		break;
	case 3:
		exit(1);
		break;
	default:
		mainMenu(numbers, userNumbers, numberOfGuesses, wins, loses);
		break;
	}
	mainMenu(numbers, userNumbers, numberOfGuesses, wins, loses);
}