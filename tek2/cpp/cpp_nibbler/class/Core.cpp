/* 
* @Author: gicque_p
* @Date:   2015-03-09 16:21:56
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-04-05 12:39:21
*/

#include "Core.hpp"

Core::Core(int newSizeX, int newSizeY, const std::string &newLib)
	: sizeX(newSizeX), sizeY(newSizeY), lib(newLib), _score(0), mainFood(0, 0)
{
	if (newSizeX < 5 or newSizeY < 5) {
		throw CoreError("Size map can't be lower than 5");
	}

	snake.pushOnBody(sizeX / 2 - 2, sizeY / 2);
	snake.pushOnBody(sizeX / 2 - 1, sizeY / 2);
	snake.pushOnBody(sizeX / 2, sizeY / 2);
	snake.pushOnBody(sizeX / 2 + 1 , sizeY / 2);
	newDirects.push_back(NONE);
	putNewFood();

	checkDirectX[LEFT] = -1;
	checkDirectX[RIGHT] = 1;
	checkDirectX[UP] = 0;
	checkDirectX[DOWN] = 0;

	checkDirectY[LEFT] = 0;
	checkDirectY[RIGHT] = 0;
	checkDirectY[UP] = -1;
	checkDirectY[DOWN] = 1;

	this->_graph = NULL;
}

bool Core::checkEnd()
{
	unsigned int i;
	const std::deque<Coord *> body = snake.getBody();

	if (body[0]->getX() < 0 || 
		body[0]->getX() > sizeX || 
		body[0]->getY() < 0 || 
		body[0]->getY() > sizeY)
		return (true);
	i = 1;
	while (i < body.size())
	{
		if (body[0]->getX() == body[i]->getX() && body[0]->getY() == body[i]->getY())
			return (true);
		i++;
	}
	return (false);
}

void Core::putNewFood()
{
	bool isOk;
	unsigned int i;
	int newX;
	int newY;

	isOk = false;
	while (!isOk)
	{
		newX = (rand() % (sizeX - 2)) + 1;
		newY = (rand() % (sizeY - 2)) + 1;
		isOk = true;
		i = 0;
		while (i < snake.getBody().size())
		{
			if (newX == snake.getBody()[i]->getX() && newY == snake.getBody()[i]->getY())
				isOk = false;
			i++;
		}
		mainFood.setX(newX);
		mainFood.setY(newY);
	}
}

void Core::start() {
	try {
		this->_graph = this->_instance.load(lib);
	} catch (const PluginError &error) {
		throw CoreError(error.what());
	}

	this->_graph->setWidth(sizeX);
	this->_graph->setHeight(sizeY);
	this->_graph->init();
}

void Core::dispAll()
{
	unsigned int pos;
	int x;
	int y;

	_graph->clearWin();

	x = 0;
	while (x < sizeX + 3)
	{
		y = 0;
		while (y < sizeY + 3)
		{
			_graph->printSquare(x, y, GREEN);
			y++;
		}
		x++;
		y = 0;
	}

	x = 0;
	while (x < sizeX + 3) {
		_graph->printSquare(x, 0, YELLOW);
		x++;
	}
	y = 1;
	while (y < sizeY + 2)
	{
		x = 0;
		_graph->printSquare(x, y, YELLOW);
		x++;
		while (x < sizeX + 2)
		{
			pos = 0;
			while (pos < snake.getBody().size())
			{
				if (x == snake.getBody()[pos]->getX() + 1 && y == snake.getBody()[pos]->getY() + 1)
				{
					if (pos == 0)
						_graph->printSquare(x, y, CYAN);
					else
						_graph->printSquare(x, y, BLUE);
					break;
				}
				pos++;
			}
			if (pos == snake.getBody().size())
			{
				if (mainFood.getX() + 1 == x && mainFood.getY() + 1 == y)
					_graph->printSquare(x, y, RED);
				else
					_graph->printSquare(x, y, GREEN);
			}
			x++;
		}
		_graph->printSquare(x, y, YELLOW);
		y++;
	}
	x = 0;
	while (x < sizeX + 3)
	{
		_graph->printSquare(x, y, YELLOW);
		x++;
	}
	_graph->refreshWin();
}

