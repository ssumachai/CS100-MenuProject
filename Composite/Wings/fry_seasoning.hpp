#ifndef __FRY_SEASONING_HPP__
#define __FRY_SEASONING_HPP__

#include "../ingredients.hpp"

class FrySeasoning : public Base{
	private:
		Ingredients* fryType;
		Ingredients* seasoning;
	public:
		FrySeasoning(){
			char input;
			bool done = false;
			while(input != 'C' && input != 'c' && input != 'R' && input != 'r' && input != 'H' && input != 'h' && input != 'N' && input != 'n'){
				std::cout << "Would you like:\n - REG. FRIES ($1.59)[R]\n - CURLY FRIES ($1.99)[C]\n - HALFSIES FRIES ($1.79)[H]\n - NONE (N)\nPLEASE ENTER (R/C/H/N): ";
				std::cin >> input;
			}
			switch(input){
				case 'R':
				case 'r':
					fryType = new Ingredients("REG. FRIES", 1.59);
					break;
				case 'C':
				case 'c':
					fryType = new Ingredients("CURLY FRIES", 1.99);
					break;
				case 'H':
				case 'h':
					fryType = new Ingredients("HALFSIES FRIES", 1.79);
					break;
				case 'N':
				case 'n':
					fryType = new Ingredients("NO FRIES", 0);
					seasoning = new Ingredients("", 0);
					done = true;
					break;
				default:
					break;
			}
			
			input = 'e';		//Empty	

			if(!done){
				while(input != 'S' && input != 's' && input != 'C' && input != 'c' && input != 'N' && input != 'n'){
					std::cout << "Please select a fry seasoning:\n- SEA SALT (S)\n- CAJUN (C)\n- NONE(N)\nPLEASE ENTER (S/C/N): ";
					std::cin >> input;
				}
			
				switch(input){
					case 'S':
					case 's':
						seasoning = new Ingredients("w/ SEA SALT", 0);
						break;
					case 'C':
					case 'c':
						seasoning = new Ingredients("w/ CAJUN", 0);
						break;
					case 'N':
					case 'n':
						seasoning = new Ingredients("w/ NO SEASONING", 0);
						break;
					default:
						break;
				}
			}
		}
		FrySeasoning(char c[2]){
			bool done = false;
			
			switch(c[0]){
                                case 'R':
					fryType = new Ingredients("REG. FRIES", 1.59);
					break;
				case 'C':
					fryType = new Ingredients("CURLY FRIES", 1.99);
					break;
				case 'H':
					fryType = new Ingredients("HALFSIES FRIES", 1.79);
					break;
				case 'N':
					fryType = new Ingredients("NO FRIES", 0);
					seasoning = new Ingredients("", 0);
					done = true;
					break;
				default:
					break;
			}
			
			if(!done){
				switch(c[1]){
					case 'S':
						seasoning = new Ingredients("w/ SEA SALT", 0);
						break;
					case 'C':
						seasoning = new Ingredients("w/ CAJUN", 0);
						break;
					case 'N':
						seasoning = new Ingredients("w/ NO SEASONING", 0);
						break;
					default:
						break;
				}
			
			}
		}		

		virtual double price(){return fryType->price();}
		virtual std::string receipt(){
			std::string str;
			str = fryType->receipt() + ' ' + seasoning->receipt();
			return str;
		}
		virtual void accept(Visitor* v){
			std::string why = fryType->receipt();

				if(why == "REG. FRIES"){
					v->visit_fry('R');
				}
				else if(why == "CURLY FRIES"){
					v->visit_fry('C');
				}
				else if(why == "HALFSIES FRIES"){
					v->visit_fry('H');
				}
				else if(why == "NO FRIES"){
					v->visit_fry('N');
				}
				else{}
		}
};

#endif // __FRY_SEASONING_HPP__		
