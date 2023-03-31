#include <gtest/gtest.h>

#include <iostream>

#include "cappuccino.h"
#include "espresso_based.h"
#include "ingredient.h"
#include "mocha.h"
#include "sub_ingredients.h"

using namespace std;

int main(int argc, char **argv) {
    if (0)  // make false to run unit-tests
    {
        // debug section
        Cappuccino cappuccino;
        cappuccino.add_side_item(new Water{1});
        Cappuccino equal;
        equal.add_side_item(new Sugar{1});
        equal = cappuccino;
        cout << string(10,'+') << endl;
        cout << equal.price() << endl;
        cout << string(10,'+') << endl;
    } else {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}