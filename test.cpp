#include "gtest/gtest.h"
#include "Composite/base.hpp"
#include "Composite/Burgers/veggies.hpp"
#include "Composite/Burgers/extras.hpp"
#include "Composite/Burgers/sauce.hpp"
#include "Composite/Burgers/burger.hpp"
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

int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

