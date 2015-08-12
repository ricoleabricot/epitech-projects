#ifndef MAP_HH_
# define MAP_HH_

# include <string>
# include <iostream>
# include <list>
# include <fstream>

# include <Clock.hh>
# include <Input.hh>

# include "AItem.hh"
# include "APlayer.hh"
# include "Explosion.hh"
# include "TextureLoader.hh"

class Map
{
private:
  std::list<AItem *> _items;
  std::list<APlayer *> _players;

  void eDestroyAll(AItem const * ref, glm::vec3 pos, TextureLoader &textureloader);
  void playEffect(AItem::effect effect, AItem * it, TextureLoader &textureloader);
  bool isColliding(glm::vec3 const & vec1, glm::vec3 const & vec2);

public:
  Map();
  ~Map();

  void addItem(AItem *);
  void deleteItem(AItem *);

  void addPlayer(APlayer *);
  void deletePlayer(APlayer *);

  void load(std::string const & file);

  void update(const gdl::Clock &, const gdl::Input &, TextureLoader &);
  void draw(const gdl::Clock &, const gdl::Input &);

  bool canMoveAt(glm::vec3 const & pos);
  bool canPlaceItem(glm::vec3 const & pos);

  std::list<AItem *> const &getItems(void) const;
  std::list<APlayer *> const &getPlayers(void) const;
};

#endif /* MAP_HH_ */
