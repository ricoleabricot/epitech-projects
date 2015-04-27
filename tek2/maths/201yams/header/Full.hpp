#ifndef FULL_HPP_
# define FULL_HPP_

# include "ASuit.hpp"

class Full : public ASuit {
 protected:
	int _k2;
	int _n2;

 public:
	Full(int, int, int, int);

	double calculate(void);
};

#endif /* !FULL_HPP_ */
