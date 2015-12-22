// класс Полином - упорядоченный односвязный список Мономов
// поддерживает операции Печать, Вставка монома, Удаление монома,  
// Поиск монома, Сложение полиномов(слияние упорядоченных списков), 
// Умножение полиномов

#ifndef _POLINOM_H_
#define _POLINOM_H


#include <iostream>
#include "monom.h"

using namespace std;

struct Node{
//Звено Node
	Monom m;
	Node *next;

	Node();
	Node(Monom x, Node *next);
	Node(Node &N);
	Node (Monom x);
	~Node();
	void SetMonom(Monom x);
	void SetNext(Node *n);
	Node * GetNext();
	Monom GetMonom();
//	void PrintNode(Node *next);
	friend ostream &operator<<(ostream &ostr, const Node *head);
};

class Polinom
{
public:
	Node* head;

	Polinom();
	Polinom(Node *next);
	~Polinom();

	void PrintPolinom(Polinom *head);//Печать полинома
	
	void InsertLast(Node *curr, Monom &data);//вставка монома в конец списка
	void InsertFirst(Node *&head, Monom &data); //вставка монома в начало списка
	void InsertMiddle(Node *curr, Monom &data); //вставка монома в середину списка
	
	void DeleteFirst(Node *&head);//Удаление первого
	void DeleteMiddle(Node *&head);//Удаление из середины
	
	void Search(Node *&head, Monom &key);//поиск
	Node* SearchForDelete(Node *&head, Monom &key);

	Polinom& Plus ( Polinom *&B,  Polinom *&C);
	Polinom& Plus2 ( Polinom *&B,  Polinom *&C);
	Polinom& Minus ( Polinom *&B,  Polinom *&C);
	Polinom& Subtruct (const Polinom *&B, const Polinom *&C);
	Polinom& Scalar (int scalar);

};

#endif