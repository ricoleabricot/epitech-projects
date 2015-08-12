//
// Inventory.hpp for Zappy in /home/rousse_3/rendu/PSU_2014_zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Wed Jun 17 13:41:30 2015 rousse_3
// Last update Thu Jul  2 16:11:58 2015 rousse_3
//

#ifndef					INVENTORY_HPP_
# define				INVENTORY_HPP_

# include				<string>
# include				<vector>
# include				"Item.hpp"

class					Inventory
{
public:
  Inventory(void);
  ~Inventory(void) throw();

  void					initialize(const std::string &str);
  int					getItem(Item item) const;
  void					addItem(Item item, int nb);
  bool					takeItem(Item item, int nb);
private:
  typedef				std::vector<std::pair<Item, int> >
					storage;
  storage				_items;
};

const std::vector<int>			getLevel(int lvl);

#endif					/* !INVENTORY_HPP_ */
