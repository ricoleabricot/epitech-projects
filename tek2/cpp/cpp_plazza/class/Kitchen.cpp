/* 
* @Author: ribeir_b
* @Date:   2015-04-20 16:36:14
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-04-26 21:11:58
*/

#include 	<iostream>
#include 	<stdlib.h>
#include 	<string.h>
#include 	"Kitchen.hpp"

void 		*trampoline(void *param)
{
	t_tramp *trampo;

	trampo = (reinterpret_cast<t_tramp *>(param));
	trampo->cook->routine(trampo->kitchen);
	return (NULL);
}

Kitchen::Kitchen(const std::string &name, int cookNumber, double multiplier) : to_read("read_" + name, READ), to_write("write_" + name, WRITE), _name(name), _cookNumber(cookNumber), _ordersNumber(0), stockTime(Misc::getTime()), quitTime(Misc::getTime()), _multiplier(multiplier)
{
	int 		i = 0;
	t_tramp 	trampo;

	stock[doe] = 5;
	stock[tomato] = 5;
	stock[gruyere] = 5;
	stock[ham] = 5;
	stock[mushroom] = 5;
	stock[steak] = 5;
	stock[eggplant] = 5;
	stock[goatCheese] = 5;
	stock[chiefLove] = 5;
	_multiplier = multiplier;
	_mutex = new Mutex();
	cook_tab = new Cook[cookNumber];
	trampo.kitchen = this;
	while (i != cookNumber)
	{
		trampo.cook = &(cook_tab[i]);
	  	cook_tab[i].setThread(new Thread(trampoline, &(trampo)));
		++i;
	}
	// cook_tab[8000].setThread(new Thread(trampoline, &(trampo)));
	write(1, "Kctor finished\n", strlen("Kctor finished\n"));
}

Kitchen::Kitchen(const std::string &name, int cookNumber) : to_read("read_" + name, WRITE), to_write("write_" + name, READ), _name(name), _cookNumber(cookNumber), _ordersNumber(0)
{
  stock[doe] = 5;
  stock[tomato] = 5;
  stock[gruyere] = 5;
  stock[ham] = 5;
  stock[mushroom] = 5;
  stock[steak] = 5;
  stock[eggplant] = 5;
  stock[goatCheese] = 5;
  stock[chiefLove] = 5;
  _mutex = NULL;
  quitTime = Misc::getTime();
  stockTime = Misc::getTime();
}

Kitchen::~Kitchen()
{
	if (_mutex != NULL)
	delete _mutex;
}

bool Kitchen::finished(void) {
	if (Misc::getTime() - quitTime >= 5000) {
		return true;
	} else {		
		return false;
	} 
}

bool Kitchen::cooked(double cookingTime) {
	if (Misc::getTime() - quitTime >= cookingTime * 1000) {
		return true;
	} else {
		return false;
	} 
}

bool Kitchen::received(double replaceStock) {
	if (Misc::getTime() - stockTime >= replaceStock) {
		return true;
	} else {		
		return false;
	} 
}

void Kitchen::run(void) 
{
	PipeData *data;
	Pizza *pizza;
	Pizza *processing;
	Pizza *awaiting;
	Cook new_taker;
	char which = 'P';

	quitTime = clock();
	write(1, "kitchen qui commence\n", strlen("kitchen qui commence\n"));
	while (!finished()) 
	{
		data = this->to_read.readPipe();
		if ((pizza = data->getPizza()) != NULL) 
		{
			resetQuit();
			int i = 0;
			while (i != _cookNumber) 
			{
				if ((processing = cook_tab[i].getProcessing()) != NULL) 
				{
					if ((awaiting = cook_tab[i].getAwaiting()) == NULL) 
					{
						new_taker = cook_tab[i];
						which = 'A';
						std::cout << "Break 1" << std::endl;
						break;
					}
					resetQuit();
				} 
				else
				{
					new_taker = cook_tab[i];
					which = 'P';
					std::cout << "Break 2" << std::endl;
					resetQuit();
					break;
				}
				++i;
			}
			Mutex *cook_mut;

			_ordersNumber++;
			cook_mut = new_taker.getMutex();
			cook_mut->lock();
			if (which == 'P') 
				new_taker.setProcessing(pizza);
			else
				new_taker.setAwaiting(pizza);
			cook_mut->unlock();
			std::cout << "Broke" << std::endl;
			data = NULL;
			resetQuit();
		}
	}
	std::cout << "END OF PROCESS" << std::endl;
	exit(0);
}

