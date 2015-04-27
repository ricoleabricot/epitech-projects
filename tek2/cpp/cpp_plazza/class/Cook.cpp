/* 
* @Author: ribeir_b
* @Date:   2015-04-22 11:02:09
* @Last Modified by:   ribeir_b
* @Last Modified time: 2015-04-24 14:26:31
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Cook.hpp"

Cook::Cook()
{
	m_processing = NULL;
	m_awaiting = NULL;
	m_mutex = new Mutex();
}

Cook::~Cook()
{
	delete m_mutex;
}

void 		Cook::setProcessing(Pizza *to_add)
{
	this->m_processing = to_add;
	this->m_processing->setState(Processing);
}

void 		Cook::setAwaiting(Pizza *to_add)
{
	this->m_awaiting = to_add;
	this->m_awaiting->setState(Awaiting);
}

void 		Cook::setThread(Thread *to_add)
{
	this->m_thread = to_add;
}

void 		Cook::clearProcessing()
{
	this->m_processing = NULL;
}

void 		Cook::clearAwaiting()
{
	this->m_awaiting = NULL;
}

void 		Cook::pizzaFinished(Pizza *to_remove)
{
	to_remove->setState(Finished);
}

Pizza 		*Cook::getProcessing() const
{
	return (this->m_processing);
}

Pizza 		*Cook::getAwaiting() const
{
	return (this->m_awaiting);
}

Thread 		*Cook::getThread() const
{
	return (this->m_thread);
}

Mutex 		*Cook::getMutex() const
{
	return (this->m_mutex);
}

int 		Cook::removeIngredient(StockType to_rm, std::map<StockType, int> *stock, bool for_real)
{
	int 	i;

	i = (*stock)[to_rm];
	if (i <= 0)
		return (0);
	else
	{
		if (for_real)
			(*stock)[to_rm] = (*stock)[to_rm] - 1;
		return (1);
	}
}

int 		Cook::removeRegina(std::map<StockType, int> *stock, bool for_real)
{
	if (!(removeIngredient(doe, stock, for_real)))
		return (1);
	if (!(removeIngredient(tomato, stock, for_real)))
		return (1);
	if (!(removeIngredient(gruyere, stock, for_real)))
		return (1);
	return (0);
}

int 		Cook::removeMargarita(std::map<StockType, int> *stock, bool for_real)
{
	if (!(removeIngredient(doe, stock, for_real)))
		return (1);
	if (!(removeIngredient(tomato, stock, for_real)))
		return (1);
	if (!(removeIngredient(gruyere, stock, for_real)))
		return (1);
	return (0);
}

int 		Cook::removeAmericana(std::map<StockType, int> *stock, bool for_real)
{
	if (!(removeIngredient(doe, stock, for_real)))
		return (1);
	if (!(removeIngredient(tomato, stock, for_real)))
		return (1);
	if (!(removeIngredient(gruyere, stock, for_real)))
		return (1);
	if (!(removeIngredient(steak, stock, for_real)))
		return (1);
	return (0);
}

int 		Cook::removeFantasia(std::map<StockType, int> *stock, bool for_real)
{
	if (!(removeIngredient(doe, stock, for_real)))
		return (1);
	if (!(removeIngredient(tomato, stock, for_real)))
		return (1);
	if (!(removeIngredient(eggplant, stock, for_real)))
		return (1);
	if (!(removeIngredient(goatCheese, stock, for_real)))
		return (1);
	if (!(removeIngredient(chiefLove, stock, for_real)))
		return (1);
	return (0);
}

void 		Cook::removeStock(TypePizza type, Kitchen *kitchen)
{
	if (type == Regina)
	{
		while (removeRegina(kitchen->getStock(), false));
		(kitchen->getMutex())->lock();
		removeRegina(kitchen->getStock(), true);
		(kitchen->getMutex())->unlock();
	}
	else if (type == Margarita)
	{
		while (removeMargarita(kitchen->getStock(), false));
		(kitchen->getMutex())->lock();
		removeMargarita(kitchen->getStock(), true);
		(kitchen->getMutex())->unlock();
	}
	else if (type == Americana)
	{
		while (removeAmericana(kitchen->getStock(), false));
		(kitchen->getMutex())->lock();
		removeAmericana(kitchen->getStock(), true);
		(kitchen->getMutex())->unlock();
	}
	else
	{
		while (removeFantasia(kitchen->getStock(), false));
		(kitchen->getMutex())->lock();
		removeFantasia(kitchen->getStock(), true);
		(kitchen->getMutex())->unlock();
	}
}

void		Cook::routine(Kitchen *kitchen)
{
	NamedPipe 	*writing;

	while (true)
	{
		if (m_processing != NULL)
		{
			removeStock(m_processing->getType(), kitchen);
			sleep(m_processing->getCookingTime(kitchen->getMultiplier()));
			m_mutex->lock();
			m_processing->setState(Finished);
			PipeData		Finish(*m_processing);
			m_processing = m_awaiting;
			if (m_processing != NULL)
				m_processing->setState(Processing);
			m_awaiting = NULL;
			m_mutex->unlock();
			writing = kitchen->getToWrite();
			write(1, "J'ai fini ma première pizza bordel !!\n", strlen("J'ai fini ma première pizza bordel !!\n"));
			writing->writePipe(Finish);
			if (m_processing != NULL)
			{
				PipeData	Process(*m_processing);

				writing->writePipe(Process);
			}
			kitchen->setOrdersNumber(kitchen->getOrdersNumber() - 1);
		}
		else if (m_awaiting != NULL)
		{
			m_mutex->lock();
			m_processing = m_awaiting;
			m_awaiting = NULL;
			m_mutex->unlock();
		}
	}
}