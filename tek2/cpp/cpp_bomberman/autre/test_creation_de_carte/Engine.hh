//
// Engine.hh for  in /home/bbr2394/rendu2015/cpp_bomberman/test_creation_de_carte
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed May  6 01:19:21 2015 Bertrand-Rapello Baptiste
// Last update Wed May  6 01:32:46 2015 Bertrand-Rapello Baptiste
//

#ifndef ENGINE_HH_
# define ENGINE_HH_

#include <iostream>
#include <Game.hh>
#include <SdlContext.hh>
#include <list>
#include "AObject.hpp"
#include "Cube.hh"

class Engine : public gdl::Game
{
public:
  Engine();
  ~Engine();  

private:
  gdl::SdlContext	_context;
  gdl::Clock		_clock;
  gdl::Input		_input;
  gdl::BasicShader	_shader;
  std::vector<AObject*>	_objects;
  int _x;
  int _y;
  
public:
  bool initialize();
  bool update();
  void draw();
  void createMap();
};

#endif
