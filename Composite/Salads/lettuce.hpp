#ifndef __LETTUCE_HPP__
#define __LETTUCE_HPP__

#include "../ingredients.hpp"

class Lettuce : public Base {
	private: 
		Ingredients* letUs;
	public:
		Lettuce(){
			char input;
			while(input != 'R' && input != 'r' && input != 'I' && input != 'i' && input != 'S' && input != 's' && input != 'K' && input != 'k'){
				std::cout << "Please select a Lettuce Option ($2.00 BASE):\n- ROMAINE (R)\n- ICEBERG (I)\n- SPRING MIX (+ $0.25) [S]\n- KALE (+ $1.00) [K]\nPLEASE ENTER (R/I/S/K):";
				std::cin >> input;
			}

			switch(input){
				case 'R':
				case 'r':
					letUs = new Ingredients("ROMAINE LETTUCE", 2.00);
					break;
				case 'I':
				case 'i':
					letUs = new Ingredients("ICEBERG LETUCE", 2.00);
					break;
				case 'S':
				case 's':
					letUs = new Ingredients("SPRING MIX", 2.25);
					break;
				case 'K':
				case 'k':
					letUs = new Ingredients("KALE SLAW", 3.00);
					break;
				default:
					break;
			}
		}

		Lettuce(char type){
			switch(type){
				case 'R':
					letUs = new Ingredients("ROMAINE LETTUCE", 2.00);
					break;
				case 'I':
					letUs = new Ingredients("ICEBERG LETTUCE", 2.00);
					break;
				case 'S':
					letUs = new Ingredients("SPRING MIX", 2.25);
					break;
				case 'K':
					letUs = new Ingredients("KALE SLAW", 3.00);
					break;
				default:
					break;
			}
		}
		
		virtual double price(){return letUs->price();}
		virtual std::string receipt(){return letUs->receipt();}
		virtual void accept(Visitor* v){
			std::string why = letUs->receipt();

			if(why == "ROMAINE LETTUCE"){
					v->visit_lettuce('R');
			}
			else if(why == "ICEBERG LETTUCE"){
					v->visit_lettuce('I');
			}
			else if(why == "SPRING MIX"){
					v->visit_lettuce('S');
			}
			else if(why == "KALE SLAW"){
					v->visit_lettuce('K');
			}
			else{}
		}

};

#endif // __LETTUCE_HPP__
