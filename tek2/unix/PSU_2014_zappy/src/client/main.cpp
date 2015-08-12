//
// main.cpp for Zappy in /home/rousse_3/rendu/Zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Mon Jun 15 22:19:31 2015 rousse_3
// Last update Thu Jul  2 16:35:32 2015 rousse_3
//

#include	<iostream>
#include	"client/Error.hpp"
#include	"client/Option.hpp"
#include	"client/Player.hpp"

int		main(int argc, const char **argv)
{
  Option	opt(argc, argv);
  
  if (opt.isValid() != true)
    return (-1);

  try
    {
      Player	ia(opt);

      std::cout << "Debut de l'execution" << std::endl;
      while (ia.isDead() != true)
	ia.doSoloDecision();
    }
  catch (const ClientError& err)
    {
      std::cerr << err.what() << std::endl;
      return (1);
    }
  std::cout << "Dead" << std::endl;
  return (0);
}
