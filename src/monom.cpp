
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
Monom :: Monom(double coeff, int *deg){
	this->deg = new int[3];
	for (int i = 0; i < 3; i++)
		this->deg[i] = deg[i];
	this->coeff = coeff;
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
	coeff = 0;
}
//void Monom :: PrintMonom(Monom *head){
//	while (head != NULL){
//		cout << "coeff = " << head->coeff << endl;
//		cout << "deg = " << head->deg << endl;
//	}
//}
ostream &operator<<(ostream &ostr, const Monom *head) // вывод
{
	while (head != NULL){
		ostr << "coeff = " << head->coeff << endl;
		ostr << "deg = " << head->deg << endl;
			}
	return ostr;
}
double Monom :: GetCoeff() const
 {
 	return coeff;
 }
 
 int* Monom :: GetDegree() const
 {
 	return deg;
 }
 
 void Monom :: SetCoeff(double c)
 {
 	coeff = c;
 }
 
 void Monom :: SetDegree(int *d)
 {
	 for(int i = 0; i < 3; i++)
 		deg[i] = d[i];
 }
 
 Monom& Monom :: operator=(const Monom& A)
 {
 	if (this == &A) {
 		return *this;
 	}
 	coeff = A.GetCoeff();
 	deg = A.GetDegree();
 	return *this;
 }
 
 bool operator==(const Monom& A,const Monom& B)
 {
	 bool flag = true;
	 for (int i = 0; i < 3; i++)
		 if (A.deg[i] != B.deg[i])
			 flag =  false;
 	return flag;
 }
 
 bool operator!=(const Monom& A, const Monom& B)
 {
 	return !(A == B);
 }
 
 bool operator < (const Monom& A, const Monom& B)
 {
	for(int i = 0; i < 3; i++)
	 if (A.deg[i] > B.deg[i])
			return false;
 	return true;
 }
 
 bool operator > (const Monom& A,const Monom& B)
 {
	 for(int i = 0; i < 3; i++)
		 if (A.deg[i] < B.deg[i])
			 return false;
 	return true;
 }
Monom operator + (const Monom& A, const Monom& B)
 {
	if (A != B)
 	{
 		throw "Different degrees";
 	}
 	Monom res(A.GetCoeff() + B.GetCoeff(), A.GetDegree());
 	return res;
 }
 
Monom operator - (const Monom& A, const Monom& B) {
	if (A != B) {
 		throw "Different degrees";
 	}
 	Monom res(A.GetCoeff() - B.GetCoeff(), A.GetDegree());
 	return res;
}

Monom operator*(const Monom& A, const Monom& B){
	
	double m = A.GetCoeff() * B.GetCoeff();
	bool flag = true;
	for (int i = 0; i < 3; i++)
			if (A.deg[i] != B.deg[i]){
				flag = false;
				break;
			}
	if (flag == false) {
		throw("Different degrees.");
	}
	Monom res(m, A.GetDegree());
	return res;
}