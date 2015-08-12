//
// Map.hpp for Zappy in /home/rousse_3/rendu/Zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Tue Jun 16 23:42:16 2015 rousse_3
// Last update Thu Jun 18 22:42:45 2015 rousse_3
//

#ifndef				MAP_HPP_
# define			MAP_HPP_

# include			<map>
# include			"Square.hpp"
# include			"Position.hpp"

class				Map
{
  Map(int sizeX, int sizeY);
  ~Map(void) throw();

  int				getSizeX(void) const;
  int				getSizeY(void) const;
  Square			&getSquare(const Position &pos);
  bool				addSquare(const Position &pos);
  void				update(void);
private:
  int				_sizeX;
  int				_sizeY;
  std::map<Position, Square>	_map;
};

#endif				/* !MAP_HPP_ */
