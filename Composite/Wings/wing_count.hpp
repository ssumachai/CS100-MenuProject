#ifndef __WING_COUNT_HPP__
#define __WING_COUNT_HPP__

#include "../ingredients.hpp"

class WingCount : public Base{
	private:
		int num;
	public:
		WingCount(){
			int val = -1;
			while(val != 3 && val != 6 && val != 9 && val != 12){
				std::cout << "How many wings? ($1.00 each) [3/6/9/12]: ";
				std::cin >> val;
				num = val;
			}
		}
		WingCount(int n){num = n;}
		virtual double price(){
			double cost = num * 1.00;
			return cost;
		}
		virtual std::string receipt(){return std::to_string(num);}
		virtual void accept(Visitor* v){
			v->visit_wing_count(num);
		}
};

#endif // __WING_COUNT_HPP__ 
