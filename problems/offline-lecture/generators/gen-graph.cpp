#include "testlib.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int q = atoi(argv[3]);
    int distWeight = atoi(argv[4]);
    assert(m >= n-1);

    std::vector<int> p(n);

    /* setup parents for vertices 1..n-1 */
    for(int i = 0; i < n; ++i)
        if (i > 0)
            p[i] = rnd.wnext(i, 0);

    printf("%d %d\n", n, m);

    /* shuffle vertices 1..n-1 */
    std::vector<int> perm(n);
    for(int i = 0; i < n; ++i)
        perm[i] = i;
    shuffle(perm.begin() + 1, perm.end());

    /* put edges considering shuffled vertices */
    std::set<std::pair<int,int>> edges;
    for (int i = 1; i < n; i++)
        if (rnd.next(2))
            edges.insert(std::make_pair(perm[i], perm[p[i]]));
        else
            edges.insert(std::make_pair(perm[p[i]], perm[i]));

    while (edges.size() < m) {
        auto eVec = rnd.distinct(2, n);
        if (edges.count({ eVec[0], eVec[1] }) == 0 && edges.count({ eVec[1], eVec[0] }) == 0) {
            edges.insert({ eVec[0], eVec[1] });
        }
    }

    for (auto [u, v] : edges) {
        printf("%d %d\n", u + 1, v + 1);
    }
    
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