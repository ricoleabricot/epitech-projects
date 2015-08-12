/* 
* @Author: gicque_p
* @Date:   2015-05-20 09:21:57
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-06-14 23:38:45
*/

#include "GameEngine.hh"

GameEngine::GameEngine() {}
GameEngine::~GameEngine() {}

bool GameEngine::initialize(void) {
    _display = new Display(1000, 1000, "Bomberman");
    _textureloader.initialize();

    for (int x = -10; x <= 10; ++x) {
	   for (int y = -10; y <= 10; ++y) {
            if (x == -10 or x == 10 or y == -10 or y == 10) {
                _map.addItem(new Wall(glm::vec3(x, 0.6, y), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), _textureloader.getTexture(WallType)));
            }
            _map.addItem(new Floor(glm::vec3(x, 0, y), glm::vec3(0, 0, 0), glm::vec3(1, 0.2, 1), _textureloader.getTexture(FloorType)));
        }
    }

    _map.addItem(new Bomb(glm::vec3(7, 0.6, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), _textureloader.getTexture(BombType)));
    _map.addItem(new Bomb(glm::vec3(5, 0.6, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), _textureloader.getTexture(BombType), 5));
    _map.addItem(new Bomb(glm::vec3(-1, 0.6, 8), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), _textureloader.getTexture(BombType), 5));
    _map.addItem(new Box(glm::vec3(3, 0.6, 8), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), _textureloader.getTexture(BoxType)));
    _map.addItem(new Box(glm::vec3(-4, 0.6, 8), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), _textureloader.getTexture(BoxType)));
    _map.addItem(new Wall(glm::vec3(-3, 0.6, 8), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), _textureloader.getTexture(WallType)));

    _map.addPlayer(new Player(glm::vec3(0, 0.6, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), _textureloader.getTexture(PlayerType), 1, 1));
    //_menu.createMenu();

    return (true);
}

bool GameEngine::update(void) {
    if (this->_input.quitGame()) {
        return false;
    } else {
        APlayer *player = _map.getPlayers().front();

        if (this->_input.itemAction()) {
            this->action(player);
        }

        this->_input.move(this->_display, player, this->_map, this->_clock);
        this->_display->updateContext(this->_clock, this->_input.getInput());
        this->_map.update(this->_clock, this->_input.getInput(), this->_textureloader);
        this->_menu.update(this->_clock, this->_input.getInput());

	if (_map.getPlayers().empty())
	  {
	    std::cout << "You died !" << std::endl;
	    return (false);
	  }
    }

    return (true);
}

void GameEngine::action(APlayer *player) {
    if (player->getItemsPlanted() < player->getMaxPlantableItems()) {
        glm::vec3 cam(this->_display->getPosition());

        if (_map.canPlaceItem(cam)) {
            _map.addItem(new Bomb(cam, glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), _textureloader.getTexture(BombType), 5, player->getId()));
            player->plantItem();
        }

    }
}

void GameEngine::draw(void) {
  _display->clear();
  _display->draw(_map.getItems(), _map.getPlayers());
  //_display->draw(_menu.getItems());
  _display->flush();
}
