#include "Composite/base.hpp"
#include "Composite/ingredients.hpp"
#include "Composite/Burgers/veggies.hpp"

int main(){
	Veggies* test = new Veggies();
	
	std::cout << test->price() << std::endl;
	std::cout << test->receipt() << std::endl;

	return 0;
}
