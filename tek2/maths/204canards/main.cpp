/* 
* @Author: gicque_p
* @Date:   2015-04-05 14:01:42
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-04-12 23:41:48
*/

#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
using namespace std;

void usage(char **argv) {
	cout << argv[0] << ": real_constant (between 0 and 2.5)" << endl;
}

double f(double a, double t) {
	return a * exp(-t) + (4 - 3 * a) * exp(-2 * t) + (2 * a - 4) * exp(-4 * t);
}

double integration(double value) {
	double a(0);
	double b(10);

	int n(50);
	double h = (b - a) / (n + 1);

	double ret(0);

	for (int i = 0; i < n; i++) {
		ret += f(value, a + i * h);
	}
	ret *= (b - a) / n;

	return ret;
}

void esperance(double a) {
	double value(a * integration(a));
	double intpart(0);
	double fractpart(0);

	fractpart = modf(value, &intpart);
	fractpart *= 60;

	cout.precision(2);
	cout << "Temps de retour moyen:\t\t\t\t\t";
	cout << intpart << " minute(s) et " << fractpart << " seconde(s)";
	cout << endl;
}

void ecartType(double a) {
	double t(0);
	double t1(0);
	double t2(0);
	double result(0);
	double intpart(0);
	double fractpart(0);

	double esperance(a * integration(a));
	double ecart(sqrt(pow(a - esperance, 2) * integration(a)));

	cout.precision(2);
	cout << "Ecart-Type des temps de retour:\t\t\t\t" << esperance - ecart << endl;

	while (t < 10) {
		result += f(a, t);

		if (result >= 50 && t1 == 0) {
			t1 = t;
		}

		if (result >= 99 && t2 == 0) {
			t2 = t;
		}

		t += 0.01;
	}

	fractpart = modf(t1, &intpart);
	fractpart *= 60;
	cout << "Temps au bout duquel 50% des canards sont revenus:\t" << intpart << " minute(s) et " << fractpart << "seconde(s)" << endl;

	fractpart = modf(t2, &intpart);
	fractpart *= 60;
	cout << "Temps au bout duquel 99% des canards sont revenus:\t" << intpart << " minute(s) et " << fractpart << "seconde(s)" << endl;
}

void pourcent(double a) {
	double t(0);
	double p1(0);
	double p2(0);
	double result(0);
	double intpart(0);
	double fractpart(0);

	while (t <= 2) {
		fractpart = modf(t, &intpart);
		result += f(a, t);

		if (intpart == 1 and fractpart == 0) {
			p1 = result;
		}

		if (intpart == 2 and fractpart == 0) {
			p2 = result;
		}

		t += 1;
	}

	cout << "Pourcentage de canards revenus après 1 minutes:\t\t" << p1 << "%" << endl;
	cout << "Pourcentage de canards revenus après 2 minutes:\t\t" << p2 << "%" << endl;	
}

int main(int argc, char **argv, char **envp) {
	if (argc != 2) {
		usage(argv);
		return -1;
	} else {
		stringstream stream(argv[1]);
		double a;

		stream >> a;
		if (a < 0.000001 or a > 2.5) {
			usage(argv);
			return -1;
		} else {
			esperance(a);
			ecartType(a);
			pourcent(a);
			execve("./display.py", argv, envp);
			return 0;
		}
	}
}