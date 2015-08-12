//
// Player.hpp for Zappy in /home/rousse_3/rendu/Zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Tue Jun 16 22:55:58 2015 rousse_3
// Last update Thu Jul  2 16:24:40 2015 rousse_3
//

#ifndef				PLAYER_HPP_
# define			PLAYER_HPP_

# include			"Ia.hpp"
# include			"Map.hpp"
# include			"Team.hpp"
# include			"Option.hpp"
# include			"Socket.hpp"
# include			"Position.hpp"
# include			"Inventory.hpp"

class				Player
{
public:
  Player(const Option &opt);
  ~Player(void) throw();

  void				doRandDecision(void);
  void				doSoloDecision(void);

  bool				avance(void);
  bool				droite(void);
  bool				gauche(void);
  bool				expulse(void);
  bool				doFork(void);
  bool				incantation(void);
  bool				broadcast(const std::string &str);
  bool				prend(Item itm);
  bool				pose(Item itm);
  bool				voir(std::string &str);
  bool				inventaire(void);
  bool				connect_nbr(int &nb);

  bool				getMsg(std::string &msg);
  void				addMsg(const std::string &msg);
  bool				isDead(void) const;

  void				end(void) const;
private:
  void				seekFood(void);
  void				callHelp(void);
  void				joinHim(void);
  bool				parse(const std::string &str);
  bool				canLvlUp(void);
  bool				needPeople(void);
  void				seekStone(void);

  // Ia				*_reflexion;
  // Map				*_gameMap;
  // Team				*_playerTeam;
  Option			_opt;
  Socket			*_server;
  Position			*_localisation;
  Inventory			*_inventory;
  int				_level;
  std::string			_name;
  bool				_isDead;
  std::vector<std::string>	_msgs;
  std::vector<int>		_pids;
};

#endif				/* !PLAYER_HPP_ */
