#include "gtest/gtest.h"
#include "include.hpp"

#include <iostream>

TEST(BurgerTest, VeggieArray){
	char array1[4] = {'Y','Y','Y','Y'};
	Veggies* test1 = new Veggies(array1);

	EXPECT_EQ(test1->price(), 0);
	EXPECT_EQ(test1->receipt(), "TOMATOES\nLETTUCE\nPICKLES\nONIONS");

	char array2[4] = {'N','N','N','N'};
        Veggies* test2 = new Veggies(array2);                                                                                                   
        
	EXPECT_EQ(test2->price(), 0);                                             
        EXPECT_EQ(test2->receipt(), "NO VEGGIES");

        char array3[4] = {'Y','N','Y','N'};
        Veggies* test3 = new Veggies(array3);                                                                                                   
        
	EXPECT_EQ(test3->price(), 0); 
        EXPECT_EQ(test3->receipt(), "TOMATOES\nPICKLES");          
}

TEST(BurgerTest, ExtrasArray){
	char array1[3] = {'Y', 'Y', 'Y'};
	Extras* test1 = new Extras(array1);
	
	EXPECT_DOUBLE_EQ(test1->price(), 4.00);
	EXPECT_EQ(test1->receipt(), "EXTRA PATTY\nBACON\nEXTRA CHEESE");

	char array2[3] = {'N', 'N', 'N'};  
        Extras* test2 = new Extras(array2);
	
	EXPECT_DOUBLE_EQ(test2->price(), 0.00);
	EXPECT_EQ(test2->receipt(), "NO EXTRAS");

	char array3[3] = {'Y', 'N', 'Y'};
	Extras* test3 = new Extras(array3);

	EXPECT_DOUBLE_EQ(test3->price(), 2.50);
	EXPECT_EQ(test3->receipt(), "EXTRA PATTY\nEXTRA CHEESE");
}

TEST(BurgerTest, SauceArray){
	char array1[3] = {'Y', 'Y', 'Y'};
	Sauce* test1 = new Sauce(array1);

	EXPECT_DOUBLE_EQ(test1->price(), 0.50);
	EXPECT_EQ(test1->receipt(), "KETCHUP\nMUSTARD\nA1 SAUCE");

	char array2[3] = {'N', 'N', 'N'};
	Sauce* test2 = new Sauce(array2);

	EXPECT_DOUBLE_EQ(test2->price(), 0);
	EXPECT_EQ(test2->receipt(), "NO SAUCE");
	
	char array3[3] = {'Y','Y','N'};
	Sauce* test3 = new Sauce(array3);

	EXPECT_DOUBLE_EQ(test3->price(), 0);
	EXPECT_EQ(test3->receipt(), "KETCHUP\nMUSTARD");
}

TEST(BurgerTest, EverythingBurger){
	char array1[4] = {'Y','Y','Y','Y'};
	Veggies* test1 = new Veggies(array1);

	EXPECT_EQ(test1->price(), 0);
	EXPECT_EQ(test1->receipt(), "TOMATOES\nLETTUCE\nPICKLES\nONIONS");

	char array2[3] = {'Y', 'Y', 'Y'};
	Extras* test2 = new Extras(array2);
	
	EXPECT_DOUBLE_EQ(test2->price(), 4.00);
	EXPECT_EQ(test2->receipt(), "EXTRA PATTY\nBACON\nEXTRA CHEESE");

	char array3[3] = {'Y', 'Y', 'Y'};
	Sauce* test3 = new Sauce(array3);

	EXPECT_DOUBLE_EQ(test3->price(), 0.50);
	EXPECT_EQ(test3->receipt(), "KETCHUP\nMUSTARD\nA1 SAUCE");

	Burger* doubleDouble = new Burger(test1, test2, test3);
	EXPECT_DOUBLE_EQ(doubleDouble->price(), 8.00);
	EXPECT_EQ(doubleDouble->receipt(), "PERSONAL BURGER\nADD\nTOMATOES\nLETTUCE\nPICKLES\nONIONS\nEXTRA PATTY\nBACON\nEXTRA CHEESE\nKETCHUP\nMUSTARD\nA1 SAUCE");
}

TEST(BurgerTest, ComboBurger){
	char array1[4] = {'Y','Y','Y','Y'};
	Veggies* test1 = new Veggies(array1);

	EXPECT_EQ(test1->price(), 0);
	EXPECT_EQ(test1->receipt(), "TOMATOES\nLETTUCE\nPICKLES\nONIONS");

	char array2[3] = {'N', 'N', 'N'};  
        Extras* test2 = new Extras(array2);
	
	EXPECT_DOUBLE_EQ(test2->price(), 0.00);
	EXPECT_EQ(test2->receipt(), "NO EXTRAS");

	char array3[3] = {'Y','Y','N'};
	Sauce* test3 = new Sauce(array3);

	EXPECT_DOUBLE_EQ(test3->price(), 0);
	EXPECT_EQ(test3->receipt(), "KETCHUP\nMUSTARD");
	
	Burger* bigMac = new Burger(test1, test2, test3);
	EXPECT_DOUBLE_EQ(bigMac->price(), 3.50);
	EXPECT_EQ(bigMac->receipt(), "PERSONAL BURGER\nADD\nTOMATOES\nLETTUCE\nPICKLES\nONIONS\nNO EXTRAS\nKETCHUP\nMUSTARD");
}

