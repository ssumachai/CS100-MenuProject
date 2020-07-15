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
			
			while(input != 'y' && input != 'Y' && input != 'n' && input != 'N'){
				std::cout << "Tomatoes? (Y/N): ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){selection.push_back(new Ingredients("TOMATOES", 0.00));}
				else{}
			}
			while(input != 'y' && input != 'Y' && input != 'n' && input != 'N'){
				std::cout << "Lettuce? (Y/N): ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){selection.push_back(new Ingredients("LETTUCE", 0.00));}
				else{}
			}
			while(input != 'y' && input != 'Y' && input != 'n' && input != 'N'){
				std::cout << "Pickles? (Y/N): ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){selection.push_back(new Ingredients("PICKLES", 0.00));}
				else{}
			}
			while(input != 'y' && input != 'Y' && input != 'n' && input != 'N'){
				std::cout << "Onions? (Y/N): ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){selection.push_back(new Ingredients("ONIONS", 0.00));} 
				else{}
			}	
			
			if(selection.empty()){selection.push_back(new Ingredient("NO VEGGIES", 0.00));}
		}
		Veggies(char c[4]){				
			char input;
			
			input = c[0];
				if(input == 'Y' || input == 'y'){selection.push_back(new Ingredients("TOMATOES", 0.00));}
				else{}
			
			input = c[1];
				if(input == 'Y' || input == 'y'){selection.push_back(new Ingredients("LETTUCE", 0.00));}
				else{}
			
			input = c[2];
				if(input == 'Y' || input == 'y'){selection.push_back(new Ingredients("PICKLES", 0.00));}
				else{}
			
			input = c[3];
				if(input == 'Y' || input == 'y'){selection.push_back(new Ingredients("ONIONS", 0.00));}
				else{}
			
			if(selection.empty()){selection.push_back(new Ingredient("NO VEGGIES", 0.00));}
		}
	virtual double price(){return 0.00;}
	virtual std::string receipt(){
		int sz = selection.size();
		std::string str = "";
		for(unsigned i = 0; i < sz - 2; i++){
			str = str + selection.at(i)->receipt() + '\n';
		}
		str = str + selection.at(sz - 1)->receipt();
		return str;
	}
};

#endif // __VEGGIES_HPP__		