void 	Kitchen::resetQuit() {
	quitTime =  Misc::getTime();
}

void Kitchen::resetStock(void) {
	stockTime = Misc::getTime();
}

bool Kitchen::canTakeOrder(void) {
	return (this->_ordersNumber + 1) <= (this->_cookNumber * 2);
}

void Kitchen::takeOrder(void) {
	this->_ordersNumber++;
}

void Kitchen::removeOrder(void) {
	this->_ordersNumber--;
}

void Kitchen::setOrdersNumber(int ordersNumber) {
	this->_ordersNumber = ordersNumber;
}

std::string Kitchen::getName(void) const {
	return this->_name;
}

int Kitchen::getOrdersNumber(void) const {
	return this->_ordersNumber;
}

int Kitchen::getStock(StockType type) {
	return this->stock[type];
}

std::map<StockType, int> 	*Kitchen::getStock(void) {
	return (&(this->stock));
}

Mutex 		*Kitchen::getMutex(void) {
	return this->_mutex;
}

NamedPipe	*Kitchen::getToRead(void)
{
  return (&to_read);
}

NamedPipe	*Kitchen::getToWrite(void)
{
  return (&to_write);
}

double 		Kitchen::getMultiplier(void)
{
	return (_multiplier);
}

void Kitchen::push(Pizza pizza) {
	int cpt(0);

	for (std::list<Pizza>::iterator it = this->_pizzas.begin(); it != this->_pizzas.end(); it++) {
		if (it->getState() == Processing) {
			cpt++;
		}
	}

	if (cpt < this->_cookNumber) {
		pizza.setState(Processing);
	}

	this->_pizzas.push_back(pizza);
	this->quitTime = clock();
}

std::list<Pizza> *Kitchen::getPizzas(void) {
	return &this->_pizzas;
}

void Kitchen::removeStock(TypePizza type) {
	if (type == Regina) {
		this->removeIngredient(doe);
		this->removeIngredient(tomato);
		this->removeIngredient(gruyere);
		this->removeIngredient(ham);
		this->removeIngredient(mushroom);
	} else if (type == Margarita) {
		this->removeIngredient(doe);
		this->removeIngredient(tomato);
		this->removeIngredient(gruyere);
	} else if (type == Americana) {
		this->removeIngredient(doe);
		this->removeIngredient(tomato);
		this->removeIngredient(gruyere);
		this->removeIngredient(steak);
	} else {
		this->removeIngredient(doe);
		this->removeIngredient(tomato);
		this->removeIngredient(eggplant);
		this->removeIngredient(goatCheese);
		this->removeIngredient(chiefLove);
	}
}

void Kitchen::removeIngredient(StockType type) {
	if (this->stock[type] > 0) {
		this->stock[type]--;
	}
}

bool Kitchen::receiveStock(void) {
	bool ret(false);

	ret = this->receiveIngredient(doe);
	this->receiveIngredient(tomato);
	this->receiveIngredient(gruyere);
	this->receiveIngredient(steak);
	this->receiveIngredient(ham);
	this->receiveIngredient(mushroom);
	this->receiveIngredient(eggplant);
	this->receiveIngredient(goatCheese);
	this->receiveIngredient(chiefLove);

	return ret;
}

bool Kitchen::receiveIngredient(StockType type) {
	if (this->stock[type] < 5) {
		this->stock[type]++;
		return true;
	}

	return false;
}

void		Kitchen::setStock(std::map<StockType, int> stck)
{
  stock = stck;
}
