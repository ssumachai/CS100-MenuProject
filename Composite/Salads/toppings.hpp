#ifndef __TOPPINGS_HPP__
#define __TOPPINGS_HPP__

#include "../ingredients.hpp"

class Toppings : public Base {
	private:
		std::vector<Ingredients*> topp;
	public:
		Toppings(){
			char input;
			
			while(is_valid(input)){
				std::cout << "Grape Tomatoes? (FREE) [Y/N]: ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){topp.push_back(new Ingredients("GRAPE TOMATOES", 0.00));}
				else{}
			}
			while(is_valid(input)){
				std::cout << "Cucumbers? (FREE) [Y/N]: ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){topp.push_back(new Ingredients("CUCUMBERS", 0.00));}
				else{}
			}
			while(is_valid(input)){
				std::cout << "Corn? (FREE) [Y/N]: ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){topp.push_back(new Ingredients("CORN", 0.00));}
				else{}
			}
			while(is_valid(input)){
				std::cout << "Black Beans? (FREE) [Y/N]: ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){topp.push_back(new Ingredients("BLACK BEANS", 0.00));} 
				else{}
			}	
			while(is_valid(input)){
				std::cout << "Croutons? (FREE) [Y/N]: ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){topp.push_back(new Ingredients("CROUTONS", 0.00));}
				else{}
			}
			while(is_valid(input)){
				std::cout << "Egg? (FREE) [Y/N]: ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){topp.push_back(new Ingredients("EGG", 0.00));}
				else{}
			}
			while(is_valid(input)){
				std::cout << "Cheese Blend? (FREE) [Y/N]: ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){topp.push_back(new Ingredients("CHEESE BLEND", 0.00));}
				else{}
			}
			while(is_valid(input)){
				std::cout << "Avocado? ($1.25) [Y/N]: ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){topp.push_back(new Ingredients("AVOCADO", 1.25));} 
				else{}
			}	
			while(is_valid(input)){
				std::cout << "Diced Bacon? ($0.75) [Y/N]: ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){topp.push_back(new Ingredients("DICED BACON", 0.75));} 
				else{}
			}				
			if(topp.empty()){topp.push_back(new Ingredients("NO TOPPINGS", 0.00));}
		}
		Toppings(char c[9]){
			char input;

			input = c[0];
				if(input == 'Y' || input == 'y'){topp.push_back(new Ingredients("GRAPE TOMATOES", 0.00));}
				else{}
			
			input = c[1];
				if(input == 'Y' || input == 'y'){topp.push_back(new Ingredients("CUCUMBERS", 0.00));}
				else{}
			
			input = c[2];
				if(input == 'Y' || input == 'y'){topp.push_back(new Ingredients("CORN", 0.00));}
				else{}
			
			input = c[3];
				if(input == 'Y' || input == 'y'){topp.push_back(new Ingredients("BLACK BEANS", 0.00));}
				else{}
			input = c[4];
				if(input == 'Y' || input == 'y'){topp.push_back(new Ingredients("CROUTONS", 0.00));}
				else{}
			
			input = c[5];
				if(input == 'Y' || input == 'y'){topp.push_back(new Ingredients("EGG", 0.00));}
				else{}
			
			input = c[6];
				if(input == 'Y' || input == 'y'){topp.push_back(new Ingredients("CHEESE BLEND", 0.00));}
				else{}
			
			input = c[7];
				if(input == 'Y' || input == 'y'){topp.push_back(new Ingredients("AVOCADO", 1.25));}
				else{}

			input = c[8];
				if(input == 'Y' || input == 'y'){topp.push_back(new Ingredients("DICED BACON", 0.75));}
				else{}

			if(topp.empty()){topp.push_back(new Ingredients("NO TOPPINGS", 0.00));}
		}
		virtual double price(){
			double sum = 0.00;
			for(unsigned i = 0; i < topp.size(); i++){
				sum += topp.at(i)->price();
			}
			return sum;
		}
		virtual std::string receipt(){
			std::string str;
			int sz = topp.size();
			for(int i = 0; i < sz - 1; i++){
				str = str + "- " + topp.at(i)->receipt() + '\n';
			}
			str = str + "- " + topp.at(sz - 1)->receipt();
			return str;
		}
};

#endif // __TOPPINGS_HPP__
