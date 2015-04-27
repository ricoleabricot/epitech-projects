/* 
* @Author: gicque_p
* @Date:   2015-03-11 15:43:22
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-03-11 21:21:12
*/

#include "UnitTests.hpp"
#include "EarthWorm.hpp"

void testMove(void);

void testsEarthWorm(void) {
	testMove();	
}

void testMove(void) {
	EarthWorm worm;
	Coord coord(10, 10);
	bool status = false;

	try {
		worm.move(NONE, coord);	
	} catch (const EarthWormError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("Move method is not catching an exception as it ought to be");
	}

	worm.pushOnBody(10, 10);
	try {
		status = worm.move(NONE, coord);
	} catch (const EarthWormError &error) {
		printError("Move method is catching an exception");
	}

	if (UnitTests::isFalse(status)) {
		printError("Move method is not returning true boolean");
	}

	try {
		status = worm.move(UP, coord);
	} catch (const EarthWormError &error) {
		printError("Move method is catching an exception");
	}

	if (UnitTests::isTrue(status)) {
		printError("Move method is not returning false boolean");
	}
}