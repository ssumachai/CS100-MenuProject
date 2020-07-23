#ifndef __SENIORDECORATOR_HPP__
#define __SENIORDECORATOR_HPP__

#include "../Composite/base.hpp"

class SeniorDecorator : public Base {
        private:
                Base* b;
        public:
                SeniorDecorator(Base* b){this->b = b;}
                virtual double price(){return b->price() - (0.15 * b->price());}
                virtual std::string receipt(){return "Senior Order:\n" + b->receipt();}
		virtual void accept(Visitor* v){
			b->accept(v);
			v->visit_senior();
		}
};

#endif // __SENIORDECORATOR_HPP__
