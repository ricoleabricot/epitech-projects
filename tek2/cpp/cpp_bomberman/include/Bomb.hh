#ifndef BOMB_HH__
# define BOMB_HH__

# include "AItem.hh"

class Bomb : public AItem {
 public:
  Bomb(glm::vec3 const &, glm::vec3 const &, glm::vec3 const &, gdl::Texture const &, int hp = 3);
  Bomb(glm::vec3 const &, glm::vec3 const &, glm::vec3 const &, gdl::Texture const &, int, int);

    virtual ~Bomb();

    virtual bool initialize(void);

    virtual bool isSolid(void) const;
  virtual bool isDamageable(void) const;
};

#endif /* BOMB_HH__ */
