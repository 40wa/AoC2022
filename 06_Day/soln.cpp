#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <unordered_set>
#include <unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::deque;
using std::unordered_set;
using std::unordered_map;


int part1() {
    std::ifstream iptfile ("input.txt");
    string linestr;

    unordered_map<char, int> charmap;
    deque<char> dq;


    while (std::getline(iptfile, linestr) && linestr != "") {

        for (int i=0; i < 3; i++) {
            char c = linestr.at(i);
            auto loc = charmap.find(c);
            if (loc == charmap.end()) {
                charmap[c] = 1;
            } else {
                charmap[c]++;
            }
            dq.push_back(c);
        }

        for (int i=3; i < linestr.length(); i++) {
            //for (const auto& elem : charmap) {
            //    cout << elem.first << '|' << elem.second << endl;
            //}
            //cout << endl;

            char c = linestr.at(i);
            if (charmap.find(c) == charmap.end() && charmap.size() == 3) {
                return i+1;
            }

            auto loc = charmap.find(c);
            if (loc == charmap.end()) {
                charmap[c] = 1;
            } else {
                charmap[c]++;
            }
            dq.push_back(c);
            auto frontloc = charmap.find(dq.front());
            charmap[dq.front()]--;
            if (charmap[dq.front()] == 0) {
                charmap.erase(dq.front());
            }
            dq.pop_front();
        }
        cout << endl;
    }

    return -1;
}

int part2() {
    std::ifstream iptfile ("input.txt");
    string linestr;

    unordered_map<char, int> charmap;
    deque<char> dq;

    int dist_chars = 14;
    while (std::getline(iptfile, linestr) && linestr != "") {

        for (int i=0; i < dist_chars-1; i++) {
            char c = linestr.at(i);
            auto loc = charmap.find(c);
            if (loc == charmap.end()) {
                charmap[c] = 1;
            } else {
                charmap[c]++;
            }
            dq.push_back(c);
        }

        for (int i=dist_chars; i < linestr.length(); i++) {
            //for (const auto& elem : charmap) {
            //    cout << elem.first << '|' << elem.second << endl;
            //}
            //cout << endl;

            char c = linestr.at(i);
            if (charmap.find(c) == charmap.end() && charmap.size() == dist_chars-1) {
                return i+1;
            }

            auto loc = charmap.find(c);
            if (loc == charmap.end()) {
                charmap[c] = 1;
            } else {
                charmap[c]++;
            }
            dq.push_back(c);
            auto frontloc = charmap.find(dq.front());
            charmap[dq.front()]--;
            if (charmap[dq.front()] == 0) {
                charmap.erase(dq.front());
            }
            dq.pop_front();
        }
        cout << endl;
    }

    return -1;
}

int main() {
    std::cout << "Part1: \n" << part1() << std::endl;
    std::cout << "Part2: \n" << part2() << std::endl;
    return 0;
}
