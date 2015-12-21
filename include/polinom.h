// ����� ������� - ������������� ����������� ������ �������
// ������������ �������� ������, ������� ������, �������� ������,  
// ����� ������, �������� ���������(������� ������������� �������), 
// ��������� ���������

#ifndef _POLINOM_H_
#define _POLINOM_H

#define eps = 0.00001
#include <iostream>
#include "monom.h"

using namespace std;

struct Node{
//����� Node
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

	void PrintPolinom(Polinom *head);//������ ��������
	
	void InsertLast(Node *curr, Monom &data);//������� ������ � ����� ������
	void InsertFirst(Node *&head, Monom &data); //������� ������ � ������ ������
	void InsertMiddle(Node *curr, Monom &data); //������� ������ � �������� ������
	
	void DeleteFirst(Node *&head);//�������� �������
	void DeleteMiddle(Node *&head);//�������� �� ��������
	
	void Search(Node *&head, Monom &key);//�����
	Node* SearchForDelete(Node *&head, Monom &key);

	Polinom& Plus (const Polinom *&B, const Polinom *&C);
	Polinom& Subtruct (const Polinom *&B, const Polinom *&C);
	Polinom& Scalar (int scalar);

};

#endif