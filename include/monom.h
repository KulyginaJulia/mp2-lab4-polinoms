// ����� ��� ��������� ������ (double �����������, ����� ��������� �������)
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

//	friend istream &operator>>(istream &istr, TBitField &bf);       //      (#�7)
 // friend ostream &operator<<(ostream &ostr, const TBitField &bf); //      (#�4)
//	void PrintMonom(Monom *head); //������ ������
	friend ostream &operator<<(ostream &ostr, const Monom *head);
//	void Insert
	  
};