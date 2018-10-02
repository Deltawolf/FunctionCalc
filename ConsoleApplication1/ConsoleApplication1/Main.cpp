
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

double userPrompt();
int menuSelection();
void funcSelection(int userMenu, int myValue);
bool continueFunc();
double sinhFunc(double value);
double coshFunc(double value);
double sqrtFunc(double value);
double logFunc(double value);
double lnFunc(double value);

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

double userPrompt()
{
	double myValue = NULL;
	cout << "Please input the value you wish to perform mathematical operation on.\n";
	cin >> myValue;
}

int menuSelection()
{
	int mySelection = NULL;
	cout << "Please select from the following mathematical operations to perform. \n";
	//Formatting and integer menu options
	cin >> mySelection;
	
}

void funcSelection(int userMenu, int myValue)
{
	enum menuChoice { sinh = 1, cosh = 2, sqrt = 3, log = 4, ln = 5 };

	switch(userMenu)
	{
	case sinh:
		sinhFunc(myValue);
		break;
	case cosh:
		coshFunc(myValue);
		break;

	case sqrt:
		sqrtFunc(myValue);
		break;

	case log:
		logFunc(myValue);
		break;

	case ln:
		lnFunc(myValue);
		break;
	}
}