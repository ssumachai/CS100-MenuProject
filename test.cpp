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

TEST(WingTest, PlainBasket){
	int sauce[3] = {0, 0, 3};
	char fries[2] = {'N', 'N'};
	int dipp[4] = {0, 0, 0, 0};
	
	WingCount* three = new WingCount(3);
	WingSauce* plain = new WingSauce(sauce);
	FrySeasoning* noFries = new FrySeasoning(fries);
	DippingSauce* dips = new DippingSauce(dipp);
	
	EXPECT_DOUBLE_EQ(three->price(), 3.00);
	EXPECT_DOUBLE_EQ(plain->price(), 0.00);
	EXPECT_DOUBLE_EQ(noFries->price(), 0.00);
	EXPECT_DOUBLE_EQ(dips->price(), 0.00);
	
	EXPECT_EQ(three->receipt(), "3");
	EXPECT_EQ(plain->receipt(), "PLAIN WINGS");
	EXPECT_EQ(noFries->receipt(), "NO FRIES ");
	EXPECT_EQ(dips->receipt(), "NO SAUCE");
	
	Wing* basket = new Wing(three, plain, noFries, dips);
	EXPECT_DOUBLE_EQ(basket->price(), 3.00);
	EXPECT_EQ(basket->receipt(), "WING BASKET\n3 PLAIN WINGS\nNO FRIES \nNO SAUCE");
}

TEST(WingTest, BuffaloBasket){
	int sauce[3] = {6, 0, 0};
	char fries[2] = {'C', 'C'};
	int dipp[4] = {1, 1, 1, 2};
	
	WingCount* six = new WingCount(6);
	WingSauce* buff = new WingSauce(sauce);
	FrySeasoning* curlyCajun = new FrySeasoning(fries);
	DippingSauce* dips = new DippingSauce(dipp);
	
	EXPECT_DOUBLE_EQ(six->price(), 6.00);
	EXPECT_DOUBLE_EQ(buff->price(), 0.60);
	EXPECT_DOUBLE_EQ(curlyCajun->price(), 1.99);
	EXPECT_DOUBLE_EQ(dips->price(), 0.75);
	
	EXPECT_EQ(six->receipt(), "6");
	EXPECT_EQ(buff->receipt(), "BUFFALO WINGS");
	EXPECT_EQ(curlyCajun->receipt(), "CURLY FRIES w/ CAJUN");
	EXPECT_EQ(dips->receipt(), "+ 1 RANCH(ES)\n+ 2 BLUE CHEESE");
	
	Wing* basket = new Wing(six, buff, curlyCajun, dips);
	EXPECT_DOUBLE_EQ(basket->price(), 9.34);
	EXPECT_EQ(basket->receipt(), "WING BASKET\n6 BUFFALO WINGS\nCURLY FRIES w/ CAJUN\n+ 1 RANCH(ES)\n+ 2 BLUE CHEESE");
}

TEST(WingTest, BBQBasket){
	int sauce[3] = {0, 9, 0};
	char fries[2] = {'R', 'S'};
	int dipp[4] = {1, 4, 0, 0};
	
	WingCount* nine = new WingCount(9);
	WingSauce* bbq = new WingSauce(sauce);
	FrySeasoning* regSeaSalt = new FrySeasoning(fries);
	DippingSauce* dips = new DippingSauce(dipp);
	
	EXPECT_DOUBLE_EQ(nine->price(), 9.00);
	EXPECT_DOUBLE_EQ(bbq->price(), 0.90);
	EXPECT_DOUBLE_EQ(regSeaSalt->price(), 1.59);
	EXPECT_DOUBLE_EQ(dips->price(), 1.00);
	
	EXPECT_EQ(nine->receipt(), "9");
	EXPECT_EQ(bbq->receipt(), "BBQ WINGS");
	EXPECT_EQ(regSeaSalt->receipt(), "REG. FRIES w/ SEA SALT");
	EXPECT_EQ(dips->receipt(), "+ 4 RANCH(ES)");
	
	Wing* basket = new Wing(nine, bbq, regSeaSalt, dips);
	EXPECT_DOUBLE_EQ(basket->price(), 12.49);
	EXPECT_EQ(basket->receipt(), "WING BASKET\n9 BBQ WINGS\nREG. FRIES w/ SEA SALT\n+ 4 RANCH(ES)");
}

