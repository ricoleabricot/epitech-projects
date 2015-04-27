/* 
* @Author: gicque_p
* @Date:   2015-04-16 15:45:46
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-04-16 15:48:18
*/

#include "Misc.hpp"
#include "UnitTests.hpp"

void testTrim(void);

void testsMisc(void) {
	testTrim();
}

void testTrim(void) {
	std::string firstString("Coucou je m'appelle Kafei");
	std::string firstTrim("Coucou je m'appelle Kafei");

	if (UnitTests::isNotEqual(firstString, firstTrim)) {
		printError("Trim method is not functionnal on normal string");
	}

	std::string secondString("     	 		 Coucou je suis un test 	 	 	");
	std::string secondTrim("Coucou je suis un test");

	if (UnitTests::isNotEqual(firstString, firstTrim)) {
		printError("Trim method is not triming string");
	}
}