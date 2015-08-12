//
// Square.hpp for Zappy in /home/rousse_3/rendu/Zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Tue Jun 16 23:52:12 2015 rousse_3
// Last update Thu Jun 18 17:42:36 2015 rousse_3
//

#ifndef				SQUARE_HPP_
# define			SQUARE_HPP_

class				Player;

# include			<vector>
# include			"Item.hpp"
# include			"Position.hpp"

class				Square
{
public:
  Square(const Position &pos);
  ~Square(void) throw();

  const std::vector<Item>	&getItems(void) const;
  const std::vector<Player*>	&getPlayers(void) const;
  int				getLastUpdate(void) const;
  void				addItems(Item item);
  void				addPlayer(Player *player);
  void				delItem(Item item);
  void				delPlayer(Player *player);
  void				update(void);
private:
  Position		_pos;
  std::vector<Item>	_content;
  std::vector<Player*>	_habitant;
  int			_lastUpdate;
};

#endif				/* !SQUARE_HPP_ */
