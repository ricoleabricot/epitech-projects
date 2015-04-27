#ifndef PAIR_HPP_
# define PAIR_HPP_

# include "ASuit.hpp"

class Pair : public ASuit {
 public:
	Pair(int, int);

	double calculate(void);
};

#endif /* !PAIR_HPP_ */
