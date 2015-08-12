/*
// AObject.cpp for AO in /home/casier_s/cpp_bomberman/Game
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Wed May  7 10:22:40 2014 sofian casier
// Last update Wed May  6 01:42:16 2015 Bertrand-Rapello Baptiste
*/

#include "AObject.hpp"

AObject::AObject() : _position(5, 5, 0), _rotation(0, 0, 0), _scale(1, 1, 1)
{
  _texture_name = "./player.tga";
}

AObject::AObject(glm::vec3 pos, Type type, std::string texture): _rotation(0, 0, -90), _scale(1, 1, 1)
{
  _type = type;
  _position = pos;
  _texture_name = texture;
}

AObject::AObject(glm::vec3 pos, glm::vec3 r, std::string texture) : _scale(1, 1, 1)
{
  _position = pos;
  _rotation = r;
  _texture_name = texture;
}

AObject::AObject(glm::vec3 pos, Type type, std::string texture, double s): _rotation(0, 0, -90), _scale(s, s, s)
{
  _type = type;
  _position = pos;
  _texture_name = texture;
}

AObject::AObject(glm::vec3 pos, glm::vec3 r, std::string texture, double s) : _scale(s, s, s)
{
  _position = pos;
  _rotation = r;
  _texture_name = texture;
}

AObject::~AObject()
{
}

void      AObject::setXcurs(double x)
{
  _xcurs = x;
}

void      AObject::setYcurs(double y)
{
  _ycurs = y;
}

void      AObject::setZcurs(double z)
{
  _zcurs = z;
}

bool	AObject::initialize()
{

}

void	AObject::update(gdl::Clock const &clock, gdl::Input &input)
{
  if (input.getKey(SDLK_UP))
    translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_DOWN))
    translate(glm::vec3(0, -1, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_LEFT))
    translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_RIGHT))
    translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
}

void AObject::translate(glm::vec3 const &v)
{
  _position += v;
}

void AObject::rotate(glm::vec3 const& axis, float angle)
{
  _rotation += axis * angle;
}

void AObject::scale(glm::vec3 const& scale)
{
  _scale *= scale;
}

glm::mat4 &AObject::getTransformation() const
{
  glm::mat4 *transform = new glm::mat4(1);

  *transform = glm::rotate(*transform, _rotation.x, glm::vec3(1, 0, 0));
  *transform = glm::rotate(*transform, _rotation.y, glm::vec3(0, 1, 0));
  *transform = glm::rotate(*transform, _rotation.z, glm::vec3(0, 0, 1));
  *transform = glm::translate(*transform, _position);
  *transform = glm::scale(*transform, _scale);
  return (*transform);
}

glm::mat4 &AObject::getTransformationPlayer() const
{
  glm::mat4 *transform = new glm::mat4(1);

  *transform = glm::translate(*transform, _position);
  *transform = glm::rotate(*transform, _rotation.x, glm::vec3(1, 0, 0));
  *transform = glm::rotate(*transform, _rotation.y, glm::vec3(0, 1, 0));
  *transform = glm::rotate(*transform, _rotation.z, glm::vec3(0, 0, 1));
  *transform = glm::scale(*transform, _scale);
  return (*transform);
}

AObject::Type      AObject::getType() const
{
  return (_type);
}

double		AObject::getX() const
{
  return _position.x;
}

double		AObject::getY() const
{
  return _position.y;
}

double		AObject::getZ() const
{
  return _position.z;
}
