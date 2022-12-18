#include <algorithm>
#include <cctype>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

template <typename T>
void move(const std::string &line, std::vector<std::vector<T>> &v);

template <typename T>
std::ostream &operator<<(std::ostream &os, std::vector<T> vec) {
    os << "{";
    if (vec.size() != 0) {
        std::copy(vec.begin(), vec.end() - 1,
                  std::ostream_iterator<T>(os, " "));
        os << vec.back();
    }
    os << "}";
    return os;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " [FILE]" << std::endl;
    }
    std::ifstream f(argv[1]);

    std::vector<std::vector<char>> v;

    std::string line;
    std::stringstream ss;
    char c;
    int len, pos;
    while (std::getline(f, line)) {
        if (line[0] == 'm')
            break;
        len = line.length();
        for (int i = 0; i < len; i++) {
            if (std::isspace(line[i]) || line[i] == '[' || line[i] == ']')
                continue;
            pos = (i - 1) / 4;

            if (pos >= v.size()) {
                v.resize(pos + 1);
            }
            v[pos].push_back(line[i]);
        }
    }
    for (auto &v1 : v)
        std::reverse(v1.begin(), v1.end());

    move(line, v);
    while (std::getline(f, line)) {
        move(line, v);
    }

    for (auto const &v1 : v)
        std::cout << v1.back();
    std::cout << std::endl;
}

template <typename T>
void move(const std::string &line, std::vector<std::vector<T>> &v) {
    int to, from, count;
    std::string dummy;
    std::stringstream ss(line);

    ss >> dummy >> count >> dummy >> from >> dummy >> to;
    to -= 1;
    from -= 1;

    std::vector<T> tmp;
    for (int i = 0; i < count; i++) {
        tmp.push_back(v[from].back());
        v[from].pop_back();
    }
    for (int i = 0; i < count; i++) {
        v[to].push_back(tmp.back());
        tmp.pop_back();
    }
}
