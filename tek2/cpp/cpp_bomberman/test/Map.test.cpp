/* 
* @Author: gicque_p
* @Date:   2015-05-29 15:35:19
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-06-01 17:37:21
*/

#include "Map.hh"
#include "Bomb.hh"
#include "Floor.hh"
#include "UnitTests.hh"

void testAddItem(void);
void testDeleteItem(void);
void testUpdate(void);

void testsMap(void) {
    testAddItem();
    testDeleteItem();
}

void testAddItem(void) {
    Map map;

    if (UnitTests::isNotEqual(0, (int)map.getItems().size())) {
        printError("AddItem method does not have an empty list of items at first use");
    }

    AItem *firstBomb = new Bomb();
    AItem *secondBomb = new Bomb();

    map.addItem(firstBomb);
    map.addItem(secondBomb);

    if (UnitTests::isNotEqual(2, (int)map.getItems().size())) {
        printError("AddItem method does not insert a correct number of items");
    }

    if (UnitTests::isNotEqual(1, map.getItems().back()->getHp())) {
        printError("AddItem method does not insert items correctly")
    }
}

void testDeleteItem(void) {
    Map map;

    if (UnitTests::isNotEqual(0, (int)map.getItems().size())) {
        printError("DeleteItem method does not have an empty list of items at first use");
    }

    AItem *firstItem = new Bomb();
    AItem *secondItem = new Floor();

    map.addItem(firstItem);
    map.addItem(secondItem);

    map.deleteItem(firstItem);

    if (UnitTests::isNotEqual(1, (int)map.getItems().size())) {
        printError("DeleteItem method does not delete a correct number of items");
    }

    if (UnitTests::isNotEqual(0, map.getItems().back()->getHp())) {
        printError("DeleteItem method does not delete items correctly")
    }
}
