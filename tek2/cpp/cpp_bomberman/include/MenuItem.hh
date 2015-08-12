//
// MenuItem.hh for  in /home/bbr2394/Arm/cpp_bomberman/include
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Tue Jun  9 16:11:27 2015 Bertrand-Rapello Baptiste
// Last update Fri Jun 12 15:55:32 2015 zwertv_e
//

#ifndef MENUITEM_HH_
# define MENUITEM_HH_

# include "AItem.hh"

class MenuItem : public ADrawableObject
{
 public:
    MenuItem(glm::vec3 const &, glm::vec3 const &, glm::vec3 const &);
    virtual ~MenuItem();

 public:
    virtual bool initialize(void);

private:
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
  float		_speed;
};

#endif /* WALL_HH_ */
