/* 
* @Author: gicque_p
* @Date:   2015-04-27 09:18:27
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-05-17 09:26:30
*/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <math.h>
#include <string.h>
using namespace std;

typedef std::numeric_limits<double> dbl;

void usage(char **argv) {
	cout << argv[0] << ": <antal mãlinder> <aritmetisk gennemsnit> <harmonisk gennemsnit> <standardafvigelse>" << endl;
}

bool valide_arguments(double antal, double aritmetisk, double harmonisk, double standar) {
	if (antal < 0) {
		cerr << "antallet af målinger skal være positiv" << endl;
	} else if (aritmetisk < 0) {
		cerr << "det aritmetiske gennemsnit skal være positiv" << endl;
	} else if (harmonisk < 0) {
		cerr << "det harmoniske gennemsnit skal være positiv" << endl;
	} else if (standar < 0) {
		cerr << "standardafvigelsen skal være positiv" << endl;
	} else {
		return true;
	}

	return false;
}

double stringToNumber(const std::string &value) {
	std::stringstream stream(value);
	double number(0);

	stream >> number;
	return number;
}

int main(int argc, char **argv) {
	char line[512];

	if (argc == 5) {
		long double antal(stringToNumber(argv[1]));
		long double aritmetisk(stringToNumber(argv[2]));
		long double kvadratisk(0);
		long double harmonisk(stringToNumber(argv[3]));
		long double standar(stringToNumber(argv[4]));

		if (valide_arguments(antal, aritmetisk, harmonisk, standar)) {
			while (cout << "indtast din vaerdi: " and cin.getline(line, 511) and strcmp(line, "ende")) {
				std::string indtast(line);
				if (!indtast.empty()) {
					long double malinder(stringToNumber(indtast));
					long double regnestykke(aritmetisk * antal);
					long double regnestykkeFirkantet((pow(standar, 2) + pow(aritmetisk, 2)) * antal);

					antal++;

					aritmetisk = (regnestykke + malinder) / antal;
					standar = sqrt(((regnestykkeFirkantet + pow(malinder, 2)) / antal) - pow(aritmetisk, 2));
					kvadratisk = sqrt((regnestykkeFirkantet + pow(malinder, 2)) / antal);
					harmonisk = antal / ((1 / malinder) + ((antal - 1) / harmonisk));

					cout << setprecision(0) << fixed;
					cout << "\tantal mãlinder:\t\t" << antal << endl;

					cout << setprecision(2) << fixed;
					cout << "\tstandardafvigelse:\t" << standar << endl;
					cout << "\taritmetisk gennemsnit:\t" << aritmetisk << endl;
					cout << "\tkvadratisk gennemsnit:\t" << kvadratisk << endl;
					cout << "\tharmonisk gennemsnit:\t" << harmonisk << endl;
					cout << endl;
				}
			}

			return 0;
		} else {
			return -1;
		}
	} else {
		usage(argv);
		return -1;
	}
}
