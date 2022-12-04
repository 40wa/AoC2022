#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;


int part1() {
    std::ifstream iptfile ("input.txt");
    string linestr;

    int score = 0;
    while (std::getline(iptfile, linestr)) {
        vector<int> vals;
        int prev_idx = 0;
        int found_idx = 0;
        while ((found_idx = linestr.find_first_of("-,", found_idx)) != string::npos) {
            vals.push_back(std::stoi(linestr.substr(prev_idx, found_idx)));
            prev_idx = found_idx+1;
            found_idx++;
        }
        vals.push_back(std::stoi(linestr.substr(prev_idx, linestr.length())));

        if ((vals[0] <= vals[2]) && (vals[1] >= vals[3])) {
            score++;
        } else if ((vals[2] <= vals[0]) && (vals[3] >= vals[1])) {
            score++;
        }
    }
    return score;
}

int part2() {
    std::ifstream iptfile ("input.txt");
    string linestr;

    int score = 0;
    while (std::getline(iptfile, linestr)) {
        vector<int> vals;
        int prev_idx = 0;
        int found_idx = 0;
        while ((found_idx = linestr.find_first_of("-,", found_idx)) != string::npos) {
            vals.push_back(std::stoi(linestr.substr(prev_idx, found_idx)));
            prev_idx = found_idx+1;
            found_idx++;
        }
        vals.push_back(std::stoi(linestr.substr(prev_idx, linestr.length())));

        if ((vals[0] <= vals[3]) && (vals[1] >= vals[2])) {
            score++;
        } else if ((vals[2] <= vals[1]) && (vals[3] >= vals[0])) {
            score++;
        }
    }
    return score;
}

int main() {
    std::cout << "Part1: \n" << part1() << std::endl;
    std::cout << "Part2: \n" << part2() << std::endl;
    return 0;
}
