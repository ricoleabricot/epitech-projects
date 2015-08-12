//
// Wall.hh for  in /home/zwertv_e/rendu/cpp_bomberman
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Sun Jun 14 16:58:02 2015 zwertv_e
// Last update Sun Jun 14 17:36:47 2015 zwertv_e
//

#ifndef	        WALL_HH_
# define        WALL_HH_

# include "AItem.hh"

class Wall : public AItem
{
public:
  Wall(glm::vec3 const &, glm::vec3 const &, glm::vec3 const &, gdl::Texture const &, int hp = 1);
  virtual ~Wall();

public:
  virtual bool initialize(void);
  virtual bool isSolid(void) const;
  virtual bool isDamageable(void) const;
  virtual bool blockItems(void) const;
};

#endif		/* WALL_HH_ */
