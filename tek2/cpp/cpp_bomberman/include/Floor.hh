#ifndef FLOOR_HH_
# define FLOOR_HH_

# include "AItem.hh"

class Floor : public AItem
{
public:
  Floor(glm::vec3 const &, glm::vec3 const &, glm::vec3 const &, gdl::Texture const &, int hp = 1);
  virtual ~Floor();

public:
  virtual bool initialize(void);
  virtual bool isSolid(void) const;
  virtual bool isDamageable(void) const;
};

#endif /* FLOOR_HH_ */
