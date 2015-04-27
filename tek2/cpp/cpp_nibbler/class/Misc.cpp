/* 
* @Author: gicque_p
* @Date:   2015-03-09 16:53:24
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-03-09 17:47:12
*/

#include "Misc.hpp"

void Misc::usage(char **argv) {
	std::cerr << argv[0] << ": ";
	std::cerr << "width_map height_map lib_nibbler_dynlib.so";
	std::cerr << std::endl;
}
