/*
// Cube.hh for bomberman in /home/koszyc_l/Documents/blih/cpp_bomberman/Game
// 
// Made by Koszyczek Laurent
// Login   <koszyc_l@epitech.net>
// 
// Started on  Mon May 19 17:19:07 2014 Koszyczek Laurent
// Last update Wed May 28 14:42:04 2014 Koszyczek Laurent
*/

#ifndef _CUBE_HH_
# define _CUBE_HH_

# include <Game.hh>
# include <Clock.hh>
# include <Input.hh>
# include <SdlContext.hh>
# include <Geometry.hh>
# include <Texture.hh>
# include <BasicShader.hh>
# include <Model.hh>
# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include <iostream>
#include "AObject.hpp"

class Cube : public AObject
{

private:
  gdl::Texture _texture;
  gdl::Geometry _geometry;

public:
  Cube();
  Cube(int x, int y);
  Cube(glm::vec3 pos, Type type, std::string texture);
  Cube(glm::vec3 pos, glm::vec3 r, std::string texture);
  virtual ~Cube();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif
