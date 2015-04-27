#ifndef SUITE_HPP_
# define SUITE_HPP_

# include "ASuit.hpp"

class Suite : public ASuit {
	int *_tab;

 public:
	Suite(int, int, int *);

	double calculate(void);
};

#endif /* !SUITE_HPP_ */
