#include "polinom.h"
#include "monom.h"
#define eps 0.0001

//���������� ��������� Node
void Node :: SetMonom(Monom x) {
 	this->m = x;
}
void Node :: SetNext(Node *n) {
 		next = n;
}
Node* Node :: GetNext(){
 	return next;
}
Monom Node :: GetMonom() {
	return m;
}
 
Node :: Node() {
	SetMonom(Monom());
	SetNext(NULL);
}

Node :: Node(Monom x) {
 	SetMonom(x);
 	SetNext(NULL);
}
Node :: Node(Monom x, Node* n) {
 		SetMonom(x);
 		SetNext(n);
}

Node :: Node(Node &N){
	this->m = N.m;
	this->next = N.next;
}

Node :: ~Node(){
	if (next != NULL) delete next;
	delete &m;
}
//void Node :: PrintNode(Node *next){
//	Node *tmp;
//	while (tmp != NULL){
//		cout << tmp->m << endl;
//		tmp = tmp->next;
//	}
//}
//ostream &operator<<(ostream &ostr, const Node *next) // �����
//{
//	Node *tmp;
//	while (tmp != NULL){
//		ostr << tmp->m << endl;
//		tmp = tmp->next;
//		}
//	return ostr;
//}

//���������� Polinom

Polinom :: Polinom (Node *next){

	//if (next == NULL)
	//	throw "List without head";
	this->head = next;
}
Polinom :: Polinom(){
	head = NULL;
}
Polinom :: ~ Polinom(){
	// ������� ��� ������
	if (this->head != NULL) delete this->head;
}
//void Polinom :: PrintPolinom(Polinom *head){
//	Polinom *next;	
//	while (next != NULL){
//		cout << next->head->m << endl;
//		next = head->next;
//	}
//}
void Polinom :: InsertLast(Node *curr, Monom &data){
	curr->next = new Node(data);
	//curr->next->m = data;
	//curr->next->next = NULL;
}
void Polinom :: InsertMiddle(Node *curr, Monom &data){
	Node *elem = new Node(data, curr->next);
	//elem->m = data;
	//elem->next = curr->next;
	curr->next =  elem;
}
void Polinom :: InsertFirst(Node *&head, Monom &data){
	Node *elem = new Node;
	elem->m = data;
	elem->next = head;
	head = elem;
}
void Polinom :: DeleteFirst(Node *&head){
	Node *tmp = head;
	head = head->next;
	delete tmp;
}
void Polinom :: DeleteMiddle(Node *&prev){
	Node *tmp = prev;
	prev->next = tmp->next;
	delete tmp;
}
void Polinom :: Search(Node *&head, Monom &key){
	 Node *tmp = head; // ����������
	 while(tmp != NULL){
		 if( tmp->m == key) break;
		 else tmp = tmp->next;
	}
	 bool flag = false;
	 while (tmp != NULL){
		 if (tmp->m < key) tmp = tmp->next;
		 else {
			 flag = true;
			 break;
		 }
	 }
	 if (flag == true){
		 if (tmp->m != key) 
			 cout << "Wasn`t found";
	 }
}
Node* Polinom :: SearchForDelete(Node *&head, Monom &key){
	 Node *tmp = head; 
	 Node *prev = NULL;
	 while(tmp != NULL){
		 if( tmp->m == key) break;
		 else tmp = tmp->next;
	}
	 bool flag = false;
	 while (tmp != NULL){
		 if (tmp->m < key){
			 prev = tmp;
			 tmp = tmp->next;
		 }
		 else {
			 flag = true;
			 break;
		 }
	 }
	 if (flag == true){
		 if (tmp->m != key) 
			 return prev;
	 }
}
Polinom& Polinom :: Plus ( Polinom *&B,  Polinom *&C){
	Polinom *tmpA, *tmpB, *tmpC;
	tmpC->head = C->head->next;
	Node*prevC = C->head;
	tmpA->head = this->head->next;
	tmpB->head = B->head->next;

	double sum = this->head->m.GetCoeff() + tmpB->head->m.GetCoeff();
	
	while((tmpA != this)&& (tmpB != B)){
		if (this->head->m == tmpB->head->m) //��������� ��������
			if (abs(sum) >= eps){
				tmpC = new Polinom();
				tmpC->head->m.coeff = sum;
				prevC->next = tmpC->head;
			}
			if (this->head->m > tmpB->head->m){
				tmpC = new Polinom();
				tmpC->head->m = Monom(tmpB->head->GetMonom());
				prevC->next = tmpC->head;
				prevC = tmpC->head;
				tmpB->head = tmpB->head->next;
			}
			else {
				tmpC = new Polinom();
				tmpC->head->m = Monom(this->head->GetMonom());
				prevC->next = tmpC->head;
				prevC = tmpC->head;
				tmpB->head = tmpB->head->next;
			}
	}
	while(tmpA->head != this->head){
		tmpC = new Polinom();
		tmpC->head->m = Monom(this->head->GetMonom());
		prevC->next = tmpC->head;
		prevC = tmpC->head;
		tmpB->head = tmpB->head->next;
	}
	while(tmpB->head != B->head){
		tmpC = new Polinom();
		Monom tmp();
		tmpC->head->m = Monom(tmpB->head->GetMonom());
		prevC->next = tmpC->head;
		prevC = tmpC->head;
		tmpB->head = tmpB->head->next;
	}
	return *tmpC;
}

