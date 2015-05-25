//4. Отсортировать строки по количеству слов - палиндромов.
#include <iostream>
#include <cstring>
#include "Functions.h"

using namespace std;

int main()
{
	
	FILE *file = fopen("file1.txt", "r");
	if (!file)
	{
		cout << "Can't open file1.txt" << endl;
		return 0;
	}

	fseek(file, 0, SEEK_END);
	long int fileSize = ftell(file);

	fseek(file, 0, SEEK_SET);

	char *buffer = new char[fileSize];
	memset(buffer, 0, fileSize);

	fread(buffer, fileSize, 1, file);

	char** lines = NULL;
	int numberOfLines = 0;
	int currentLine = 0;

	char * pch = strtok(buffer, "\n");
	while (pch != NULL)                        
	{
		if (!lines)
		{
			numberOfLines = atoi(pch);
			lines = new char*[numberOfLines];
		}
		else
		{
			lines[currentLine++] = pch;
		}

		pch = strtok(NULL, "\n");
	}

	cout << "-------------------------------\n";

	for (int i = 0; i < numberOfLines; ++i)
	{
		cout << lines[i] << "\n";
	}

	qsort(lines, numberOfLines, sizeof(char*), &compareByPolyndromeCount);

	cout << "-------------------------------\n";

	for (int i = 0; i < numberOfLines; ++i)
	{
		cout << lines[i] << "\n";
	}

	delete[] lines;
	delete[] buffer;

	fclose(file);

	return 0;
}