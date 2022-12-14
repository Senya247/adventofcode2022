#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " [FILE]" << std::endl;
    }
    std::ifstream f(argv[1]);

    char c1, c2, c3; // dummies
    int a, b, c, d, sum = 0;

    std::string line;
    std::stringstream ss;
    while (std::getline(f, line)) {
        ss.clear();
        ss << line;
        ss >> a >> c1 >> b >> c2 >> c >> c3 >> d;

        if ((a <= d) && (b >= c))
            sum++;
    }
    std::cout << sum << std::endl;
}
