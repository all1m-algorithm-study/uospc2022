#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    std::vector<std::vector<int>> dist(n+1, std::vector<int>(n+1, -1));
    for (int i = 1; i <= n; ++i) {
        std::queue<int> q;
        q.emplace(i);
        dist[i][i] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (int next : graph[curr]) {
                if (dist[i][next] == -1) {
                    q.emplace(next);
                    dist[i][next] = dist[i][curr]+1;
                }
            }
        }
    }

    int q;
    std::cin >> q;

    while (q--) {
        int a, b, x, c, d, y;
        std::cin >> a >> b >> x >> c >> d >> y;
        bool yes;
        if (dist[a][b] <= x || dist[c][d] <= y) {
            yes = true;
        } else {
            yes = (dist[a][c] + dist[b][d] + 2 <= x + y) || 
                  (dist[a][d] + dist[b][c] + 2 <= x + y);
        }
        std::cout << (yes ? "YES\n" : "NO\n");
    }

    return 0;
}