//
// Box.hh for  in /home/zwertv_e/rendu/cpp_bomberman
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Sun Jun 14 16:31:21 2015 zwertv_e
// Last update Sun Jun 14 16:32:52 2015 zwertv_e
//

#ifndef		BOX_HH_
# define	BOX_HH_

# include "AItem.hh"

class Box : public AItem
{
public:
  Box(glm::vec3 const &, glm::vec3 const &, glm::vec3 const &, gdl::Texture const &, int hp = 1);
  virtual ~Box();

public:
  virtual bool initialize(void);
  virtual bool isSolid(void) const;
  virtual bool isDamageable(void) const;
};

#endif		/* BOX_HH_ */
