/* 
* @Author: gicque_p
* @Date:   2015-03-09 16:22:04
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-03-11 21:19:17
*/

#include "EarthWorm.hpp"

EarthWorm::EarthWorm()
{
	checkDirectX[LEFT] = -1;
	checkDirectX[RIGHT] = 1;
	checkDirectX[UP] = 0;
	checkDirectX[DOWN] = 0;

	checkDirectY[LEFT] = 0;
	checkDirectY[RIGHT] = 0;
	checkDirectY[UP] = -1;
	checkDirectY[DOWN] = 1;
}

const std::deque<Coord *> &EarthWorm::getBody() const
{
	return (body);
}

bool EarthWorm::move(t_direct newDirect, Coord &mainFood)
{
	int pos;

	if (body.size() == 0) {
		throw EarthWormError("Body deque is empty");
	}

	if (body[0]->getX() + checkDirectX[newDirect] == mainFood.getX() && body[0]->getY() + checkDirectY[newDirect] == mainFood.getY())
		return (true);
	else
	{
		pos = body.size() - 1;
		while (pos > 0)
		{
			body[pos]->setX(body[pos - 1]->getX());
			body[pos]->setY(body[pos - 1]->getY());
			pos--;
		}
		body[pos]->setX(body[pos]->getX() + checkDirectX[newDirect]);
		body[pos]->setY(body[pos]->getY() + checkDirectY[newDirect]);
	}
	return (false);
}

void EarthWorm::pushOnBody(int newX, int newY)
{
	body.push_front(new Coord(newX, newY));
}
