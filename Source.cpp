#include<iostream>
#include"Polynomial.h"
using namespace std;
void LoadPoly(ifstream &, Polynomial** &, int &);
void PrintPoly(Polynomial **, const  int &);
ostream & operator<<(ostream & Console, const char *&S);
int main()
{
	int tc;
	Polynomial* (*Ps), *APs, *Sps, *Mps;
	char ch;
	int c1, c2;
	char Choice;
	ifstream Rdr("Poly.txt");
	LoadPoly(Rdr, Ps, tc);
	PrintPoly(Ps, tc);
	do
	{
		cout << " Which Opreaction you want to perfrom\n";
		cout << "+" << " Addtion\n";
		cout << "-" << "Subtraction\n";
		cout << "*" << "Multiply\n";
		cout << "=" << " Assignment \n";
		cin >> ch;
		if (ch == '+')
		{
			cout << " Which Tow polynomial you want to add\n";
			cin >> c1 >> c2;
			if (c1 == 1 && c2 == 1)
			{
				cout << " Sorry cannot add";
			}
			else if (c1 == 1 && c2 == 2)
			{
				APs = Ps[0][0] + Ps[1];
				APs->PrintP();
			}
			else if (c1 == 1 && c2 == 3)
			{
				APs = Ps[0][0] + Ps[2];
				APs->PrintP();
			}
			else if (c1 == 2 && c2 == 3)
			{
				APs = Ps[1][0] + Ps[2];
				APs->PrintP();
			}
		}
		if (ch == '-')
		{
			cout << " Which Tow polynomial you want to subtract\n";
			cin >> c1 >> c2;
			if (c1 == 1 && c2 == 1)
			{
				cout << " Sorry cannot add";
			}
			else if (c1 == 1 && c2 == 2)
			{
				Sps = Ps[0][0] - Ps[1];
				Sps->PrintP();
			}
			else if (c1 == 1 && c2 == 3)
			{
				Sps = Ps[0][0] - Ps[2];
				Sps->PrintP();
			}
			else if (c1 == 2 && c2 == 3)
			{
				Sps = Ps[1][0] - Ps[2];
				Sps->PrintP();
			}
		}
		if (ch == '*')
		{
			cout << " Which Tow polynomial you want to subtract\n";
			cin >> c1 >> c2;
			if (c1 == 1 && c2 == 1)
			{
				cout << " Sorry cannot add";
			}
			else if (c1 == 1 && c2 == 2)
			{
				Mps = Ps[0][0] * Ps[1];
				Mps->PrintP();
			}
			else if (c1 == 1 && c2 == 3)
			{
				Mps = Ps[0][0] * Ps[2];
				Mps->PrintP();
			}
			else if (c1 == 2 && c2 == 3)
			{
				Mps = Ps[1][0] * Ps[2];
				Mps->PrintP();
			}
		}
		if (ch == '=')
		{
			APs = Ps[0][0] + Ps[2];
			APs->PrintP();
			Sps = Ps[0][0] - Ps[1];
			Sps->PrintP();
			Mps = Ps[0][0] * Ps[1];
			Mps->PrintP();
			int A1, A2;
			cout << " Which two Result you want to use" << endl;
			cin >> A1 >> A2;
			if (A1 == 1 && A2 == 2)
			{
				APs = Sps;
				cout << " After Assining\n Addtion=\n";
				APs->PrintP();
			}
			if (A1 == 2 && A2 == 1)
			{
				Sps = APs;
				cout << " After Assining\n Subtraction=\n";
				Sps->PrintP();
			}
			if (A1 == 1 && A2 == 3)
			{
				APs = Mps;
				cout << " After Assining\n Addtion=\n";
				APs->PrintP();
			}
			if (A1 == 3 && A2 == 1)
			{
				Mps = APs;
				cout << " After Assining\n Multiplay=\n";
				Mps->PrintP();
			}
			if (A1 == 2 && A2 == 3)
			{
				Sps = Mps;
				cout << " After Assining\n  Subtraction=\n";
				Sps->PrintP();
			}
			if (A1 == 3 && A2 == 2)
			{
				Mps = Sps;
				cout << " After Assining\n Multiply=\n";
				Mps->PrintP();
			}

		}
		cout << " Do you want to check again ? (y/n)\n";
		cin >> Choice;
	} while (Choice == 'y');
	system("pause");
	return 0;
}
void LoadPoly(ifstream &Rdr, Polynomial** &Ps, int &Tc)
{
	Rdr >> Tc;
	Ps = new Polynomial*[Tc];
	for (int pi = 0; pi < Tc; pi++)
	{
		Ps[pi] = new Polynomial(Rdr);

	}
}
void PrintPoly(Polynomial *(*Ps), const int &Ts)
{
	for (int pi = 0; pi < Ts; pi++)
	{
		Ps[pi]->PrintP();
	}
}
ostream & operator<<(ostream & Console, const char *&S)
{
	Console << S << endl;
	return Console;
}