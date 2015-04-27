/* 
* @Author: gicque_p
* @Date:   2015-02-18 17:01:39
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-23 11:44:07
*/

#include "UnitTests.hpp"
#include "Memory.hpp"
#include "Hatchery.hpp"
#include "Core.hpp"

static void testPop(void);
static void testPush(void);
static void testPopInstruction(void);
static void testPushInstruction(void);

void testsMemory(void) {
	testPop();
	testPush();
	testPopInstruction();
	testPushInstruction();
}

void testPop(void) {
	Memory memory;
	Hatchery hatchery;
	IOperand *operand = hatchery.createOperand(Int8, "42");

	memory.push(operand);
	try {
		memory.pop();
	} catch (const std::exception &error) {
		printError("Pop method is catching an exception");
	}

	if (UnitTests::isNotEqual((int)memory.getStack().size(), 0)) {
		printError("Pop method is not deleting elements in the stack");
	}
}

void testPush(void) {
	Memory memory;
	Hatchery hatchery;
	IOperand *firstOperand = hatchery.createOperand(Int8, "8");
	IOperand *secondOperand = hatchery.createOperand(Double, "42.85");
	IOperand *thirdOperand = hatchery.createOperand(Int16, "42.50");

	try {
		memory.push(firstOperand);
	} catch (const std::exception &error) {
		printError("Push method is catching an exception");
	}

	if (UnitTests::isNotEqual(memory.getStack().top()->toString(), "8")) {
		printError("Push method is not inserting the right value");
	}

	try {
		memory.push(secondOperand);
	} catch (const std::exception &error) {
		printError("Push method is catching an exception");
	}

	if (UnitTests::isNotEqual(memory.getStack().top()->toString(), "42.85")) {
		printError("Push method is not inserting the right value");
	}

	try {
		memory.push(thirdOperand);
	} catch (const std::exception &error) {
		printError("Push method is catching an exception");
	}

	if (UnitTests::isNotEqual(memory.getStack().top()->toString(), "42")) {
		printError("Push method is not inserting the right value");
	}
}

void testPopInstruction(void) {
	Memory memory;
	Hatchery hatchery;
	IOperand *operand = hatchery.createOperand(Int8, "42");

	memory.pushInstruction(&Core::push, operand);
	try {
		memory.popInstruction();
	} catch (const std::exception &error) {
		printError("PopInstruction method is catching an exception");
	}

	if (UnitTests::isNotEqual((int)memory.getQueue().size(), 0)) {
		printError("Pop method is not deleting elements in the stack");
	}
}

void testPushInstruction(void) {
	Memory memory;
	Hatchery hatchery;
	IOperand *operand = hatchery.createOperand(Int8, "42");

	try {
		memory.pushInstruction(&Core::push, operand);
	} catch (const std::exception &error) {
		printError("PopInstruction method is catching an exception");
	}

	if (UnitTests::isNotEqual((int)memory.getQueue().size(), 1)) {
		printError("Pop method is not deleting elements in the stack");
	}
}
