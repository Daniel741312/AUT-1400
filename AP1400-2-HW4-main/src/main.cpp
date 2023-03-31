#include <iostream>
#include <gtest/gtest.h>
#include "unique_ptr.h"
//#include "shared_ptr.hpp"
using namespace std;

int main(int argc, char **argv)
{
    if (0) // make false to run unit-tests
    {
        // debug section 
    }
    else
    {
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