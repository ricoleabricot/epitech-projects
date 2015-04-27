/* 
* @Author: gicque_p
* @Date:   2015-02-13 12:21:51
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-23 17:11:07
*/

#include "UnitTests.hpp"
#include "Hatchery.hpp"

static void testCreateOperand(void);
static void testCreateInt8(void);
static void testCreateInt16(void);
static void testCreateInt32(void);
static void testCreateFloat(void);
static void testCreateDouble(void);

void testsHatchery(void) {
	testCreateOperand();
	testCreateInt8();
	testCreateInt16();
	testCreateInt32();
	testCreateFloat();
	testCreateDouble();
}

void testCreateOperand(void) {
	Hatchery hatchery;

	try {
		hatchery.createOperand(Int8, "42");
	} catch (const HatcheryError &error) {
		printError("createOperand method is catching an exception");
	}

	try {
		hatchery.createOperand(Int32, "42");
	} catch (const HatcheryError &error) {
		printError("createOperand method is catching an exception");
	}
}

void testCreateInt8(void) {
	Hatchery hatchery;
	std::ostringstream buffer;
	bool status = false;

	buffer << INT8_MIN;
	try {
		hatchery.createOperand(Int8, buffer.str());
	} catch (const HatcheryError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("createInt8 method is not catching an exception as it ougth to be");
	}

	buffer.str("");
	buffer.clear();
	buffer << INT8_MAX;
	status = false;
	try {
		hatchery.createOperand(Int8, buffer.str());
	} catch (const HatcheryError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("createInt8 method is not catching an exception as it ougth to be");
	}

	buffer.str("");
	buffer.clear();
	buffer << 0;
	try {
		hatchery.createOperand(Int8, buffer.str());
	} catch (const HatcheryError &error) {
		printError("createInt8 is catching an exception");
	}
}

void testCreateInt16(void) {
	Hatchery hatchery;
	std::ostringstream buffer;
	bool status = false;

	buffer << INT16_MIN;
	try {
		hatchery.createOperand(Int16, buffer.str());
	} catch (const HatcheryError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("createInt16 method is not catching an exception as it ougth to be");
	}

	buffer.str("");
	buffer.clear();
	buffer << INT16_MAX;
	status = false;
	try {
		hatchery.createOperand(Int16, buffer.str());
	} catch (const HatcheryError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("createInt16 method is not catching an exception as it ougth to be");
	}

	buffer.str("");
	buffer.clear();
	buffer << INT8_MAX;
	try {
		hatchery.createOperand(Int16, buffer.str());
	} catch (const HatcheryError &error) {
		printError("createInt16 is catching an exception");
	}
}

void testCreateInt32(void) {
	Hatchery hatchery;
	std::ostringstream buffer;
	bool status = false;

	buffer << INT32_MIN;
	try {
		hatchery.createOperand(Int32, buffer.str());
	} catch (const HatcheryError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("createInt32 method is not catching an exception as it ougth to be");
	}

	buffer.str("");
	buffer.clear();
	buffer << INT32_MAX;
	status = false;
	try {
		hatchery.createOperand(Int32, buffer.str());
	} catch (const HatcheryError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("createInt32 method is not catching an exception as it ougth to be");
	}

	buffer.str("");
	buffer.clear();
	buffer << INT16_MAX;
	try {
		hatchery.createOperand(Int32, buffer.str());
	} catch (const HatcheryError &error) {
		printError("createInt32 is catching an exception");
	}
}

void testCreateFloat(void) {
	Hatchery hatchery;
	std::ostringstream buffer;

	buffer << INT32_MAX;
	try {
		hatchery.createOperand(Float, buffer.str());
	} catch (const HatcheryError &error) {
		printError("createFloat is catching an exception");
	}

	buffer.str("");
	buffer.clear();
	buffer << 0.1;
	try {
		hatchery.createOperand(Double, buffer.str());
	} catch (const HatcheryError &error) {
		printError("createFloat is catching an exception");
	}
}

void testCreateDouble(void) {
	Hatchery hatchery;
	std::ostringstream buffer;

	buffer << std::numeric_limits<float>::max();
	try {
		hatchery.createOperand(Float, buffer.str());
	} catch (const HatcheryError &error) {
		printError("createFloat is catching an exception");
	}

	buffer.str("");
	buffer.clear();
	buffer << 0.1;
	try {
		hatchery.createOperand(Double, buffer.str());
	} catch (const HatcheryError &error) {
		printError("createDouble is catching an exception");
	}
}
