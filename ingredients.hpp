#ifndef __INGREDIENTS_HPP__
#define __INGREDIENTS_HPP__

#include "base.hpp"

class Ingredients : public Base {
	private:
		double price;
		std::string name;
	public:
		Ingredients(std::string str, double val){name = str; price = val;}
		virtual double price(){return price;}
		virtual std::string receipt{return name;}
};

#endif // __INGREDIENTS_HPP__
