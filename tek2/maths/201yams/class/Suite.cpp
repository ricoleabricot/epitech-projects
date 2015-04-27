/* 
* @Author: gicque_p
* @Date:   2015-02-04 15:20:01
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-27 17:11:30
*/

#include "Suite.hpp"
#include "Yams.hpp"

Suite::Suite(int k, int n, int *tab) : ASuit(k, n, "Straigth") {
	this->_tab = tab;
}

double Suite::calculate(void) {
	int *tab = this->_tab;
	int i = 0;
	int j = 0;
	int cpt = 0;
	bool find = false;

	while (i < 5) {
		if ((tab[i] > 0 and tab[i] < (this->_n - 4)) and tab[i] > this->_n) {
			cpt++;
			tab[i] = 6;
		}
		i++;
	}

	i = 0;
	while (i < 5) {
		j = i + 1;
		find = false;
		while (j < 5) {
			if (tab[j] == tab[i]) {
				find = true;
				break;
			}
			j++;
		}

		if (find == true) {
			cpt++;
		}

		i++;
	}

	Yams yams(this->_k, this->_k - cpt);
	return yams.calculate();
}
