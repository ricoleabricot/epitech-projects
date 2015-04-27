/*
* @Author: gicque_p
* @Date:   2015-04-17 18:31:09
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-04-26 21:12:27
*/

#include "Reception.hpp"
#include "Process.hpp"

Reception::Reception(double preparePizza, int numberCook, int replaceStock) : _preparePizza(preparePizza), _numberCook(numberCook), _replaceStock(replaceStock), _lastKitchen(0), _earnedMoney(10000), _savedMoney(10000), _day(1), _log("") {
	time_t now = time(0);
	tm *ltm = localtime(&now);
	std::ostringstream stream;

	_currentKitchen = NULL;
	stream << "log/" << ltm->tm_mday << "-" << (1 + ltm->tm_mon) << "-" << (1900) + ltm->tm_year << ".log";
	this->_log.changeLogFile(stream.str());

	this->_log.write("--- NEW SESSION OF PLAZZA ---\n");
}

Reception::~Reception() {
	this->_log.write("--- END SESSION OF PLAZZA ---\n");
}

void Reception::init(void) {
	if (this->_preparePizza <= 0 or this->_preparePizza > 5) {
		throw ReceptionError("Pizza preparation time must be contained between 0 (excluded) and 5");
	} else if (this->_numberCook <= 0 or this->_numberCook > 20) {
		throw ReceptionError("Number of cooks by kitchen must be contained between 0 (excluded) and 20");
	} else if (this->_replaceStock < 500 or this->_replaceStock > 3000) {
		throw ReceptionError("Kitchen's stock replacement time must be contained between 500 and 3000");
	}
}

void Reception::run(void) {
	Kitchen *to_send;

	while (!this->_orders.empty()) {
		bool taken(false);

		this->_kitchens.sort(Misc::sortByOrders);
		for (std::list<Kitchen>::iterator it = this->_kitchens.begin(); it != this->_kitchens.end(); it++) {
			if (it->canTakeOrder()) {
				it->takeOrder();
				it->push(this->_orders.front());

				to_send = &(*it);
				taken = true;
				break;
			}
		}

		if (!taken) {
			to_send = createKitchen();
			to_send->push(this->_orders.front());
		}

		sendOrder(to_send);
		this->pop();
	}

	this->_currentKitchen = NULL;
}

Kitchen *Reception::createKitchen(void) {
	pid_t pid;
	std::ostringstream stream;

	stream << "Kitchen" << this->_lastKitchen;
	// NamedPipe::create("write_" + stream.str());
	// NamedPipe::create("read_" + stream.str());
	// pid = Process::createProcess();
	pid = 1;

	if (pid == -1) {
		exit(1);
	} else if (pid == 0) {
		// Kitchen new_kitch(stream.str(), _numberCook, _preparePizza);		

		write(1, "New process\n", strlen("New process\n"));
		this->_log.write("Launching new Kitchen process\n");
		// new_kitch.run();
	} else {
		Kitchen kitchen(stream.str(), _numberCook);

		this->_kitchens.push_back(kitchen);
		this->_kitchens.back().takeOrder();
		this->_earnedMoney -= 300;
		this->_lastKitchen++;
		this->_log.write("Creation of new Kitchen in the list\n");
		return (&(this->_kitchens.back()));
	}

	return (NULL);
}

void Reception::sendOrder(Kitchen *to_send) {
	PipeData data(this->_orders.front());
	NamedPipe *to_read;

	to_read = to_send->getToRead();
	to_read->writePipe(data);
}

void Reception::stop(void) {
	for (std::list<Kitchen>::iterator it = this->_kitchens.begin(); it != this->_kitchens.end(); it++) {
		it->getToWrite()->destroy();
		it->getToRead()->destroy();
	}
}

void Reception::push(Pizza pizza) {
	this->_log.write("Receiving a new order on the queue\n");
	this->_orders.push(pizza);
}

void Reception::pop(void) {
	this->_log.write("Deleting a new order on the queue\n");
	this->_orders.pop();
}

void Reception::setCurrentKitchen(Kitchen &currentKitchen) {
  this->_currentKitchen = &currentKitchen;
}

