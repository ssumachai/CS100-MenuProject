#ifndef __SAUCE_HPP
#define __SAUCE_HPP

#include <vector>
#include "../ingredients.hpp"

class Sauce : public Base{
	private:
		std::vector<Ingredients*> lost;
	public:
		Sauce(){
			char input;

			while(is_valid(input)){
				std::cout << "Ketchup? (FREE) [Y/N]: ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){lost.push_back(new Ingredients("KETCHUP", 0));} 
				else{}
			}
			while(is_valid(input)){
				std::cout << "Mustard? (FREE) [Y/N]: ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){lost.push_back(new Ingredients("MUSTARD", 0));}
				else{}
			}
			while(is_valid(input)){
				std::cout << "A1 Sauce ($0.50)? [Y/N]: ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){lost.push_back(new Ingredients("A1 SAUCE", 0.50));} 
				else{}
			}

			if(lost.empty()){lost.push_back(new Ingredients("NO SAUCE", 0));}

		}
		
		Sauce(char c[3]){
			char input;
			
			input = c[0];
			if(input == 'Y' || input == 'y'){lost.push_back(new Ingredients("KETCHUP", 0));}
			else{}
			
			input = c[1];
			if(input == 'Y' || input == 'y'){lost.push_back(new Ingredients("MUSTARD", 0));} 
			else{}
			
			input = c[2];
			if(input == 'Y' || input == 'y'){lost.push_back(new Ingredients("A1 SAUCE", 0.50));}
			else{}

			if(lost.empty()){lost.push_back(new Ingredients("NO SAUCE", 0));}
		}

		virtual double price(){
			double sum = 0.00;
			for(unsigned i = 0; i < lost.size(); i++){sum += lost.at(i)->price();}
			return sum;
		}
		
		virtual std::string receipt(){
			std::string str;
			int sz = lost.size();
			for(int i = 0; i < sz - 1; i++){str = str + lost.at(i)->receipt() + '\n';}
			str += lost.at(sz - 1)->receipt();
			return str;
		}
};

#endif // __SAUCE_HPP__

