#ifndef ASUIT_HPP_
# define ASUIT_HPP_

# include <iostream>
# include <iomanip>
# include <cmath>
using namespace std;

class ASuit {
 protected:
	int _k;
	int _n;
	std::string _name;

 public:
	ASuit(int, int, const std::string &);

	ASuit& operator=(ASuit const &);

	int getK(void) const;
	int getN(void) const;
	std::string getName(void) const;
	void setName(const std::string &);

	virtual double calculate(void) = 0;
};

int factorial(int);
double binomial(double, double);

#endif /* !ASUIT_HPP_ */
