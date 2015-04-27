/* 
* @Author: gicque_p
* @Date:   2015-02-04 15:20:01
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-27 14:45:01
*/

#include "Full.hpp"

Full::Full(int k, int n, int k2, int n2) : ASuit(k, n, "Full") {
	this->_k2 = k2;
	this->_n2 = n2;
}

double Full::calculate(void) {
	if (this->_n > 3) {
		this->_n = 3;
	}

	if (this->_n2 > 2) {
		this->_n2 = 2;
	}

	double pair = factorial(5 - this->_n - this->_n2) / (factorial(3 - this->_n2) * factorial((5 - this->_n2 - this->_n) - (3 - this->_n)));
	double brelan = factorial(2 - this->_n2) / (factorial(2 - this->_n2) * factorial((2 - this->_n2) - (2 - this->_n2)));

	return double(pair * brelan) / pow(6, 5 - this->_n - this->_n2) * 100;
}