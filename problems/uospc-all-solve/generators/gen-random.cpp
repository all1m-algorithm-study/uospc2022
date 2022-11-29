#include "testlib.h"
#include <iostream>

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    printf("%d %d %d\n", rnd.next(1, 20), rnd.next(1, 300), rnd.next(1, 300));

    return 0;
}