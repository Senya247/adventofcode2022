#include <fstream>
#include <iostream>
#include <string>

int score(char a, char b);
int decide(char a, char b);

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " [FILE]" << std::endl;
    }
    std::ifstream f(argv[1]);

    int sum = 0;
    char a, b;
    while (f >> a >> b) {
        sum += decide(a, b);
    }
    std::cout << sum << std::endl;

    f.close();
}

int decide(char a, char b) {
    int WIN = 6;
    int DRAW = 3;
    int LOSE = 0;

    int R = 1;
    int P = 2;
    int S = 3;

    switch (a) {
    case 'A':
        switch (b) {
        case 'X':
            return LOSE + S;
        case 'Y':
            return DRAW + R;
        case 'Z':
            return WIN + P;
        }
    case 'B':
        switch (b) {
        case 'X':
            return LOSE + R;
        case 'Y':
            return DRAW + P;
        case 'Z':
            return WIN + S;
        }
    case 'C':
        switch (b) {
        case 'X':
            return LOSE + P;
        case 'Y':
            return DRAW + S;
        case 'Z':
            return WIN + R;
        }
    }
    return 0;
}

int score(char a, char b) {
    int WIN = 6;
    int DRAW = 3;
    int LOSE = 0;

    int R = 1;
    int P = 2;
    int S = 3;

    switch (a) {
    case 'A':
        switch (b) {
        case 'X':
            return DRAW + R;
        case 'Y':
            return WIN + P;
        case 'Z':
            return LOSE + S;
        }
    case 'B':
        switch (b) {
        case 'X':
            return LOSE + R;
        case 'Y':
            return DRAW + P;
        case 'Z':
            return WIN + S;
        }
    case 'C':
        switch (b) {
        case 'X':
            return WIN + R;
        case 'Y':
            return LOSE + P;
        case 'Z':
            return DRAW + S;
        }
    }
    return 0;
}
