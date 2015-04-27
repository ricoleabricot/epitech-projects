/* 
* @Author: gicque_p
* @Date:   2015-02-13 14:23:08
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-23 15:03:44
*/

#include "UnitTests.hpp"
#include "Core.hpp"
#include "Hatchery.hpp"

static void testPush(void);
static void testPop(void);
static void testDump(void);
static void testAssert(void);
static void testAdd(void);
static void testSub(void);
static void testMul(void);
static void testDiv(void);
static void testMod(void);
static void testPrint(void);

void testsCore(void) {
	testPush();
	testPop();
	testDump();
	testAssert();
	testAdd();
	testSub();
	testMul();
	testDiv();
	testMod();
	testPrint();
}

void testPush(void) {
	Core core;
	Hatchery hatchery;
	IOperand *firstOperand = hatchery.createOperand(Int8, "8");
	IOperand *secondOperand = hatchery.createOperand(Double, "42.85");
	IOperand *thirdOperand = hatchery.createOperand(Int16, "42.50");

	try {
		core.push(firstOperand);
	} catch (const std::exception &error) {
		printError("Push method is catching an exception");
	}

	if (UnitTests::isNotEqual(core.getMemory().getStack().top()->toString(), "8")) {
		printError("Push method is not inserting the right value");
	}

	try {
		core.push(secondOperand);
	} catch (const std::exception &error) {
		printError("Push method is catching an exception");
	}

	if (UnitTests::isNotEqual(core.getMemory().getStack().top()->toString(), "42.85")) {
		printError("Push method is not inserting the right value");
	}

	try {
		core.push(thirdOperand);
	} catch (const std::exception &error) {
		printError("Push method is catching an exception");
	}

	if (UnitTests::isNotEqual(core.getMemory().getStack().top()->toString(), "42")) {
		printError("Push method is not inserting the right value");
	}
}

void testPop(void) {
	Core firstCore;
	Core secondCore;
	Hatchery hatchery;
	IOperand *operand = hatchery.createOperand(Int8, "42");
	bool status = false;

	firstCore.push(operand);
	try {
		firstCore.pop();
	} catch (const CoreError &error) {
		printError("Pop method is catching an exception");
	}

	status = false;
	try {
		secondCore.pop();
	} catch (const CoreError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("Pop method is not catching an exception as it ought to be");
	}

	if (UnitTests::isNotEqual((int)secondCore.getMemory().getStack().size(), 0)) {
		printError("Pop method is not deleting elements in the stack");
	}
}

void testDump(void) {
	Core core;
	Hatchery hatchery;

	std::stringstream buffer;
	std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

	IOperand *firstOperand = hatchery.createOperand(Int8, "42");
	IOperand *secondOperand = hatchery.createOperand(Int16, "42");
	IOperand *thirdOperand = hatchery.createOperand(Int32, "-42");
	IOperand *fourthOperand = hatchery.createOperand(Float, "42.50");
	IOperand *fifthOperand = hatchery.createOperand(Double, "42.50");

	core.push(firstOperand);
	core.push(secondOperand);
	core.push(thirdOperand);
	core.push(fourthOperand);
	core.push(fifthOperand);

	core.dump();
	std::string dump = buffer.str();
	std::cout.rdbuf(old);

	if (UnitTests::isNotEqual(dump, "42.5\n42.5\n-42\n42\n42\n")) {
		printError("Dump method is not dumping all right values");
	}
}

void testAssert(void) {
	Core core;
	Hatchery hatchery;
	IOperand *firstOperand = hatchery.createOperand(Int8, "42");
	IOperand *secondOperand = hatchery.createOperand(Int16, "42");
	bool status = false;

	core.push(firstOperand);
	try {
		core.assert(firstOperand);
	} catch (const CoreError &error) {
		printError("Assert method is catching an exception");
	}

	status = false;
	try {
		core.assert(secondOperand);
	} catch (const CoreError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("Assert method is not catching an exception as it ought to be");
	}
}

void testAdd(void) {
	Core core;
	Hatchery hatchery;
	IOperand *firstOperand = hatchery.createOperand(Int8, "8");
	IOperand *secondOperand = hatchery.createOperand(Int16,"16");
	IOperand *thirdOperand = hatchery.createOperand(Int32,"-24");
	bool status = false;

	try {
		core.add();
	} catch (const CoreError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("Add method is not catching an exception as it ougth to be");
	}

	core.push(firstOperand);
	core.push(secondOperand);
	status = false;
	try {
		core.add();
	} catch (const CoreError &error) {
		printError("Add method is catching an exception");
	}

	if (UnitTests::isNotEqual((int)core.getMemory().getStack().size(), 1)) {
		printError("Add method is not deleting elements in the stack after the operation");
	}

	if (UnitTests::isNotEqual(core.getMemory().getStack().top()->toString(), "24")) {
		printError("Add method is not adding elements correctly");
	}

	core.push(thirdOperand);
	status = false;
	try {
		core.add();
	} catch (const CoreError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("Add method is not catching an exception as it ougth to be");
	}
}

