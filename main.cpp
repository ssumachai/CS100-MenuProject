#include "base.hpp"
#include "ingredients.hpp"
#include "veggies.hpp"

int main(){
	Veggies* test = new Veggies();
	
	std::cout << test->price() << std::endl;
	std::cout << test->receipt() << std::endl;

	return 0;
}
