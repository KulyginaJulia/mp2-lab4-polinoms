#include <gtest.h>
#include "polinom.h"
#include "monom.h"
// тесты мономов и полиномов


TEST(Monome, Can_create_monom){
	ASSERT_NO_THROW(Monom m(0.5, 1, 1, 1));
}
TEST(Monom, Create_monom_with_negative_degree){
	ASSERT_ANY_THROW(Monom m(3.5, 1, -8, 1));
}
TEST(Monom, Can_copy_monom){
	Monom m1(3, 1, 1, 1);
	ASSERT_NO_THROW(Monom m2(m1));
}
TEST(Polinom, Can_create_polinom){
	ASSERT_NO_THROW(Polinom p());
}
TEST(Polinom, Can_create_polinom_with_parametres){
	Node *Megahead = 0;
	ASSERT_ANY_THROW(Polinom p(Megahead));
}

TEST(Node, Can_create_node){
	Node *Megahead = 0;
	Monom m(1.5 , 0, 0 , 0 );
	ASSERT_ANY_THROW(Node n(m, Megahead));
}

TEST(Node, Can_copy_node){
	Node *Megahead = 0;
	Monom m1(3, 1, 1, 1);
	Node n1(m1, Megahead);
	ASSERT_NO_THROW(Node n2(n1));
}

TEST(Polinom, Can_insert_monom_last){
	Monom m1(3, 1, 1, 1);
	Monom m2(5.4, 2, 1, 1);
	Node *Megahead = 0;
	Node n1(m1, Megahead);
	Polinom p(&n1);
	Polinom *curr = 0;
//	p.InsertLast(curr, m2);
	//EXPECT_EQ(m2, p.head);

}

//TEST(){
//
//
//}