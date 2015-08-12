//
// Player.hh for zappy in /home/ribeir_b/rendu/PSU_2014_zappy
// 
// Made by Nicolas Ribeiro Teixeira
// Login   <ribeir_b@epitech.net>
// 
// Started on  Wed Jul  1 13:00:58 2015 Nicolas Ribeiro Teixeira
// Last update Sun Jul  5 20:54:37 2015 Nicolas Ribeiro Teixeira
//

#ifndef		PLAYER_HH_
# define	PLAYER_HH_

# include	<sys/time.h>

class		Player
{
private:
  int		m_id;
  int		m_x;
  int		m_y;
  int		m_lvl;
  int		m_orientation;
  std::string	m_teamname;
  int		m_inventory[7];
  int		m_state;
  int		m_timer;
public:
  Player(int, int, int, int, int, std::string, int);
  ~Player();
  void		resetId(void);
  void		setX(int x);
  void		setY(int y);
  void		setLvl(int lvl);
  void		setOrientation(int orientation);
  void		setInventory(int tab[7]);
  void		setState(int state);
  void		setTimer(int time);
  void		decrementTimer(int decr);
  int		getX(void) const;
  int		getY(void) const;
  int		getLvl(void) const;
  int		getOrientation(void) const;
  int		getInventory(int index) const;
  int		getId(void) const;
  std::string const &getTeam(void) const;
  int		getState(void) const;
  int		getTimer(void) const;
};

#endif		/* !PLAYER_HH_ */
