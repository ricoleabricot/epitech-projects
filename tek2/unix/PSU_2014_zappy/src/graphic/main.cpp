//
// main.cpp for zappy in /home/ribeir_b/rendu/PSU_2014_zappy/src/graphic_client
// 
// Made by Nicolas Ribeiro Teixeira
// Login   <ribeir_b@epitech.net>
// 
// Started on  Mon Jun 22 10:43:33 2015 Nicolas Ribeiro Teixeira
// Last update Sun Jul  5 21:59:34 2015 Pierrick Gicquelais
//

#include	<string.h>
#include	<iostream>
#include	"graphic/Welcome.hh"
#include	"graphic/Socket.hh"
#include	"graphic/Game.hh"

bool		check_XOpen(void);

void		check_display(char **env)
{
  bool		display_found = false;

  if (!check_XOpen())
    {
      std::cerr << "Problem with the DISPLAY environment" << std::endl;
      exit(1);
    }
  if (env == NULL || env[0] == NULL)
    {
      std::cerr << "Problem with the DISPLAY environment" << std::endl;
      exit(1);
    }
  for (int i = 0; env[i] != NULL; i++)
    {
      if (strncmp(env[i], "DISPLAY=", 8) == 0)
	display_found = true;
    }
  if (!display_found)
    {
      std::cerr << "Problem with the DISPLAY environment" << std::endl;
      exit(1);
    }
}

int		main(int ac, char **av, char **env)
{
  check_display(env);
  if (ac == 1)
    {
      try {

	Welcome		menu;

	menu.loadFonts();
	menu.loadPictures();
	menu.loadSounds();
	menu.run();
      } catch (const std::exception &exception) {
	std::cerr << exception.what() << std::endl;
      }
    }
  else if (ac == 3)
    {
      Game		game(av[1], std::atoi(av[2]));

      if (!(game.initWorked()))
	{
	  std::cerr << "Cannot connect to server" << std::endl;
	  return (-1);
	}
      game.run();
    }
  else
    {
      std::cout << "USAGE : ./zappy_graphic OR ./zappy_graphic <address> <port>" << std::endl;
      return (-1);
    }
  return (0);
}
