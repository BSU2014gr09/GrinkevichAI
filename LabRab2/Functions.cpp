#include <iostream>
#include <iomanip>
#include <time.h>

#include "Functions.h"

using namespace std;

void init(int** matrix, int size)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			matrix[i][j] = rand() % 100 - 50;
}

void print(int** matrix, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cout.width(4);
			cout << setw(5) << matrix[i][j] << "   ";
		}
		cout << endl;
	}
}
void posAndLastRows(int** matrix, int size)
{
	for (int i = 0; i < size; ++i)
	{
		bool onlyPositives = true;

		for (int j = 0; j < size; ++j)
		{
			if (matrix[i][j] < 0)
			{
				onlyPositives = false;
				break;
			}
		}
		if (onlyPositives)
		{
			swapRows(&matrix[i], &matrix[size - 1]);
			break;
		}
	}
}
void swapRows(int **row1, int **row2)
{
	if (row1 != row2)
	{
		int* tmp = *row1;
		*row1 = *row2;
		*row2 = tmp;
	}
}
