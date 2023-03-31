#ifndef Q2_H
#define Q2_H
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <exception>

namespace q2{

struct Patient {
    Patient(std::string item) {
        if (item.back() == '\r') item.pop_back();
        std::vector<std::string> vecs;
        std::string str{};
        for (auto ch : item) {
            if (ch == ' ') {
                continue;
            } else if (ch != ',') {
                str += ch;
            } else {
                vecs.push_back(str);
                str = "";
            }
        }
        vecs.push_back(str);
        name = vecs[0] + " " + vecs[1];
        age = stoi(vecs[2]);
        smokes = stoi(vecs[3]);
        area_q = stoi(vecs[4]);
        alkhol = stoi(vecs[5]);
        risk = 3 * age + 5 * smokes + 2 * area_q + 4 * alkhol;
    }
    std::string name;
    size_t age;
    size_t smokes;
    size_t area_q;
    size_t alkhol;
    size_t risk;
    bool operator<(const Patient& p) const {
        return risk >= p.risk;
    }
};

std::vector<Patient> read_file(const std::string& filename) {
    std::ifstream ifs(filename, std::ios::in);
    if (!ifs) {
        throw std::runtime_error("open file error");
    }
    int i = 0;
    char buf[100];
    std::vector<Patient> vecp;

    while (ifs.getline(buf, 100)) {
        if (i++ < 2) continue;
        vecp.push_back(Patient(buf));
    }

    ifs.close();
    return vecp;
}

void sort(std::vector<Patient>& vecp) {
    std::sort(vecp.begin(), vecp.end());
    /*
    std::sort(vecp.begin(), vecp.end(), 
                [](const Patient& p1, const Patient& p2) -> bool{
                    return p1.risk >= p2.risk;
                });
    */
}


}
#endif  // Q2_H