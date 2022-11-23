#include "testlib.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int t = atoi(argv[2]);
    int q = atoi(argv[3]);
    int distWeight = atoi(argv[4]);

    std::vector<int> p(n);

    /* setup parents for vertices 1..n-1 */
    for(int i = 0; i < n; ++i)
        if (i > 0)
            p[i] = rnd.wnext(i, t);

    printf("%d %d\n", n, n-1);

    /* shuffle vertices 1..n-1 */
    std::vector<int> perm(n);
    for(int i = 0; i < n; ++i)
        perm[i] = i;
    shuffle(perm.begin() + 1, perm.end());

    /* put edges considering shuffled vertices */
    std::vector<std::pair<int,int>> edges;
    for (int i = 1; i < n; i++)
        if (rnd.next(2))
            edges.push_back(std::make_pair(perm[i], perm[p[i]]));
        else
            edges.push_back(std::make_pair(perm[p[i]], perm[i]));

    /* shuffle edges */
    shuffle(edges.begin(), edges.end());

    for (int i = 0; i + 1 < n; i++)
        printf("%d %d\n", edges[i].first + 1, edges[i].second + 1);
    
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