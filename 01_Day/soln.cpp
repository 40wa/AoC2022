#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int part_one() {
    std::ifstream iptfile ("inputdos.txt");
    std::string linestr;

    std::vector<int> vals;
    vals.push_back(0);
    int ctr = 0;
    while (std::getline(iptfile, linestr)) {
        try {
            vals[vals.size() - 1] += std::stoi(linestr);
        } catch (...) {
            vals.push_back(0);
        }

        ctr++;
    }

    //for (auto v: vals) {
    //    std::cout << v << ' ';
    //}
    //std::cout << '\n';

    int m = *std::max_element(vals.begin(), vals.end());
    return m;
}

int part_two() {
    std::ifstream iptfile ("inputdos.txt");
    std::string linestr;

    std::vector<int> vals;
    vals.push_back(0);
    int ctr = 0;
    while (std::getline(iptfile, linestr)) {
        try {
            vals[vals.size() - 1] += std::stoi(linestr);
        } catch (...) {
            vals.push_back(0);
        }

        ctr++;
    }

    sort(vals.begin(), vals.end());
    //for (auto v: vals) {
    //    std::cout << v << ' ';
    //}
    //std::cout << '\n';

    int end_sum = 0;
    for (int i = 0; i < 3; i++) {
        end_sum += vals[vals.size() - 1 - i];
    }
    return end_sum;
}

int main() {
    int p1 = part_one();
    std::cout << "part one: " << p1 << '\n';

    int p2 = part_two();
    std::cout << "part two: " << p2 << '\n';
}
