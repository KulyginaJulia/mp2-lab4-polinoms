#include "polinom.h"

//Ğåàëèçàöèÿ ñòğóêòóğû Node
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
void Node ::  PrintNode(Node *next){
	

}

//Ğåàëèçàöèÿ Polinom
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
