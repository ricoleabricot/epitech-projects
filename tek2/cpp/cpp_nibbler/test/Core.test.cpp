/* 
* @Author: gicque_p
* @Date:   2015-03-11 15:41:25
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-03-11 23:24:46
*/

#include "UnitTests.hpp"
#include "Core.hpp"

void testCtor(void);
void testStart(void);
void testRun(void);
void testStop(void);

void testsCore(void) {
	testCtor();
	testStart();
	testRun();
	testStop();
}

void testCtor(void) {
	bool status = false;

	try {
		Core core(0, 0, "./lib_nibbler_ncurses.so");
	} catch (const CoreError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("Constructor is not catching an exception as it ought to be");
	}

	try {
		Core core(10, 10, "./lib_nibbler_ncurses.so");
	} catch (const CoreError &error) {
		printError("Constructor is catching an exception");
	}
}

void testStart(void) {
	Core core(10, 10, "./unknow_library.so");
	bool status = false;

	try {
		core.start();
	} catch (const CoreError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("Start method is not catching an exception as it ought to be");
	}
}

void testRun(void) {
	Core core(10, 10, "./lib_nibbler_ncurses.so");
	bool status = false;
	
	try {
		core.run();	
	} catch (const CoreError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("Run method is not catching an exception as it ought to be");
	}
}

void testStop(void) {
	Core core(10, 10, "./lib_nibbler_ncurses.so");
	bool status = false;

	try {
		core.stop();
	} catch (const Error &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("End method is not catching an exception as it ought to be");
	}

	core.start();
	try {
		core.stop();
	} catch (const Error &error) {
		printError("Stop method is catching an exception");
	}
}