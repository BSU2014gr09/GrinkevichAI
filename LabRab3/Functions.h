#ifndef POLYNOM_FUNCTIONS
#define POLYNOM_FUNCTIONS

struct PolynomMember
{
	int exp;
	int coef;
};

struct Polynom
{
	PolynomMember *members;
	int numMembers;
};

void AddPolynom(const Polynom *first, const Polynom *second, Polynom *result, bool negate = false);
void SubPolynom(const Polynom *first, const Polynom *second, Polynom *result);
void InitPolynom(Polynom *polynom);
void PopulatePolynom(Polynom *polynom);
void FreePolynom(Polynom *polynom);
void PrintPolynom(Polynom *polynom);

#endif