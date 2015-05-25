#include "Functions.h"
#include <iostream>
#include <cstring>

bool isPolyndrome(const char *str)
{
	int left = 0;
	int right = strlen(str) - 1;
	if (right == left)
		return false;
	while (left < right)
	{
		if (str[left++] != str[right--])
			return false;
	}

	return	true;
}

int countPolyndromes(const char *str)
{
	int count = 0;

	char buffer[256] = { 0 };
	const char *word = NULL;
	int wordLength = 0;

	while (char c = *(str++))
	{
		if (c != ' ')
		{
			if (!word)
				word = str - 1;

			++wordLength;
		}
		else
		{
			memcpy(buffer, word, wordLength);

			if (isPolyndrome(buffer))
			{
				++count;
			}

			memset(buffer, 0, 256);
			word = NULL;
			wordLength = 0;
		}
	}

	if (word)
	{
		memcpy(buffer, word, wordLength);

		if (isPolyndrome(buffer))
		{
			++count;
		}
	}

	return count;
}

int compareByPolyndromeCount(const void *first, const void* second)
{
	const char *firstStr = *(const char **)first;
	const char *secondStr = *(const char **)second;

	return countPolyndromes(firstStr) - countPolyndromes(secondStr);
}