void Core::checkCollision(int &grow, bool &isEnd)
{
	isEnd = checkEnd();
	if (newDirects.front() != NONE && snake.move(newDirects.front(), mainFood))
	{
		grow += 3;
		putNewFood();
		this->_score += 100;
	}
	if (grow > 0)
	{
		snake.pushOnBody(snake.getBody()[0]->getX() + checkDirectX[newDirects.front()], 
			snake.getBody()[0]->getY() + checkDirectY[newDirects.front()]);
		grow--;
	}
	if (newDirects.size() > 1)
		newDirects.pop_front();
	dispAll();
}

void Core::checkDirection(bool &isEnd)
{
	t_direct tmpDirect;

	tmpDirect = this->_graph->getNextDirect();
	if (tmpDirect == EXIT)
		isEnd = true;
	else if (tmpDirect != NONE && newDirects.size() < 2)
	{
		if (tmpDirect == LEFT)
		{
			if (newDirects.front() == NONE)
				tmpDirect = UP;
			else
				tmpDirect = (t_direct)(newDirects.front() - 1);
			if (tmpDirect < 1)
				tmpDirect = (t_direct)4;
		}
		else if (tmpDirect == RIGHT)
		{
			if (newDirects.front() == NONE)
				tmpDirect = DOWN;
			else
				tmpDirect = (t_direct)(newDirects.front() + 1);
			if (tmpDirect > 4)
				tmpDirect = (t_direct)1;
		}
		newDirects.push_back(tmpDirect);
	}
}

void Core::run(void) {
	bool isEnd = false;
	int grow;

	grow = 0;

	if (this->_graph == NULL) {
		throw CoreError("Dynamic library is uninitialized");
	}

	while (!isEnd)
	{
		if (this->_graph->wait() == true)
			checkCollision(grow, isEnd);
		else
			checkDirection(isEnd);
	}
}

void Core::stop(void) {
	if (this->_graph == NULL) {
		throw CoreError("Dynamic library uninitialized");
	} else {
		this->_graph->end_init();	
		this->_instance.unload();
	}
}

void Core::highScore(void) {
	std::ifstream file(".scoring", std::ios::in);

	std::string nickname;
	std::cout << "Your score: " << this->_score << std::endl;
	if (file) {
		signal(SIGINT, sig_handler);
		std::cout << "Enter your Nickname: ";
		try {
			std::cin >> nickname;
		} catch (const std::exception &error) {
			throw CoreError(error.what());
		}

		std::cin.clear();
		std::cin.ignore();
		if (nickname.empty()) {
			throw CoreError("Nickname missing, scoring invalid");
		} else {
			std::list<std::string> scores;
			std::string line;

			std::cout << "List of 5 best scores: " << std::endl;
			while (getline(file, line)) {
				scores.push_back(line);
			}
			file.close();
		
			std::ofstream file(".scoring", std::ofstream::out);
			if (file) {
				bool is_scored(false);
				for (std::list<std::string>::iterator it = scores.begin(); it != scores.end(); it++) {
					std::string tmp(*it);
					std::string value;

					if (tmp.find_first_of(':') != tmp.npos) {
						value = tmp.substr(tmp.find_first_of(':') + 1);

						if (atoi(value.c_str()) < this->_score and !is_scored) {
							std::cout << "\033[01;31m" << nickname << ":" << this->_score << "\033[0m" << std::endl;
							file << nickname << ":" << this->_score << std::endl;
							is_scored = true;
						} else {
							std::cout << tmp << std::endl;
							file << tmp << std::endl;
						}
					} else if (!is_scored) {
						std::cout << "\033[01;31m" << nickname << ":" << this->_score << "\033[0m" << std::endl;
						file << nickname << ":" << this->_score << std::endl;
						is_scored = true;
					} else {
						std::cout << tmp << std::endl;
						file << tmp << std::endl;
					}
				}

				if (is_scored) {
					std::cout << "NEW ENTERING HIGH SCORE, WELL DONE !!" << std::endl;
				}
			} else {
				throw CoreError("Scoring file is missing");
			}
		}
	} else {
		throw CoreError("Scoring file is missing");
	}
}

void sig_handler(int sig) {
	(void)sig;
	exit(EXIT_SUCCESS);
}