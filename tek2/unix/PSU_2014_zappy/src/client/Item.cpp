//
// Item.cpp for Zappy in /home/rousse_3/rendu/PSU_2014_zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Thu Jul  2 16:27:58 2015 rousse_3
// Last update Thu Jul  2 17:55:59 2015 rousse_3
//

#include			"client/Item.hpp"

Item				stringToItem(const std::string &str)
{
  if (str == "linemate")
    return (linemate);
  if (str == "deraumere")
    return (deraumere);
  if (str == "sibur")
    return(sibur);
  if (str == "mendiane")
    return (mendiane);
  if (str == "phiras")
    return (phiras);
  if (str == "thystame")
    return (thystame);
  return (food);
}
