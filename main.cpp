#include "Composite/base.hpp"
#include "include.hpp"

#include<iostream>
#include<string>
#include <iomanip>

using namespace std;

int main(){
        char consumerType;
        int baseChoice;
        int numWings;
        Base* Meal;
        Base* Final;

        cout << "Greetings!\nAre you:\na student? - Enter 'u'\n55 or older? - Enter 's'\na veteran? - Enter 'v'\nan employee? - Enter 'e'\nnone of the above? - Enter 'o'\n";
        cout << "Enter 'q' to quit.\n";
        cin >> consumerType;

        cout << "\nMenu:\n";
        cout << "1. Cheese Burger\n2. Wings\n3. Salad\n";
        cout << "Please enter the number of the food item you want.\n";
        cin >> baseChoice;
        
        if (baseChoice == 1) {
            cout << "Veggies:\n";
            Veggies* V = new Veggies();
            
	    cout << "Extras:\n";
            Extras* E = new Extras();
		
            cout << "Sauce:\n";
            Sauce* S = new Sauce();
            
            Meal = new Burger(V, E, S);
	}
	else if (baseChoice == 2) {
            WingCount* WC = new WingCount();
            
            cout << "Wing Sauce:\n";
            WingSauce* WS = new WingSauce(WC);

            cout << "Seasoning:\n";
            FrySeasoning* FS = new FrySeasoning();

            cout << "Dipping sauce:\n";
            DippingSauce* DS = new DippingSauce();
            
            
            Meal = new Wing(WC, WS, FS, DS);
	}
	else if (baseChoice == 3) {
            cout << "Lettuce type:\n";
            Lettuce* L = new Lettuce();
            
            cout << "Toppings:\n";
            Toppings* T = new Toppings();
               
            cout << "Protein:\n";
            Protein* P = new Protein();
            
	    cout << "Dressings:\n";
            Dressing* D = new Dressing();

            Meal = new Salad(L, T, P, D);
	}
	else {
            cout << "Invalid input.\n";
            return 0;
        }

        switch (consumerType) {
                case 'u':
                	Final = new StudentDecorator(Meal);
                        break;
                case 's':
                	Final = new SeniorDecorator(Meal);
                        break;
                case 'v':
                	Final = new VeteranDecorator(Meal);
                        break;
                case 'e':
                	Final = new EmployeeDecorator(Meal);
                        break;
                case 'o':
                        break;
                default:
                        return 0;
        }
	Visitor* vis = new Visitor();
	Final->accept(vis);
	
        cout << "\nYour total is: $" << fixed << setprecision(2) << Final->price() << endl << endl;
        cout << Final->receipt() << endl << vis->get_message() << endl;

        return 0;
}
