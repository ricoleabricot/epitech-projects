#ifndef KITCHEN_HPP
# define KITCHEN_HPP

# include <map>
# include <list>
# include <ctime>
# include <sys/time.h>
# include <string>

# include "Mutex.hpp"
# include "NamedPipe.hpp"
# include "Cook.hpp"
# include "StockType.hpp"
# include "Misc.hpp"

class Cook;

class Kitchen {
private:
	Mutex 						*_mutex;
 	std::map<StockType, int> 	stock;
	Cook 						*cook_tab;
	NamedPipe 					to_read;
	NamedPipe 					to_write;
	std::string 				_name;
	int 						_cookNumber;
	int 						_ordersNumber;
	double 						stockTime;
	double						quitTime;
	double 						_multiplier;
	std::list<Pizza>			_pizzas;
public:
	Kitchen(const std::string &, int, double);
  Kitchen(const std::string &, int);
  ~Kitchen(void);

  	void resetQuit();
  	void resetStock();
	bool canTakeOrder(void);
	void takeOrder(void);
	void removeOrder(void);
	void setOrdersNumber(int);
	std::string getName(void) const;
	int getOrdersNumber(void) const;
	int getStock(StockType);
	std::map<StockType, int> *getStock(void);
	Mutex 		*getMutex(void);
	NamedPipe	*getToRead(void);
	NamedPipe	*getToWrite(void);
	double 		getMultiplier(void);
	std::list<Pizza> *getPizzas(void);

	void push(Pizza);
	void removeStock(TypePizza);
	void removeIngredient(StockType);
	bool receiveStock(void);
	bool receiveIngredient(StockType);

  	void 		run();
	bool 		finished();
	bool		cooked(double);
	bool		received(double);
	void 		routine();
  void	setStock(std::map<StockType, int> stock);
};

typedef struct 	s_tramp
{
	Kitchen 	*kitchen;
	Cook 		*cook;
} 				t_tramp;

#endif 	/* !KITCHEN_HPP */
