#ifndef TEXTURELOADER_HH_
# define TEXTURELOADER_HH_

# include <iostream>
# include <map>

# include "Texture.hh"
# include "Exception.hh"

enum ItemType {
    BombType,
    ExplosionType,
    FloorType,
    BoxType,
    WallType,
    PlayerType
};

class TextureLoader {
 private:
    std::map<ItemType, gdl::Texture> _map;

 public:
    TextureLoader();
    ~TextureLoader();

  void initialize(void);
    gdl::Texture &getTexture(ItemType);
};

#endif /* TEXTURELOADER_HH_ */
