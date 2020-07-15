#ifndef __BURGER_HPP__
#define __BURGER_HPP__

#include "ingredients.hpp"
#include <vector>

class Burger : public Base{
	private:
		Base* A[3];
	public:	
		Burger(Base* veg, Base* ex, Base* sau){
			A[0] = veg;
			A[1] = ex;
			A[2] = sau;
		}
		virtual double price(){
			double sum = 0.00;
			sum = 3.50 + A[0]->price() + A[1]->price() + A[2]->price();
			return sum;
		}
		virtual std::string receipt(){
			std::string str;
			str = "PERSONAL BURGER\nADD\n" + A[0]->receipt() + '\n' + A[1]->receipt() + '\n' + A[2]->receipt();	
			return str;
		}
};

#endif // __BURGER_HPP__
