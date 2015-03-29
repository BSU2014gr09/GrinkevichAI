//8. В матрице А(N,N) найти первую строку, не содержащую отрицательных элементов,
//   и поменять её с последней строкой. Указатели на строки.
#include "Main.h"
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
			init(matrix);
			print(matrix);
			posAndLastRows(matrix);
			cout << endl << "Result: " << endl;
			print(matrix);
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
void init(int** matrix)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < N; ++i)
	for (int j = 0; j < N; ++j)
		matrix[i][j] = rand() % 100 - 50;

}
void print(int** matrix)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout.width(4);
			cout << setw(5) << matrix[i][j] << "   ";
		}
		cout << endl;
	}
}
void posAndLastRows(int** matrix)
{
	for (int i = 0; i < N; ++i)
	{
		bool onlyPositives = true;

		for (int j = 0; j < N; ++j)
		{
			if (matrix[i][j] < 0)
			{
				onlyPositives = false;
				break;
			}
		}
		if (onlyPositives)
		{
			swapRows(matrix[i], matrix[N - 1]);
			break;
		}
	}
}
void swapRows(int *row1, int *row2)
{
	int tmp[N];
	memcpy(tmp, row1, N * sizeof(int));
	memcpy(row1, row2, N * sizeof(int));
	memcpy(row2, tmp, N * sizeof(int));
}
