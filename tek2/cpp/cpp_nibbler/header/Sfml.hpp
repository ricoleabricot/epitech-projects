#ifndef SFML_HPP_
# define SFML_HPP_

# include <map>

# include "SFML/Graphics.hpp"
# include "SFML/Audio/Music.hpp"

# include "IDisplay.hpp"

# define WIDTH_WIN 800
# define HEIGHT_WIN 800

class Sfml : public IDisplay {
private:
	int _width;
	int _height;
	std::string _name;
	sf::RenderWindow mainWindow;
	sf::Music mainMusic;
	std::map<t_color, sf::Color> checkColor;
	std::map<t_color, sf::Texture *> checkTexture;
 public:
	Sfml() {};
	~Sfml() {};

	int getWidth() const;
	void setWidth(int);
	int getHeight() const;
	void setHeight(int);
	void init();
	void end_init();
	void printSquare(int, int, t_color);
	void clearWin();
	void refreshWin();
	bool wait();
	t_direct getNextDirect();
};

#endif /* !SFML_HPP_ */