#include "testlib.h"
#include <iostream>
#include <vector>

const int MAX_N = 100;
const std::vector<int> CAND { 1, 2, 4, 8 };

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int maxIdx = atoi(argv[2]);

    if (n == -1) {
        n = rnd.next(1, MAX_N);
    }
    if (maxIdx == -1) {
        maxIdx = rnd.next(0, (int)CAND.size()-1);
    }

    ensure(maxIdx < CAND.size());

    std::cout << n << "\n";

    for (int i = 0; i < n; ++i) {
        std::cout << CAND[rnd.next(0, maxIdx)] << "\n";
    }

    return 0;
}