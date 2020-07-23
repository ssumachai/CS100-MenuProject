#ifndef __VEGGIES_HPP__
#define __VEGGIES_HPP__

#include <vector>
#include "../ingredients.hpp"

class Veggies : public Base{
	private:
		std::vector<Ingredients*> selection;
	public:
		Veggies(){
			char input;
			
			while(is_valid(input)){
				std::cout << "Tomatoes? (FREE) [Y/N]: ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){selection.push_back(new Ingredients("TOMATOES", 0.00));}
				else{}
			}
			while(is_valid(input)){
				std::cout << "Lettuce? (FREE) [Y/N]: ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){selection.push_back(new Ingredients("LETTUCE", 0.00));}
				else{}
			}
			while(is_valid(input)){
				std::cout << "Pickles? (FREE) [Y/N]: ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){selection.push_back(new Ingredients("PICKLES", 0.00));}
				else{}
			}
			while(is_valid(input)){
				std::cout << "Onions? (FREE) [Y/N]: ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){selection.push_back(new Ingredients("ONIONS", 0.00));} 
				else{}
			}	
			
			if(selection.empty()){selection.push_back(new Ingredients("NO VEGGIES", 0.00));}
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
			
			if(selection.empty()){selection.push_back(new Ingredients("NO VEGGIES", 0.00));}
		}
	virtual double price(){return 0.00;}
	virtual std::string receipt(){
		int sz = selection.size();
		std::string str = "";
		for(unsigned i = 0; i < sz - 1; i++){
			str = str + selection.at(i)->receipt() + '\n';
		}
		str = str + selection.at(sz - 1)->receipt();
		return str;
	}
	virtual void accept(Visitor* v){
		if(selection.at(0)->receipt() == "NO VEGGIES"){return;}
		else{
			for(unsigned i = 0; i < selection.size(); i++){
				v->visit_veggie();
			}
		}
	}
};

#endif // __VEGGIES_HPP__		

