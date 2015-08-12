//
// Team.hpp for Zappy in /home/rousse_3/rendu/Zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Tue Jun 16 23:37:59 2015 rousse_3
// Last update Wed Jun 17 19:10:50 2015 rousse_3
//

#ifndef							TEAM_HPP_
# define						TEAM_HPP_

# include						<string>
# include						<vector>

class							Team
{
public:
  Team(const std::string &teamName);
  ~Team(void) throw();

  int							getNbPlayer(void) const;
  int							getNbPlayerMax(void) const;
  const std::string					&getTeamName(void) const;
  const std::vector<std::pair<std::string, int> >	&getTeam(void) const;
  void							setMaxPlayer(int nbPlayerMax);
  void							addPlayer(const std::string &name, int level);
  void							levelUp(const std::string &name);
private:
  int							_nbPlayer;
  int							_nbPlayerMax;
  std::string						_teamName;
  std::vector<std::pair<std::string, int> >		_players;
};

#endif							/* !TEAM_HPP_ */
