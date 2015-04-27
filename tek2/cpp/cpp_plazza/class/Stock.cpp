/* 
* @Author: ribeir_b
* @Date:   2015-04-20 19:04:57
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-04-21 16:00:45
*/

#include "Stock.hpp"

Stock::Stock(void) {}
Stock::~Stock(void) {}

void 	Stock::setDoe(int param)
{
	this->doe = param;
}

void 	Stock::setTomato(int param)
{
	this->tomato = param;
}

void 	Stock::setGruyere(int param)
{
	this->gruyere = param;
}

void 	Stock::setHam(int param)
{
	this->ham = param;
}

void 	Stock::setMushrooms(int param)
{
	this->mushrooms = param;
}

void 	Stock::setSteak(int param)
{
	this->steak = param;
}

void 	Stock::setEggplant(int param)
{
	this->eggplant = param;
}

void 	Stock::setGoatCheese(int param)
{
	this->goatCheese = param;
}

void 	Stock::setChiefLove(int param)
{
	this->chiefLove = param;
}

int	 	Stock::getDoe() const
{
	return (this->doe);
}

int 	Stock::getTomato() const
{
	return (this->tomato);
}

int 	Stock::getGruyere() const
{
	return (this->gruyere);
}

int 	Stock::getHam() const
{
	return (this->ham);
}

int 	Stock::getMushrooms() const
{
	return (this->mushrooms);
}

int 	Stock::getSteak() const
{
	return (this->steak);
}

int 	Stock::getEggplant() const
{
	return (this->eggplant);
}

int 	Stock::getGoatCheese() const
{
	return (this->goatCheese);
}

int 	Stock::getChiefLove() const
{
	return (this->chiefLove);
}
