#ifndef __WING_HPP__
#define __WING_HPP__

#include "../ingredients.hpp"

class Wing : public Base {
	private:
		Base* A[4];
	public:
		Wing(Base* c, Base* toss, Base* fry, Base* dip){
			A[0] = c;
			A[1] = toss;
			A[2] = fry;
			A[3] = dip;
		}
		virtual double price(){
			double sum = 0.00;
			sum = A[0]->price() + A[1]->price() + A[2]->price() + A[3]->price();
			return sum;
		}
		virtual std::string receipt(){
			std::string str;
			str = "WING BASKET\n" + A[0]->receipt() + ' ' + A[1]->receipt() + '\n' + A[2]->receipt() + '\n' + A[3]->receipt();
			return str;
		}
		virtual void accept(Visitor* v){
			A[0]->accept(v);
			A[1]->accept(v);
			A[2]->accept(v);
			A[3]->accept(v);
			
			v->visit_wing();
		}
};

#endif //__WINGS_HPP__
