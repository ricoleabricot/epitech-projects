/* 
* @Author: gicque_p
* @Date:   2015-05-15 16:25:36
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-05-19 12:36:24
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Core.hpp"
using namespace std;

void usage(char **argv) {
    cout << argv[0] << ": <region_code> [...]" << endl;
}

int main(int argc, char **argv, char **envp) {
    if (argc < 2) {
        usage(argv);
        return -1;
    } else {
        Core core;

        try {
            core.init(argc, argv, envp);
            core.run();
            core.end();
        } catch (const Exception &error) {
            cerr << "\033[1;31m" << error.what() << "\033[0m" << endl;
            return -1;
        }
            
        return 0;
    }
}
