//25.	В строке в каждой паре слов поменять слова местами, если длины слов совпадают, иначе заменить их звёздочками.
#include"Main.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	const int len = 100;
	bool isRunning = true;

	while (isRunning)
	{
		char *s = 0;
		int input = 0;

		cout << "+==================================================+" << endl;
		cout << "==       Enter 0 to learn the condition           ==" << endl;
		cout << "==       Enter 1 to perform and know the rezult   ==" << endl;
		cout << "==       Enter 2 to exit                          ==" << endl;
		cout << "+==================================================+" << endl;
		cin >> input;
		cin.ignore();
		system("cls");
		switch (input)
		{
		case 0:
			cout << "25.В строке в каждой паре слов поменять слова местами, если" << endl << "    длины слов совпадают, иначе заменить их звёздочками." << endl << endl;
			break;
		case 1:
			s = allocate(len);
			initStr(s, len);
			reverseWords(s);
			cout << "\nrezult: " << s << endl << endl;
			delete[] s;
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
	return 0;
}

char* allocate(int len)
{
	return new char[len];
}

void deleteArray(char* s)
{
	delete[] s;
}

void initStr(char * s, int len)
{
	cin.getline(s, len);
}

void reverseWords(char *s)
{
	char word1[256] = { 0 };
	int idx1 = 0;

	char word2[256] = { 0 };
	int idx2 = 0;

	bool isFirstWord = true;
	char *word1Ptr = 0;

	char symbol = 0;
	do
	{
		symbol = *s++;

		if ((symbol != '\0') && (symbol != ' '))
		{
			if (isFirstWord)
			{
				if (!word1Ptr)
					word1Ptr = s - 1;
				word1[idx1++] = symbol;
			}
			else
			{
				word2[idx2++] = symbol;
			}
		}
		else if (idx1 > 0)
		{
			if (isFirstWord)
			{
				isFirstWord = false;
			}
			else if (idx2 > 0)
			{
				if (idx1 == idx2)
				{
					memset(word1Ptr, '*', idx2);
					word1Ptr[idx2] = ' ';
					memset(word1Ptr + idx2 + 1, '*', idx1);
				}
				else
				{
					memcpy(word1Ptr, word2, idx2);
					word1Ptr[idx2] = ' ';
					memcpy(word1Ptr + idx2 + 1, word1, idx1);
				}

				isFirstWord = true;
				memset(word1, 0, 256);
				idx1 = 0;
				memset(word2, 0, 256);
				idx2 = 0;

				word1Ptr = 0;
			}
		}
	} while (symbol);
}
