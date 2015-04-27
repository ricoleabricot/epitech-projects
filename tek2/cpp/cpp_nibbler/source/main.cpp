/* 
* @Author: gicque_p
* @Date:   2015-03-09 14:43:43
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-04-03 11:58:42
*/

#include <iostream>
#include <sstream>

#include "OpenGL.hpp"

#include "Core.hpp"
#include "Misc.hpp"

int main(int argc, char **argv) {
	if (argc != 4) {
		Misc::usage(argv);
		return -1;
	} else {
		std::istringstream sx(argv[1]);
		std::istringstream sy(argv[2]);
		int x;
		int y;

		sx >> x;
		sy >> y;

		try {
			Core game(x, y, argv[3]);

			game.start();
			game.run();
			game.stop();
			game.highScore();
		} catch (const Error &error) {
			std::cerr << error.where() << ": " << error.what() << std::endl;
			return -1;
		} catch (const std::exception &error) {
			std::cerr << "std::exception: " << error.what() << std::endl;
			return -1;
		}

		return 0;
	}
}
