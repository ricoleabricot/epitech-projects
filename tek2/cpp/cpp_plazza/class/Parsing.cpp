/* 
* @Author: gicque_p
* @Date:   2015-04-16 13:54:56
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-04-24 19:18:06
*/

#include "Parsing.hpp"

Parsing::Parsing() {
	this->_types["regina"] = Regina;
	this->_types["margarita"] = Margarita;
	this->_types["americana"] = Americana;
	this->_types["fantasia"] = Fantasia;

	this->_sizes["S"] = S;
	this->_sizes["M"] = M;
	this->_sizes["L"] = L;
	this->_sizes["XL"] = XL;
	this->_sizes["XXL"] = XXL;
}

Parsing::~Parsing() {}

void Parsing::prepareOrders(Reception *reception, const std::string &order) {
	std::istringstream line(order);
	char token[512];

	struct s_data data;
	size_t orderNumber(1);

	if (order.empty()) {
		throw ParsingError("Empty Order");
	} else if (order.size() > 512) {
		throw ParsingError("Order too long, we ain't scribes you know ?");
	} else {
		while (line.getline(token, 512, ';')) {
			std::string newToken(token);

			data = this->prepareOrder(Misc::trim(newToken), orderNumber);
			for (size_t j = 0; j < data.number; j++) {
				Pizza pizza(data.type, data.size);
				pizza.setState(Awaiting);

				reception->push(pizza);
			}

			orderNumber++;
		}
	}
}

struct s_data Parsing::prepareOrder(const std::string &order, size_t orderNumber) {
	struct s_data data;
	std::istringstream word(order);
	std::string type;
	std::string size;
	std::string number;
	std::string other;

	word >> type;
	word >> size;
	word >> number;
	word >> other;

	if (!other.empty()) {
		std::stringstream stream;
		stream << "Too many argument in your order number ";
		stream << orderNumber;
		throw ParsingError(stream.str());
	} else {
		if (type.empty() or size.empty() or number.empty()) {
			std::stringstream stream;
			stream << "Not enough argument in your order number ";
			stream << orderNumber;
			throw ParsingError(stream.str());
		} else {
			std::transform(type.begin(), type.end(), type.begin(), ::tolower);
			std::transform(size.begin(), size.end(), size.begin(), ::toupper);
			std::transform(number.begin(), number.end(), number.begin(), ::tolower);

			data.type = prepareType(type, orderNumber);
			data.size = prepareSize(size, orderNumber);
			data.number = prepareNumber(number, orderNumber);

			return data;
		}
	}
}

TypePizza Parsing::prepareType(const std::string &type, size_t orderNumber) {
	if (this->_types.find(type) != this->_types.end()) {
		return this->_types[type];
	} else {
		std::stringstream stream;
		stream << "Unknow pizza type in your order number ";
		stream << orderNumber;

		throw ParsingError(stream.str());
	}
}

SizePizza Parsing::prepareSize(const std::string &size, size_t orderNumber) {
	if (this->_sizes.find(size) != this->_sizes.end()) {
		return this->_sizes[size];
	} else {
		std::stringstream stream;
		stream << "Unknow pizza size in your order number ";
		stream << orderNumber;

		throw ParsingError(stream.str());
	}
}

size_t Parsing::prepareNumber(const std::string &number, size_t orderNumber) {
	if (number.at(0) == 'x') {
		std::string newNumber(number.substr(1, number.length()));
		std::stringstream stream(newNumber);
		size_t pizzaNumber;
		stream >> pizzaNumber;

		if (pizzaNumber > 0 and pizzaNumber < 100) {
			return pizzaNumber;
		} else {
			std::stringstream stream;
			stream << "You must enter a pizza number between 1 and 99 in your order number ";
			stream << orderNumber;
			throw ParsingError(stream.str());
		}
	} else {
		std::stringstream stream;
		stream << "You must enter an 'x' character for pizza number in your order number ";
		stream << orderNumber;
		throw ParsingError(stream.str());
	}
}
