#include <gtest/gtest.h>

#include <iostream>

#include "client.h"
#include "server.h"
using namespace std;

void show_pending_transactions() {
	std::cout << std::string(20, '*') << std::endl;
	for (const auto& trx : pending_trxs)
		std::cout << trx << std::endl;
	std::cout << std::string(20, '*') << std::endl;
}

int main(int argc, char** argv) {
	if (false)  // make false to run unit-tests
	{
		Server server{};
		pending_trxs.clear();
		auto bryan{server.add_client("bryan")};
		auto clint{server.add_client("clint")};
		auto sarah{server.add_client("sarah")};

		std::string mempool{};
		for (const auto& trx : pending_trxs)
			mempool += trx;

		show_wallets(server);
		size_t nonce{server.mine()};
		show_wallets(server);

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