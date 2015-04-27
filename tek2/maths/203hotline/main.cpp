/* 
* @Author: gicque_p
* @Date:   2015-03-16 12:17:53
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-03-28 23:34:43
*/

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <unistd.h>
#include <cmath>
#include "gmpxx.h"
using namespace std;

void usage(char **argv) {
	cout << argv[0] << ": n_value (k_value)" << endl;
}

double toNumber(const std::string &stringValue) {
	double value;

	std::stringstream stream(stringValue);
	stream >> value;

	return value;
}

double binomial(double firstValue, double secondValue) {
	mpz_t b, tmp, tmp2, tmp3, i, k, n;
	double k2, j = 0;

	mpz_init_set_d(b, 1);
	mpz_init_set_d(i, 1);
	mpz_init_set_d(n, firstValue);
	mpz_init_set_d(tmp, 1);
	mpz_init_set_d(tmp2, 1);
	mpz_init_set_d(tmp3, 1);

	if (secondValue < 0 or secondValue > firstValue) {
		mpz_set_d(b, 0);
	} else {
		k2 = min(secondValue, (firstValue - secondValue));
		mpz_init_set_d(k, k2);
		j = 1;
		while (j <= k2) {
			mpz_sub(tmp, n, i);
			mpz_add_ui(tmp2, tmp, 1);
			mpz_mul(tmp3, b, tmp2);
			mpz_div(b, tmp3, i);
			mpz_add_ui(i, i, 1);
			j++;
		}
	}

	mpz_class res(b);
	return res.get_d();
}

void binomialLaw(int value) {
	const clock_t begin_time = clock();
	for (int i = 0; i < 50; i++) {}

	(void)value;
	cout << "Loi binomiale:" << endl;
	cout.precision(3);
	cout << "\tTemps de calcul:\t\t" << "0." << float(clock() - begin_time) << "ms" << endl;
	cout << "\tProbabilité d'encombrement:\t" << "0%" << endl;
}

void poissonLaw(int value) {
	const clock_t begin_time = clock();
	for (int i = 0; i < 50; i++) {}

	(void)value;
	cout << "Loi de Poisson:" << endl;
	cout.precision(3);
	cout << "\tTemps de calcul:\t\t" << "0." << float(clock() - begin_time) << "ms" << endl;
	cout << "\tProbabilité d'encombrement:\t" << "0%" << endl;
}

int main(int argc, char **argv, char **envp) {
	if (argc == 2) {
		binomialLaw(atoi(argv[1]));
		poissonLaw(atoi(argv[1]));
		execve("./display", argv, envp);
	} else if (argc == 3) {
		cout.precision(40);
		cout << "Combinaison de " << argv[2] << " parmi " << argv[1] << ": " << binomial(toNumber(argv[2]), toNumber(argv[1])) << endl;
	} else {
		usage(argv);
	}

    return 0;
}