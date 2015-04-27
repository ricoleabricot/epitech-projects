/* 
* @Author: gicque_p
* @Date:   2015-04-16 15:40:51
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-04-25 12:33:42
*/

#include "Misc.hpp"

void Misc::usage(char **argv) {
	std::cout << argv[0] << ": ";
	std::cout << "<preparation time> <number of cooks> <stock replacement time>";
	std::cout << std::endl;
}

double Misc::stringToNumber(const std::string &value) {
	std::stringstream stream(value);
	double number;

	stream >> number;

	return (number);
}

bool Misc::sortByOrders(const Kitchen &k1, const Kitchen &k2) {
	return k1.getOrdersNumber() < k2.getOrdersNumber();
}

std::string Misc::getIngredientName(StockType type) {
	std::map<StockType, std::string> map;

	map[doe] = "Doe";
	map[tomato] = "Tomato";
	map[gruyere] = "Gruyere";
	map[ham] = "Ham";
	map[mushroom] = "Mushroom";
	map[steak] = "Steak";
	map[eggplant] = "EggPlant";
	map[goatCheese] = "GoatCheese";
	map[chiefLove] = "ChiefLove";

	return map[type];
}

std::string Misc::getPizzaTypeName(TypePizza type) {
	std::map<TypePizza, std::string> map;

	map[Regina] = "Regina";
	map[Margarita] = "Margarita";
	map[Americana] = "Americana";
	map[Fantasia] = "Fantasia";

	return map[type];
}

std::string Misc::getPizzaSizeName(SizePizza size) {
	std::map<SizePizza, std::string> map;

	map[S] = "S";
	map[M] = "L";
	map[L] = "M";
	map[XL] = "XL";
	map[XXL] = "XXL";

	return map[size];
}

double Misc::getTime(void) {
	struct timeval  tv;
	gettimeofday(&tv, NULL);

	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

std::string &Misc::ltrim(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
	return s;
}

std::string &Misc::rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
	return s;
}

std::string &Misc::trim(std::string &s) {
	return ltrim(rtrim(s));
}
