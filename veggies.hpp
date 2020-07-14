#ifndef __VEGGIES_HPP__
#define __VEGGIES_HPP__

#include "base.hpp"
#include <vector>

class Veggies : public Base{
	private:
		std::vector<Ingredients*> selection;
	public:
		Veggies(){
			char input;
			std::cout << "Tomatoes? (Y/N): ";
			std::cin >> input;
			if(input == 'Y' || input == 'y'){selection.push_back(new Ingredients("TOMATOES", 0.00));}
			else if(input == 'N' || input == 'n'){selections.push_back(new Ingredients("NO TOMATOES", 0.00));} 
			else{}
		}
		Veggies(char *c[5]){}
};

#endif // __VEGGIES_HPP__		

