/* 
* @Author: gicque_p
* @Date:   2015-02-04 15:20:01
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-22 17:32:02
*/

#include "Carre.hpp"

Carre::Carre(int k, int n) : ASuit(k, n, "Four of a kind") {}

double Carre::calculate(void) {
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
