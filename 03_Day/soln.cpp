#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using std::cout;
using std::endl;
using std::string;


int part1() {
    std::ifstream iptfile ("input.txt");
    string linestr;

    int total_priority = 0;

    while (std::getline(iptfile, linestr)) {
        std::unordered_set<char> l_set;
        char found_char;
        for (int i = 0; i < linestr.length() / 2; i++) {
            l_set.insert(linestr[i]);
        }
        for (int i = linestr.length() / 2; i < linestr.length(); i++) {
            if (l_set.count(linestr[i])) {
                found_char = linestr[i];
                break;
            }
        }

        int priority = 0;
        if ((int)found_char > 96) {
            priority = (int)found_char - 96;
        } else {
            priority = (int)found_char - 64 + 26;
        }
        total_priority += priority;
    }

    return total_priority;
}

int part2() {
    std::ifstream iptfile ("input.txt");
    string linestr;

    int total_priority = 0;

    int spinner = 0;
    std::unordered_set<char> a_set;
    std::unordered_set<char> b_set;
    while (std::getline(iptfile, linestr)) {
        if (spinner == 0) {
            a_set = {};
            b_set = {};

            for (auto v : linestr) {
                a_set.insert(v);
            }
        } else if (spinner == 1) {
            for (auto v: linestr) {
                if (a_set.count(v)) {
                    b_set.insert(v);
                }
            }
        } else if (spinner == 2) {
            for (auto v: linestr) {
                if (b_set.count(v)) {

                    int priority = 0;
                    if ((int)v > 96) {
                        priority = (int)v - 96;
                    } else {
                        priority = (int)v - 64 + 26;
                    }
                    total_priority += priority;
                    break;
                }
            }
        }
        spinner = (spinner + 1) % 3;
    }
    return total_priority;
}

int main() {
    std::cout << "Part1: \n" << part1() << std::endl;
    std::cout << "Part2: \n" << part2() << std::endl;
    return 0;
}
