//
// Welcome.cpp for zappy in /home/ribeir_b/rendu/PSU_2014_zappy/src/graphic
// 
// Made by Nayden Makusa
// Login   <makusa_n@epitech.net>
// 
// Started on  Sun Jul  5 12:46:37 2015 Nayden Makusa
// Last update Sun Jul  5 23:21:48 2015 Nayden Makusa
//

#include		<iostream>
#include		<string>
#include		<string.h>
#include		"graphic/Game.hh"
#include		"graphic/Welcome.hh"

Welcome::Welcome()
{
}

Welcome::~Welcome()
{
}

void			Welcome::runGame(std::string const &txtAddress, std::string const &txtPort)
{
  Game			game(txtAddress, std::atoi(txtPort.c_str()));

  if (!(game.initWorked()))
    {
      std::cerr << "Cannot connect to server" << std::endl;
      exit (-1);
    }
  game.run();
}

void			Welcome::run()
{
  sf::RenderWindow	window(sf::VideoMode(1200, 675), "My window");
  std::string		txtAddress("127.0.0.1");
  std::string		txtPort("8080");
  int			swap = 0;

  this->_music.play();
  this->_music.setLoop(true);
  _address.setString(txtAddress + '|');
  _port.setString(txtPort);
  while (window.isOpen())
    {
      sf::Event		event;

      while (window.pollEvent(event))
        {
	  switch (event.type)
	    {
	    case sf::Event::TextEntered:
	      if (event.text.unicode >= 32 && event.text.unicode <= 126 && swap == 0 && txtAddress.length() <= 20)
		{
		  _letterSound.play();
		  txtAddress = txtAddress + static_cast<char>(event.text.unicode);
		  _address.setString(txtAddress + '|');
		}
	      else if (event.text.unicode >= 32 && event.text.unicode <= 126 && swap == 1 && txtPort.length() <= 20)
		{
		  _letterSound.play();
		  txtPort = txtPort + static_cast<char>(event.text.unicode);
		  _port.setString(txtPort + '|');
		}
	      else if (event.text.unicode == 8)
		{
		  _letterBackSound.play();
		  if (swap == 0)
		    {
		      if (!txtAddress.empty())
			txtAddress.resize(txtAddress.length() - 1);
		      _address.setString(txtAddress + '|');
		    }
		  else
		    {
		      if (!txtPort.empty())
			txtPort.resize(txtPort.length() - 1);
		      _port.setString(txtPort + '|');
		    }
		}
	      break;
	    case sf::Event::KeyPressed:
	      switch (event.key.code)
		{
		case sf::Keyboard::Up:
		  swap = 0;
		  this->_triforce.setPosition(35, 225);
		  _moveSound.play();
		  _address.setString(txtAddress + '|');
		  _port.setString(txtPort);
		  break;
		case sf::Keyboard::Down:
		  swap = 1;
		  this->_triforce.setPosition(35, 375);
		  _moveSound.play();
		  _address.setString(txtAddress);
		  _port.setString(txtPort + '|');
		  break;
		case sf::Keyboard::Escape:
		  window.close();
		  this->_music.stop();
		  break;
		case sf::Keyboard::Return:
		  window.close();
		  this->_music.stop();
		  this->runGame(txtAddress, txtPort);
		  break;
		default:
		  break;
		}
	    case sf::Event::Closed:
	      if (event.type == sf::Event::Closed)
		{
		  window.close();
		  this->_music.stop();
		}
	      break;
	    default:
	      break;
	    }
        }
      window.clear();
      window.draw(_wallpaper);
      window.draw(_triforce);
      window.draw(_address);
      window.draw(_port);
      window.display();
    }
}