Polinom& Polinom :: Plus2 ( Polinom *&B,  Polinom *&C){
	// this = B + C
	// this = A
	Node *tmpA, *tmpB, *tmpC;
	// ��������� this
	tmpA = new Node(Monom(-1, -1, -1, -1)); // ��������� ������, ����� ����� �������
	tmpA = this->head;
	tmpB = this->head;
	tmpC = this->head;
	while((tmpB != NULL)&& (tmpC != NULL)) // ���� � � � �� ���������
	{
		//���������� ������� tmpC->data->degree � tmpB->data->degree
		//���� ��� =, ��
		// double sum = tmpB->m.GetCoeff() + tmpC->m.GetCoeff();
		//tmpC->SetNext = new Node(Monom(sum, degree));

	}
	return *this;	
}

Polinom& Polinom :: Minus ( Polinom *&B,  Polinom *&C){
	Polinom *tmpA, *tmpB, *tmpC;
	tmpC->head = C->head->next;
	Node*prevC = C->head;
	tmpA->head = this->head->next;
	tmpB->head = B->head->next;
	double min = this->head->m.GetCoeff() - tmpB->head->m.GetCoeff();
	while((tmpA != this)&& (tmpB != B)){
		if (this->head->m == tmpB->head->m) //��������� �������� 
			if ((min >= 0.00001) || (min <=  -0.00001)){
				tmpC = new Polinom();
				tmpC->head->m.coeff = min;
				prevC->next = tmpC->head;
			}
			if (this->head->m > tmpB->head->m){
				tmpC = new Polinom();
				tmpC->head->m = Monom(tmpB->head->GetMonom());
				prevC->next = tmpC->head;
				prevC = tmpC->head;
				tmpB->head = tmpB->head->next;
			}
			else {
				tmpC = new Polinom();
				tmpC->head->m = Monom(this->head->GetMonom());
				prevC->next = tmpC->head;
				prevC = tmpC->head;
				tmpB->head = tmpB->head->next;
			}
	}
	while(tmpA->head != this->head){
		tmpC = new Polinom();
		tmpC->head->m = Monom(this->head->GetMonom());
		prevC->next = tmpC->head;
		prevC = tmpC->head;
		tmpB->head = tmpB->head->next;
	}
	while(tmpB->head != B->head){
		tmpC = new Polinom();
		Monom tmp();
		tmpC->head->m = Monom(tmpB->head->GetMonom());
		prevC->next = tmpC->head;
		prevC = tmpC->head;
		tmpB->head = tmpB->head->next;
	}
	return *tmpC;
}
Polinom& Polinom :: Subtruct (const Polinom *&B, const Polinom *&C){
	Polinom *tmpA, *tmpB, *tmpC;
	tmpC->head = C->head->next;
	Node*prevC = C->head;
	tmpA->head = this->head->next;
	tmpB->head = B->head->next;
	while (tmpA->head != this->head ){
		while (tmpB->head != B->head){
		//�������������� � ������� tmpC = Insert(C, tmpC);
		}

	}
	return *this;

}
Polinom& Polinom :: Scalar (int scalar){

	return *this;
}
