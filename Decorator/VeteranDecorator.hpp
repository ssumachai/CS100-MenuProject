#ifndef __VETERANDECORATOR_HPP__
#define __VETERANDECORATOR_HPP__

#include "../Composite/base.hpp"

class VeteranDecorator : public Base {
        private:
                Base* b;
        public:
                VeteranDecorator(Base* b){this->b = b;}
                virtual double price(){return b->price() - (0.2 * b->price());}
                virtual std::string receipt(){return "Veteran Order:\n" + b->receipt();}
		virtual void accept(Visitor* v){
			b->accept(v);
			v->visit_veteran();
		}
};

#endif // __VETERANDECORATOR_HPP__
