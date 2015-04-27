#ifndef MISC_HPP_
# define MISC_HPP_

# include <iostream>
# include <sstream>
# include <algorithm>
# include <functional>
# include <cctype>
# include <locale>

# include "Kitchen.hpp"

class Misc {
 public:
	static void usage(char **);
	static double stringToNumber(const std::string &);
	static bool sortByOrders(const Kitchen &, const Kitchen &);

	static std::string getIngredientName(StockType);
	static std::string getPizzaTypeName(TypePizza);
	static std::string getPizzaSizeName(SizePizza);

	static double getTime(void);

	static std::string &ltrim(std::string &);
	static std::string &rtrim(std::string &);
	static std::string &trim(std::string &);
};

#endif /* MISC_HPP_ */
