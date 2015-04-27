#ifndef _CORE_HPP_
# define _CORE_HPP_

# include <iostream>
# include <fstream>
# include <string>
# include <csignal>
# include <list>
# include <map>

# include "Plugin.hpp"
# include "IDisplay.hpp"
# include "EarthWorm.hpp"

class Core {
 private:
	const int sizeX;
	const int sizeY;
	const std::string lib;
	int _score;

	EarthWorm snake;
	Coord mainFood;
	Plugin<IDisplay> _instance;
	IDisplay *_graph;

	std::list<t_direct> newDirects;
	std::map<t_direct, int> checkDirectX;
	std::map<t_direct, int> checkDirectY;

	bool checkEnd();
	void putNewFood();
	void checkCollision(int &, bool &);
	void checkDirection(bool &);
	void dispAll();
 public:
	Core(int newSizeX, int newSizeY, const std::string &newLib);

	void start();
	void run();
	void stop();
	void highScore(void);
};

void sig_handler(int);

#endif