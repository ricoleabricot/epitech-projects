//
// Position.hpp for Zappy in /home/rousse_3/rendu/Zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Tue Jun 16 23:47:40 2015 rousse_3
// Last update Sat Jun 27 00:47:17 2015 rousse_3
//

#ifndef			POSITION_HPP_
# define		POSITION_HPP_

# include		<string>

class			Position
{
public:
  typedef		enum
    {
      UP,
      RIGHT,
      DOWN,
      LEFT
    }			orientation;

  Position(int x, int y, int xMax, int yMax);
  ~Position(void) throw();

  bool			operator<(const Position &lvalue) const;
  int			getX(void) const;
  int			getY(void) const;
  orientation		getOrientation(void) const;
  void			expulse(const std::string &square);
  void			rotate(int rotate);
  void			move(void);
private:
  int			_x;
  int			_y;
  int			_xMax;
  int			_yMax;
  orientation		_orientation;
};

#endif			/* !POSITION_HPP */
