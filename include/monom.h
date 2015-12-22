// класс или структура Монома (double коэффициент, целая свернутая степень)
#pragma once

#include <iostream>
using namespace std;

class Monom{
public:
	double coeff;
	int *deg;

	Monom();
	Monom(double coeff, int *deg);
	Monom(double coef, int a, int b, int c);
	Monom(Monom &m);
	~Monom();

//	friend istream &operator>>(istream &istr, TBitField &bf);
 // friend ostream &operator<<(ostream &ostr, const TBitField &bf);
//	void PrintMonom(Monom *head); //Печать монома
	friend ostream &operator<<(ostream &ostr, const Monom *head);
	double GetCoeff() const;
	int * GetDegree() const;
	void SetCoeff(double c);
	void SetDegree(int *d);

	friend bool operator == (const Monom& A, const Monom& B);
 	friend bool operator != (const Monom& A, const Monom& B);
 	friend bool operator < (const Monom& A, const Monom& B);
 	friend bool operator > (const Monom& A, const Monom& B);
 	Monom& operator = (const Monom& B);
 
 	friend Monom operator + (const Monom& A, const Monom& B);
 	friend Monom operator - (const Monom& A, const Monom& B);
	friend Monom operator * (const Monom& A, const Monom& B);
	  
};