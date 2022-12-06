#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;


string part1() {
    std::ifstream iptfile ("input.txt");
    string linestr;

    int stack_count = 9;
    vector<char> stacks[stack_count];
    std::fill_n(stacks, stack_count, vector<char>());
    while (std::getline(iptfile, linestr) && linestr != "") {
        if (linestr[1] == '1') {
            break;
        }
        for (int i = 0; i < stack_count; i++) {

            if ((i*4 + 1 < linestr.length()) && linestr[i*4 + 1] != ' ') {
                //stacks[i].push_back(linestr[i*4 + 1]);
                stacks[i].insert(stacks[i].begin(), linestr[i*4 + 1]);
            }
        }
        cout << linestr << endl;
    }

    for (int i=0; i < stack_count; i++) {
        vector<char> stk = stacks[i];
        cout << i+1 << ") ";
        for (auto item : stk) {
            cout << item << ' ';
        }
        cout << endl;
    }



    // Skip the empty line
    std::getline(iptfile, linestr);
    while (std::getline(iptfile, linestr) && linestr != "") {
        vector<int> vals;
        int prev = 0;
        int pos = 0;

        //cout << linestr << endl;
        while ((pos = linestr.find(' ', pos)) != string::npos) {
            //cout << '<' << prev << '_' << pos << '>';
            //cout << '|' << linestr.substr(prev, pos-prev) << '|';
            if (std::all_of(linestr.begin() + prev, linestr.begin() + pos, ::isdigit)) {
                //cout << linestr.substr(prev, pos-prev) << '|';
                vals.push_back(std::stoi(linestr.substr(prev, pos-prev)));
            }
            //cout << linestr.substr(prev, pos-prev) << '|';
            prev = pos + 1;
            pos++;
        }
        //cout << '[' << prev << '_' << pos << ']' << linestr.substr(prev, linestr.length() - prev) << endl;
        //cout << linestr.substr(prev, linestr.length() - prev) << endl;
        vals.push_back(std::stoi(linestr.substr(prev, linestr.length() - prev)));

        cout << endl;
        for (auto v: vals) {
            cout << v << ' ';
        }
        cout << endl;
        for (int i=0; i < stack_count; i++) {
            vector<char> stk = stacks[i];
            cout << i+1 << ") ";
            for (auto item : stk) {
                cout << item << ' ';
            }
            cout << endl;
        }

        // Now that we have the instructions, action the instructions on the stack.
        //
        int number = vals[0];
        int source = vals[1]-1;
        int target = vals[2]-1;

        for (int n = 0; n < number; n++) {
            char last_elem = stacks[source].back();
            stacks[target].push_back(last_elem);
            stacks[source].pop_back();
        }
    }

    string top_items = "";
    for (int i=0; i < stack_count; i++) {
        top_items.push_back(stacks[i].back());
    }

    //cout << top_items << endl;

    return top_items;
}

string part2() {
    std::ifstream iptfile ("input.txt");
    string linestr;

    int stack_count = 9;
    vector<char> stacks[stack_count];
    std::fill_n(stacks, stack_count, vector<char>());
    while (std::getline(iptfile, linestr) && linestr != "") {
        if (linestr[1] == '1') {
            break;
        }
        for (int i = 0; i < stack_count; i++) {

            if ((i*4 + 1 < linestr.length()) && linestr[i*4 + 1] != ' ') {
                //stacks[i].push_back(linestr[i*4 + 1]);
                stacks[i].insert(stacks[i].begin(), linestr[i*4 + 1]);
            }
        }
        cout << linestr << endl;
    }

    for (int i=0; i < stack_count; i++) {
        vector<char> stk = stacks[i];
        cout << i+1 << ") ";
        for (auto item : stk) {
            cout << item << ' ';
        }
        cout << endl;
    }



    // Skip the empty line
    std::getline(iptfile, linestr);
    while (std::getline(iptfile, linestr) && linestr != "") {
        vector<int> vals;
        int prev = 0;
        int pos = 0;

        //cout << linestr << endl;
        while ((pos = linestr.find(' ', pos)) != string::npos) {
            //cout << '<' << prev << '_' << pos << '>';
            //cout << '|' << linestr.substr(prev, pos-prev) << '|';
            if (std::all_of(linestr.begin() + prev, linestr.begin() + pos, ::isdigit)) {
                //cout << linestr.substr(prev, pos-prev) << '|';
                vals.push_back(std::stoi(linestr.substr(prev, pos-prev)));
            }
            //cout << linestr.substr(prev, pos-prev) << '|';
            prev = pos + 1;
            pos++;
        }
        //cout << '[' << prev << '_' << pos << ']' << linestr.substr(prev, linestr.length() - prev) << endl;
        //cout << linestr.substr(prev, linestr.length() - prev) << endl;
        vals.push_back(std::stoi(linestr.substr(prev, linestr.length() - prev)));

        cout << endl;
        for (auto v: vals) {
            cout << v << ' ';
        }
        cout << endl;
        for (int i=0; i < stack_count; i++) {
            vector<char> stk = stacks[i];
            cout << i+1 << ") ";
            for (auto item : stk) {
                cout << item << ' ';
            }
            cout << endl;
        }

        // Now that we have the instructions, action the instructions on the stack.
        //
        int number = vals[0];
        int source = vals[1]-1;
        int target = vals[2]-1;

        for (int n = number-1; n >= 0; n--) {
            char elem = stacks[source].at(stacks[source].size() - 1 - n);
            stacks[target].push_back(elem);
        }
        for (int n = 0; n < number; n++) {
            stacks[source].pop_back();
        }
    }

    string top_items = "";
    for (int i=0; i < stack_count; i++) {
        top_items.push_back(stacks[i].back());
    }

    //cout << top_items << endl;

    return top_items;
}

int main() {
    //std::cout << "Part1: \n" << part1() << std::endl;
    std::cout << "Part2: \n" << part2() << std::endl;
    return 0;
}
