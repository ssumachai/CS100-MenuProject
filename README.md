# CS100 Menu Project

> Author(s): Sumachai Suksanguan, Karsten Fields


The two of us plan on creating a Menu Application that will utilize Composite, Decorator, and Strategy Design Patterns.

# Premise

Foodservice is a growing industry, and as restaurants get more and more advanced, so will the technology needed.  We believe that using these patterns to design a functional menu option that allows users to keep better track of their items and food will be much more efficient in the long run. After all, food can be composed of many "smaller" ingredients, and "decorated" as well.  Utilising a Strategy Pattern will allow for more specific implementations of certain functions.

This project will be coded primarily in C++.  The README. will be updated along the way, with all important aspects highlighted during the developmental process.  The program will be tested both by user-input during a demo, and pre-determined character arrays that will populate our constructors.  This will be further discussed in the testing portion of each design patterns implementation.

Our program will utilize a simple interface that involves the implementation of `price()` and `receipt()` accross multiple design patterns.  The first function will return the comprehensive price of the item purchased, while the second will return the string receipt representation of the order.  The functions are described in `base.hpp`

```c++
class Base{
	public:
		//Constructors
		Base(){}
		
		//Pure Virtual Functions
		virtual double price() = 0;
		virtual std::string receipt() = 0;
};
```

# Utilization of Composite Pattern 

Many foods are composed of smaller, more functional foods.  For simplicity, we will limiting the items on our menu to staples at certain restaurants.  In this case, guests will have the option of a Cheeseburger Basket, Wing Basket, or a Salad. For readability purposes, we have made placed all appropriate files into their respective directories.  The `Composite` Directory will contain the `base.hpp` file, along with 3 subdirectories that correspond the the following classes.

## Ingredients

Every single food is composed of Ingredients.  So it makes sense that while `Base` serves as our super class, we would need a much more smaller, and friendly interface.  The smallest aspect of food, a single ingredient.  Our program will constantly be creating `Ingredients` objects, that are used in food construction, all with pre-determined prices and responsibilities.

```c++
class Ingredients : public Base {
	private:
		double value;
		std::string name;
	public:
		Ingredients(std::string str, double val){name = str; value = val;}
		double price(){return value;}
		std::string receipt(){return name;}
};
```
> Note: With `Ingredients` being the smallest interfaceable object, larger objects such as `Veggies` and `Burgers` may recursively implement their `price()` and `receipt()` functions to depict *all* ingredients being used.

### Cheeseburger Basket

Cheeseburgers come in several forms, with them often adding toppings and extras as they please.  With our program, the user will be able to select a Cheeseburger Base that includes: a bun, single burger patty, and cheese.  From there, guests may opt to include the following extras: tomatoes, lettuce, pickles, onions, bacon, an additional patty, an additional slice of cheese, ketchup, and/or mustard.

The declaration for a object of type `Burger` is as follows: `Burger* burgerName = new Burger(Base*, Base*, Base*);`.  The burger is comprised of its base ingredients (Bun, Patty, Cheese), and then extras that are broken down into the following subclasses: `Veggies`, `Extras`, and `Sauce`.  As a result, `Burger`'s implementation of the `price()` function is as follows:

```c++
virtual double price(){
	double sum = 0.00;
	sum = 3.50 + A[0]->price() + A[1]->price() + A[2]->price();
	return sum;
}
```
> Note: Where 3.50 indicates the base price of the burger and A[0], A[1], and A[2] represent the combined prices of the extra ingredients.

### Wing Basket

There are so many ways to eat a chicken these days, just as there are as many ways to coat them. The user will be able to select a Chicken Strip Base that will includes: their preffered number of Strips (3/6/9/12), a coating for their strips, fry seasoning, and a dipping sauce.

Much like the `Burger` subclass, this basket is composed of many of the guests preffered choices.  All of these selections are broken down into the following subclasses: `WingCount`, `WingSauce`, `FrySeasoning`, and `Dipping Sauce`.

### Salad

For our guests who would prefer a healthier alternative, our application will allow them to create their own salad.  It is much harder to generalize a salad, so it will mostly be mix and match for our guests.  

As a result, the `Salad` subclass will be composided of the guests: preference of lettuce, additional toppings, protein, and dressing.  Those will be broken down into these subclasses: `Lettuce`, `Toppings`, `Protein`, and `Dressing`.
