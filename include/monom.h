// класс или структура Монома (double коэффициент, целая свернутая степень)
#pragma once

#include <iostream>

class Monom{
public:
	double coeff;
	int *deg;

	Monom();
	Monom(double coef, int a, int b, int c);
	Monom(Monom &m);
	~Monom();

	void Print(Monom *head); //Печать монома
//	void Insert

};