#include "testlib.h"
#include <iostream>
#include <string>
#include <cassert>

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    assert(argc >= 2);
    std::string kind = argv[1];

    int n = -1, m = -1, k = -1;
    if (kind == "yes") {
        do {
            n = rnd.next(1, 20);
            m = rnd.next(1, 300);
            k = rnd.next(1, 300);
        } while (!(n*k < m));
    } else if (kind == "no") {
        do {
            n = rnd.next(1, 20);
            m = rnd.next(1, 300);
            k = rnd.next(1, 300);
        } while (!(n*k > m));
    } else { // equal
        do {
            n = rnd.next(1, 20);
            k = 300 / n;
            m = n*k;
        } while (!(n*k == m));
    }

    assert(1 <= n && n <= 20);
    assert(1 <= m && m <= 300);
    assert(1 <= k && k <= 300);

    printf("%d %d %d\n", n, m, k);

    return 0;
}