TEST(WingTest, ComboBasket){
	int sauce[3] = {6, 3, 3};
	char fries[2] = {'H', 'N'};
	int dipp[4] = {1, 2, 1, 2};
	
	WingCount* twelve = new WingCount(12);
	WingSauce* combo = new WingSauce(sauce);
	FrySeasoning* halfNo = new FrySeasoning(fries);
	DippingSauce* dips = new DippingSauce(dipp);
	
	EXPECT_DOUBLE_EQ(twelve->price(), 12.00);
	EXPECT_DOUBLE_EQ(combo->price(), 0.90);
	EXPECT_DOUBLE_EQ(halfNo->price(), 1.79);
	EXPECT_DOUBLE_EQ(dips->price(), 1.00);
	
	EXPECT_EQ(twelve->receipt(), "12");
	EXPECT_EQ(combo->receipt(), "COMBO WINGS\n- 6 BUFFALO\n- 3 BBQ\n- 3 PLAIN");
	EXPECT_EQ(halfNo->receipt(), "HALFSIES FRIES w/ NO SEASONING");
	EXPECT_EQ(dips->receipt(), "+ 2 RANCH(ES)\n+ 2 BLUE CHEESE");
	
	Wing* basket = new Wing(twelve, combo, halfNo, dips);
	EXPECT_DOUBLE_EQ(basket->price(), 15.69);
	EXPECT_EQ(basket->receipt(), "WING BASKET\n12 COMBO WINGS\n- 6 BUFFALO\n- 3 BBQ\n- 3 PLAIN\nHALFSIES FRIES w/ NO SEASONING\n+ 2 RANCH(ES)\n+ 2 BLUE CHEESE");
}

TEST(SaladTest, LettuceInput){
	Lettuce* rom = new Lettuce('R');
	Lettuce* ice = new Lettuce('I');
	Lettuce* mix = new Lettuce('S');
	Lettuce* kale = new Lettuce('K');

	EXPECT_DOUBLE_EQ(rom->price(), 2.00);
	EXPECT_DOUBLE_EQ(ice->price(), 2.00);
	EXPECT_DOUBLE_EQ(mix->price(), 2.25);
	EXPECT_DOUBLE_EQ(kale->price(), 3.00);

	EXPECT_EQ(rom->receipt(), "ROMAINE LETTUCE");
	EXPECT_EQ(ice->receipt(), "ICEBERG LETTUCE");
	EXPECT_EQ(mix->receipt(), "SPRING MIX");
	EXPECT_EQ(kale->receipt(), "KALE SLAW");
}

TEST(SaladTest, ToppingArray){
	char array1[9] = {'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y'};
	Toppings* allToppings = new Toppings(array1);

	EXPECT_DOUBLE_EQ(allToppings->price(), 2.00);
	EXPECT_EQ(allToppings->receipt(), "- GRAPE TOMATOES\n- CUCUMBERS\n- CORN\n- BLACK BEANS\n- CROUTONS\n- EGG\n- CHEESE BLEND\n- AVOCADO\n- DICED BACON");

	char array2[9] = {'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N'};
	Toppings* noToppings = new Toppings(array2);
	
	EXPECT_EQ(noToppings->price(), 0);
	EXPECT_EQ(noToppings->receipt(), "- NO TOPPINGS");

	char array3[9] = {'Y', 'N', 'Y', 'N', 'Y', 'N', 'Y', 'N', 'Y'};
	Toppings* mixToppings = new Toppings(array3);
	
	EXPECT_DOUBLE_EQ(mixToppings->price(), 0.75);
	EXPECT_EQ(mixToppings->receipt(), "- GRAPE TOMATOES\n- CORN\n- CROUTONS\n- CHEESE BLEND\n- DICED BACON");
}

TEST(SaladTest, ProteinArray){
	char array1[3] = {'Y', 'Y', 'Y'};
	Protein* superGainz = new Protein(array1);
	
	EXPECT_DOUBLE_EQ(superGainz->price(), 5.25);
	EXPECT_EQ(superGainz->receipt(), "- GRILLED CHICKEN\n- GRILLED SALMON\n- SOY CHICKEN");

	char array2[3] = {'N', 'N', 'N'};
	Protein* sadGainz = new Protein(array2);
	
	EXPECT_EQ(sadGainz->price(), 0);
	EXPECT_EQ(sadGainz->receipt(), "- NO PROTEIN");

	char array3[3] = {'Y', 'N', 'Y'};
	Protein* mehGainz = new Protein(array3);

	EXPECT_DOUBLE_EQ(mehGainz->price(), 3.25);
	EXPECT_EQ(mehGainz->receipt(), "- GRILLED CHICKEN\n- SOY CHICKEN");
}

TEST(SaladTest, DressingArray){
	char rSide[2] = {'R', 'Y'};
	char cae[2] = {'C', 'N'};
	char no[2] = {'N', 'N'};
	
	Dressing* ranchOnSide = new Dressing(rSide);
	Dressing* caesar = new Dressing(cae);
	Dressing* dry = new Dressing(no);

	EXPECT_EQ(ranchOnSide->price(), 0);
	EXPECT_EQ(caesar->price(), 0);
	EXPECT_EQ(dry->price(), 0);
	
	EXPECT_EQ(ranchOnSide->receipt(), "RANCH DRESSING ON SIDE");
	EXPECT_EQ(caesar->receipt(), "CAESAR DRESSING");
	EXPECT_EQ(dry->receipt(), "NO DRESSING");
}

