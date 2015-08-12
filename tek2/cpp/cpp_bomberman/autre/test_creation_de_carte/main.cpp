//
// main.cpp for  in /home/bbr2394/rendu2015/cpp_bomberman/test_creation_de_carte
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed May  6 01:27:06 2015 Bertrand-Rapello Baptiste
// Last update Wed May  6 01:34:08 2015 Bertrand-Rapello Baptiste
//

#include <iostream>
#include "AObject.hpp"
#include "Engine.hh"

int	main()
{
  Engine engine;

  if (engine.initialize() == false)
    {
      std::cout << "failure on init" << std::endl;
      return (EXIT_FAILURE);
    }

  while (engine.update() == true)
    engine.draw();

  return EXIT_SUCCESS;
  
}
