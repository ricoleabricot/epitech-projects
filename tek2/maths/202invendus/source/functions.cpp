/* 
* @Author: gicque_p
* @Date:   2015-03-02 15:07:07
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-03-13 15:02:50
*/

#include <iostream>
#include <iomanip>
#include "Law.hpp"
#include "Error.hpp"
using namespace std;

void displayTab(Law &law) {
	cout << setprecision(3) << fixed;
	cout << "\tX=10\tX=20\tX=30\tX=40\tX=50\tLoi Y" << endl;
	for (int i = 0; i < 6; i++) {
		if (i == 5) {
			cout << "Loi X\t";
		} else {
			cout << "Y=" << (i * 10) + 10 << "\t";
		}

		for (int j = 0; j < 6; j++) {
			cout << law._tab[i][j] << "\t";
		}
		cout << endl;
	}
}

void displayDatas(Law &law) {
	cout << "z:\t20\t30\t40\t50\t60\t70\t80\t90\t100\ttotal" << endl;
	cout << "p(Z=z):\t";
	cout << setprecision(3) << fixed;

	cout << law._tab[0][0] << "\t";
	cout << law._tab[1][0] + law._tab[0][1] << "\t";
	cout << law._tab[2][0] + law._tab[1][1] + law._tab[0][2] << "\t";
	cout << law._tab[3][0] + law._tab[2][1] + law._tab[1][2] + law._tab[0][3] << "\t";
	cout << law._tab[4][0] + law._tab[3][1] + law._tab[2][2] + law._tab[1][3] + law._tab[0][4] << "\t";
	cout << law._tab[4][1] + law._tab[3][2] + law._tab[2][3] + law._tab[1][4] << "\t";
	cout << law._tab[4][2] + law._tab[3][3] + law._tab[2][4] << "\t";
	cout << law._tab[4][3] + law._tab[3][4] << "\t";
	cout << law._tab[4][4] << "\t";
	cout << 1 << endl;
}

void displayProbabilities(Law &law) {
	cout << setprecision(3) << fixed;

	cout << "Espérance de X:\t" << law.esperanceX() << endl;
	cout << "Variance de X:\t" << law.varianceX() << endl;
	cout << "Espérance de Y:\t" << law.esperanceY() << endl;
	cout << "Variance de Y:\t" << law.varianceY() << endl;
	cout << "Espérance de Z:\t" << law.esperanceX() + law.esperanceY() << endl;
	cout << "Variance de Z:\t" << law.varianceX() + law.varianceY() << endl;
}

bool isNumber(const std::string &value) {
	std::string::const_iterator it = value.begin();
	while (it != value.end()) {
		if (!std::isdigit(*it) and *it != '.' and *it != '-') {
			return false;
		} else {
			*it++;
		}
	}

	return true;
}
