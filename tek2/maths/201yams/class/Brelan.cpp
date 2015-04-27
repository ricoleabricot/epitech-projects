/* 
* @Author: gicque_p
* @Date:   2015-02-04 15:20:01
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-22 17:31:58
*/

#include <cstdio>
#include "Brelan.hpp"

Brelan::Brelan(int k, int n) : ASuit(k, n, "Three of a kind") {}

double Brelan::calculate(void) {
	double res = 0;

	if (this->_n >= this->_k) {
		return 100;
	} else {
		for (int x = this->_k - this->_n; x < (5 - this->_n + 1); x++) {
			res += binomial(5 - this->_n, x);
		}

		return res * 100;
	}
}
