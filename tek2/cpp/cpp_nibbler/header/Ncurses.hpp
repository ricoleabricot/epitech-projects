#ifndef NCURSES_HPP_
# define NCURSES_HPP_

# include "curses.h"

# include "IDisplay.hpp"

class Ncurses : public IDisplay {
	int _width;
	int _height;

 public:
	Ncurses() {};
	~Ncurses() {};

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

#endif /* !NCURSES_HPP_ */
