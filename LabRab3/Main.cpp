#include <iostream>
#include <time.h>
#include "Functions.h"

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));

	Polynom polynom1, polynom2;
	Polynom result;

	bool isRunning = true;
	while (isRunning)
	{
		int input = 0;

		cout << "====================================================" << endl;
		cout << "==        Polynomials + operations                ==" << endl;
		cout << "==       Enter 1 to add polynomials               ==" << endl;
		cout << "==       Enter 2 to subtract polynomials          ==" << endl;
		cout << "==       Enter 3 to exit                          ==" << endl;
		cout << "====================================================" << endl;
		cin >> input;
		cin.ignore();
		system("cls");
		switch (input)
		{
		case 1:
			InitPolynom(&polynom1);
			InitPolynom(&polynom2);
			InitPolynom(&result);

			PopulatePolynom(&polynom1);
			PopulatePolynom(&polynom2);

			PrintPolynom(&polynom1);
			PrintPolynom(&polynom2);

			AddPolynom(&polynom1, &polynom2, &result);

			PrintPolynom(&result);
			break;
		case 2:
			InitPolynom(&polynom1);
			InitPolynom(&polynom2);
			InitPolynom(&result);

			PopulatePolynom(&polynom1);
			PopulatePolynom(&polynom2);

			NegatePolinom(&polynom1);

			PrintPolynom(&polynom1);
			PrintPolynom(&polynom2);

			SubPolynom(&polynom1, &polynom2, &result);

			PrintPolynom(&result);
			break;
		case 3:
			cout << "Good-Bye!" << endl;
			isRunning = false;
			break;
		default:
			cout << "Error, bad input!" << endl;
			break;
		}
	}
	FreePolynom(&polynom1);
	FreePolynom(&polynom2);
	FreePolynom(&result);

	return 0;
}

