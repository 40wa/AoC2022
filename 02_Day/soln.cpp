#include <iostream>
#include <fstream>
#include <string>

int part1() {
    std::ifstream iptfile ("input.txt");
    std::string linestr;

    int score = 0;
    while (std::getline(iptfile, linestr)) {

        char A = 'A';
        char X = 'X';
        int opp_move = (int)linestr[0] - (int)A;
        int rec_move = (int)linestr[2] - (int)X;
        int outcome = (rec_move - opp_move + 3) % 3;

        score += (rec_move + 1);
        score += ((outcome + 1) % 3) * 3;
    }

    return score;
}

int part2() {
    std::ifstream iptfile ("input.txt");
    std::string linestr;

    int score = 0;
    while (std::getline(iptfile, linestr)) {

        char A = 'A';
        char X = 'X';
        int opp_move = (int)linestr[0] - (int)A;
        int outcome = ((int)linestr[2] - (int)X + 2) % 3;
        int rec_move = (opp_move + outcome) % 3;

        score += (rec_move + 1);
        score += ((outcome + 1) % 3) * 3;
        ctr++;
    }

    return score;
}

int main() {
    std::cout << "Part1: \n" << part1() << std::endl;
    std::cout << "Part2: \n" << part2() << std::endl;
    return 0;
}
