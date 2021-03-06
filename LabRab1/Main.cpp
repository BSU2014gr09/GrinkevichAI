//25.	В строке в каждой паре слов поменять слова местами, если длины слов совпадают, иначе заменить их звёздочками.
#include <iostream>
#include "Functions.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	const int len = 100;
	char *s = new char[len];
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
			cout << "25.В строке в каждой паре слов поменять слова местами, если длины слов совпадают, иначе заменить их звёздочками." << endl << endl;
			break;
		case 1:
			cin.getline(s, len);
			reverseWords(s);
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

	delete[] s;
	return 0;
}