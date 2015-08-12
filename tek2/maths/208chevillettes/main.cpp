/* 
* @Author: gicque_p
* @Date:   2015-05-19 21:08:09
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-05-20 09:11:43
*/

#include <iostream>
#include <sstream>
#include <vector>

#include "Core.hpp"
using namespace std;

void usage(char **argv) {
    cout << argv[0] << ": <o0> <o1> <o2> <o3> <o4> <o5> <o6> <o7> <o8+>" << endl;
}

int main(int argc, char **argv) {
    if (argc != 10) {
        usage(argv);
        return -1;
    } else {
        Core core;

        try {
            core.init(argc, argv);
            core.run();
            core.end();
        } catch (const Exception &exception) {
            cerr << exception.what() << endl;
            return -1;
        }

        return 0;
    }
}
