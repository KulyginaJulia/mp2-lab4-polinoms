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

TEST(Monom, can_set_and_get) {
 	Monom m;
 	m.SetCoeff(10);
	int d[3];
	d[0] = 1;
	d[1] = 0;
	d[2] = 1;
 	m.SetDegree(d);
 
 	EXPECT_EQ(10, m.GetCoeff());
 	EXPECT_EQ(101, m.GetDegree());
 }
 TEST(Monom, can_check_equality)
 {
 	Monom a(1, 1, 2, 3);
 	Monom b(1, 1, 2, 3);
 	EXPECT_TRUE(a == b);
 }
 TEST(Monom, can_check_noy_equality_degree) {
 	Monom a(1, 1, 0, 0);
 	Monom b(1, 1, 2, 3);
 	EXPECT_FALSE(a == b);
 }
 
 TEST(Monom, can_compare_noy_equality_monoms_by_degree) {
 	Monom a(1, 1, 0, 0);
 	Monom b(1, 1, 2, 3);
 	EXPECT_TRUE(a < b);
 	EXPECT_FALSE(a > b);
 }
 
 TEST(Monom, can_add_monoms) {
 	Monom a(1, 1, 0, 0);
 	Monom b(2, 1, 0, 0);
 	Monom c = a + b;
 	EXPECT_EQ(3, c.GetCoeff());
 	EXPECT_EQ(100, c.GetDegree());
 }

TEST(Monom, can_multiply) {
	Monom a(3, 1, 0, 0);
	Monom b(2, 1, 0, 0);
	Monom c = a * b;
	EXPECT_EQ(6, c.GetCoeff());
	EXPECT_EQ(200, c.GetDegree());
}

TEST(Monom, can_not_multiply_whith_large_degrees) {
	Monom a(3, 9, 0, 1);
	Monom b(2, 1, 0, 9);
	Monom c;
	ASSERT_ANY_THROW(c = a * b);
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
