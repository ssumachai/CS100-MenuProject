#ifndef __STUDENTDECORATOR_HPP__
#define __STUDENTDECORATOR_HPP__

#include "../base.hpp"

class StudentDecorator : public Base {
	private:
		Base* b;
	public:
		StudentDecorator(Base* b){this->b = b;}
    		virtual double price(){return b->price() - (0.1 * b->price());}
		virtual std::string receipt(){return "Student Order:\n" + b->receipt();} 
};

#endif // __STUDENTDECORATOR_HPP__
