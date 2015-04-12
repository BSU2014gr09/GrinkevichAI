//8. В матрице А(N,N) найти первую строку, не содержащую отрицательных элементов, и поменять её с последней строкой. Указатели на строки.
#include <iostream>
#include <iomanip>
#include <time.h>

#include "Functions.h"

using namespace std;

const int N = 4;

int main()
{
	setlocale(LC_ALL, "rus");

	int** matrix = new int*[N];
	for (int i = 0; i < N; ++i)
		matrix[i] = new int[N];

	bool isRunning = true;
	while (isRunning)
	{
		int input = 0;

		cout << "====================================================" << endl;
		cout << "==       Enter 0 to learn the condition           ==" << endl;
		cout << "==       Enter 1 to perform and know the rezult   ==" << endl;
		cout << "==       Enter 2 to exit                          ==" << endl;
		cout << "====================================================" << endl;
		cin >> input;
		cin.ignore();
		system("cls");
		switch (input)
		{
		case 0:
			cout << "8. В матрице А(N,N) найти первую строку, не содержащую отрицательных элементов," << endl << "   и поменять её с последней строкой. Указатели на строки." << endl << endl;
			break;
		case 1:
			init(matrix, N);
			print(matrix, N);
			posAndLastRows(matrix, N);
			cout << endl << "Result: " << endl;
			print(matrix, N);
			break;
		case 2:
			cout << "Good-Bye!" << endl;
			isRunning = false;
			break;
		default:
			cout << "Error, bad input!" << endl;
			break;
		}
	}

	for (int i = 0; i < N; ++i)
		delete[] matrix[i];
	delete[] matrix;

	return 0;
}