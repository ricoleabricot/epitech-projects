/* 
* @Author: gicque_p
* @Date:   2015-05-20 16:06:36
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-06-14 23:49:07
*/

#include "Map.hh"

Map::Map() :
    _items()
{}

Map::~Map() {
    for (std::list<AItem *>::iterator it = _items.begin(); it != _items.end(); it++) {
        delete *it;
    }
}

void Map::addItem(AItem *item) {
    if (item->initialize()) {
        _items.push_back(item);
    } else {
        throw MapException("Cannot initialize item");
    }
}

void Map::deleteItem(AItem *item) {
    for (std::list<AItem *>::iterator it = _items.begin(); it != _items.end(); it++) {
        if (*it == item) {
            _items.erase(it);
            break;
        }
    }
}

void Map::addPlayer(APlayer *player) {
    if (player->initialize()) {
        _players.push_back(player);
    } else {
        throw MapException("Cannot initialize player");
    }
}

void Map::deletePlayer(APlayer *player) {
    for (std::list<APlayer *>::iterator it = _players.begin(); it != _players.end(); it++) {
        if (*it == player) {
            _players.erase(it);
            break;
        }
    }
}

void Map::load(std::string const & file)
{
  std::ifstream myfile;
  std::string   line;

  myfile.open(file.c_str(), std::ifstream::in);
  if (myfile.is_open())
    {
      while (std::getline(myfile, line))
	{
	  std::cout << line << std::endl;
	}
      myfile.close();
    }
  //else
  // Exception
}

bool Map::canPlaceItem(glm::vec3 const & pos)
{
  std::list<AItem *>::iterator it;
  glm::vec3 tmp;

 for (it = _items.begin(); it != _items.end(); it++)
   {
     tmp = (*it)->getPosition();
     if ((*it)->blockItems())
       {
	 if (isColliding(pos, tmp))
	   return (false);
       }
   }
 return (true);
}

bool Map::canMoveAt(glm::vec3 const & pos)
{
  std::list<AItem *>::iterator it;
  glm::vec3 tmp;

 for (it = _items.begin(); it != _items.end(); it++)
   {
     tmp = (*it)->getPosition();
     if ((*it)->isSolid())
       {
	 if (isColliding(pos, tmp))
	   return (false);
       }
   }
 return (true);
}

bool Map::isColliding(glm::vec3 const & vec1, glm::vec3 const & vec2)
{
  if (vec1.x + 0.5 > vec2.x - 0.5 && vec1.x - 0.5 < vec2.x + 0.5 && vec1.y + 0.5 > vec2.y - 0.5 && vec1.y - 0.5 < vec2.y + 0.5 && vec1.z + 0.5 > vec2.z - 0.5 && vec1.z - 0.5 < vec2.z + 0.5)
    return (true);
  return (false);
}

