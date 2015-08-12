//
// Welcome.hh for zappy in /home/makusa_n/tek2/PSU_2014_zappy/graphique/legendOfZappy
// 
// Made by Nayden Makusa
// Login   <makusa_n@epitech.net>
// 
// Started on  Mon Jun 29 15:26:09 2015 Nayden Makusa
// Last update Sun Jul  5 21:52:20 2015 Pierrick Gicquelais
//

#ifndef			WELCOME_HH_
# define		WELCOME_HH_

# include		<iostream>
# include		<string>
# include		<SFML/Window.hpp>
# include		<SFML/Graphics.hpp>
# include		<SFML/Audio.hpp>

class			Welcome
{
public:
  Welcome();
  ~Welcome();
  void			loadFonts();
  void			loadPictures();
  void			loadSounds();
  void			runGame(std::string const &txtAddress, std::string const &txtPort);
  void			run();
private:
  sf::Text		_address;
  sf::Text		_port;
  sf::Font		_triForce;
  sf::Texture		_texWallpaper;
  sf::Sprite		_wallpaper;
  sf::Texture		_texTriforce;
  sf::Sprite		_triforce;
  sf::Music		_music;
  sf::SoundBuffer	_bufferMoveSound;
  sf::Sound		_moveSound;
  sf::SoundBuffer	_bufferLetterSound;
  sf::Sound		_letterSound;
  sf::SoundBuffer	_bufferLetterBackSound;
  sf::Sound		_letterBackSound;
};

#endif			/* WELCOME_HH_ */