TEST(BurgerTest, PlainBurger){
	char array1[4] = {'N','N','N','N'};
        Veggies* test1 = new Veggies(array1);                                                                                                   
        
	EXPECT_EQ(test1->price(), 0);                                             
        EXPECT_EQ(test1->receipt(), "NO VEGGIES");

	char array2[3] = {'N', 'N', 'N'};  
        Extras* test2 = new Extras(array2);
	
	EXPECT_DOUBLE_EQ(test2->price(), 0.00);
	EXPECT_EQ(test2->receipt(), "NO EXTRAS");

	char array3[3] = {'N', 'N', 'N'};
	Sauce* test3 = new Sauce(array3);

	EXPECT_DOUBLE_EQ(test3->price(), 0);
	EXPECT_EQ(test3->receipt(), "NO SAUCE");

	Burger* why = new Burger(test1, test2, test3);
	EXPECT_DOUBLE_EQ(why->price(), 3.50);
	EXPECT_EQ(why->receipt(), "PERSONAL BURGER\nADD\nNO VEGGIES\nNO EXTRAS\nNO SAUCE");
}

TEST(WingTest, WingCount){
	WingCount* three = new WingCount(3);
	WingCount* six = new WingCount(6);
	WingCount* nine = new WingCount(9);
	WingCount* twelve = new WingCount(12);
	
	EXPECT_EQ(three->price(), 3.00);
	EXPECT_EQ(six->price(), 6.00);
	EXPECT_EQ(nine->price(), 9.00);
	EXPECT_EQ(twelve->price(), 12.00);

	EXPECT_EQ(three->receipt(),"3");
	EXPECT_EQ(six->receipt(), "6");
	EXPECT_EQ(nine->receipt(), "9");
	EXPECT_EQ(twelve->receipt(), "12");
}

TEST(WingTest, WingSauceArray){
	int sau1[3] = {3, 0, 0};
	int sau2[6] = {0, 6, 0};
	int sau3[9] = {0, 0, 9};
	int sau4[12] = {4, 4, 4};
	
	WingSauce* buff = new WingSauce(sau1);
	WingSauce* bbq = new WingSauce(sau2);
	WingSauce* plain = new WingSauce(sau3);
	WingSauce* combo = new WingSauce(sau4);

	EXPECT_DOUBLE_EQ(buff->price(), 0.30);
	EXPECT_DOUBLE_EQ(bbq->price(), 0.60);
	EXPECT_EQ(plain->price(), 0);
	EXPECT_DOUBLE_EQ(combo->price(), 0.80);

	EXPECT_EQ(buff->receipt(), "BUFFALO WINGS");
	EXPECT_EQ(bbq->receipt(), "BBQ WINGS");
	EXPECT_EQ(plain->receipt(), "PLAIN WINGS");
	EXPECT_EQ(combo->receipt(), "COMBO WINGS\n- 4 BUFFALO\n- 4 BBQ\n- 4 PLAIN");
}

TEST(WingTest, FrySeasoningArray){
	char c1[2] = {'C', 'C'};
	char c2[2] = {'R', 'S'};
	char c3[2] = {'H', 'N'};
	char none[2] = {'N', 'N'};

	FrySeasoning* cc = new FrySeasoning(c1);
	FrySeasoning* rs = new FrySeasoning(c2);
	FrySeasoning* hn = new FrySeasoning(c3);
	FrySeasoning* non = new FrySeasoning(none);

	EXPECT_DOUBLE_EQ(cc->price(), 1.99);
	EXPECT_DOUBLE_EQ(rs->price(), 1.59);
	EXPECT_DOUBLE_EQ(hn->price(), 1.79);
	EXPECT_EQ(non->price(), 0);

	EXPECT_EQ(cc->receipt(), "CURLY FRIES w/ CAJUN");
	EXPECT_EQ(rs->receipt(), "REG. FRIES w/ SEA SALT");
	EXPECT_EQ(hn->receipt(), "HALFSIES FRIES w/ NO SEASONING");
	EXPECT_EQ(non->receipt(), "NO FRIES ");
}

TEST(WingTest, DippingSauceArray){
	int c1[4] = {1, 2, 1, 2};
	int c2[4] = {0, 0, 1, 2};
	int c3[4] = {1, 2, 0, 0};
	int c4[4] = {0, 0, 0, 0};

	DippingSauce* dip1 = new DippingSauce(c1);
	DippingSauce* dip2 = new DippingSauce(c2);
	DippingSauce* dip3 = new DippingSauce(c3);
	DippingSauce* dip4 = new DippingSauce(c4);
	
	EXPECT_DOUBLE_EQ(dip1->price(), 1.00);
	EXPECT_DOUBLE_EQ(dip2->price(), 0.50);
	EXPECT_DOUBLE_EQ(dip3->price(), 0.50);
	EXPECT_EQ(dip4->price(), 0);

	EXPECT_EQ(dip1->receipt(), "+ 2 RANCH(ES)\n+ 2 BLUE CHEESE");
	EXPECT_EQ(dip2->receipt(), "+ 2 BLUE CHEESE");
	EXPECT_EQ(dip3->receipt(), "+ 2 RANCH(ES)");
	EXPECT_EQ(dip4->receipt(), "NO SAUCE");
}
 
int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

