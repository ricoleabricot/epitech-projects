//
// getLevel.cpp for zappy in /home/rousse_3/rendu/PSU_2014_zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Sat Jun 27 1case 9:1case 8:16 2015 rousse_3
// Last update Thu Jul  2 17:51:26 2015 rousse_3
//

#include	<vector>
#include	"client/Item.hpp"

static void		getPlayer(int lvl, std::vector<int> &tab)
{
  switch (lvl)
    {
    case 1:
      tab[0] = 1;
      break;;
    case 2:
    case 3:
      tab[0] = 2;
      break;;
    case 4:
    case 5:
      tab[0] = 4;
      break;;
    default:
      tab[0] = 6;
    }
}

static void		getLinemate(int lvl, std::vector<int> &tab)
{
  switch (lvl)
    {
    case 3:
    case 7:
      tab[1] = 2;
      break;;
    default:
      tab[1] = 1;
    }
}

static void		getDeraumere(int lvl, std::vector<int> &tab)
{
  switch (lvl)
    {
    case 2:
    case 4:
      tab[2] = 1;
      break;;
    case 1:
    case 3:
      tab[2] = 0;
      break;;
    default:
      tab[2] = 3;
    }
}

static void		getSibur(int lvl, std::vector<int> &tab)
{
  switch (lvl)
    {
    case 1:
      tab[3] = 0;
      break;;
    case 4:
    case 7:
      tab[3] = 2;
      break;;
    case 6:
      tab[3] = 3;
      break;;
    default:
      tab[3] = 1;
    }
}

static void		getMendiane(int lvl, std::vector<int> &tab)
{
  switch (lvl)
    {
    case 5:
      tab[4] = 3;
      break;;
    case 7:
      tab[4] = 2;
      break;;
    default:
      tab[4] = 0;
    }
}

static void		getPhiras(int lvl, std::vector<int> &tab)
{
  switch (lvl)
    {
    case 3:
    case 7:
      tab[5] = 2;
      break;;
    case 4:
    case 6:
      tab[5] = 1;
      break;;
    default:
      tab[5] = 0;
    }
}

static void		getThystame(int lvl, std::vector<int> &tab)
{
  switch (lvl)
    {
    case 7:
      tab[6] = 1;
      break;;
    default:
      tab[6] = 0;
    }
}

const std::vector<int>	getLevel(int lvl)
{
  std::vector<int>	tab;

  tab.resize(8);
  getPlayer(lvl, tab);
  getLinemate(lvl, tab);
  getDeraumere(lvl, tab);
  getSibur(lvl, tab);
  getMendiane(lvl, tab);
  getPhiras(lvl, tab);
  getThystame(lvl, tab);
  tab[7] = 3;
  return (tab);
}
