/* 
* @Author: gicque_p
* @Date:   2015-06-12 15:37:16
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-06-14 17:02:30
*/

#include "TextureLoader.hh"

TextureLoader::TextureLoader() :
    _map()
{}

void TextureLoader::initialize() {
    if (!_map[BombType].load("./texture/tnt.tga")) {
        throw TextureLoaderException("Can't load Bomb texture");
    }

    if (!_map[ExplosionType].load("./texture/explosion.tga")) {
        throw TextureLoaderException("Can't load Wall texture");
    }

    if (!_map[FloorType].load("./texture/brick.tga")) {
        throw TextureLoaderException("Can't load Floor texture");
    }

    if (!_map[BoxType].load("./texture/woodbox.tga")) {
        throw TextureLoaderException("Can't load Box texture");
    }

    if (!_map[WallType].load("./texture/wall.tga")) {
        throw TextureLoaderException("Can't load Box texture");
    }

    if (!_map[PlayerType].load("./texture/player.tga")) {
        throw TextureLoaderException("Can't load Player texture");
    }
}

TextureLoader::~TextureLoader() {}

gdl::Texture &TextureLoader::getTexture(ItemType type) {
    if (_map.find(type) != _map.end()) {
        return _map[type];
    } else {
        throw TextureLoaderException("Can't find texture");
    }
}
