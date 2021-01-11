#include <iostream>
#include <string> 
#include <time.h>  
#include <iomanip>   
#include <vector>
#include <stdlib.h>
#include "dataLayer.h";
#include "presentationLayer.h";

using namespace std;

int main()
{
	int numbers[4];
	int userNumbers[4];
	int numberOfGuesses = 0;
	int wins = 0;
	int loses = 0;
	mainMenu(numbers, userNumbers, numberOfGuesses, wins, loses);
}
