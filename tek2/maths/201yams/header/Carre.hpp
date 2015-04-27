#ifndef CARRE_HPP_
# define CARRE_HPP_

# include "ASuit.hpp"

class Carre : public ASuit {
 public:
	Carre(int, int);

	double calculate(void);
};

#endif /* !CARRE_HPP_ */
