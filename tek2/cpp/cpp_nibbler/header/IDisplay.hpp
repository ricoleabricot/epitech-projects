#ifndef IDISPLAY_HPP_
# define IDISPLAY_HPP_

# include <iostream>
# include <deque>
# include <stdlib.h>

# include "Coord.hpp"

typedef enum e_color
{
	BLACK = 1,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE
} t_color;

class IDisplay {
 public:
	virtual ~IDisplay() {};

	virtual int getWidth() const = 0;
	virtual void setWidth(int) = 0;
	virtual int getHeight() const = 0;
	virtual void setHeight(int) = 0;
	virtual void init() = 0;
	virtual void end_init() = 0;
	virtual void printSquare(int x, int y, t_color color) = 0;
	virtual void clearWin() = 0;
	virtual void refreshWin() = 0;
	virtual bool wait() = 0;
	virtual t_direct getNextDirect() = 0;
};

#endif /* !IDISPLAY_HPP_ */

