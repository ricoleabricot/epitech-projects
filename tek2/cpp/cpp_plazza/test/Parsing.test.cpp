/* 
* @Author: gicque_p
* @Date:   2015-04-16 14:06:38
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-04-21 17:20:08
*/

#include "Parsing.hpp"
#include "UnitTests.hpp"

void testPrepareOrders(void);
void testPrepareOrder(void);
void testPrepareType(void);
void testPrepareSize(void);
void testPrepareNumber(void);

void testsParsing(void) {
	testPrepareOrders();
	testPrepareOrder();
	testPrepareType();
	testPrepareSize();
	testPrepareNumber();
}

void testPrepareOrders(void) {
	Reception firstReception(1, 1, 1);
	Parsing firstParsing;
	bool flag(false);

	try {
		firstParsing.prepareOrders(&firstReception, "");
	} catch (const ParsingError &error) {
		flag = true;
	}

	if (UnitTests::isFalse(flag)) {
		printError("PrepareOrders method is not catching an exception with an empty string");
	}

	if (UnitTests::isNotEqual((int)firstReception.getOrders().size(), 0)) {
		printError("PrepareOrders method is pushing a pizza in queue with an error");
	}

	Reception secondReception(1, 1, 1);
	Parsing secondParsing;

	try {
		secondParsing.prepareOrders(&secondReception, "Regina XL x2; fantasia L X1; margarita XL x5; americana S x2");
	} catch (const ParsingError &error) {
		std::cout << error.what() << std::endl;
		printError("PrepareOrders method is catching an error on a simple order");
	}

	if (UnitTests::isNotEqual((int)secondReception.getOrders().size(), 10)) {
		printError("PrepareOrders method is not pushing right pizzas number in queue");
	}
}

void testPrepareOrder(void) {
	Parsing firstParsing;
	bool flag(false);

	try {
		firstParsing.prepareOrder("regina XL x13 toomany", 0);
	} catch (const ParsingError &error) {
		flag = true;
	}

	if (UnitTests::isFalse(flag)) {
		printError("PrepareOrder method is not catching an exception with too many arguments in order");
	}

	Parsing secondParsing;
	flag = false;

	try {
		secondParsing.prepareOrder("regina XL", 0);
	} catch (const ParsingError &error) {
		flag = true;
	}

	if (UnitTests::isFalse(flag)) {
		printError("PrepareOrder method is not catching an exception with not enough arguments in order");
	}

	Parsing thirdParsing;

	try {
		thirdParsing.prepareOrder("regina XL x13", 0);
	} catch (const ParsingError &error) {
		printError("PrepareOrder method is catching an error on a simple order");
	}
}

void testPrepareType(void) {
	Parsing firstParsing;
	bool flag(false);

	try {
		firstParsing.prepareType("unknownType", 0);
	} catch (const ParsingError &error) {
		flag = true;
	}

	if (UnitTests::isFalse(flag)) {
		printError("PrepareType method is not catching an exception with an unknown pizza type");
	}

	Parsing secondParsing;

	try {
		secondParsing.prepareType("regina", 0);
	} catch (const ParsingError &error) {
		printError("PrepareType method is catching an error on a simple order");
	}
}

void testPrepareSize(void) {
	Parsing firstParsing;
	bool flag(false);

	try {
		firstParsing.prepareSize("unknownSize", 0);
	} catch (const ParsingError &error) {
		flag = true;
	}

	if (UnitTests::isFalse(flag)) {
		printError("PrepareSize method is not catching an exception with an unknown pizza size");
	}

	Parsing secondParsing;

	try {
		secondParsing.prepareSize("XL", 0);
	} catch (const ParsingError &error) {
		printError("PrepareSize method is catching an error on a simple order");
	}
}

void testPrepareNumber(void) {
	Parsing firstParsing;
	bool flag(false);

	try {
		firstParsing.prepareNumber("unknownNumer", 0);
	} catch (const ParsingError &error) {
		flag = true;
	}

	Parsing secondParsing;
	flag = false;

	try {
		secondParsing.prepareNumber("35", 0);
	} catch (const ParsingError &error) {
		flag = true;
	}

	if (UnitTests::isFalse(flag)) {
		printError("PrepareNumber method is not catching an exception with an invalid number format");
	}

	Parsing thirdParsing;
	flag = false;

	try {
		thirdParsing.prepareNumber("x", 0);
	} catch (const ParsingError &error) {
		flag = true;
	}

	if (UnitTests::isFalse(flag)) {
		printError("PrepareNumber method is not catching an exception with an invalid number format");
	}

	Parsing fourthParsing;
	flag = false;

	try {
		fourthParsing.prepareNumber("xcoucou", 0);
	} catch (const ParsingError &error) {
		flag = true;
	}

	if (UnitTests::isFalse(flag)) {
		printError("PrepareNumber method is not catching an exception with an invalid number format");
	}

	Parsing fifthParsing;
	flag = false;

	try {
		fifthParsing.prepareNumber("x100", 0);
	} catch (const ParsingError &error) {
		flag = true;
	}

	if (UnitTests::isFalse(flag)) {
		printError("PrepareNumber method is not catching an exception with a number too high");
	}

	Parsing sixthParsing;

	try {
		sixthParsing.prepareNumber("x13", 0);
	} catch (const ParsingError &error) {
		printError("PrepareNumber method is catching an error on a simple order");
	}
}
