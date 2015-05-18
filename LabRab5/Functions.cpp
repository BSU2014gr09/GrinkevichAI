#include <iostream>
#include <time.h>
#include "Functions.h"
using namespace std;

Polynom::Polynom() :
	members(NULL), 
	numMembers(0)
{
}

Polynom::Polynom(const Polynom& src)
{
	numMembers = src.numMembers;
	members = new PolynomMember[numMembers];

	for (int i = 0; i < numMembers; ++i)
	{
		members[i] = src.members[i];
	}
}

Polynom::~Polynom()
{
	Free();
}

void Polynom::Free()
{
	delete[] members;
	members = NULL;
	numMembers = 0;
}

void Polynom::Populate()
{
	Free();

	numMembers = rand() % 10;
	members = new PolynomMember[numMembers];

	for (int i = 0; i < numMembers; ++i)
	{
		int coef = rand() % 10 - 5;

		members[i].exp = i;
		members[i].coef = coef;
	}
}

void Polynom::Print()
{
	for (int i = 0; i < numMembers; ++i)
	{
		const PolynomMember *member = &members[i];
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

Polynom Polynom::operator+(const Polynom &second)
{
	Polynom result;
	Add(second, result, false);
	return result;
}

Polynom Polynom::operator-(const Polynom &second)
{
	Polynom result;
	Add(second, result, true);
	return result;
}

void Polynom::Add(const Polynom &second, Polynom &result, bool negate)
{
	result.members = new PolynomMember[numMembers + second.numMembers];

	int numResult = 0;

	for (int i = 0; i < numMembers; ++i)
		result.members[numResult++] = members[i];

	result.numMembers = numResult;

	for (int i = 0; i < second.numMembers; ++i)
	{
		const PolynomMember *mSecond = &second.members[i];
		bool hasMatch = false;

		for (int j = 0; j < result.numMembers; ++j)
		{
			PolynomMember *mResult = &result.members[i];

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
			result.members[numResult++] = *mSecond;
	}
	
	result.numMembers = numResult;
}

Polynom Polynom::operator*(const Polynom &second)
{
	Polynom result;
	result.members = new PolynomMember[numMembers * second.numMembers];
	result.numMembers = 0;

	for (int i = 0; i < numMembers; ++i)
	{
		const PolynomMember *mFirst = &members[i];
		for (int j = 0; j < second.numMembers; ++j)
		{
			PolynomMember *mSecond = &second.members[j];

			PolynomMember *mResult = NULL;

			int exp = mFirst->exp + mSecond->exp;
			for (int k = 0; k < result.numMembers; ++k)
			{
				if (result.members[k].exp == exp)
				{
					mResult = &result.members[k];
					break;
				}
			}

			if (mResult)
				mResult->coef += mFirst->coef * mSecond->coef;
			else
			{
				mResult = &result.members[result.numMembers];
				mResult->exp = mFirst->exp + mSecond->exp;
				mResult->coef = mFirst->coef * mSecond->coef;
				++result.numMembers;
			}
		}
	}
	return result;
}