void testSub(void) {
	Core core;
	Hatchery hatchery;
	IOperand *firstOperand = hatchery.createOperand(Int8, "8");
	IOperand *secondOperand = hatchery.createOperand(Int16, "16");
	IOperand *thirdOperand = hatchery.createOperand(Int32, "8");
	bool status = false;

	try {
		core.sub();
	} catch (const CoreError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("Sub method is not catching an exception as it ougth to be");
	}

	core.push(firstOperand);
	core.push(secondOperand);
	status = false;
	try {
		core.sub();
	} catch (const CoreError &error) {
		printError("Sub method is catching an exception");
	}

	if (UnitTests::isNotEqual((int)core.getMemory().getStack().size(), 1)) {
		printError("Sub method is not deleting elements in the stack after the operation");
	}

	if (UnitTests::isNotEqual(core.getMemory().getStack().top()->toString(), "8")) {
		printError("Sub method is not substribing elements correctly");
	}

	core.push(thirdOperand);
	status = false;
	try {
		core.sub();
	} catch (const CoreError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("Sub method is not catching an exception as it ougth to be");
	}
}

void testMul(void) {
	Core core;
	Hatchery hatchery;
	IOperand *firstOperand = hatchery.createOperand(Int8, "8");
	IOperand *secondOperand = hatchery.createOperand(Int16,"16");
	IOperand *thirdOperand = hatchery.createOperand(Int32,"-1");
	bool status = false;

	try {
		core.mul();
	} catch (const CoreError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("Mul method is not catching an exception as it ougth to be");
	}

	core.push(firstOperand);
	core.push(secondOperand);
	status = false;
	try {
		core.mul();
	} catch (const CoreError &error) {
		printError("Mul method is catching an exception");
	}

	if (UnitTests::isNotEqual((int)core.getMemory().getStack().size(), 1)) {
		printError("Mul method is not deleting elements in the stack after the operation");
	}

	if (UnitTests::isNotEqual(core.getMemory().getStack().top()->toString(), "128")) {
		printError("Mul method is not multiplying elements correctly");
	}

	core.push(thirdOperand);
	status = false;
	try {
		core.mul();
	} catch (const CoreError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("Mul method is not catching an exception as is ougth to be");
	}
}

void testDiv(void) {
	Core core;
	Hatchery hatchery;
	IOperand *firstOperand = hatchery.createOperand(Int8, "8");
	IOperand *secondOperand = hatchery.createOperand(Int16,"16");
	IOperand *thirdOperand = hatchery.createOperand(Int32,"0");
	bool status = false;

	try {
		core.div();
	} catch (const CoreError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("Div method is not catching an exception as it ougth to be");
	}

	core.push(firstOperand);
	core.push(secondOperand);
	status = false;
	try {
		core.div();
	} catch (const CoreError &error) {
		printError("Div method is catching an exception");
	}

	if (UnitTests::isNotEqual((int)core.getMemory().getStack().size(), 1)) {
		printError("Div method is not deleting elements in the stack after the operation");
	}

	if (UnitTests::isNotEqual(core.getMemory().getStack().top()->toString(), "2")) {
		printError("Div method is not multiplying elements correctly");
	}

	core.push(thirdOperand);
	status = false;
	try {
		core.div();
	} catch (const CoreError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("Div method is not catching an exception as it ougth to be");		
	}

	core.push(thirdOperand);
	core.push(firstOperand);
	status = false;
	try {
		core.div();
	} catch (const CoreError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("Div method is not catching an exception as it ougth to be");
	}
}

void testMod(void) {
	Core core;
	Hatchery hatchery;
	IOperand *firstOperand = hatchery.createOperand(Int8, "8");
	IOperand *secondOperand = hatchery.createOperand(Int16, "15");
	bool status = false;

	try {
		core.mod();
	} catch (const CoreError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("Mod method is not catching an exception as it ougth to be");
	}

	core.push(firstOperand);
	core.push(secondOperand);
	status = false;
	try {
		core.mod();
	} catch (const CoreError &error) {
		printError("Mod method is catching an exception");
	}

	if (UnitTests::isNotEqual((int)core.getMemory().getStack().size(), 1)) {
		printError("Mod method is not deleting elements in the stack after the operation");
	}

	if (UnitTests::isNotEqual(core.getMemory().getStack().top()->toString(), "7")) {
		printError("Mod method is not moduling elements correctly");
	}

	core.push(firstOperand);
	core.push(firstOperand);
	try {
		core.mod();
	} catch (const CoreError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("Mod method is not catching an exception as it ougth to be");
	}
}

void testPrint(void) {
	Core core;
	Hatchery hatchery;
	IOperand *firstOperand = hatchery.createOperand(Int8, "42");
	bool status = false;

	std::stringstream buffer;
	std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

	core.push(firstOperand);
	try {
		core.print();
	} catch (const CoreError &error) {
		printError("Print method is catching an exception");
	}
	
	IOperand *secondOperand= hatchery.createOperand(Int8, "97");
	IOperand *thirdOperand = hatchery.createOperand(Int8, "110");
	
	core.push(secondOperand);
	core.print();
	core.push(thirdOperand);
	core.print();

	std::string dump = buffer.str();
	std::cout.rdbuf(old);

	if (UnitTests::isNotEqual(dump, "*\na\nn\n")) {
		printError("Print method is not printing the right characters");
	}

	IOperand *fifthOperand = hatchery.createOperand(Int16,"42");

	core.push(fifthOperand);
	status = false;
	try {
		core.print();
	} catch (const CoreError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("Print method is not catching an exception as it ought to be");
	}
}
