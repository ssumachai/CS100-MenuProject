#ifndef __EXTRAS_HPP__
#define __EXTRAS_HPP__

#include <vector>
#include "ingredients.hpp"

class Extras : public Base{
	private:
		std::vector<Ingredients*> more;
	public:
		Extras(){
			char input;
			
			while(input != 'y' && input != 'Y' && input != 'n' && input != 'N'){
				std::cout << "Extra Patty? ($2.00) [Y/N]: ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){more.push_back(new Ingredients("EXTRA PATTY", 2.00));} 
				else{}
			}
			while(input != 'y' && input != 'Y' && input != 'n' && input != 'N'){
				std::cout << "Bacon? ($1.50) [Y/N]: ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){more.push_back(new Ingredients("BACON", 1.50));}
				else{}
			}
			while(input != 'y' && input != 'Y' && input != 'n' && input != 'N'){
				std::cout << "Extra Cheese? ($0.50) [Y/N]: ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){more.push_back(new Ingredients("EXTRA CHEESE", 0.50));} 
				else{}
			}

			if(more.empty()){more.push_back(new Ingredients("NO EXTRAS", 0.00));}
		}
		Extras(char c[3]){
			char input;
			
			input = c[0];
			if(input == 'Y' || input == 'y'){more.push_back(new Ingredients("EXTRA PATTY", 2.00));}
			else{}
			
			input = c[1];
			if(input == 'Y' || input == 'y'){more.push_back(new Ingredients("BACON", 1.50));} 
			else{}
			
			input = c[2];
			if(input == 'Y' || input == 'y'){more.push_back(new Ingredients("EXTRA CHEESE", 0.50));}
			else{}

			if(more.empty()){more.push_back(new Ingredients("NO EXTRAS", 0.00));}
		}

		virtual double price(){
			double sum = 0.00;
			for(unsigned i = 0; i < more.size(); i++){sum += more.at(i)->price();}
			return sum;
		}
		virtual std::string receipt(){
			std::string str;
			int sz = more.size();
			for(unsigned i = 0; i < sz - 1; i++){str = str + more.at(i)->receipt() + '\n';}
			str += more.at(sz - 1)->receipt();
			return str;
		}
};

#endif // __EXTRAS_HPP__
