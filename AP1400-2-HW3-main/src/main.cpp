#include <gtest/gtest.h>

#include <iostream>

#include "bst.h"
using namespace std;

int main(int argc, char **argv) {
	if (0)	// make false to run unit-tests
	{
		// debug section
		BST bst1{5, 1, 10, 2, 8, 50, 4, 60};
		BST bst2{3, 2, 100, 20, 8, 50, 4, 60, 44, 23};
		auto v = (*bst1.find_successor(5))->value;
		auto l = bst2.length();

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