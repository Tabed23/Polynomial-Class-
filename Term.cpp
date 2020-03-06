#include "Term.h"
using namespace std;
Term::Term()
{
}
Term::~Term()
{
}
Term::Term(float C, int D)
{
	this->Const = C;
	this->Drgee = D;
}
void Term::SetConst(const float C)
{
	Const = C;
}
void Term::SetDgree(const int D)
{
	Drgee = D;
}
float Term::GetConst()const
{
	return Const;
}
int Term::GetDrgee()const
{
	return Drgee;
}
void Term::PrintTerm()
{
	cout << " " << Const << " x^" << Drgee;

}
bool Term::IsNeg()
{
	return this->Const < 0;
}