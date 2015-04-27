/* 
* @Author: gicque_p
* @Date:   2015-03-02 15:40:30
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-03-03 00:51:32
*/

#include "Law.hpp"
#include "Error.hpp"

Law::Law(int a, int b) : _a(a), _b(b) {
	double res = 0;

	for (int i = 10; i <= 50; i += 10) {
		res = 0;
		for (int j = 10; j <= 50; j += 10) {
			try {
				this->_tab[(i / 10) - 1][(j / 10) - 1] = this->join(j, i);
				res += this->_tab[(i / 10) - 1][(j / 10) - 1];
			} catch (const Error &error) {
				throw Error(error.what());
			}
		}
		this->_tab[(i / 10) - 1][5] = res;
	}

	for (int i = 10; i <= 50; i += 10) {
		res	= 0;	
		for (int j = 10; j <= 50; j += 10) {
			res += this->join(i, j);
		}
		this->_tab[5][(i / 10) - 1] = res;
	}
	this->_tab[5][5] = 1;
}

double Law::join(int x, int y) {
	double res1;
	double res2;

	res1 = ((this->_a - x) * (this->_b - y));
	res2 = (((5 * this->_a) - 150) * ((5  * this->_b) - 150));

	if (res2 == 0) {
		throw Error("Division by zero");
	} else {
		return res1 / res2;
	}
}

double Law::esperanceX(void) {
	double res = 0;
	for (int i = 10; i <= 50; i += 10) {
		res += i * this->_tab[5][(i / 10) - 1];
	}

	return res;
}


double Law::varianceX(void) {
	double res = 0;
	for (int i = 10; i <= 50; i += 10) {
		res += pow(i, 2) * this->_tab[5][(i / 10) - 1];
	}

	res -= pow(this->esperanceX(), 2);
	return res;
}


double Law::esperanceY(void) {
	double res = 0;
	for (int i = 10; i <= 50; i += 10) {
		res += i * this->_tab[(i / 10) - 1][5];
	}

	return res;
}


double Law::varianceY(void) {
	double res = 0;
	for (int i = 10; i <= 50; i += 10) {
		res += pow(i, 2) * this->_tab[(i / 10) - 1][5];
	}

	res -= pow(this->esperanceY(), 2);
	return res;
}

int Law::getA(void) const {
	return this->_a;
}

int Law::getB(void) const {
	return this->_b;
}
