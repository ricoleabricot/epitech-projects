/* 
* @Author: gicque_p
* @Date:   2015-02-12 09:59:22
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-23 11:38:09
*/

#include "Parsing.hpp"
#include "Core.hpp"

int main(int argc, char **argv) {
	Parsing parsing;
	Core core;

	try {
		if (argc > 1) {
			std::ifstream file(argv[1]);
			parsing.getCommands(file, &core);
		} else {
			parsing.getCommands(std::cin, &core);
		}
	} catch (const ParsingError &error) {
		std::cerr << error.what() << std::endl;
		return -1;
	}

	try {
		core.execute();
	} catch (const CoreError &error) {
		std::cerr << error.what() << std::endl;
		return -1;
	}

	return 0;
}