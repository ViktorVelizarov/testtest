#include <iostream>
#include <string> 
#include <time.h>  
#include <iomanip>   
#include <vector>
#include <stdlib.h>
#include "dataLayer.h";
#include "presentationLayer.h";

void generateNumNoDuplicates(int numbers[])
{
	int br = 1;
	srand(time(NULL));
	while (br != 0)
	{
		br = 0;
		for (int i = 0; i < 4; i++)
		{

			numbers[i] = rand() % 7 + 1;
			for (int j = 0; j < 4; j++)
			{
				if (numbers[i] == numbers[j] && i != j)
				{
					br++;
				}
			}
		}
	}

}

void generateNumWithDuplicates(int numbers[])
{
	for (int i = 0; i < 4; i++)
	{
		numbers[i] = rand() % 7 + 1;
	}
}

bool checkInteger(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]) == false)
			return false;
	}
	return true;
}
bool areEqual(int numbers[], int finalNumbers[])
{
	for (int i = 0; i < 4; i++)
		if (numbers[i] != finalNumbers[i])
			return false;
	return true;
}
void createVector(vector<int> arrayOfGuesses[], int userNumbers[], int numberOfGuesses, int vectorSize)
{
	for (int j = 0; j < vectorSize; j++)
	{
		arrayOfGuesses[numberOfGuesses].push_back(userNumbers[j]);
	}
}

void compareNumbers(int numbers[], int userNumbers[], int  numberOfGuesses, int& wins, int& loses)
{

	int finalNumbers[4] = { 10, 10,10,10 };
	vector<int> guessedNumAndPos[100];
	vector<int> arrayOfGuesses[100];
	vector<int> guessedNumbers[100];

	while (areEqual(numbers, finalNumbers) == false)
	{
		inputGuessNumbers(userNumbers);
		createVector(arrayOfGuesses, userNumbers, numberOfGuesses, 4);
		for (int i = 0; i < 4; i++)
		{
			if (numbers[i] == userNumbers[i])
			{

				guessedNumAndPos[numberOfGuesses].push_back(numbers[i]);
				finalNumbers[i] = numbers[i];
			}
			if (numbers[i] != userNumbers[i])
			{

				for (int j = 0; j < 4; j++)
				{

					if (numbers[i] == userNumbers[j])
					{
						guessedNumbers[numberOfGuesses].push_back(numbers[i]);
					}
				}
			}
		}
		numberOfGuesses++;
		if (13 - numberOfGuesses < 10)
		{
			cout << "+--------------+" << endl;
			cout << "|Guesses left:" << 13 - numberOfGuesses << "|" << endl;
			cout << "+--------------+" << endl;

		}
		else
		{
			cout << "+---------------+" << endl;
			cout << "|Guesses left:" << 13 - numberOfGuesses << "|" << endl;
			cout << "+---------------+" << endl;
		}
		cout << "+--------+" << endl;
		cout << "|wins: " << wins << " |" << endl;
		cout << "|loses: " << loses << "|" << endl;
		cout << "+--------+" << endl;
		cout << setw(69) << setiosflags(ios::right) << "+------------+" << endl;
		cout << setw(69) << setiosflags(ios::right) << "|4 digit code|" << endl;
		cout << setw(69) << setiosflags(ios::right) << "|------------|" << endl;
		cout << setw(58) << setiosflags(ios::right) << "|  ";
		for (int i = 0; i < 4; i++)
		{
			if (finalNumbers[i] == 10)
			{
				cout << "? ";
			}
			else
			{
				cout << finalNumbers[i] << " ";
			}
		}
		cout << "  |" << endl;
		cout << setw(69) << setiosflags(ios::right) << "+------------+";
		cout << endl << endl;
		cout << "+-----------------------------+";
		cout << setw(35) << setiosflags(ios::right) << "+--------+";
		cout << setw(43) << setiosflags(ios::right) << "+---------------+" << endl;
		cout << "|Guessed numbers and positions|";
		cout << setw(35) << setiosflags(ios::right) << "| Gueses |";
		cout << setw(43) << setiosflags(ios::right) << "|Guessed numbers|" << endl;
		cout << "+-----------------------------+";
		cout << setw(35) << setiosflags(ios::right) << "+--------+";
		cout << setw(43) << setiosflags(ios::right) << "+---------------+" << endl;
		if (numberOfGuesses >= 13)
		{
			loses++;
			numberOfGuesses = 0;
			system("CLS");
			cout << "You have no more guesses. Better luck next time! " << endl;
			cout << " !-- GAME OVER --!" << endl;
			GameOver();
			break;
		}
		else
		{
			outputVector(guessedNumAndPos, numberOfGuesses, arrayOfGuesses, guessedNumbers);
		}
	}
	if (areEqual(numbers, finalNumbers) == true)
	{
		wins++;
		system("CLS");
		cout << "Congatulations! You guessed the secret coordinates!" << endl;
		GameOver();
	}
}


void setNumWithDuplicates(int numbers[])
{
	string arrayNumbers;
	cout << "+-------------------------------+" << endl;
	cout << "|Enter the 4 secret numbers here|" << endl;
	cout << "+-------------------------------+" << endl;
	for (int i = 0; i < 4; i++)
	{
		cin >> arrayNumbers;
		if (checkInteger(arrayNumbers) == false)
		{
			do {
				system("CLS");
				cout << "The value you entered was not an integer. Please enter a whole number : ";
				cin >> arrayNumbers;
				checkInteger(arrayNumbers);
			} while (checkInteger(arrayNumbers) == false);
		}
		numbers[i] = stoi(arrayNumbers);
		if (numbers[i] < 0 or numbers[i] > 7)
		{

			do {
				system("CLS");
				cout << "Your number must be between 0 and 7" << endl;
				cin >> numbers[i];
			} while (numbers[i] < 0 or numbers[i] > 7);
		}
	}
}
void setNumNoDuplicates(int numbers[])
{
	string arrayNumbers;
	int duplicates = 0;
	cout << "+-------------------------------+" << endl;
	cout << "|Enter the 4 secret numbers here|" << endl;
	cout << "+-------------------------------+" << endl;
	for (int i = 0; i < 4; i++)
	{
		cin >> arrayNumbers;
		if (checkInteger(arrayNumbers) == false)
		{
			do {
				system("CLS");
				cout << "The value you entered was not an integer. Please enter a whole number : ";
				cin >> arrayNumbers;
				checkInteger(arrayNumbers);
			} while (checkInteger(arrayNumbers) == false);
		}
		numbers[i] = stoi(arrayNumbers);
		if (numbers[i] < 0 or numbers[i] > 7)
		{

			do {
				system("CLS");
				cout << "Your number must be between 0 and 7" << endl;
				cin >> arrayNumbers;
				if (checkInteger(arrayNumbers) == false)
				{
					do {
						system("CLS");
						cout << "The value you entered was not an integer. Please enter a whole number : ";
						cin >> arrayNumbers;
						checkInteger(arrayNumbers);
					} while (checkInteger(arrayNumbers) == false);
				}
				numbers[i] = stoi(arrayNumbers);
			} while (numbers[i] < 0 or numbers[i] > 7);
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i != j and numbers[i] == numbers[j])
				duplicates++;
		}
	}
	if (duplicates > 0)
	{
		system("CLS");
		cout << "+--------------------------------------------+" << endl;
		cout << "|Try again , but this time without duplicates|" << endl;
		cout << "+--------------------------------------------+" << endl << endl << endl;
		setNumNoDuplicates(numbers);
	}
}