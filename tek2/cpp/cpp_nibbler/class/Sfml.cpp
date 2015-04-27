/* 
* @Author: gicque_p
* @Date:   2015-03-10 12:16:51
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-04-02 18:06:37
*/

#include "Sfml.hpp"

int Sfml::getWidth() const
{
	return (_width);
}

void Sfml::setWidth(int width)
{
	_width = width;
}

int Sfml::getHeight() const
{
	return (_height);
}

void Sfml::setHeight(int height)
{
	_height = height;
}

void Sfml::init()
{
	mainWindow.create(sf::VideoMode(WIDTH_WIN + (WIDTH_WIN / _width) * 2, HEIGHT_WIN + (HEIGHT_WIN / _height) * 2), "nibbler");
	mainMusic.openFromFile("media/music.ogg");
	mainMusic.setLoop(true);
	mainMusic.play();

	checkColor[BLACK] = sf::Color(0, 0, 0);
	checkColor[RED] = sf::Color(255, 0, 0);
	checkColor[GREEN] = sf::Color(0, 255, 0);
	checkColor[YELLOW] = sf::Color(255, 255, 0);
	checkColor[BLUE] = sf::Color(0, 0, 255);
	checkColor[MAGENTA] = sf::Color(255, 0, 255);
	checkColor[CYAN] = sf::Color(0, 255, 255);
	checkColor[WHITE] = sf::Color(255, 255, 255);

	checkTexture[BLACK] = new sf::Texture;
	if (!checkTexture[BLACK]->loadFromFile("media/black.png"))
		checkTexture[BLACK] = NULL;
	checkTexture[RED] = new sf::Texture;
	if (!checkTexture[RED]->loadFromFile("media/food.png"))
		checkTexture[RED] = NULL;
	checkTexture[GREEN] = new sf::Texture;
	if (!checkTexture[GREEN]->loadFromFile("media/grass.png"))
		checkTexture[GREEN] = NULL;
	checkTexture[YELLOW] = new sf::Texture;
	if (!checkTexture[YELLOW]->loadFromFile("media/bad_side.png"))
		checkTexture[YELLOW] = NULL;
	checkTexture[BLUE] = new sf::Texture;
	if (!checkTexture[BLUE]->loadFromFile("media/snake_body.png"))
		checkTexture[BLUE] = NULL;
	checkTexture[MAGENTA] = new sf::Texture;
	if (!checkTexture[MAGENTA]->loadFromFile("media/magenta.png"))
		checkTexture[MAGENTA] = NULL;
	checkTexture[CYAN] = new sf::Texture;
	if (!checkTexture[CYAN]->loadFromFile("media/snake_head.png"))
		checkTexture[CYAN] = NULL;
	checkTexture[WHITE] = new sf::Texture;
	if (!checkTexture[WHITE]->loadFromFile("media/white.png"))
		checkTexture[WHITE] = NULL;
}

void Sfml::end_init()
{
	mainWindow.close();
	mainMusic.stop();
}

void Sfml::printSquare(int x, int y, t_color color)
{
	sf::RectangleShape rect(sf::Vector2f(WIDTH_WIN / _width, HEIGHT_WIN / _height));
	sf::Texture tex;
	if (!checkTexture[color])
		rect.setFillColor(checkColor[color]);
	else
		rect.setTexture(checkTexture[color]);
	rect.setPosition((WIDTH_WIN / _width) * (x + 1), (HEIGHT_WIN / _height) * (y + 1));
	mainWindow.draw(rect);
}

void Sfml::clearWin()
{
	mainWindow.clear(sf::Color::Black);
}

void Sfml::refreshWin()
{
	mainWindow.display();
}

t_direct Sfml::getNextDirect()
{
	sf::Event event;
	
	mainWindow.pollEvent(event);
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Left)
			return (LEFT);
		else if (event.key.code == sf::Keyboard::Right)
			return (RIGHT);
		else if (event.key.code == sf::Keyboard::Escape)
			return (EXIT);
	}
	return (NONE);
}

bool Sfml::wait()
{
	static sf::Clock cl;

	if (cl.getElapsedTime().asMilliseconds() >= 100)
	{
		cl.restart();
		return (true);
	}
	else
		return (false);
}

extern "C" {
	IDisplay *createModule(void) {
		return new Sfml;
	}
} 
