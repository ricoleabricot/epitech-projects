/* 
* @Author: gicque_p
* @Date:   2015-02-04 15:17:42
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-22 19:01:15
*/

#include "ASuit.hpp"

ASuit::ASuit(int k, int n, const std::string &name) : _k(k), _n(n), _name(name) {}

ASuit& ASuit::operator=(ASuit const &suit) {
	this->_k = suit.getK();
	this->_n = suit.getN();

	return *this;
}

int ASuit::getK(void) const {
	return this->_k;
}

int ASuit::getN(void) const {
	return this->_n;
}

std::string ASuit::getName(void) const {
	return this->_name;
}

void ASuit::setName(const std::string &name) {
	this->_name = name;
}