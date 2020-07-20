#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <iostream>

class Base{
	public:
		//Constructors
		Base(){}
		
		//Pure Virtual Functions
		virtual double price() = 0;
		virtual std::string receipt() = 0;
		bool is_valid(char value){return (value != 'Y' && value != 'y' && value != 'N' && value != 'n');}
};

#endif // __BASE_HPP__
