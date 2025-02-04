#include <iostream>

#include "bit.hpp"

int main(int argc, char** argv) {
    std::cout << bit::is(0xAA, 1) << std::endl;
    return 0;
}
