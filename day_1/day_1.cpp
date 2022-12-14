#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " [FILE]" << std::endl;
    }
    std::ifstream f(argv[1]);

    std::vector<int> v;
    std::string line;
    int c = 0;
    while (std::getline(f, line)) {
        if (line.empty()) {
            v.push_back(c);
            c = 0;
        }
        c += atoi(line.c_str());
    }

    std::sort(v.begin(), v.end(), std::greater<int>());
    std::cout << v[0] + v[1] + v[2] << std::endl;
}
