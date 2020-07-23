#ifndef __EMPLOYEEDECORATOR_HPP__
#define __EMPLOYEEDECORATOR_HPP__

#include "../Composite/base.hpp"

class EmployeeDecorator : public Base {
        private:
                Base* b;
        public:
                EmployeeDecorator(Base* b){this->b = b;}
                virtual double price(){return b->price() - (0.5 * b->price());}
                virtual std::string receipt(){return "Employee Order:\n" + b->receipt();}
		virtual void accept(Visitor* v){
			b->accept(v);
			v->visit_employee();
		}
};

#endif // __EMPLOYEEDECORATOR_HPP__
