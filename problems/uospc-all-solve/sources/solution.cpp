#include <iostream>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::cout << (n*k <= m ? "YES" : "NO");
    return 0;
}