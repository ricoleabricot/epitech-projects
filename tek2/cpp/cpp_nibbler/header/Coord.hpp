#ifndef _COORD_HPP_
# define _COORD_HPP_

typedef enum e_direct
{
	NONE = 0,
	UP = 1,
	RIGHT = 2,
	DOWN = 3,
	LEFT = 4,
	EXIT = 5
} t_direct;

class Coord
{
private:
	int x;
	int y;
public:
	Coord(int newX, int newY);
	
	int getX() const;
	void setX(int newX);
	int getY() const;
	void setY(int newY);
};

#endif