bool Reception::verifyKitchenState(void) {
	bool orderNew(false);
	
	if (this->_kitchens.size() > 0) {
		for (std::list<Kitchen>::iterator it = this->_kitchens.begin(); it != this->_kitchens.end(); it++) {
			for (std::list<Pizza>::iterator it2 = it->getPizzas()->begin(); it2 != it->getPizzas()->end(); it2++) {
				if (it2->getState() == Processing) {
					if (it->cooked(it2->getCookingTime(this->_preparePizza))) {
						it2->setState(Finished);
						it->removeOrder();
						it->resetQuit();
						this->_earnedMoney += it2->getCookingTime(1) * it2->getSize();
						orderNew = true;
					}
				} else if (it2->getState() == Awaiting and orderNew) {
					it2->setState(Processing);
					it->resetQuit();
					it->removeStock(it2->getType());
					it->resetStock();
					orderNew = false;
				}
			}

			if (it->received(this->_replaceStock)) {
				if (it->receiveStock()) {
					this->_earnedMoney -= 20;
				}

				it->resetStock();
			}

			if (it->finished()) {
				this->_log.write("Solding a kitchen\n");

				if (this->_currentKitchen != NULL and it->getName() == this->_currentKitchen->getName()) {
					this->_currentKitchen = NULL;
				}

				it = this->_kitchens.erase(it);
				this->_earnedMoney += 250;
				return true;
			}
		}		
	}

	return false;
}

int Reception::rentNewDay(void) {
	unsigned int size(0);
	int ret(0);

	if ((size = this->_kitchens.size()) == 0) {
		this->_earnedMoney -= 500;
	} else {
		this->_earnedMoney -= this->_kitchens.size() * 100;
	}

	ret = this->_earnedMoney - this->_savedMoney;

	this->_day++;
	this->_savedMoney = this->_earnedMoney;

	return ret;
}

double Reception::getPreparePizza(void) const {
	return this->_preparePizza;
}

int Reception::getNumberCook(void) const {
	return this->_numberCook;
}

int Reception::getReplaceStock(void) const {
	return this->_replaceStock;
}

std::list<Kitchen> *Reception::getKitchens(void) {
	return (&(this->_kitchens));
}

std::queue<Pizza> Reception::getOrders(void) const {
	return this->_orders;
}

int Reception::getEarnedMoney(void) const {
	return this->_earnedMoney;
}

Kitchen *Reception::getCurrentKitchen(void) const {
	return this->_currentKitchen;
}

int Reception::getDay(void) const {
	return this->_day;
}

int Reception::getSavedMoney(void) const {
	return this->_savedMoney;
}

void			Reception::setReadFD(fd_set *rfds)
{
  FD_ZERO(rfds);
  for (std::list<Kitchen>::iterator it = _kitchens.begin(); it != _kitchens.end(); it++)
    FD_SET(it->getToWrite()->getfd(), rfds);
}

void			Reception::checkReadFD(fd_set *rfds)
{
  PipeData		*data;
  std::map<StockType, int> *map;
  Pizza			*pzz;

  for (std::list<Kitchen>::iterator it = _kitchens.begin(); it != _kitchens.end(); it++)
    if (FD_ISSET(it->getToWrite()->getfd(), rfds))
      {
	data = it->getToWrite()->readPipe();
	if ((map = data->getStock()) != NULL)
	  it->setStock(*map);
	if ((pzz = data->getPizza()) != NULL)
	  std::cout << "PIZZA END" << std::endl;
	delete(data);
      }
}

int			Reception::max_fd(void)
{
  int			fd;

  fd = 0;
  for (std::list<Kitchen>::iterator it = _kitchens.begin(); it != _kitchens.end(); it++)
    if (it->getToWrite()->getfd() > fd)
      fd = it->getToWrite()->getfd();
  return (fd + 1);
}

void			Reception::readPipes(void)
{
  fd_set		rfds;
  struct timeval	timeout;

  timeout.tv_sec = 0;
  timeout.tv_usec = 100000;
  setReadFD(&rfds);
  if (select(max_fd(), &rfds, NULL, NULL, &timeout) != -1)
    checkReadFD(&rfds);
}
