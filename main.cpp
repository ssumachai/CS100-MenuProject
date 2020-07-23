#include "Composite/base.hpp"
#include "include.hpp"

#include<iostream>
#include<string>
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
            cout << "Extras:\n";
            Extras* E = new Extras();
            
            cout << "Veggies:\n";
            Veggies* V = new Veggies();
            
            cout << "Sauce:\n";
            Sauce* S = new Sauce();
            
            Meal = new Burger(V, E, S);
	}
	else if (baseChoice == 2) {
          	cout << "How many wings do you want? Enter a number:\n";
            cin >> numWings;
            WingCount* WC = new WingCount(numWings);
            
          	cout << "Dipping sauce:\n";
            DippingSauce* DS = new DippingSauce();
            
            cout << "Seasoning:\n";
            FrySeasoning* FS = new FrySeasoning();
            
            cout << "Wing Sauce:\n";
            WingSauce* WS = new WingSauce(WC);
            
            Meal = new Wing(WC, WS, FS, DS);
	}
	else if (baseChoice == 3) {
          	cout << "Lettuce type:\n";
            Lettuce* L = new Lettuce();
            
          	cout << "Toppings:\n";
            Toppings* T = new Toppings();
            
            cout << "Dressings:\n";
            Dressing* D = new Dressing();
            
            cout << "Protein:\n";
            Protein* P = new Protein();
            
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

        cout << "\nYour total is: $" << Final->price() << endl << endl;
        cout << Final->receipt() << endl;

        return 0;
}
