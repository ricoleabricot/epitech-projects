//
// Explosion.hh for  in /home/zwertv_e/rendu/cpp_bomberman
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Thu Jun 11 19:20:59 2015 zwertv_e
// Last update Sun Jun 14 15:53:04 2015 zwertv_e
//

#ifndef		EXPLOSION_HH__
# define	EXPLOSION_HH__

# include "AItem.hh"

class Explosion : public AItem
{
public:
  Explosion(glm::vec3 const &, glm::vec3 const &, glm::vec3 const &, gdl::Texture const &, int hp = 3);
  virtual ~Explosion();

public:
  virtual bool initialize(void);
  virtual bool isSolid(void) const;
  virtual bool isDamageable(void) const;
};

#endif		/* EXPLOSION_HH__ */
