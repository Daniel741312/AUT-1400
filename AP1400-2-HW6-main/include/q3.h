#ifndef Q3_H
#define Q3_H
#include <regex>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <fstream>
#include <stdexcept>

namespace q3{

static size_t time_conversion(const std::string& time) {
	std::string pattern = "(\\d+)h(\\d*)m*";
	std::regex reg(pattern);
	std::smatch result;
	size_t res = 0;
	if (std::regex_match(time, result, reg)) {
		res += stoi(result[1]) * 60;
		if (result[2] != "")  {
			res += stoi(result[2]);
		}
	}
	return res;
}

static std::vector<std::string> split(const std::string& str) {
	std::vector<std::string> res;
	std::string s = "";
	for (char ch : str) {
		if (ch != ',') {
			s.push_back(ch);
		} else {
			res.push_back(s);
			s = "";
		}
	}
	res.push_back(s);
	return res;
}

struct Flight {
	Flight(const std::string& item) {
		std::string pattern = "\\d- flight_number:(.+) - duration:(.+) - connections:(\\d+) - connection_times:(.+) - price:(\\d+)";
		std::regex reg(pattern);
		std::smatch result;
		if (std::regex_search(item,result, reg)) {
			flight_number = result[1];
			duration = time_conversion(result[2]);
			connections = stoi(result[3]);

			std::vector<std::string> vecs = split(result[4]);
			connection_times = 0;
			for (const auto& i : vecs) {
				connection_times += time_conversion(i);
			}
			price = stoi(result[5]);
		}
		sum = duration + connection_times + 3 * price;
	}
	std::string flight_number;
	size_t duration;
	size_t connections;
	size_t connection_times;
	size_t price;
	size_t sum;
	bool operator<(const Flight& f) const {	//MUST be const !!!
		return sum >= f.sum;
	}
};

std::priority_queue<Flight> gather_flights(const std::string& filename) {
    std::priority_queue<Flight> pq{};
	std::ifstream ifs(filename, std::ios::in);
	if (!ifs) {
		throw std::runtime_error("can't open file filghts.txt");
	}
	char buf[256];
	while (ifs.getline(buf, 256)) {
		std::string item(buf);
		if (item.back() == '\r') {
			item.pop_back();
		}
		pq.push(Flight(item));
	}
    return pq;
}

}

#endif //Q3_H