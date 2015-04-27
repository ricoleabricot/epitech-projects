/* 
* @Author: gicque_p
* @Date:   2015-02-04 12:25:13
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-27 17:10:58
*/

#include <sstream>
#include <cstdlib>
#include <map>

#include "Pair.hpp"
#include "Brelan.hpp"
#include "Carre.hpp"
#include "Full.hpp"
#include "Suite.hpp"
#include "Yams.hpp"
#include "Error.hpp"

int timesInTab(int *, int);
bool isNumber(const std::string &);

static void yamsThat(char **);
static ASuit *createObject(const std::string &, unsigned int, int *tab);

int main(int argc, char **argv) {
	(void)argv;
	if (argc != 7) {
		cerr << "\033[01;31mYou must enter 6 arguments only\033[0m" << endl;
		return -1;
	} else {
		try {
			yamsThat(argv);		
		} catch (const Error &error) {
			cerr << "\033[01;31m" << error.what() << "\033[0m" << endl;
			return -1;
		}

		return 0;
	}
}

void yamsThat(char **argv) {
	for (int i = 1; i < 6; i++) {
		if (!isNumber(argv[i])) {
			throw Error("You can only enter number between 1 and 6 for the first five arguments");
		}
	}

	ASuit *object;
	int tab[5] = { atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]) };
	std::string lastArg(argv[6]);
	std::string name;
	unsigned int pos;

	if ((pos = lastArg.find_first_of("_")) == lastArg.npos) {
		throw Error("Name of last argument undefined");
	} else {
		name = lastArg.substr(0, pos);
		lastArg.erase(0, pos + 1);

		if (name == "full") {
			std::string firstValue;
			std::string secondValue;

			if ((pos = lastArg.find_last_of("_")) == lastArg.npos) {
				throw Error("Syntax error for a full value");
			} else {
				firstValue = lastArg.substr(0, pos);
				secondValue = lastArg.substr(pos + 1, lastArg.npos);

				if (firstValue.empty() or secondValue.empty() or !isNumber(firstValue) or !isNumber(secondValue)) {
					throw Error("You can only enter number between 1 and 6 for the value of the two lasts argument");
				} else if (firstValue == secondValue) {
					throw Error("You can't enter the same value for the two arguments of a Full");
				} else {
					stringstream buffer;
					buffer << "Full of ";
					buffer << firstValue;
					buffer << " by ";
					buffer << secondValue;

					unsigned int n1 = timesInTab(tab, atoi(firstValue.c_str()));
					unsigned int n2 = timesInTab(tab, atoi(secondValue.c_str()));

					object = new Full(3, n1, 2, n2);
					object->setName(buffer.str());
				}
			}
		} else {
			if (lastArg.empty() or !isNumber(lastArg)) {
				throw Error("You can only enter number between 1 and 6 for the value of the last argument");
			} else {
				if (name == "suite" and atoi(lastArg.c_str()) < 5) {
					throw Error("You can't enter a value lower than 5 for a Straigth (it's logical!)");
				} else {
					unsigned int n = timesInTab(tab, atoi(lastArg.c_str()));
					if (name == "suite") {
						n = atoi(lastArg.c_str());
					}

					object = createObject(name, n, tab);
				}
			}
		}

		if (object) {
			cout << setprecision(2) << fixed;
			cout << "The probability to make a " << object->getName() << " of " << lastArg << " is around " << object->calculate() << "%" << endl;
		} else {
			throw Error("Unknowned last argument");
		}
	}
}

ASuit *createObject(const std::string &name, unsigned int value, int *tab) {
	map<const std::string, ASuit *> map;

	map["paire"] = new Pair(2, value);
	map["brelan"] = new Brelan(3, value);
	map["carre"] = new Carre(4, value);
	map["suite"] = new Suite(5, value, tab);
	map["yams"] = new Yams(5, value);

	return map[name];
}
