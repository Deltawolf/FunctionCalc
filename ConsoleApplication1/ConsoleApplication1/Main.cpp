
/*
Zach Shore
ENGR 210
05/OCT/2018
Main.cpp
This program performs mathematical operations on the entered value.
*/

#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
#include <cmath>

using namespace std;

//Core functions for int main
double userPrompt();
int menuSelection();
void funcSelection(int userMenu, double myValue);
bool continueFunc();

//If operations menu expands, change this value to reflect the number of available options.
//Edit enum inside of funcSelection() to reflect new items as well.
const int totalMenuItems = 5;
//Functions available to menu selection.
void sinhFunc(double value);
void coshFunc(double value);
void sqrtFunc(double value);
void logFunc(double value);
void lnFunc(double value);



/*
**************************
Main
**************************

1. The program accepts a value from the user.
2. The program will select a menu selection from the user.
3. A mathematical operation is performed through function selection switch.
4. The user is prompted if they would like to use the program again.

*/
int main()
{
	bool userContinue = false;
	double userValue = NULL;
	int userMenu = NULL;

	do
	{
		
		userValue = userPrompt();

		userMenu = menuSelection();

		funcSelection(userMenu, userValue);
		
		userContinue = continueFunc();

	}while (userContinue);
	
}


/*
**************************
USER INPUT
**************************

All user input is structured inside a do/while loop which checks to verify that the input from the user
matches the appropriate data type. If this data is not valid, we clear the error flag (cin.clear()),
ignore the line, and attempt to acquire a new input. If the value is not appropriate for the mathematical
operation, this will be handled inside the function for that operation instead.

*/
double userPrompt()
//This function is used to prompt the user to enter a value to perform mathematical operations upon.
{
	double userValue = NULL;

	do
	{

		if (cin.fail())
		{
			cout << "\nThe entry was not a valid type.\nPlease attempt to enter a new numerical value.\n\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}

		cout << "\n\nPlease enter a numerical value to perform a mathematical operation on.\n";
		cin >> userValue;

	} while (cin.fail());

	return userValue;
}

int menuSelection()
//This function displays the menu and is used to allow the user to select an item from the menu.
{

	string starString = "";

	cout << "Please select from the following mathematical operations to perform. \n";
	cout << starString.assign(33, '*'); //Menu separation
	cout << "\n1. sinh\n2. cosh\n3. sqrt\n4. log\n5. ln\n";
	cout << starString.assign(33, '*') << endl; //Menu separation

	int userValue = NULL;

	do
	{

		if (cin.fail())
		{
			cout << "\nYour entry was not valid. Please select a menu item by number.\n\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}

		cout << "\nPlease select an item from the menu.\n";
		cin >> userValue;

	} while (cin.fail());

	if (userValue > totalMenuItems)
	{
		cout << "\n\nYou have entered an invalid menu selection. Try again. \n\n";
		userValue = menuSelection();
	}
	
	return userValue;
	
}

bool continueFunc()
//This function is used to prompt the user whether they would like run the program with a new value.
{
	bool userChoice = false;
	bool isAcceptable = true;
	char cRetry = NULL;

	cout << "\n\nGreat!\n";

	do {
	
		isAcceptable = true;

		if (cin.fail())
		{
			cout << "\nThe entry was not a valid type.\nPlease enter the letter 'Y' for yes or 'N' for no. \n\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}


		cout << "\nWould you like to calculate an additional value? (Y/N)\n";
		cin >> cRetry;

		if (cRetry == 'Y' || cRetry == 'y')
		{
			userChoice = true;
		}
		else if (cRetry == 'N' || cRetry == 'n')
		{

			cout << "\n\nThanks for using the Operation Calculator(C) by ZachInc!\n\n";
			break;
		}
		else
		{
			cout << "\nThe entry was not a valid type.\nPlease enter the letter 'Y' for yes or 'N' for no. \n\n";
			isAcceptable = false;
		}

	} while (!isAcceptable);


	return userChoice;
}


/*
**************************
Mathematical Operations
**************************
*/

void funcSelection(int userMenu, double userValue)
//This function selects a mathetmatical operation selected by using the values from menuSelection() and userPrompt().
{
	enum menuChoice { sinh = 1, cosh = 2, sqrt = 3, log = 4, ln = 5 };

	switch(userMenu)
	{
	case sinh:
		sinhFunc(userValue);
		break;

	case cosh:
		coshFunc(userValue);
		break;

	case sqrt:
		sqrtFunc(userValue);
		break;

	case log:
		logFunc(userValue);
		break;

	case ln:
		lnFunc(userValue);
		break;

	default:
		cout << "Invalid menu selection. How did you even get here? Please restart the program.\n\n";
		exit(0);
	}
}



void sinhFunc(double userValue)
//Performs hyperbolic sine upon the given value from userPrompt()
{
	userValue = sinh(userValue);
	cout << "The hyperbolic sine of your value is: " << userValue;
}
	

void coshFunc(double userValue)
//Performs hyperbolic cosine upon the given value from userPrompt()
{
	userValue = cosh(userValue);
	cout << "The hyperbolic cosine of your value is: " << userValue;
}

void sqrtFunc(double userValue)
//Calculates the square root upon the given value from userPrompt()
{
	if (userValue < 0)
	{
		cout << "\n\nYour input was not valid for the domain of the function. Try a new value.\n\n";
		userValue = userPrompt();
		funcSelection(3, userValue);
	}
	userValue = sqrt(userValue);

	cout << "The square root of your value is: " << userValue;
}

void logFunc(double userValue)
//Performs the log10 operation upon the given value from userPrompt()
{
	
	userValue = log10(userValue);

	cout << "The log 10 of your value is: " << userValue;
}

void lnFunc(double userValue)
//Performs the natural log operation upon the given value from userPrompt()
{
	if (userValue < 0)
	{
		cout << "\n\nYour input was not valid for the domain of the function. Try a new value.\n\n";
		userValue = userPrompt();
		funcSelection(5, userValue);
	}

	userValue = log(userValue);

	cout << "The natural log of your value is: " << userValue;
}
