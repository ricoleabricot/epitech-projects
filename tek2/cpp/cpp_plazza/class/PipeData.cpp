//
// PipeData.cpp for Plazza in /home/boisso_c/rendu/cpp_plazza/class
// 
// Made by Christian Boisson
// Login   <boisso_c@epitech.net>
// 
// Started on  Tue Apr 21 14:40:12 2015 Christian Boisson
// Last update Thu Apr 23 12:05:27 2015 Christian Boisson
//

#include	"PipeData.hpp"

PipeData::PipeData() : m_setPizza(false), m_setStock(false), m_pizza(NONETYPE, NONESIZE)
{

}

PipeData::PipeData(const std::map<StockType, int> &stock) : m_setPizza(false), m_setStock(true), m_pizza(NONETYPE, NONESIZE)
{
  m_stock = stock;
}

PipeData::PipeData(const Pizza &pizza) : m_setPizza(true), m_setStock(false), m_pizza(pizza)
{

}

PipeData::PipeData(const std::map<StockType, int> &stock, const Pizza &pizza) : m_setPizza(true), m_setStock(true), m_pizza(pizza)
{
  m_stock = stock;
}

PipeData::~PipeData(void)
{

}

void		PipeData::setStock(const std::map<StockType, int> &stock)
{
  m_stock = stock;
  m_setStock = true;
}

void		PipeData::setPizza(const Pizza &pizza)
{
  m_pizza = pizza;
  m_setPizza = true;
}

std::map<StockType, int>	*PipeData::getStock(void)
{
  if (m_setStock)
    return (&m_stock);
  else
    return (NULL);
}

Pizza		*PipeData::getPizza(void)
{
  if (m_setPizza)
    return (&m_pizza);
  else
    return (NULL);
}
