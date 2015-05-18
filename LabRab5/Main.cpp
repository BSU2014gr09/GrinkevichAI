#include <iostream>
#include <time.h>
#include "Functions.h"

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));

	Polynom polynom1;
	Polynom polynom2;

	polynom1.Populate();
	polynom2.Populate();
	polynom1.Print();
	polynom2.Print();

	cout << "The sum of polynomials" << endl;
	Polynom result = polynom1 + polynom2;
	result.Print();

	cout << "The difference of polynomials" << endl;
	Polynom result1 = polynom1 - polynom2;
	result1.Print();

	cout << "Multiplication of polynomials" << endl;
	Polynom result2 = polynom1 * polynom2;
	result2.Print();
	
	return 0;
}

