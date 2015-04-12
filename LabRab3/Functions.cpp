#include <iostream>
#include <time.h>
#include "Functions.h"

using namespace std;

void AddPolynom(const Polynom *first, const Polynom *second, Polynom *result, bool negate /*= false*/)
{
	result->members = new PolynomMember[first->numMembers + second->numMembers];

	int numResult = 0;

	for (int i = 0; i < first->numMembers; ++i)
	{
		result->members[numResult++] = first->members[i];
	}

	result->numMembers = numResult;

	for (int i = 0; i < second->numMembers; ++i)
	{
		const PolynomMember *mSecond = &second->members[i];
		bool hasMatch = false;

		for (int j = 0; j < result->numMembers; ++j)
		{
			PolynomMember *mResult = &result->members[i];

			if (mResult->exp == mSecond->exp)
			{
				if (negate)
					mResult->coef -= mSecond->coef;
				else
					mResult->coef += mSecond->coef;
				hasMatch = true;
				break;
			}
		}

		if (!hasMatch)
		{
			result->members[numResult++] = *mSecond;
		}
	}

	result->numMembers = numResult;
}

void NegatePolinom(Polynom *polynom)
{
	for (int i = 0; i < polynom->numMembers; ++i)
	{
		PolynomMember *member = &polynom->members[i];
		member->coef = -member->coef;
	}
}

void SubPolynom(const Polynom *first, const Polynom *second, Polynom *result)
{
	AddPolynom(first, second, result, true);
}

void InitPolynom(Polynom *polynom)
{
	polynom->members = NULL;
	polynom->numMembers = 0;
}

void PopulatePolynom(Polynom *polynom)
{
	FreePolynom(polynom);

	polynom->numMembers = rand() % 10;
	polynom->members = new PolynomMember[polynom->numMembers];

	for (int i = 0; i < polynom->numMembers; ++i)
	{
		int coef = rand() % 10 - 5;

		polynom->members[i].exp = i;
		polynom->members[i].coef = coef;
	}
}

void PrintPolynom(Polynom *polynom)
{
	for (int i = 0; i < polynom->numMembers; ++i)
	{
		const PolynomMember *member = &polynom->members[i];
		if (member->coef > 0)
			cout << " + ";
		else if (member->coef < 0)
			cout << " - ";
		else
			continue;

		if (member->exp == 0)
			cout << abs(member->coef);
		else
			cout << abs(member->coef) << "x^" << member->exp;
	}

	cout << endl << endl;
}

void FreePolynom(Polynom *polynom)
{
	delete[] polynom->members;
	polynom->members = NULL;
	polynom->numMembers = 0;
}