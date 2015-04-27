/* 
* @Author: gicque_p
* @Date:   2015-04-14 11:34:29
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-04-21 17:43:11
*/

#include "Log.hpp"
#include "UnitTests.hpp"

void testOpenIn(void);
void testOpenOut(void);
void testDisplay(void);

void testsLog(void) {
	testOpenOut();
	testOpenIn();
	testDisplay();
}

void testOpenOut(void) {
	Log firstLog("file.test.log");

	try {
		firstLog.openOut();
		firstLog.close();
	} catch (const LogError &error) {
		printError("OpenOut method is catching an exception");
	}
}

void testOpenIn(void) {
	Log firstLog("prout.test.log");
	bool flag(false);

	try {
		firstLog.openIn();
		firstLog.close();
	} catch (const LogError &error) {
		flag = true;
	}

	if (UnitTests::isFalse(flag)) {
		printError("OpenIn method is not catching an exception as it ought to be");
	}

	Log secondLog("file.test.log");

	try {
		secondLog.openIn();
		secondLog.close();
	} catch (const LogError &error) {
		printError("OpenIn method is catching an exception");
	}
}

void testDisplay(void) {
	Log firstLog("file.test.log");
	std::stringstream buffer;
	std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

	firstLog.write("Je suis un fichier de log");
	firstLog.display();

	if (UnitTests::isNotEqual(buffer.str(), "Je suis un fichier de log\n")) {
		printError("Display method is not printing the right log");
	}

	remove("file.test.log");
	std::cout.rdbuf(old);
}
