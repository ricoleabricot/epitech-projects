/* 
* @Author: gicque_p
* @Date:   2015-04-17 19:05:09
* @Last Modified by:   Kafei59
* @Last Modified time: 2015-04-25 01:40:34
*/

#include "Reception.hpp"
#include "UnitTests.hpp"

void testInit(void);
void testRun(void);

void testsReception(void) {
	testInit();
	testRun();
}

void testInit(void) {
	Reception firstReception(0, 1, 2);
	bool flag(false);

	try {
		firstReception.init();
	} catch (const ReceptionError &error) {
		flag = true;
	}

	if (UnitTests::isFalse(flag)) {
		printError("Init method is not catching an exception with a parameter of value zero");
	}

	Reception secondReception(1, 100, 2);
	flag = false;

	try {
		secondReception.init();
	} catch (const ReceptionError &error) {
		flag = true;
	}

	if (UnitTests::isFalse(flag)) {
		printError("Init method is not catching an exception with a parameter of value one hundred");
	}

	Reception thirdReception(0.5, 1, 500);
	flag = false;

	try {
		thirdReception.init();
	} catch (const ReceptionError &error) {
		printError("Init method is catching an exception with a right initiation");
	}

	if (UnitTests::isNotEqual(thirdReception.getPreparePizza(), 0.5)) {
		printError("Init method is not assigning right value for preparePizza");
	}

	if (UnitTests::isNotEqual(thirdReception.getNumberCook(), 1)) {
		printError("Init method is not assigning right value for numberCook");
	}
}

void testRun(void) {
	Reception firstReception(1, 1, 1);

	firstReception.run();
	if (UnitTests::isNotEqual((int)firstReception.getOrders().size(), 0)) {
		printError("Run method have not right number of orders at start");
	}

	if (UnitTests::isNotEqual((int)firstReception.getKitchens()->size(), 0)) {
		printError("Run method have not right number of kitchens at start");
	}

	Reception secondReception(1, 1, 1);
	Pizza pizza(Regina, XL);

	secondReception.push(pizza);
	secondReception.run();

	if (UnitTests::isNotEqual((int)secondReception.getOrders().size(), 0)) {
		printError("Run method is not popping an order");
	}

	if (UnitTests::isNotEqual((int)secondReception.getKitchens()->size(), 1)) {
		printError("Run method is not creating a Kitchen like expected");
	}

	secondReception.push(pizza);
	secondReception.run();

	if (UnitTests::isNotEqual((int)secondReception.getOrders().size(), 0)) {
		printError("Run method is not popping an order");
	}

	if (UnitTests::isNotEqual((int)secondReception.getKitchens()->size(), 1)) {
		printError("Run method is creating an new kitchen even if she can takes the order");
	}	
}