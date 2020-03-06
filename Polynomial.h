#pragma once
#include "Term.h"
#include<fstream>
using namespace std;
class Polynomial
{
private:

	int TermCount;
	Term *Ts;
	int Greater(const int,const int)const;
public:
	Polynomial(){};
	Polynomial(const Polynomial &);
	Polynomial(ifstream &);
	~Polynomial();
	void PrintP()const;
	Polynomial*operator+(Polynomial *&)const;
	Polynomial*operator-(Polynomial *&)const;
	Polynomial*operator*(Polynomial *&)const;
	Polynomial & operator=(const Polynomial &);
};

