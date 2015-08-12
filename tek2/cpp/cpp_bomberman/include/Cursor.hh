//
// Cursor.hh for  in /home/bbr2394/Arm/cpp_bomberman/include
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Tue Jun  9 16:11:27 2015 Bertrand-Rapello Baptiste
// Last update Fri Jun 12 16:06:00 2015 zwertv_e
//

#ifndef CURSOR_HH_
# define CURSOR_HH_

# include <SdlContext.hh>
# include <iostream>

# include "ADrawableObject.hh"

class Cursor : public ADrawableObject
{
 public:
    Cursor(glm::vec3 const &, glm::vec3 const &, glm::vec3 const &);
    virtual ~Cursor();

 public:
    virtual bool initialize(void);


private:
  float		_speed;
};

#endif /* WALL_HH_ */