void Map::playEffect(AItem::effect effect, AItem * it, TextureLoader &textureloader)
{
  AItem *exp;

  switch (effect)
    {
    case AItem::Damage:
      it->damage();
      break;

    case AItem::StartExplosionH:
      if (canPlaceItem(glm::vec3(it->getPosition().x, it->getPosition().y, it->getPosition().z - 1)))
	{
	  exp = new Explosion(glm::vec3(it->getPosition().x, it->getPosition().y, it->getPosition().z - 1), glm::vec3(0, 0, 0), glm::vec3(0.5, 0.5, 0.5), textureloader.getTexture(ExplosionType));
	  exp->addEffect(AItem::ExplodeH, AItem::OnSpawn);
	  addItem(exp);
	}
      if (canPlaceItem(glm::vec3(it->getPosition().x, it->getPosition().y, it->getPosition().z + 1)))
	{
	  exp = new Explosion(glm::vec3(it->getPosition().x, it->getPosition().y, it->getPosition().z + 1), glm::vec3(0, 0, 0), glm::vec3(0.5, 0.5, 0.5), textureloader.getTexture(ExplosionType));
	  exp->addEffect(AItem::ExplodeH, AItem::OnSpawn);
	  addItem(exp);
	}
      break;

    case AItem::StartExplosionV:
      if (canPlaceItem(glm::vec3(it->getPosition().x - 1, it->getPosition().y, it->getPosition().z)))
	{
	  exp = new Explosion(glm::vec3(it->getPosition().x - 1, it->getPosition().y, it->getPosition().z), glm::vec3(0, 0, 0), glm::vec3(0.5, 0.5, 0.5), textureloader.getTexture(ExplosionType));
	  exp->addEffect(AItem::ExplodeV, AItem::OnSpawn);
	  addItem(exp);
	}
      if (canPlaceItem(glm::vec3(it->getPosition().x + 1, it->getPosition().y, it->getPosition().z)))
	{
	  exp = new Explosion(glm::vec3(it->getPosition().x + 1, it->getPosition().y, it->getPosition().z), glm::vec3(0, 0, 0), glm::vec3(0.5, 0.5, 0.5), textureloader.getTexture(ExplosionType));
	  exp->addEffect(AItem::ExplodeV, AItem::OnSpawn);
	  addItem(exp);
	}
      break;

    case AItem::ExplodeH:
      if (it->getHp() > 0)
	{
	  if (canPlaceItem(glm::vec3(it->getPosition().x, it->getPosition().y, it->getPosition().z - 1)))
	    {
	      exp = new Explosion(glm::vec3(it->getPosition().x, it->getPosition().y, it->getPosition().z - 1), glm::vec3(0, 0, 0), glm::vec3(0.5, 0.5, 0.5), textureloader.getTexture(ExplosionType), it->getHp() - 1);
	      exp->addEffect(AItem::ExplodeH, AItem::OnSpawn);
	      addItem(exp);
	    }
	  if (canPlaceItem(glm::vec3(it->getPosition().x, it->getPosition().y, it->getPosition().z + 1)))
	    {
	      exp = new Explosion(glm::vec3(it->getPosition().x, it->getPosition().y, it->getPosition().z + 1), glm::vec3(0, 0, 0), glm::vec3(0.5, 0.5, 0.5), textureloader.getTexture(ExplosionType), it->getHp() - 1);
	      exp->addEffect(AItem::ExplodeH, AItem::OnSpawn);
	      addItem(exp);
	    }
	}
      break;

    case AItem::ExplodeV:
      if (it->getHp() > 0)
	{
	  if (canPlaceItem(glm::vec3(it->getPosition().x - 1, it->getPosition().y, it->getPosition().z)))
	    {
	      exp = new Explosion(glm::vec3(it->getPosition().x - 1, it->getPosition().y, it->getPosition().z), glm::vec3(0, 0, 0), glm::vec3(0.5, 0.5, 0.5), textureloader.getTexture(ExplosionType), it->getHp() - 1);
	      exp->addEffect(AItem::ExplodeV, AItem::OnSpawn);
	      addItem(exp);
	    }
	  if (canPlaceItem(glm::vec3(it->getPosition().x + 1, it->getPosition().y, it->getPosition().z)))
	    {
	      exp = new Explosion(glm::vec3(it->getPosition().x + 1, it->getPosition().y, it->getPosition().z), glm::vec3(0, 0, 0), glm::vec3(0.5, 0.5, 0.5), textureloader.getTexture(ExplosionType), it->getHp() - 1);
	      exp->addEffect(AItem::ExplodeV, AItem::OnSpawn);
	      addItem(exp);
	    }
	}
      break;

    case AItem::DestroyAll:
      eDestroyAll(it, it->getPosition(), textureloader);
      break;
    default:
      break;
    };
}

void Map::eDestroyAll(AItem const * ref, glm::vec3 pos, TextureLoader &textureloader)
{
  gdl::Clock tmp;
  glm::vec3 tmpPos;
  std::list<AItem::effect> effects;
  std::list<AItem::effect>::iterator it_eff;
  std::list<AItem *>::iterator it;
  std::list<APlayer *>::iterator itp;

  for (it = _items.begin(); it != _items.end(); it++)
    {
      if ((*it) != ref && isColliding((*it)->getPosition(), pos) && (*it)->isDamageable() && (*it)->getHp() > 0)
	{
	  (*it)->destroy();
	  effects = (*it)->play(tmp.getElapsed());
	  for (it_eff = effects.begin(); it_eff != effects.end(); ++it_eff)
	    playEffect(*it_eff, *it, textureloader);
	}
    }
  for (itp = _players.begin(); itp != _players.end(); itp++)
    {
      tmpPos = (*itp)->getPosition();
      tmpPos.x *= -1;
      tmpPos.z *= -1;
      if (isColliding(tmpPos, pos) && (*itp)->getHp() > 0)
	{
	  (*itp)->damage();
	}
    }
}

void Map::update(const gdl::Clock &clock, const gdl::Input &input, TextureLoader &textureloader)
{
  std::list<AItem::effect> effects;
  std::list<AItem::effect>::iterator it_eff;
  std::list<AItem *>::iterator it;
  std::list<APlayer *>::iterator it2;
  (void)input;

  for (it = _items.begin(); it != _items.end(); it++)
    {
      effects = (*it)->play(clock.getElapsed());
      for (it_eff = effects.begin(); it_eff != effects.end(); ++it_eff)
	{
	  playEffect(*it_eff, *it, textureloader);
	}
      if ((*it)->getHp() < 0)
	it = _items.erase(it);
    }

  for (it2 = _players.begin(); it2 != _players.end(); it2++)
    {
      (*it2)->update(_items);
      if ((*it2)->getHp() <= 0)
	it2 = _players.erase(it2);
    }
}

std::list<AItem *> const &Map::getItems(void) const {
    return _items;
}

std::list<APlayer *> const &Map::getPlayers(void) const {
    return _players;
}
