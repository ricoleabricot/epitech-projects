//
// Team.cpp for Zappy in /home/rousse_3/rendu/PSU_2014_zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Wed Jun 17 19:04:36 2015 rousse_3
// Last update Wed Jun 17 19:13:45 2015 rousse_3
//

#include		"client/Team.hpp"

Team::Team(const std::string &teamName) :
  _nbPlayer(1),
  _nbPlayerMax(0),
  _teamName(teamName),
  _players()
{}

Team::~Team(void) throw() {}

int			Team::getNbPlayer(void) const
{
  return (_nbPlayer);
}

int			Team::getNbPlayerMax(void) const
{
  return (_nbPlayerMax);
}

const std::string	&Team::getTeamName(void) const
{
  return (_teamName);
}

const std::vector<std::pair<std::string, int> >	&Team::getTeam(void) const
{
  return (_players);
}

void			Team::setMaxPlayer(int nbPlayerMax)
{
  _nbPlayerMax = nbPlayerMax;
}

void			Team::addPlayer(const std::string &name, int level)
{
  _players.push_back(std::pair<std::string, int>(name, level));
}

void			Team::levelUp(const std::string &name)
{
  std::vector<std::pair<std::string, int> >::iterator	it = _players.begin();
  std::vector<std::pair<std::string, int> >::iterator	end = _players.end();

  while (it != end)
    {
      if ((*it).first == name)
	(*it).second += 1;
      ++it;
    }
}
