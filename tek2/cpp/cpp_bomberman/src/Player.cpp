/* 
* @Author: gicque_p
* @Date:   2015-06-14 17:11:08
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-06-14 21:29:23
*/

#include "Player.hh"

Player::Player(glm::vec3 const &position, glm::vec3 const &rotation, glm::vec3 const &scale, gdl::Texture const &texture, int id, int hp) :
    APlayer(position, rotation, scale, texture, id, hp)
{}

Player::~Player() {}
