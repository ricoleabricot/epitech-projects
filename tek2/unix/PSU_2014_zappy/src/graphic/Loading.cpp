//
// loading.cpp for zappy in /home/makusa_n/tek2/PSU_2014_zappy/welcome
// 
// Made by Nayden Makusa
// Login   <makusa_n@epitech.net>
// 
// Started on  Wed Jul  1 13:03:43 2015 Nayden Makusa
// Last update Sun Jul  5 13:10:34 2015 Nicolas Ribeiro Teixeira
//

#include		<iostream>
#include		<string>
#include		"graphic/Welcome.hh"

void			Welcome::loadFonts()
{
  if (!_triForce.loadFromFile("fonts/pixelFont.otf"))
    {
      std::cerr << "Problem with the importation of the font" << std::endl;
      exit(1);
    }
  this->_address.setFont(this->_triForce);
  this->_address.setCharacterSize(60);
  this->_address.setColor(sf::Color::White);
  this->_address.setPosition(150, 225);
  this->_port.setFont(this->_triForce);
  this->_port.setCharacterSize(60);
  this->_port.setColor(sf::Color::White);
  this->_port.setPosition(150, 375);
}

void			Welcome::loadPictures()
{
  if (!(_texWallpaper.loadFromFile("sprites/wallpaper.png")))
    {
      std::cerr << "Problem with the importation of a picture (wallpaper)" << std::endl;
      exit(1);
    }
  if (!(_texTriforce.loadFromFile("sprites/triforce.png")))
    {
      std::cerr << "Problem with the importation of a picture (triforce)" << std::endl;
      exit(1);
    }
  this->_wallpaper.setTexture(_texWallpaper);
  this->_wallpaper.setPosition(0, 0);
  this->_triforce.setTexture(_texTriforce);
  this->_triforce.setPosition(35, 225);
}

void			Welcome::loadSounds()
{
  if (!_music.openFromFile("musics/selectScreen.ogg"))
    {
      std::cerr << "Problem with the importation of a music (selectScreen)" << std::endl;
      exit(1);
    }
  if (!_bufferMoveSound.loadFromFile("musics/menuCursor.wav"))
    {
      std::cerr << "Problem with the importation of a sound (menuCursor)" << std::endl;
      exit(1);
    }
  if (!_bufferLetterSound.loadFromFile("musics/menuLetter.wav"))
    {
      std::cerr << "Problem with the importation of a sound (menuLetter)" << std::endl;
      exit(1);
    }
  if (!_bufferLetterBackSound.loadFromFile("musics/menuLetterBack.wav"))
    {
      std::cerr << "Problem with the importation of a sound (menuLetterBack)" << std::endl;
      exit(1);
    }
  this->_moveSound.setBuffer(this->_bufferMoveSound);
  this->_letterSound.setBuffer(this->_bufferLetterSound);
  this->_letterBackSound.setBuffer(this->_bufferLetterBackSound);
}
