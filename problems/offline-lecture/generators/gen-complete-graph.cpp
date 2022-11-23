#include "testlib.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int q = atoi(argv[2]);
    int distWeight = atoi(argv[3]);

    int m = (n*(n-1)) / 2;
    assert(m <= 3000);
    // (n*(n-1)) / 2 <= 3000
    // n = 77.961

    printf("%d %d\n", n, m);
    int added = 0;
    for (int u = 1; u <= n; ++u) {
        for (int v = u+1; v <= n; ++v) {
            printf("%d %d\n", u, v);
            ++added;
        }
    }
    assert(added == m);
    
    printf("%d\n", q);

    while (q--) {
        auto edge1 = rnd.distinct(2, n);
        auto edge2 = rnd.distinct(2, n);
        int x = rnd.wnext(1, n-1, distWeight);
        int y = rnd.wnext(1, n-1, distWeight);
        printf("%d %d %d %d %d %d\n", edge1[0]+1, edge1[1]+1, x, edge2[0]+1, edge2[1]+1, y);
    }

    return 0;
}