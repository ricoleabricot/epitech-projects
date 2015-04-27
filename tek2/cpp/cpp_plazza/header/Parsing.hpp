#ifndef PARSING_HPP_
# define PARSING_HPP_

# include <iostream>
# include <sstream>
# include <string>
# include <map>
# include <queue>

# include "Reception.hpp"
# include "Pizza.hpp"
# include "Misc.hpp"
# include "Error.hpp"

struct s_data {
	TypePizza type;
	SizePizza size;
	size_t number;
};

class Reception;

class Parsing {
	std::map<std::string, TypePizza> _types;
	std::map<std::string, SizePizza> _sizes;

	Parsing(const Parsing &);
	Parsing &operator=(const Parsing &);

 public:
	Parsing();
	~Parsing();

	void prepareOrders(Reception *, const std::string &);
	struct s_data prepareOrder(const std::string &, size_t);
	TypePizza prepareType(const std::string &, size_t);
	SizePizza prepareSize(const std::string &, size_t);
	size_t prepareNumber(const std::string &, size_t);
};

#endif /* PARSING_HPP_ */
