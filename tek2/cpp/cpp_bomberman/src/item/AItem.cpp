#include "AItem.hh"

AItem::AItem(glm::vec3 const &position, glm::vec3 const &rotation, glm::vec3 const &scale, gdl::Texture const &texture, int hp) :
  ADrawableObject(position, rotation, scale, texture),
  _elapsedSecond(0),
  _elapsedHalfSec(0),
  _hp(hp),
  _speed(0),
  _justSpawned(true),
  _effects()
{
  addEffect(AItem::Nothing, AItem::OnDeath);
}

AItem::AItem(glm::vec3 const &position, glm::vec3 const &rotation, glm::vec3 const &scale, gdl::Texture const &texture, int hp, int id) :
  ADrawableObject(position, rotation, scale, texture),
  _elapsedSecond(0),
  _elapsedHalfSec(0),
  _hp(hp),
  _speed(0),
  _justSpawned(true),
  _id(id),
  _effects()
{
  addEffect(AItem::Nothing, AItem::OnDeath);
}

AItem::~AItem()
{}

void AItem::addEffect(AItem::effect effect, AItem::trigger trigger)
{
    _effects[trigger].push_back(effect);
}

bool AItem::isTriggered(AItem::trigger trigger)
{
  switch (trigger)
    {
    case AItem::OnPlay:
      return true;
    case AItem::OnSpawn:
      if (_justSpawned)
	return true;
      break;
    case AItem::OnDeath:
      if (_hp == 0)
	{
	  --this->_hp;
	  return true;
	}
      break;
    case AItem::OnSecond:
      if (_elapsedSecond >= 1.0)
	{
	  --_elapsedSecond;
	  return true;
	}
      break;
    case AItem::OnHalfSecond:
      if (_elapsedHalfSec >= 0.5)
	{
	  _elapsedHalfSec -= 0.5;
	  return true;
	}
      break;
    }
  return false;
}

std::list<AItem::effect> AItem::play(double elapsedTime)
{
    std::list<AItem::effect> res;
    std::list<AItem::effect>::iterator ite;
    std::map<AItem::trigger, std::list<AItem::effect> >::iterator it;

    _elapsedSecond += elapsedTime;
    _elapsedHalfSec += elapsedTime;
    for (it = _effects.begin(); it != _effects.end(); ++it)
    {
        if (this->isTriggered(it->first))
	  {
            for (ite = it->second.begin(); ite != it->second.end(); ite++)
	      res.push_back(*ite);
	  }
    }
    _justSpawned = false;

    return res;
}

void AItem::damage(void) { --this->_hp; }
void AItem::destroy(void)
{
  if (this->_hp > 0)
    this->_hp = 0;
}
int AItem::getHp(void) const { return (_hp); }
bool AItem::blockItems(void) const { return (false); }

int AItem::getId(void) const {
    return this->_id;
}
