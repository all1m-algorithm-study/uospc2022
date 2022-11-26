#include "testlib.h"
#include <iostream>

const int MAX_N = 100;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int s = atoi(argv[1]);
    ensure(s == 1 || s == 2 || s == 4 || s == 8);
    std::cout << MAX_N << "\n";
    for (int i = 0; i < MAX_N; ++i) {
        std::cout << s << "\n";
    }

    return 0;
}