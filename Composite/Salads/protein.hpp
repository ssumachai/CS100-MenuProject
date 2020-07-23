#ifndef __PROTEIN_HPP__
#define __PROTEIN_HPP__

#include "../ingredients.hpp"

class Protein : public Base {
	private:
		std::vector<Ingredients*> gainz;
	public:
		Protein(){
			char input;
			
			input = 'c';	
			while(is_valid(input)){
				std::cout << "Chicken? ($1.50) [Y/N]: ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){gainz.push_back(new Ingredients("GRILLED CHICKEN", 1.50));} 
				else{}
			}
			input = 'c';
			while(is_valid(input)){
				std::cout << "Salmon? ($2.00) [Y/N]: ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){gainz.push_back(new Ingredients("GRILLED SALMON", 2.00));}
				else{}
			}
			input = 'c';
			while(is_valid(input)){
				std::cout << "Soy Chicken? ($1.75) [Y/N]: ";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){gainz.push_back(new Ingredients("SOY CHICKEN", 1.75));} 
				else{}
			}
			if(gainz.empty()){gainz.push_back(new Ingredients("NO PROTEIN", 0.00));}
		}
		Protein(char c[3]){
			char input;
			
			input = c[0];
			if(input == 'Y' || input == 'y'){gainz.push_back(new Ingredients("GRILLED CHICKEN", 1.50));}
			else{}
			
			input = c[1];
			if(input == 'Y' || input == 'y'){gainz.push_back(new Ingredients("GRILLED SALMON", 2.00));} 
			else{}
			
			input = c[2];
			if(input == 'Y' || input == 'y'){gainz.push_back(new Ingredients("SOY CHICKEN", 1.75));}
			else{}

			if(gainz.empty()){gainz.push_back(new Ingredients("NO PROTEIN", 0.00));}
		}
		virtual double price(){
			double sum = 0.00;
			for(unsigned i = 0; i < gainz.size(); i++){
				sum += gainz.at(i)->price();
			}
			return sum;
		}
		virtual std::string receipt(){
			std::string str;
			int sz = gainz.size();
			for(int i = 0; i < sz - 1;i++){
				str = str + "- " + gainz.at(i)->receipt() + '\n';
			}
			str = str + "- " + gainz.at(sz - 1)->receipt();
			return str;
		}
		virtual void accept(Visitor* v){
			if(gainz.at(0)->receipt() == "NO PROTEIN"){return;}
			else{
				for(unsigned i = 0; i < gainz.size(); i++){
					v->visit_proteins();
				}
			}
		}
};

#endif // __PROTEIN_HPP__
