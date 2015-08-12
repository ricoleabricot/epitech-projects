//
// Cursor.cpp for  in /home/bbr2394/Arm/cpp_bomberman/src
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Tue Jun  9 16:13:31 2015 Bertrand-Rapello Baptiste
// Last update Fri Jun 12 15:54:24 2015 zwertv_e
//

#include "Cursor.hh"

Cursor::Cursor(glm::vec3 const & pos, glm::vec3 const & rot, glm::vec3 const & scale) : ADrawableObject(pos, rot, scale)
{
}

Cursor::~Cursor()
{

}

bool Cursor::initialize()
{
 _speed = 10.0f;
  // On charge la texture qui sera affichee sur chaque face du cube
  if (_texture.load("./texture/cursor_head_2.tga") == false)
    {
      std::cerr << "Cannot load the cube texture" << std::endl;
      return (false);
    }

  // tout les pushVertex qui suivent seront de cette couleur
  // On y push les vertices d une premiere face
  _geometry.pushVertex(glm::vec3(-2, 0, 2));
  _geometry.pushVertex(glm::vec3(2, 0, 2));
  _geometry.pushVertex(glm::vec3(2, 0, -2));
  _geometry.pushVertex(glm::vec3(-2, 0, -2));
  // Les UVs d'une premiere face
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.build();
  std::cout << "Cursor initialized" << std::endl;
  return (true);
}
