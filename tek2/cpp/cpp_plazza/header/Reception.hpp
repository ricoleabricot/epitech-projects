#ifndef RECEPTION_HPP_
# define RECEPTION_HPP_

# include <iostream>
# include <sstream>
# include <list>
# include <queue>
# include <sys/select.h>

# include "MainWindow.hpp"
# include "Kitchen.hpp"
# include "Pizza.hpp"
# include "Parsing.hpp"
# include "Log.hpp"
# include "Error.hpp"

class Reception {
	double _preparePizza;
	int _numberCook;
	int _replaceStock;
	int _lastKitchen;
	int _earnedMoney;
	int _savedMoney;
	int _day;
	Kitchen *_currentKitchen;

	std::list<Kitchen> _kitchens;
	std::queue<Pizza> _orders;

	Reception(const Reception &);
	Reception &operator=(const Reception &);

	void	setReadFD(fd_set *rfds);
	void	checkReadFD(fd_set *rfds);
	int	max_fd(void);

 public:
	Log _log;

	Reception(double, int, int);
	~Reception();

	void init(void);
	void run(void);
	void stop(void);

	Kitchen *createKitchen(void);
	void sendOrder(Kitchen *);

	void push(Pizza);
	void pop(void);

	void setCurrentKitchen(Kitchen &);
	bool verifyKitchenState(void);

	int rentNewDay(void);

	double getPreparePizza(void) const;
	int getNumberCook(void) const;
	int getReplaceStock(void) const;
	std::list<Kitchen> *getKitchens(void);
	std::queue<Pizza> getOrders(void) const;
	int getEarnedMoney(void) const;
	Kitchen *getCurrentKitchen(void) const;
	int getDay(void) const;
	int getSavedMoney(void) const;
	
	void readPipes(void);
};

#endif /* RECEPTION_HPP_ */
