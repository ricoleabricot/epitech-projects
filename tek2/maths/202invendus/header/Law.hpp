#ifndef LAW_HPP_
# define LAW_HPP_

# include <iostream>
# include <cstdlib>
# include <cmath>

class Law {
	int _a;
	int _b;

 public:
	double _tab[6][6];

	Law(int, int);
	~Law() {};

	double join(int, int);
	double esperanceX(void);
	double varianceX(void);
	double esperanceY(void);
	double varianceY(void);
	
	int getA(void) const;
	int getB(void) const;
};

#endif /* !LAW_HPP_ */