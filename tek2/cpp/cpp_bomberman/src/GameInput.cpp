/* 
* @Author: gicque_p
* @Date:   2015-06-14 16:44:23
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-06-14 23:53:10
*/

#include "GameInput.hh"

GameInput::GameInput() :
    _input()
{}

GameInput::~GameInput() {}

void GameInput::move(Display *display, APlayer *player, Map &map, const gdl::Clock &clock) {
    glm::vec3 translation(0, 0, 0);

    if (this->turnLeft()) {
        translation = glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * 3.0f;
    } else if (this->turnRight()) {
        translation = glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * 3.0f;
    } else if (this->turnUp()) {
        translation = glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * 3.0f;
    } else if (this->turnDown()) {
        translation = glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * 3.0f;
    }

    display->setTranslation(translation);
    player->translate(translation);

    glm::vec3 pos(-player->getPosition().x, player->getPosition().y, -player->getPosition().z);

    if (map.canMoveAt(pos)) {
        display->setTranslation(-translation);
        player->translate(-translation);
    }
}

bool GameInput::quitGame(void) {
    return this->_input.getKey(SDLK_ESCAPE) or this->_input.getInput(SDL_QUIT);
}

bool GameInput::itemAction(void) {
    return this->_input.getKey(SDLK_SPACE);
}

bool GameInput::turnLeft(void) {
    return this->_input.getKey(SDLK_LEFT);
}

bool GameInput::turnRight(void) {
    return this->_input.getKey(SDLK_RIGHT);
}

bool GameInput::turnUp(void) {
    return this->_input.getKey(SDLK_UP);
}

bool GameInput::turnDown(void) {
    return this->_input.getKey(SDLK_DOWN);
}

gdl::Input &GameInput::getInput(void) {
    return this->_input;
}
