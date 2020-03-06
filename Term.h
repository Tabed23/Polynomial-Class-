#pragma once
#include<iostream>
#include<fstream>
class Term
{
private:
	float Const;
	int Drgee;
public:
	Term();
	~Term();
	Term(float, int);
	void SetConst(const float);
	float GetConst()const;
	void SetDgree(const int);
	int GetDrgee() const;
	bool IsNeg();
	void PrintTerm();
};

