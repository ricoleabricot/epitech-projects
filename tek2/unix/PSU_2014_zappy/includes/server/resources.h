/*
** resources.h for zappy in /home/boisso_c/rendu/PSU_2014_zappy/includes/server
** 
** Made by Christian Boisson
** Login   <boisso_c@epitech.net>
** 
** Started on  Tue Jun 23 16:31:21 2015 Christian Boisson
** Last update Mon Jun 29 11:54:53 2015 Christian Boisson
*/

#ifndef			RESOURCES_H_
# define		RESOURCES_H_

# define		RESOURCES	7

enum			e_resources
  {
    FOOD = 0,
    LINEMATE = 1,
    DERAUMERE = 2,
    SIBUR = 3,
    MENDIANE = 4,
    PHIRAS = 5,
    THYSTAME = 6
  };

# define		DROPTABLE	{5, 4, 3, 3, 2, 2, 1}

# define		RESTABLE	{" nourriture", \
					" linemate", \
					" deraumere", \
					" sibur", \
					" mendiane", \
					" phiras", \
					" thystame"}

#endif			/* !RESOURCES_H_ */
