#include "Matrix.hpp"

#include <iostream>

int main(int argc, char **argv) {
    Matrix m(3, 3);
    m[0][0] = 1;
    m[2][2] = 2;
    std::cout << m;
    return EXIT_SUCCESS;
}
