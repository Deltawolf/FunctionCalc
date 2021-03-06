
/*
Zach Shore
ENGR 210
06/OCT/2018
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

enum menuChoice { menuSinh = 1, menuCosh = 2, menuSqrt = 3, menuLog = 4, menuLN = 5 }; 
//named menuFunc for each entry to avoid ambiguous naming error I encountered with the math functions


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

//This function is used to prompt the user to enter a value to perform mathematical operations upon.
double userPrompt()

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

//This function displays the menu and is used to allow the user to select an item from the menu.
int menuSelection()

{

	string starString = "";

	cout << "\nPlease select from the following mathematical operations to perform. \n\n";
	cout << starString.assign(33, '*'); //Menu separation
	cout << "\n1. Hyperbolic Sine\n\n2. Hyperbolic Cosine\n\n3. Square Root\n\n4. Log Base 10\n\n5. Natural Log\n";
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

//This function is used to prompt the user whether they would like run the program with a new value.
bool continueFunc()

{
	bool userChoice = false;
	bool isAcceptable = true;
	char cRetry = NULL;

	cout << "\n\nGreat!\n";

	do {
	

		if (cin.fail()) //Should be redudant. All inputs should be considered characters.
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
			isAcceptable = true;
		}
		else if (cRetry == 'N' || cRetry == 'n')
		{

			cout << "\n\nThanks for using the Operation Calculator(C) by ZachInc!\n\n";
			isAcceptable = true;
		}
		else
		{
			cout << "\nThe entry was not a valid type.\nYou must enter a letter 'Y' for yes or 'N' for no. \n\n";
			isAcceptable = false;
			cin.ignore(1000, '\n'); //Will repeat line for each character if this is removed. Must ignore remainder of line if not Y or N. This was neglected in my previous program, and I have caught this here.
			cout << endl;
		}

	} while (!isAcceptable);


	return userChoice;
}


/*
**************************
Mathematical Operations
**************************
*/

//This function selects a mathetmatical operation selected by using the values from menuSelection() and userPrompt().
void funcSelection(int userMenu, double userValue)

{
	
	switch(userMenu)
	{
	case menuSinh:
		sinhFunc(userValue);
		break;

	case menuCosh:
		coshFunc(userValue);
		break;

	case menuSqrt:
		sqrtFunc(userValue);
		break;

	case menuLog:
		logFunc(userValue);
		break;

	case menuLN:
		lnFunc(userValue);
		break;

	default://Not sure how a user could reach this state. If they do, the program will exit.
		cout << "Invalid menu selection. How did you even get here? Please restart the program.\n\n";
		exit(0);
	}
}


//Performs hyperbolic sine upon the given value from userPrompt()
void sinhFunc(double userValue)

{
	userValue = sinh(userValue);
	cout << "\nThe hyperbolic sine of your value is: " << userValue << endl;
}
	
//Performs hyperbolic cosine upon the given value from userPrompt()
void coshFunc(double userValue)

{
	userValue = cosh(userValue);
	cout << "\nThe hyperbolic cosine of your value is: " << userValue << endl;
}

//Calculates the square root upon the given value from userPrompt()
void sqrtFunc(double userValue)

{
	//Domain of real square root values handled here
	if (userValue < 0)
	{
		cout << "\n\nYour input was not valid for the domain of the function. Try a new value.\n\n";
		userValue = userPrompt();
		funcSelection(menuSqrt, userValue);
	}
	userValue = sqrt(userValue);

	cout << "\nThe square root of your value is: " << userValue << endl;
}

//Performs the log10 operation upon the given value from userPrompt()
void logFunc(double userValue)

{
	//Domain of log10 handled here
	if (userValue < 0)
	{
		cout << "\n\nYour input was not valid for the domain of the function. Try a new value.\n\n";
		userValue = userPrompt();
		funcSelection(menuLog, userValue);
	}

	userValue = log10(userValue);

	cout << "\nThe log 10 of your value is: " << userValue << endl;
}

//Performs the natural log operation upon the given value from userPrompt()
void lnFunc(double userValue)

{
	//Domain of natural log handled here
	if (userValue < 0)
	{
		cout << "\n\nYour input was not valid for the domain of the function. Try a new value.\n\n";
		userValue = userPrompt();
		funcSelection(menuLN, userValue);
	}

	userValue = log(userValue);

	cout << "\nThe natural log of your value is: " << userValue << endl;
}
