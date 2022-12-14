#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int priority(char a);
char common(std::vector<std::string> v);

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

    int lno = 1;
    std::string line;

    std::vector<std::vector<std::string>> v;
    std::vector<std::string> t;
    while (std::getline(f, line)) {
        t.push_back(line);
        if (lno % 3 == 0) {
            v.push_back(t);
            t.clear();
        }
        lno++;
    }

    int sum = 0;
    char c;
    for (auto &v1 : v) {
        std::cout << v1 << std::endl;
        if ((c = common(v1)))
            sum += priority(c);
    }
    std::cout << sum << std::endl;
}

char common(std::vector<std::string> v) {
    std::vector<std::vector<int>> freq;
    int l = v.size(), m;

    freq.resize(l);
    for (int i = 0; i < l; i++)
        freq[i].resize(26 * 2);

    for (int i = 0; i < l; i++) {
        m = v[i].length();
        for (int j = 0; j < m; j++) {
            if (islower(v[i][j])) {
                /* puts("yeet1");
                printf("index [%d][%d]\n", i, v[i][j] - 97); */
                freq[i][v[i][j] - 97]++;
                // puts("yeet2");
            } else {
                // puts("yeet3");
                freq[i][v[i][j] - 39]++;
                // puts("yeet4");
            }
        }
    }

    for (int i = 0; i < 26 * 2; i++) {
        int p = 1;
        for (int j = 0; j < l; j++)
            p *= freq[j][i];
        if (p != 0) {
            if (i >= 0 && i <= 25)
                return i + 97;
            return i + 39;
        }
    }
    return 0;
}

int priority(char a) {
    if (islower(a)) {
        return a - 96;
    }
    return a - 38;
}
