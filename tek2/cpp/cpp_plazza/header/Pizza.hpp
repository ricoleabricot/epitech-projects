#ifndef PIZZA_HPP_
# define PIZZA_HPP_

# include <iostream>
# include <map>

# include "Error.hpp"

enum TypePizza {
	Regina = 1,
	Margarita = 2,
	Americana = 4,
	Fantasia = 8,
	NONETYPE
};

enum SizePizza {
	S = 1,
	M = 2,
	L = 4,
	XL = 8,
	XXL = 16,
	NONESIZE
};

enum PizzaState {
	Awaiting,
	Processing,
	Finished
};

class Pizza {
private:
	TypePizza 	_type;
	SizePizza 	_size;
	PizzaState	_state;
	int _id;

	std::map<TypePizza, int> _map;

 public:
	Pizza(TypePizza, SizePizza);
	~Pizza();

	TypePizza getType(void) const;
	SizePizza getSize(void) const;
	PizzaState getState(void) const;
	int getId(void) const;

	void 	setState(PizzaState);

	double getCookingTime(double);
};

#endif /* PIZZA_HPP_ */
