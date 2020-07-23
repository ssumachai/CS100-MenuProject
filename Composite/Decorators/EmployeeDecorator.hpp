#ifndef __EMPLOYEEDECORATOR_HPP__
#define __EMPLOYEEDECORATOR_HPP__

#include "../base.hpp"

class EmployeeDecorator : public Base {
        private:
                Base* b;
        public:
                EmployeeDecorator(Base* b){this->b = b;}
                virtual double price(){return b->price() - (0.5 * b->price());}
                virtual std::string receipt(){return "Employee Order:\n" + b->receipt();}
};

#endif // __EMPLOYEEDECORATOR_HPP__
