//
// main.cpp for ma in /home/casier_s/libbomber
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Mon May  5 15:55:25 2014 sofian casier
// Last update Tue May  6 17:32:53 2014 Bertrand-Rapello Baptiste
//

#include <cstdlib>
#include "GameEngine.hpp"

int main()

{
  GameEngine engine;
  GameEngine enginebis;


  if (engine.initialize() == false)
    {
      std::cout << "failure on init" << std::endl;
      return (EXIT_FAILURE);
    }

  while (engine.update() == true)
    engine.draw();

  return EXIT_SUCCESS;
}
