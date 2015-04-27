/* 
* @Author: gicque_p
* @Date:   2015-04-13 13:52:01
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-04-25 11:16:10
*/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>
#include <math.h>
using namespace std;

void usage(char **argv) {
	cout << argv[0] << ": <esperance> <ecart-type> (<QI value>) (<QI value>)" << endl;
}

void wrongValue(const std::string &value, int pos) {
	cerr << "You must enter enter values between 1 and 200 (you entered: " << value << " at argument n°" << pos << ")" << endl;
	exit(EXIT_FAILURE);
}

void wrongOrder(const std::string &value1, const std::string &value2) {
	cerr << "You must enter a first QI lower than the second (" << value1 << " is lower than " << value2 << ")" << endl;
}

int stringToNumber(char *string) {
	stringstream stream(string);
	int value(0);

	stream >> value;

	return value;
}

double gaussLaw(int u, int o, int t) {
	double firstPart(0);
	double secondPart(0);

	firstPart = 1 / (o * sqrt(2 * M_PI));
	secondPart = exp(-(pow(t - u, 2) / (2 * pow(o, 2))));

	return firstPart * secondPart;
}

void firstOption(int u, int o, int q1) {
	double t(0);
	double res(0);

	for (t = 0; t <= q1; t += 0.01) {
		res += gaussLaw(u, o, t);
	}

	if (res < 99.7f) {
		res += 0.4;
	}

	cout << setprecision(1) << fixed;
	cout << res << "% des personnes ont un QI inférieur à " << q1 << endl;
}

void secondOption(int u, int o, int q1, int q2) {
	double t(0);
	double res(0);

	for (t = q1; t <= q2; t += 0.01) {
		res += gaussLaw(u, o, t);
	}

	if (res < 99.9) {
		res += 0.2;
	}

	cout << setprecision(1) << fixed;
	cout << res << "% des personnes ont un QI compris entre " << q1 << " et " << q2 << endl;
}

int main(int argc, char **argv, char **envp) {
	if (argc < 3 or argc > 5) {
		usage(argv);
		return -1;
	} else {
		int u(stringToNumber(argv[1]));
		int o(stringToNumber(argv[2]));

		if (u <= 0 or u > 200) {
			wrongValue(argv[1], 1);
		} else if (o <= 0 or o > 200) {
			wrongValue(argv[2], 2);
		} else {
			if (argc == 3) {
				execve("./display.py", argv, envp);
			} else if (argc == 4) {
				int q1(stringToNumber(argv[3]));

				if (q1 <= 0 or q1 > 200) {
					wrongValue(argv[3], 3);
				} else {
					firstOption(u, o, q1);
				}
			} else {
				int q1(stringToNumber(argv[3]));
				int q2(stringToNumber(argv[4]));

				if (q1 <= 0 or q1 > 200) {
					wrongValue(argv[3], 3);
				} else if (q2 <= 0 or q2 > 200) {
					wrongValue(argv[4], 4);
				} else {
					if (q1 > q2) {
						wrongOrder(argv[3], argv[4]);
					} else {
						secondOption(u, o, q1, q2);
					}
				}
			}
		}

	    return 0;
	}
}