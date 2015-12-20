#include "monom.h" 
#include "polinom.h"
Monom :: Monom (double coef, int a, int b, int c){

	if ((a < 0) || (b < 0) || (c < 0))
		throw "Degree has a negative value";

	this->deg = new int [3];
	
	this->deg[0] = a;
	this->deg[1] = b;
	this->deg[2] = c;
	this->coeff = coef;
}
Monom :: ~Monom(){
	delete []this->deg;
}
Monom :: Monom(Monom &m){
	this->deg = new int [3];

	for (int i = 0; i < 2; i++)
		m.deg[i] = deg[i];
	this->coeff = m.coeff;
}
Monom :: Monom(){
	deg = NULL;
}
void Monom :: PrintMonom(Monom *head){
	while (head != NULL){
		cout << "coeff = " << head->coeff << endl;
		cout << "deg = " << head->deg << endl;
	}
}
ostream &operator<<(ostream &ostr, const Monom *head) // вывод
{
	while (head != NULL){
		ostr << "coeff = " << head->coeff << endl;
		ostr << "deg = " << head->deg << endl;
			}
	return ostr;
}