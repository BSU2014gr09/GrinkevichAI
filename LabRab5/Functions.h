#ifndef POLYNOM_FUNCTIONS
#define POLYNOM_FUNCTIONS

class PolynomMember
{
public:
	int exp;
	int coef;
};

class Polynom
{
public:
	Polynom();
	Polynom(const Polynom& src);
	~Polynom();

	void Populate();
	void Print();

	Polynom operator+(const Polynom &polynom);
	Polynom operator-(const Polynom &polynom);
	Polynom operator*(const Polynom &polynom);
	
private:
	void Free();
	void Add(const Polynom &second, Polynom &result, bool negate);

	PolynomMember *members;
	int numMembers;
};


#endif