#include "gtest/gtest.h"
#include "base.hpp"
#include "veggies.hpp"
#include <iostream>

TEST(VeggieTest, ArrayInput){
	char array[4] = {'Y','Y','Y','Y'};
	Veggies* test_val = new Veggies(array);

	EXPECT_EQ(test_val->price(), 0);
	EXPECT_EQ(test_val->receipt(), "TOMATOES\nLETTUCE\nPICKLES\nONIONS");
}

int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

