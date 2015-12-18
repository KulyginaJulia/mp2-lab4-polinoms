// ����� ������� - ������������� ����������� ������ �������
// ������������ �������� ������, ������� ������, �������� ������,  
// ����� ������, �������� ���������(������� ������������� �������), 
// ��������� ���������

#ifndef _POLINOM_H_
#define _POLINOM_H

#include <iostream>
#include "monom.h"

struct Node{
//����� Node
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

	void PrintPol(Polinom *head);//������ ��������
	
	void InsertLast(Polinom *curr, Monom *data);//������� ������ � ����� ������
	void InsertFirst(Polinom &head, Monom *data); //������� ������ � ������ ������
	void InsertMiddle(Polinom &curr, Monom *data); //������� ������ � �������� ������
	
	void DeleteFirst(Polinom *&head);//�������� �������
	void DeleteMiddle(Polinom *&head);//�������� �� ��������
	
	Polinom* Search(Polinom *head, Monom *key);//�����

	Polinom& operator+ (const Polinom &p);
	Polinom& operator* (const Polinom &p);
};

#endif