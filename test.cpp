#include "gtest/gtest.h"
#include "base.hpp"
#include "veggies.hpp"
#include <iostream>

TEST(VeggieTest, ArrayInput){
	char array1[4] = {'Y','Y','Y','Y'};
	Veggies* test1 = new Veggies(array1);

	EXPECT_EQ(test1->price(), 0);
	EXPECT_EQ(test1->receipt(), "TOMATOES\nLETTUCE\nPICKLES\nONIONS");

	char array2[4] = {'N','N','N','N'};
        Veggies* test2 = new Veggies(array2);                                                                                                   
        
	EXPECT_EQ(test2->price(), 0);                                             
        EXPECT_EQ(test2->receipt(), "NO TOMATOES\nNO LETTUCE\nNO PICKLES\nNO ONIONS");

        char array3[4] = {'Y','N','Y','N'};
        Veggies* test3 = new Veggies(array3);                                                                                                   
        
	EXPECT_EQ(test3->price(), 0); 
        EXPECT_EQ(test3->receipt(), "TOMATOES\nNO LETTUCE\nPICKLES\nNO ONIONS");          
}

int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

