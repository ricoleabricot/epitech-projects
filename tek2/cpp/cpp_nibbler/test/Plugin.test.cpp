/* 
* @Author: gicque_p
* @Date:   2015-03-10 14:26:27
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-03-11 16:49:31
*/

#include "UnitTests.hpp"
#include "Plugin.hpp"
#include "IDisplay.hpp"

void testLoad(void);
void testUnload(void);

void testsPlugin(void) {
	testLoad();
	testUnload();
}

void testLoad(void) {
	Plugin<IDisplay> plugin;
	IDisplay *module;
	bool status = false;

	try {
		module = plugin.load("./lib_nibbler_ncurses.so");
	} catch (const PluginError &error) {
		printError("Load method is catching an exception");
	}

	try {
		module = plugin.load("./unknow_file.so");
	} catch (const PluginError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("Load method is not catching an exception as it ought to be");
	}
}

void testUnload(void) {
	Plugin<IDisplay> plugin;
	bool status = false;

	try {
		plugin.unload();
	} catch (const PluginError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("Unload method is not catching an exception as it ought to be");
	}

	plugin.load("./lib_nibbler_ncurses.so");
	try {
		plugin.unload();
	} catch (const PluginError &error) {
		printError("Unload method is catching an exception");
	}
}