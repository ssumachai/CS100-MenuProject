#ifndef __INGREDIENTS_HPP__
#define __INGREDIENTS_HPP__

#include "../base.hpp"

class Ingredients : public Base {
	private:
		double value;
		std::string name;
	public:
		Ingredients(std::string str, double val){name = str; value = val;}
		double price(){return value;}
		std::string receipt(){return name;}
};

#endif // __INGREDIENTS_HPP__
