#ifndef __VEGGIES_HPP__
#define __VEGGIES_HPP__

#include <vector>
#include "ingredients.hpp"

class Veggies : public Base{
	private:
		std::vector<Ingredients*> selection;
	public:
		Veggies(){
			char input;
			std::cout << "Tomatoes? (Y/N): ";
			std::cin >> input;
			if(input == 'Y' || input == 'y'){selection.push_back(new Ingredients("TOMATOES", 0.00));}
			else if(input == 'N' || input == 'n'){selection.push_back(new Ingredients("NO TOMATOES", 0.00));} 
			else{}
			
			std::cout << "Lettuce? (Y/N): ";
			std::cin >> input;
			if(input == 'Y' || input == 'y'){selection.push_back(new Ingredients("LETTUCE", 0.00));}
			else if(input == 'N' || input == 'n'){selection.push_back(new Ingredients("NO LETTUCE", 0.00));} 
			else{}
			
			std::cout << "Pickles? (Y/N): ";
			std::cin >> input;
			if(input == 'Y' || input == 'y'){selection.push_back(new Ingredients("PICKLES", 0.00));}
			else if(input == 'N' || input == 'n'){selection.push_back(new Ingredients("NO PICKLES", 0.00));} 
			else{}
			
			std::cout << "Onions? (Y/N): ";
			std::cin >> input;
			if(input == 'Y' || input == 'y'){selection.push_back(new Ingredients("ONIONS", 0.00));}
			else if(input == 'N' || input == 'n'){selection.push_back(new Ingredients("NO ONIONS", 0.00));} 
			else{}
		}
		Veggies(char (*c)[4]){				
			char input;
			
			input = (*c)[0];
			if(input == 'Y' || input == 'y'){selection.push_back(new Ingredients("TOMATOES", 0.00));}
			else if(input == 'N' || input == 'n'){selection.push_back(new Ingredients("NO TOMATOES", 0.00));} 
			else{}
			
			input = (*c)[1];
			if(input == 'Y' || input == 'y'){selection.push_back(new Ingredients("LETTUCE", 0.00));}
			else if(input == 'N' || input == 'n'){selection.push_back(new Ingredients("NO LETTUCE", 0.00));} 
			else{}
			
			input = (*c)[2];
			if(input == 'Y' || input == 'y'){selection.push_back(new Ingredients("PICKLES", 0.00));}
			else if(input == 'N' || input == 'n'){selection.push_back(new Ingredients("NO PICKLES", 0.00));} 
			else{}
			
			input = (*c)[3];
			if(input == 'Y' || input == 'y'){selection.push_back(new Ingredients("ONIONS", 0.00));}
			else if(input == 'N' || input == 'n'){selection.push_back(new Ingredients("NO ONIONS", 0.00));} 
			else{}
		}
	virtual double price(){return 0.00;}
	virtual std::string receipt(){
		std::string str = "";
		for(unsigned i = 0; i < 3; i++){
			str = str + selection.at(i)->receipt() + std::endl;
		}
		str = str + selection.at(3)->receipt();
		return str;
	}
};

#endif // __VEGGIES_HPP__		

