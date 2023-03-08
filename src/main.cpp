#include <iostream>
#include "sober.h"

int main() {
    Sober sober;
    std::cout << "2 + 2 = " << sober.add(2, 2) << std::endl;
    return 0;
}