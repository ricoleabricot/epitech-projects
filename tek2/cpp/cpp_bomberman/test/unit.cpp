/* 
* @Author: gicque_p
* @Date:   2015-05-29 14:48:07
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-06-01 17:32:14
*/

#include <iostream>
#include "Exception.hh"

void testsMap(void);
void testsItem(void);

int main() {
    try {
        testsMap();
        // testsItem();
    } catch (const Exception &exception) {
        std::cerr << "Wild exception appears (non-catched): " << exception.what() << std::endl;
        return -1;
    }

    return 0;
}
