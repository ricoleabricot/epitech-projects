#ifndef COOK_HPP
# define COOK_HPP

class 	Kitchen;

# include "Pizza.hpp"
# include "Thread.hpp"
# include "Kitchen.hpp"
# include "StockType.hpp"

class Cook
{
private:
	Thread 		*m_thread;
	Pizza		*m_processing;
	Pizza		*m_awaiting;
	Mutex 		*m_mutex;
public:
	Cook();
	~Cook();
	void 		setProcessing(Pizza *);
	void 		setAwaiting(Pizza *);
	void 		setThread(Thread *);
	void 		clearProcessing();
	void 		clearAwaiting();
	void 		pizzaFinished(Pizza *);
	Pizza		*getProcessing() const;
	Pizza		*getAwaiting() const;
	Thread 		*getThread() const;
	Mutex 		*getMutex() const;
	int 		removeIngredient(StockType, std::map<StockType, int> *, bool);
	int 		removeRegina(std::map<StockType, int> *, bool);
	int 		removeMargarita(std::map<StockType, int> *, bool);
	int 		removeAmericana(std::map<StockType, int> *, bool);
	int 		removeFantasia(std::map<StockType, int> *, bool);
	void		removeStock(TypePizza, Kitchen *);
	void 		routine(Kitchen *);
};

#endif
