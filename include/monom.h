// класс или структура Монома (double коэффициент, целая свернутая степень)
#pragma once

#include <iostream>
using namespace std;

class Monom{
public:
	double coeff;
	int *deg;

	Monom();
	Monom(double coef, int a, int b, int c);
	Monom(Monom &m);
	~Monom();

//	friend istream &operator>>(istream &istr, TBitField &bf);       //      (#О7)
 // friend ostream &operator<<(ostream &ostr, const TBitField &bf); //      (#П4)
//	void PrintMonom(Monom *head); //Печать монома
	friend ostream &operator<<(ostream &ostr, const Monom *head);
//	void Insert
	  
};