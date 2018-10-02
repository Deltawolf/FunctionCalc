
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void menuDisplay();
double sinh(double value);
double cosh(double value);
double sqrt(double value);
double log(double value);
double ln(double value);

int main()
{
	enum menuChoice { sinh, cosh, sqrt, log, ln };
	double myValue = NULL;
	menuChoice menuSelection;
	int userMenu = NULL;

	cout << "Please input the value you wish to perform mathematical operation on.\n";
	cin >> myValue;

	cout << "Please select from the following mathematical operations to perform. \n";
	menuDisplay();
	cin >> userMenu;

	menuSelection = userMenu;

	switch (menuSelection)
	{
	case sinh:
		sinh(myValue);
		break;
	case cosh:
		cosh(myValue);
		break;

	case sqrt:
		sqrt(myValue);
		break;

	}

}