TEST(SaladTest, SadSalad){
	char array1[9] = {'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N'};
	char array2[3] = {'N', 'N', 'N'};
	char array3[3] = {'N', 'N'};
	
	Lettuce* romaine = new Lettuce('R');
	Toppings* noToppings = new Toppings(array1);
	Protein* sadGainz = new Protein(array2);
	Dressing* dry = new Dressing(array3);
	
	EXPECT_DOUBLE_EQ(romaine->price(), 2.00);
	EXPECT_DOUBLE_EQ(noToppings->price(), 0);
	EXPECT_DOUBLE_EQ(sadGainz->price(), 0);
	EXPECT_DOUBLE_EQ(dry->price(), 0);
	
	EXPECT_EQ(romaine->receipt(), "ROMAINE LETTUCE");
	EXPECT_EQ(noToppings->receipt(), "- NO TOPPINGS");
	EXPECT_EQ(sadGainz->receipt(), "- NO PROTEIN");
	EXPECT_EQ(dry->receipt(), "NO DRESSING");

	Salad* why = new Salad(romaine, noToppings, sadGainz, dry);
	EXPECT_DOUBLE_EQ(why->price(), 2.49);
	EXPECT_EQ(why->receipt(), "PERSONAL SALAD\nROMAINE LETTUCE WITH\n- NO TOPPINGS\nADD\n- NO PROTEIN\nWITH NO DRESSING");
}

TEST(SaladTest, NormalSalad){
	char array1[9] = {'Y', 'N', 'Y', 'N', 'Y', 'Y', 'Y', 'Y', 'N'};
	char array2[3] = {'Y', 'N', 'N'};
	char array3[3] = {'S', 'N'};
	
	Lettuce* spring = new Lettuce('S');
	Toppings* myToppings = new Toppings(array1);
	Protein* iTry = new Protein(array2);
	Dressing* heh = new Dressing(array3);
	
	EXPECT_DOUBLE_EQ(spring->price(), 2.25);
	EXPECT_DOUBLE_EQ(myToppings->price(), 1.25);
	EXPECT_DOUBLE_EQ(iTry->price(), 1.50);
	EXPECT_DOUBLE_EQ(heh->price(), 0);
	
	EXPECT_EQ(spring->receipt(), "SPRING MIX");
	EXPECT_EQ(myToppings->receipt(), "- GRAPE TOMATOES\n- CORN\n- CROUTONS\n- EGG\n- CHEESE BLEND\n- AVOCADO");
	EXPECT_EQ(iTry->receipt(), "- GRILLED CHICKEN");
	EXPECT_EQ(heh->receipt(), "SOUTHWEST DRESSING");
	
	Salad* why = new Salad(spring, myToppings, iTry, heh);
	EXPECT_DOUBLE_EQ(why->price(), 5.00);
	EXPECT_EQ(why->receipt(), "PERSONAL SALAD\nSPRING MIX WITH\n- GRAPE TOMATOES\n- CORN\n- CROUTONS\n- EGG\n- CHEESE BLEND\n- AVOCADO\nADD\n- GRILLED CHICKEN\nWITH SOUTHWEST DRESSING");
}

TEST(SaladTest, MaxSalad){
	char array1[9] = {'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y'};
	char array2[3] = {'Y', 'Y', 'Y'};
	char array3[3] = {'V', 'Y'};
	
	Lettuce* kale = new Lettuce('K');
	Toppings* allToppings = new Toppings(array1);
	Protein* bigGainz = new Protein(array2);
	Dressing* oh = new Dressing(array3);
	
	EXPECT_DOUBLE_EQ(kale->price(), 3.00);
	EXPECT_DOUBLE_EQ(allToppings->price(), 2.00);
	EXPECT_DOUBLE_EQ(bigGainz->price(), 5.25);
	EXPECT_DOUBLE_EQ(oh->price(), 0);
	
	EXPECT_EQ(kale->receipt(), "KALE SLAW");
	EXPECT_EQ(allToppings->receipt(), "- GRAPE TOMATOES\n- CUCUMBERS\n- CORN\n- BLACK BEANS\n- CROUTONS\n- EGG\n- CHEESE BLEND\n- AVOCADO\n- DICED BACON");
	EXPECT_EQ(bigGainz->receipt(), "- GRILLED CHICKEN\n- GRILLED SALMON\n- SOY CHICKEN");
	EXPECT_EQ(oh->receipt(), "BALSAMIC VINEGAR & OLIVE OIL ON SIDE");

	Salad* why = new Salad(kale, allToppings, bigGainz, oh);
	EXPECT_DOUBLE_EQ(why->price(), 10.25);
	EXPECT_EQ(why->receipt(), "PERSONAL SALAD\nKALE SLAW WITH\n- GRAPE TOMATOES\n- CUCUMBERS\n- CORN\n- BLACK BEANS\n- CROUTONS\n- EGG\n- CHEESE BLEND\n- AVOCADO\n- DICED BACON\nADD\n- GRILLED CHICKEN\n- GRILLED SALMON\n- SOY CHICKEN\nWITH BALSAMIC VINEGAR & OLIVE OIL ON SIDE");
}
	
int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

