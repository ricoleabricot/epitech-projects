//
// ADrawableObject.cpp for  in /home/zwertv_e/rendu/cpp_bomberman
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Thu Jun 11 16:08:38 2015 zwertv_e
// Last update Thu Jun 11 18:43:21 2015 zwertv_e
//

#include "ADrawableObject.hh"

ADrawableObject::ADrawableObject(glm::vec3 const &position, glm::vec3 const &rotation, glm::vec3 const &scale) :
  _position(position),
  _rotation(rotation),
  _scale(scale),
  _texture(),
  _geometry()
{}

ADrawableObject::ADrawableObject(glm::vec3 const &position, glm::vec3 const &rotation, glm::vec3 const &scale, gdl::Texture const &texture) :
  _position(position),
  _rotation(rotation),
  _scale(scale),
  _texture(texture),
  _geometry()
{}

ADrawableObject::~ADrawableObject()
{}

glm::vec3 ADrawableObject::getPosition(void) const
{
  return (_position);
}

void ADrawableObject::translate(glm::vec3 const &translation) {
    _position += translation;
}

void ADrawableObject::rotate(glm::vec3 const &axis, float angle) {
    _rotation = (axis * angle) + _rotation;
}

void ADrawableObject::scale(glm::vec3 const &scale) {
    _scale *= scale;
}

glm::mat4 ADrawableObject::transformation(glm::vec3 const  &translation, glm::vec3 const &rotation, glm::vec3 const &scale) const {
    glm::mat4 transform(1);
    glm::vec3 pos(_position);
    glm::vec3 rot(_rotation);
    glm::vec3 scal(_scale);

    pos += translation;
    rot += rotation;
    scal *= scale;
    transform = glm::rotate(transform, rot.x, glm::vec3(1, 0, 0));
    transform = glm::rotate(transform, rot.y, glm::vec3(0, 1, 0));
    transform = glm::rotate(transform, rot.z, glm::vec3(0, 0, 1));
    transform = glm::translate(transform, pos);
    transform = glm::scale(transform, scal);

    return transform;
}

void ADrawableObject::draw(gdl::AShader &shader, glm::vec3 const &translation, glm::vec3 const &rotation, glm::vec3 const &scaleValue)
{
    _texture.bind();
    _geometry.draw(shader, transformation(translation, rotation, scaleValue), GL_QUADS);
}
