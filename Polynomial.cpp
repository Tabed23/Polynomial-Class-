#include "Polynomial.h"
#include<iostream>
using namespace std;
Polynomial::Polynomial(ifstream &rdr)
{
	rdr >> TermCount;
	Ts = new Term[TermCount];
	for (int ti = 0; ti < TermCount; ti++)
	{
		float C;
		int D;
		rdr >> C >> D;
		Ts[ti].SetConst(C);
		Ts[ti].SetDgree(D);
	}
}
Polynomial::~Polynomial()
{
	cout << " Polynomial has  been dis- Structor\n";
	delete[] Ts;
}

Polynomial::Polynomial(const Polynomial &C)
{
	Polynomial P;
	P.TermCount = C.TermCount;
	P.Ts = C.Ts;
}


int Polynomial::Greater(const int A, const int B)const
{
	return ((A > B) ? A : B);
}
void Polynomial::PrintP()const
{
	for (int ti = 0; ti < this->TermCount; ti++)
	{
		if (ti && this->Ts[ti].IsNeg())
		{
			cout << "+";
		}
		this->Ts[ti].PrintTerm();
	}
	cout << endl;
}
Polynomial*  Polynomial::operator+(Polynomial *&P1)const 
{
	int Nterm = Greater(this->TermCount, P1->TermCount);
	Polynomial * add = new Polynomial[Nterm];
	add->Ts = new Term[Nterm];
	if (this->TermCount == P1->TermCount)
	{
		for (int i = 0; i < Nterm; i++)
		{
			float C, Cp; int D, Dp;
			C = Ts[i].GetConst();
			D = Ts[i].GetDrgee();
			Cp = P1->Ts[i].GetConst();
			Dp = P1->Ts[i].GetDrgee();
			if (D == Dp)
			{
				add->Ts[i].SetDgree(Greater(D, Dp));
				add->Ts[i].SetConst(C + Cp);
			}

		}
		add->TermCount = Nterm;
		return add;

	}
	int ai = 0;
	for (int i = 0; i < Nterm; i++)
	{
		float C, Cp; int D, Dp;
		C = Ts[ai].GetConst();
		D = Ts[ai].GetDrgee();
		Cp = P1->Ts[i].GetConst();
		Dp = P1->Ts[i].GetDrgee();
		if (D == Dp)
		{
			add->Ts[i].SetDgree(Greater(D, Dp));
			ai++;
			add->Ts[i].SetConst(C + Cp);
		}
		else
		{
			add->Ts[i].SetDgree(Greater(D, Dp));
			add->Ts[i].SetConst(Greater(C, Cp));
		}

	}
	add->TermCount = Nterm;
	return add;
}
Polynomial* Polynomial::operator-(Polynomial *&P1)const
{
	int Nterm = Greater(TermCount, P1->TermCount);
	Polynomial * sub = new Polynomial[Nterm];
	sub->Ts = new Term[Nterm];
	if (TermCount == P1->TermCount)
	{
		for (int i = 0; i < Nterm; i++)
		{
			float C, Cp; int D, Dp;
			C = Ts[i].GetConst();
			D = Ts[i].GetDrgee();
			Cp = P1->Ts[i].GetConst();
			Dp = P1->Ts[i].GetDrgee();
			if (D == Dp)
			{
				sub->Ts[i].SetDgree(Greater(D, Dp));
				sub->Ts[i].SetConst(C - Cp);
			}

		}
		sub->TermCount = Nterm;
		return sub;

	}
	int ai = 0;
	for (int i = 0; i < Nterm; i++)
	{
		float C, Cp; int D, Dp;
		C = Ts[ai].GetConst();
		D = Ts[ai].GetDrgee();
		Cp = P1->Ts[i].GetConst();
		Dp = P1->Ts[i].GetDrgee();
		if (D == Dp)
		{
			sub->Ts[i].SetDgree(Greater(D, Dp));
			ai++;
			sub->Ts[i].SetConst(C - Cp);
		}
		else
		{
			sub->Ts[i].SetDgree(Greater(D, Dp));
			sub->Ts[i].SetConst(Greater(C, Cp));
		}

	}
	sub->TermCount = Nterm;
	return sub;

}
Polynomial * Polynomial::operator*(Polynomial *&P1)const
{
	int Nterm = TermCount + P1->TermCount;
	Polynomial * Multi = new Polynomial[Nterm];
	Multi->Ts = new Term[Nterm];
	int Count = 0;
	for (int i = 0; i < TermCount; i++)
	{
		for (int j = 0; j < P1->TermCount; j++)
		{
			float C, Cp; int D, Dp, M;
			C = Ts[i].GetConst();
			D = Ts[i].GetDrgee();
			Cp = P1->Ts[j].GetConst();
			Dp = P1->Ts[j].GetDrgee();
			M = C*Cp;
			Multi->Ts[i + j].SetConst(M);
			Multi->Ts[i + j].SetDgree(Greater(D, Dp));
		}
	}
	Multi->TermCount = Nterm - 1;
	return Multi;
}
Polynomial& Polynomial::operator=(const Polynomial & P)
{
	this->TermCount = P.TermCount;
	this->Ts = P.Ts;
	return (*this);
}