/* 
* @Author: gicque_p
* @Date:   2015-04-16 18:24:51
* @Last Modified by:   Kafei59
* @Last Modified time: 2015-04-25 00:26:09
*/

#include "Pizza.hpp"

Pizza::Pizza(TypePizza type, SizePizza size) : _type(type), _size(size), _state(Awaiting) {
	static int id(0);

	this->_id = id;
	id++;

	this->_map[Margarita] = 1;
	this->_map[Regina] = 2;
	this->_map[Americana] = 2;
	this->_map[Fantasia] = 4;
}

Pizza::~Pizza() {}

TypePizza Pizza::getType(void) const {
	return this->_type;
}

SizePizza Pizza::getSize(void) const {
	return this->_size;
}

PizzaState 	Pizza::getState(void) const {
	return this->_state;
}

int Pizza::getId(void) const {
	return this->_id;
}

void 		Pizza::setState(PizzaState state) {
	this->_state = state;
}

double Pizza::getCookingTime(double multiplier) {
	if (this->_type != NONETYPE and this->_map[this->_type]) {
		return this->_map[this->_type] * multiplier;
	} else {
		throw PizzaError("Unknown pizza Type");
	}
}
