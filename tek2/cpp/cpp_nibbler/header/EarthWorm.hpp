#ifndef _EARTHWORM_HPP_
# define _EARTHWORM_HPP_

# include <deque>
# include <map>

# include "Coord.hpp"
# include "Error.hpp"

class EarthWorm
{
private:
	std::map<t_direct, int> checkDirectX;
	std::map<t_direct, int> checkDirectY;
	std::deque<Coord *> body;
public:
	EarthWorm();

	const std::deque<Coord *> &getBody() const;

	bool move(t_direct newDirect, Coord &mainFood);
	void pushOnBody(int newX, int newY);
	
};

#endif