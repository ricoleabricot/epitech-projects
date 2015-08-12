#ifndef AITEM_HH_
# define AITEM_HH_

# include <list>
# include <map>
# include <cmath>

# include <Clock.hh>
# include <Texture.hh>
# include <Geometry.hh>

# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>

# include "ADrawableObject.hh"
# include "Exception.hh"

class AItem : public ADrawableObject
{
public:
  enum trigger
    {
      OnDeath = 0,
      OnPlay,
      OnHalfSecond,
      OnSecond,
      OnSpawn
    };

  enum effect
    {
      Damage = 0,
      StartExplosionH,
      StartExplosionV,
      ExplodeH,
      ExplodeV,
      DestroyAll,
      Nothing
    };

  AItem(glm::vec3 const &, glm::vec3 const &, glm::vec3 const &, gdl::Texture const &, int);
  AItem(glm::vec3 const &, glm::vec3 const &, glm::vec3 const &, gdl::Texture const &, int, int);
  virtual ~AItem();

  std::list<AItem::effect> play(double elapsedTime);
  void addEffect(AItem::effect _effect, AItem::trigger _trigger);

  virtual bool isSolid(void) const = 0;
  virtual bool isDamageable(void) const = 0;
  virtual bool blockItems(void) const;
  int getHp(void) const;

  void damage(void);
  void destroy(void);

  int getId(void) const;

protected:
  double _elapsedSecond;
  double _elapsedHalfSec;
  unsigned int _hp;
  unsigned int _speed;
  bool _justSpawned;
  int _id;
  std::map<AItem::trigger, std::list<AItem::effect> > _effects;

  virtual bool isTriggered(AItem::trigger _trigger);
};

#endif /* AITEM_HH_ */
