//
// Item.hpp for Zappy in /home/rousse_3/rendu/PSU_2014_zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Wed Jun 17 13:44:19 2015 rousse_3
// Last update Thu Jul  2 17:09:25 2015 rousse_3
//

#ifndef				ITEM_HPP_
# define			ITEM_HPP_

# include			<string>

typedef				enum
  {
    linemate,
    deraumere,
    sibur,
    mendiane,
    phiras,
    thystame,
    food
  }				Item;

Item				stringToItem(const std::string &str);

#endif				/* !ITEM_HPP_ */
