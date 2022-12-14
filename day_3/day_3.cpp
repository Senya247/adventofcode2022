#include <algorithm>
#include <cctype>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int priority(char a);
char common(std::vector<std::string> v);

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " [FILE]" << std::endl;
    }
    std::ifstream f(argv[1]);

    int sum = 0, lno = 1;
    std::string line;

    std::vector<std::vector<std::string>> v;
    std::vector<std::string> t;
    while (std::getline(f, line)) {
        std::sort(line.begin(), line.end());
        t.push_back(line);
        if (lno % 3 == 0) {
            v.push_back(t);
            t.clear();
        }
        lno++;
    }

    for (auto &v1 : v) {
    }
}

char common(std::vector<std::string> v) {
    static std::vector<std::vector<int>> freq;
    int l = v.size(), m;

    freq.reserve(l);
    for (auto &f : freq)
        f.reserve(26 * 2);

    for (int i = 0; i < l; i++) {
        m = v[i].length();
        for (int j = 0; j < m; j++) {
            if (islower(v[i][j]))
                freq[i][v[i][j] - 97]++;
            else
                freq[i][v[i][j] - 39]++;
        }
    }
}

int priority(char a) {
    if (islower(a)) {
        return a - 96;
    }
    return a - 38;
}
