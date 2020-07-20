#ifndef __SALAD_HPP__
#define __SALAD_HPP__

#include "../ingredients.hpp"

class Salad : public Base {
	private:
		Base* A[4];
	public:
		Salad(Base* let, Base* toppi, Base* pro, Base* dress){
			A[0] = let;
			A[1] = toppi;
			A[2] = pro;
			A[3] = dress;
		}
		virtual double price(){
			double sum = 0;
			sum = A[0]->price() + A[1]->price() + A[2]->price() + A[3]->price();
			if(sum < 2.49){
				sum = 2.49;
			}
			return sum;
		}
		virtual std::string receipt(){
			std::string str;
			str = "PERSONAL SALAD\n" + A[0]->receipt() + " WITH\n" + A[1]->receipt() + "\nADD\n" + A[2]->receipt() + "\nWITH " + A[3]->receipt();
			return str;
		}
};

#endif // __SALAD_HPP__
