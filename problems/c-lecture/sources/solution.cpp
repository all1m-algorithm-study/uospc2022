#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int total = 0, max = 0;
    for (int i = 0; i < n; ++i) {
        int s;
        std::cin >> s;
        total += s;
        max = std::max(max, s);
    }

    std::cout << (total / max + (total % max > 0 ? 1 : 0)) * max;

    return 0;
}