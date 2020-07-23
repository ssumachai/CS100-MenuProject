#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <iostream>
#include "../Visitor/visitor.hpp"

class Base{
	public:
		//Constructors
		Base(){}
		
		//Pure Virtual Functions
		virtual double price() = 0;
		virtual std::string receipt() = 0;
		bool is_valid(char value){return (value != 'Y' && value != 'y' && value != 'N' && value != 'n');}
		virtual void accept(Visitor* v) = 0;
};

#endif // __BASE_HPP__
