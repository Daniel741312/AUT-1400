#include "server.h"

#include "client.h"

//global varibles should be defined in the source file
std::vector<std::string> pending_trxs;

Server::Server() {
}

std::shared_ptr<Client> Server::add_client(std::string id) {
	std::default_random_engine e;
	std::uniform_int_distribution u(0, 9);
	std::string tail = "";
	for (int i = 0; i < 4; ++i) {
		tail += std::to_string(u(e));
	}
	for (const auto& c : clients) {
		if (c.first->get_id() == id) {
			id += tail;
		}
	}
	auto cli = std::make_shared<Client>(id, *this);
	clients[cli] = 5;
	return cli;
}

std::shared_ptr<Client> Server::get_client(std::string id) const {
	for (const auto& c : clients) {
		if (c.first->get_id() == id) {
			return c.first;
		}
	}
	return nullptr;
}

double Server::get_wallet(std::string id) const {
	for (const auto& c : clients) {
		if (c.first->get_id() == id) {
			return c.second;
		}
	}
	return 0;
}

bool Server::parse_trx(const std::string& trx, std::string& sender, std::string& receiver, double& value) {
	std::string pattern = "(\\w+)-(\\w+)-(\\d+\\.\\d+)";
	std::regex r(pattern);
	std::smatch results;
	if (std::regex_match(trx, results, r)) {
		sender = results.str(1);
		receiver = results.str(2);
		value = std::stod(results.str(3));
		return true;
	} else {
		throw std::runtime_error("trx doesn't match format");
	}
	return false;
}

bool Server::add_pending_trx(std::string trx, std::string signature) const {
	std::string sender, receviver;
	double value;
	Server::parse_trx(trx, sender, receviver, value);
	auto p_recevier = get_client(receviver);
	auto p_sender = get_client(sender);
	if (p_recevier == nullptr)
		return false;

	bool authentic = crypto::verifySignature(p_sender->get_publickey(), trx, signature);
	if (authentic && value <= clients.at(p_sender)) {
		pending_trxs.push_back(trx);
		return true;
	}
	return false;
}

size_t Server::mine() {
	std::string mempool{};
	for (const auto& trx : pending_trxs) {
		mempool += trx;
	}
	size_t nonce = 0;
	bool flag = false;  //not mined
	while (!flag) {
		for (auto& c_w : clients) {
			nonce = c_w.first->generate_nonce();
			if (crypto::sha256(mempool + std::to_string(nonce)).substr(0, 10).find("000") != std::string::npos) {   //mined
                flag = true;
				c_w.second += 6.25;
				for (const auto& trx : pending_trxs) {
					std::string sender, receiver;
					double value;
					Server::parse_trx(trx, sender, receiver, value);
					clients[get_client(sender)] -= value;
					clients[get_client(receiver)] += value;
				}
				pending_trxs.clear();
                return nonce;
			}
		}
	}
	return nonce;
}

using MPD = std::map<std::shared_ptr<Client>, double>;
void show_wallets(const Server& server) {
	std::cout << std::string(20, '*') << std::endl;
    /*
        * a hack way to visit the private member varible of server
        * constrained by the rule, which doesn't allow us to modify `class Server`
    */
	for (const auto& client : *((MPD*)&server)) 
		std::cout << client.first->get_id() << " : " << client.second << std::endl;
	std::cout << std::string(20, '*') << std::endl;
}