/* 
* @Author: gicque_p
* @Date:   2015-02-06 21:07:41
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-22 18:50:27
*/

#include <iostream>
#include <cmath>
using namespace std;

int factorial(int number) {
	return (number <= 0) ? 1 : number * factorial(number - 1);
}

double binomial(double k, double n) {
	return (factorial(k) / (factorial(n) * factorial(k-n))) * pow(0.1666, n) * pow(0.8333, k-n);
}

int timesInTab(int *tab, int number) {
	int j;

	j = 0;
	for (int i = 0; i < 5; i++) {
		if (tab[i] == number) {
			j++;
		}
	}

	return j;
}

bool isNumber(const std::string &value) {
	if ((value.at(0) < '0' or value.at(0) > '6') or value.length() > 1) {
		return false;
	} else {
		return true;
	}
}
