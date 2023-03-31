#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "server.h"
#include "crypto.h"

class Server;

class Client {
public:
	Client(std::string id, const Server& server);
	std::string get_id();
	std::string get_publickey() const;
	double get_wallet() const;
	std::string sign(std::string txt) const;
	bool transfer_money(std::string receiver, double value) const;
	size_t generate_nonce();
private:
	Server const* const server;
	const std::string id;
	std::string public_key;
	std::string private_key;
};

#endif //CLIENT_H