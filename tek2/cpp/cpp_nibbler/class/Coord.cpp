/* 
* @Author: gicque_p
* @Date:   2015-03-09 16:21:51
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-03-11 21:19:50
*/

#include "Coord.hpp"

Coord::Coord(int newX, int newY) { 
	x = newX;
	y = newY;
}

int Coord::getX(void) const {
	return (x);
}

void Coord::setX(int newX) {
	x = newX;
}

int Coord::getY(void) const {
	return (y);
}

void Coord::setY(int newY) {
	y = newY;
}
