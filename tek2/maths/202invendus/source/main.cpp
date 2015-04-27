/* 
* @Author: gicque_p
* @Date:   2015-03-02 12:03:20
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-03-03 09:15:12
*/

#include <iostream>
#include "Law.hpp"
#include "Error.hpp"
using namespace std;

void sellThat(Law &);
void displayTab(Law &);
void displayDatas(Law &);
void displayProbabilities(Law &);

int main(int argc, char **argv) {
	if (argc != 3) {
		cerr << "\033[01;31m./202invendus: You must enter only 3 arguments\033[0m" << endl;
		return -1;
	} else {
		try {
			Law law(atoi(argv[1]), atoi(argv[2]));
			sellThat(law);
		} catch (const Error &error) {
			cerr << "\033[01;31m" << error.what() << "\033[0m" << endl;
			return -1;
		}

		return 0;
	}
}

void sellThat(Law &law) {
	displayTab(law);
	cout << endl;
	displayDatas(law);
	cout << endl;
	displayProbabilities(law);
}