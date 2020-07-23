#ifndef __DIPPING_SAUCE_HPP__
#define __DIPPING_SAUCE_HPP__

#include "../ingredients.hpp"

class DippingSauce : public Base {
	private:
		std::vector<Ingredients*> dips;
	public:
		DippingSauce(){
			char input;
			int num;
			
			while(is_valid(input)){
				std::cout << "Would you like any dipping sauces? (Y/N):";
				std::cin >> input;
				if(input == 'Y' || input == 'y'){
					std::cout << "Ranch? ($0.25) [Y/N]:";
					std::cin >> input;
					if(input == 'Y' || input == 'y'){
						std::cout << "Quantity? (Please enter a number):";
						std::cin >> num;
						std::string str = std::to_string(num) + " RANCH(ES)";
						Ingredients* temp = new Ingredients(str, (0.25 * num));
						dips.push_back(temp);
					}
					else{}
					std::cout << "Blue Cheese? ($0.25) [Y/N]:";
					std::cin >> input;
					if(input == 'Y' || input == 'y'){
						std::cout << "Quantity? (Please enter a number):";
						std::cin >> num;
						std::string str2 = std::to_string(num) + " BLUE CHEESE";
						Ingredients* temp = new Ingredients(str2, (0.25 * num));
						dips.push_back(temp);
					}
					else{}
				}
				else{
					Ingredients* temp = new Ingredients("NO DIP", 0);
					dips.push_back(temp);
				}
			}
		}

		DippingSauce(int c[4]){
			if(c[0] == 0 && c[2] == 0){
				Ingredients* temp = new Ingredients("NO DIP", 0);
				dips.push_back(temp);
			}
			if(c[0] == 1){
				std::string str = std::to_string(c[1]) + " RANCH(ES)";
				Ingredients* temp = new Ingredients(str, (0.25 * c[1]));
				dips.push_back(temp);
			}
			if(c[2] == 1){
				std::string str1 = std::to_string(c[3]) + " BLUE CHEESE";
				Ingredients* temp = new Ingredients(str1, (0.25 * c[3]));
				dips.push_back(temp);
			}
		}

		virtual double price(){
			double sum = 0.00;
			for(unsigned i = 0; i < dips.size(); i++){
				sum += dips.at(i)->price();
			}
			return sum;
		}
		virtual std::string receipt(){
			std::string str;
			
			if(this->price() == 0){
				str = "NO SAUCE";
			}
			else{
				int sz = dips.size();
				for(unsigned i = 0; i < sz - 1;i++){
					str = str + "+ " + dips.at(i)->receipt() + '\n';
				}
				str = str + "+ " + dips.at(sz - 1)->receipt();
			}
			return str;
		}
		virtual void accept(Visitor* v){
			v->visit_dip(dips.at(0)->receipt() != "NO DIP");
		}
};

#endif // __FRY_SEASONING_HPP__
		
		
			
