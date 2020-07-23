#ifndef __DRESSING_HPP__
#define __DRESSING_HPP__

#include "../ingredients.hpp"

class Dressing : public Base {
	private:
		Ingredients* coat;
	public:
		Dressing(){
			char input, input2;
			std::string name;
			bool side = false;
			while(input != 'C' && input != 'c' && input != 'R' && input != 'r' && input != 'B' && input != 'b' && input != 'V' && input != 'v' && input != 'S' && input != 's' && input != 'N' && input != 'n'){
				std::cout << "Please Select a Dressing (FREE):\n- CAESAR (C)\n- RANCH (R)\n- BLUE CHEESE (B)\n- BALSAMIC/OLIVE (V)\n- SOUTHWEST (S)\n- NO DRESSING (N)\nPLEASE ENTER (R/C/B/V/S/N): ";
				std::cin >> input;			
			}
			if(input != 'N' && input == 'n'){
				while(is_valid(input2)){
					std::cout << "Would you like your dressing on the side? (Y/N):";
					std::cin >> input2;
					if(input2 == 'Y' || input2 == 'y'){side = true;}
				}		
			}

			switch(input){
				case 'C':
				case 'c':
					name = "CAESAR DRESSING";
					break;
				case 'R':
				case 'r':
					name = "RANCH DRESSING";
					break;
				case 'B':
				case 'b':
					name = "BLUE CHEESE";
					break;
				case 'V':
				case 'v':
					name = "BALSAMIC VINEGAR & OLIVE OIL";
					break;
				case 'S':
				case 's':
					name = "SOUTHWEST DRESSING";
					break;
				case 'N':
				case 'n':
					name = "NO DRESSING";
					break;
				default:
					break;
			}

			if(side){
				name = name + " ON SIDE";
			}

			coat = new Ingredients(name, 0.00);
	}
	Dressing(char c[2]){
		bool side = false;
		std::string name;

		if(c[1] == 'Y'){side = true;}

		switch(c[0]){
			case 'C':
				name = "CAESAR DRESSING";
				break;
			case 'R':
				name = "RANCH DRESSING";
				break;
			case 'B':
				name = "BLUE CHEESE";
				break;
			case 'V':
				name = "BALSAMIC VINEGAR & OLIVE OIL";
				break;
			case 'S':
				name = "SOUTHWEST DRESSING";			
				break;
			case 'N':
				name = "NO DRESSING";
				break;
			default:
				break;
		}

		if(side){
			name = name + " ON SIDE";
		}

		coat = new Ingredients(name, 0.00);
	}
	virtual double price(){return 0.00;}
	virtual std::string receipt(){return coat->receipt();}
	virtual void accept(Visitor* v){
		std::string why = coat->receipt();
		
		if(why == "CAESAR DRESSING" || why == "CAESAR DRESSING ON SIDE"){
				v->visit_dressing('C');
		}
		else if(why == "RANCH DRESSING" || why == "RANCH DRESSING ON SIDE"){
				v->visit_dressing('R');
		}
		else if(why == "BLUE CHEESE" || why == "BLUE CHEESE ON SIDE"){
				v->visit_dressing('B');
		}
		else if(why == "BALSAMIC VINEGAR & OLIVE OIL" || why == "BALSAMIC VINEGAR & OLIVE OIL ON SIDE"){
				v->visit_dressing('V');
		}
		else if(why == "SOUTHWEST DRESSING" || why == "SOUTHWEST DRESSING ON SIDE"){
				v->visit_dressing('S');
		}
		else if(why == "NO DRESSING"){
				v->visit_dressing('N');
		}
		else{}
	}
};

#endif // __DRESSING_HPP__
