// класс Полином - упорядоченный односвязный список Мономов
// поддерживает операции Печать, Вставка монома, Удаление монома,  
// Поиск монома, Сложение полиномов(слияние упорядоченных списков), 
// Умножение полиномов

#ifndef _POLINOM_H_
#define _POLINOM_H

#include <iostream>
#include "monom.h"

struct Node{
//Звено Node
	Monom m;
	Node *next;

	Node();
	Node(Monom m, Node *next);
	Node(Node &N);
	~Node();
	void PrintNode(Node *next);
};


class Polinom
{
public:
	Node* head;

	Polinom();
	Polinom(Node *next);
	~Polinom();

	void PrintPol(Polinom *head);//Печать полинома
	
	void InsertLast(Polinom *curr, Monom *data);//вставка монома в конец списка
	void InsertFirst(Polinom &head, Monom *data); //вставка монома в начало списка
	void InsertMiddle(Polinom &curr, Monom *data); //вставка монома в середину списка
	
	void DeleteFirst(Polinom *&head);//Удаление первого
	void DeleteMiddle(Polinom *&head);//Удаление из середины
	
	Polinom* Search(Polinom *head, Monom *key);//поиск

	Polinom& operator+ (const Polinom &p);
	Polinom& operator* (const Polinom &p);
};

#endif