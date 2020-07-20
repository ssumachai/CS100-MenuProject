#ifndef __WING_SAUCE_HPP__
#define __WING_SAUCE_HPP__

class WingSauce : public Base {
	private:
		int count[3];
	public:
		WingSauce(WingCount* num){
			int dummy = num->price();
			int hold = 0;
			
			while(dummy != 0){
				std::cout << "How Many Buffalo Wings would you like? ($0.10 each) [1 - " << dummy << "]:";
				std::cin >> hold;
				dummy -= hold;
				count[0] += hold;
				if(dummy != 0){
					std::cout << "How Many BBQ Wings would you like? ($0.10 each) [1 - " << dummy << "]:";
					std::cin >> hold;
					dummy -= hold;
					count[1] += hold;
				}
				if(dummy != 0){
					std::cout << "How many Plain Wings would you like? (FREE) [1 - " << dummy << "]:";
					std::cin >> hold;
					dummy -= hold;
					count[2] += hold;
				}

			}
		}
		WingSauce(int c[3]){count[0] = c[0]; count[1] = c[1]; count[2] = c[2];}
		virtual double price(){
			double sum = 0;
			sum = (count[0] * .10) + (count[1] * .10);
			return sum;
		}
		virtual std::string receipt(){
			std::string str; 
			if(count[0] != 0 && count[1] == 0 && count[2] == 0){
				str = "BUFFALO WINGS";
			}
			else if(count[0] == 0 && count[1] != 0 && count[2] == 0){
				str = "BBQ WINGS";
			}
			else if(count[0] == 0 && count[1] == 0 && count[2] != 0){
				str = "PLAIN WINGS";
			}
			else{
				str = "COMBO WINGS\n- " + std::to_string(count[0]) + " BUFFALO\n- " + std::to_string(count[1]) + " BBQ\n- " + std::to_string(count[2]) + " PLAIN";
			}

			return str;
	}
};

#endif // __WING_SAUCE_HPP__
			
			
