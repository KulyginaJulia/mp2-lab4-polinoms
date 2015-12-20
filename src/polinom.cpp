#include "polinom.h"
#include "monom.h"

//Реализация структуры Node
Node :: Node(Monom m, Node *next){
	if (next == NULL)
		throw "next is empty";
	this->m = m;
	this->next = next;
}
Node :: Node(){
	if (next != NULL) next = NULL; 
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
ostream &operator<<(ostream &ostr, const Node *next) // вывод
{
	Node *tmp;
	while (tmp != NULL){
		ostr << tmp->m << endl;
		tmp = tmp->next;
		}
	return ostr;
}
//Реализация Polinom
Polinom :: Polinom (Node *next){

	//if (next == NULL)
	//	throw "List without head";
	this->head = next;
}
Polinom :: Polinom(){
	head = NULL;
}
Polinom :: ~ Polinom(){
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
	curr->next = new Node;
	curr->next->m = data;
	curr->next->next = NULL;
}
void Polinom :: InsertMiddle(Node *curr, Monom &data){
	Node *elem = new Node;
	elem->m = data;
	elem->next = curr->next;
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
	 Node *tmp;
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
	 Node *tmp; Node *prev = NULL;
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
	 if (flag == true){            //не уверена
		 if (tmp->m != key) 
			 return prev;
	 }
}
Polinom& Polinom :: Plus (Polinom *&B, Polinom *&C){
	Node *tmpA, *tmpB, *tmpC;
	tmpC = C->head->next;
	Node*prevC = C;
	tmpA = this->head->next;
	tmpB = B->head->next;
	while((tmpA != this)&& (tmpB != B)){
		if (this->head->m->deg == tmpB->head->m->deg)
			if (abs(this->head->m->coeff + tmpB->head->m->coeff) > eps){
				tmpC = new Polinom();
				tmpC->head->m->coeff = this->head->m->coeff + tmpB->head->m->coeff;
				prevC->next = tmpC;
			}
			if (this->head->m->deg > tmpB->m->deg){
				tmpC = new Polinom();
				tmpC->m(tmpB->m);
				prevC->next = tmpC;
				prevC = tmpC;
				tmpB = tmpB->next;
			}
			else {
				tmpC = new Polinom();
				tmpC->m(this->head->m);
				prevC->next = tmpC;
				prevC = tmpC;
				tmpB = tmpB->next;
			}
	}
	while(this->head != this){
	
	}
	while(tmpB != B){
	
	}
}
Polinom& Polinom :: Subtruct (const Polinom *&B, const Polinom &C){


}
Polinom& Polinom :: Scalar (int scalar){


}
