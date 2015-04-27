/* 
* @Author: gicque_p
* @Date:   2015-02-18 11:02:02
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-21 19:25:27
*/

#include "UnitTests.hpp"
#include "Parsing.hpp"
#include "Core.hpp"

// static void testGetGrammar(void);
static void testGetCommands(void);
static void testCommandLine(void);
static void testCheckElements(void);
static void testIsNumber(void);

void	testsParsing(void) {
	testGetCommands();
	testCommandLine();
	testCheckElements();
	testIsNumber();
	// testGetGrammar();
}

void testGetCommands(void) {
	Parsing firstParsing;
	Parsing secondParsing;
	Parsing thirdParsing;
	Parsing fourthParsing;
	Parsing fifthParsing;
	Parsing sixthParsing;
	Core core;
	bool status = false;

	status = false;
	try {
		std::ifstream file("test/data/wrongexample1.avm");
		firstParsing.getCommands(file, &core);
	} catch (const ParsingError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("getCommands is not catching an exception as it ougth to be");
	}

	status = false;
	try {
		std::ifstream file("test/data/wrongexample2.avm");
		secondParsing.getCommands(file, &core);
	} catch (const ParsingError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("getCommands is not catching an exception as it ougth to be");
	}

	status = false;
	try {
		std::ifstream file("test/data/wrongexample3.avm");
		thirdParsing.getCommands(file, &core);
	} catch (const ParsingError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("getCommands is not catching an exception as it ougth to be");
	}

	status = false;
	try {
		std::ifstream file("test/data/wrongexample4.avm");
		fourthParsing.getCommands(file, &core);
	} catch (const ParsingError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("getCommands is not catching an exception as it ougth to be");
	}

	status = false;
	try {
		std::ifstream file("test/data/wrongexample5.avm");
		fifthParsing.getCommands(file, &core);
	} catch (const ParsingError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("getCommands is not catching an exception as it ougth to be");
	}

	try {
		std::ifstream file("test/data/example.avm");
		sixthParsing.getCommands(file, &core);
	} catch (const ParsingError &error) {
		printError("getCommands method is catching an exception");		
	}

}

static void testCommandLine(void) {
	Parsing parsing;
	Core core;
	bool status = false;

	try {
		parsing.commandLine("push", &core);
	} catch (const ParsingError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("commandLine method is not catching an exception as it ougth to be");
	}

	status = false;
	try {
		parsing.commandLine("push int32", &core);
	} catch (const ParsingError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("commandLine method is not catching an exception as it ougth to be");
	}

	status = false;
	try {
		parsing.commandLine("push lol(32)", &core);
	} catch (const ParsingError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("commandLine method is not catching an exception as it ougth to be");
	}

	status = false;
	try {
		parsing.commandLine("push int32(32a)", &core);
	} catch (const ParsingError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("commandLine method is not catching an exception as it ougth to be");
	}

	status = false;
	try {
		parsing.commandLine("dump 44", &core);
	} catch (const ParsingError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("commandLine method is not catching an exception as it ougth to be");
	}

	status = false;
	try {
		parsing.commandLine("dump 44", &core);
	} catch (const ParsingError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("commandLine method is not catching an exception as it ougth to be");
	}

	try {
		parsing.commandLine("push double(33);", &core);
	} catch (const ParsingError &error) {
		printError("commandLine method is catching an exception");
	}
}

static void testCheckElements(void) {
	Parsing parsing;
	bool status = false;

	try {
		parsing.checkElements("pop");
	} catch (const ParsingError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("checkElements method is not catching an exception as it ougth to be");
	}

	status = false;
	try {
		parsing.checkElements("add");
	} catch (const ParsingError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("checkElements method is not catching an exception as it ougth to be");
	}

	parsing.checkElements("push");
	try {
		parsing.checkElements("pop");
	} catch (const ParsingError &error) {
		printError("checkElements method is catching an exception");
	}
}

static void testIsNumber(void) {
	Parsing parsing;
	bool status = false;

	try {
		parsing.isNumber("42");
	} catch (const ParsingError &error) {
		printError("isNumber method is catching an exception");
	}

	try {
		parsing.isNumber("42.42");
	} catch (const ParsingError &error) {
		printError("isNumber method is catching an exception");
	}

	try {
		parsing.isNumber("42a");
	} catch (const ParsingError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("isNumber method is not catching an exception as it ougth to be");
	}
}
