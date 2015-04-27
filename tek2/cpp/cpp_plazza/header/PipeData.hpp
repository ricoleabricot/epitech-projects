//
// PipeData.hpp for Plazza in /home/boisso_c/rendu/cpp_plazza/header
// 
// Made by Christian Boisson
// Login   <boisso_c@epitech.net>
// 
// Started on  Tue Apr 21 14:39:28 2015 Christian Boisson
// Last update Thu Apr 23 12:02:50 2015 Christian Boisson
//

#ifndef		PIPEDATA_HPP_
# define	PIPEDATA_HPP_

# include	<unistd.h>
# include	<map>

# include	"StockType.hpp"
# include	"Pizza.hpp"

class		PipeData
{
public:
  PipeData();
  PipeData(const std::map<StockType, int> &stock);
  PipeData(const Pizza &pizza);
  PipeData(const std::map<StockType, int>  &stock, const Pizza &pizza);
  ~PipeData();
  void		setStock(const std::map<StockType, int> &stock);
  void		setPizza(const Pizza &pizza);
  std::map<StockType, int>	*getStock(void);
  Pizza		*getPizza(void);
private:
  bool		m_setPizza;
  bool		m_setStock;
  Pizza		m_pizza;
  std::map<StockType, int>		m_stock;
};

#endif		/* !PIPEDATA_HPP_ */
