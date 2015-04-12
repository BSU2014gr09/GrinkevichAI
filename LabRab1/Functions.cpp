#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Functions.h"

using namespace std;

void reverseWords(char *s)
{
	cout << s << '\n';

	int len = strlen(s);

	char *firstWord = NULL;

	char *word = strtok(s, " ");
	while (word)
	{
		if (!firstWord)
		{
			firstWord = word;
		}
		else
		{
			int firstLen = strlen(firstWord);
			int secondtLen = strlen(word);

			if (firstLen == secondtLen)
			{
				memset(firstWord, '*', firstLen);
				memset(word, '*', secondtLen);
			}
			else
			{
				char *buffer = new char[firstLen + 1];

				strcpy(buffer, firstWord);
				strcpy(firstWord, word);

				int spacesCount = (int)(word - firstWord) - firstLen;

				strcpy(firstWord + secondtLen + spacesCount, buffer);

				delete[] buffer;
			}

			firstWord = NULL;
		}

		word = strtok(NULL, " ");
	}

	int i = 0;
	while (i < len)
	{
		if (s[i] == '\0')
			s[i] = ' ';

		++i;
	}
	cout << s << '\n';
}

