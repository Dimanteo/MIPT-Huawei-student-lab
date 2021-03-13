#include "Matrix.hpp"

#include <iostream>

int main() {
    Matrix diag(3, 3);
    diag.fill({
        {1, 0, 0}, 
        {0, 2, 0}, 
        {0, 0, 3}
    });
    std::cout << diag << '\n';
    Matrix A(5, 3);
    A.fill({
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    });
    std::cout << A << '\n';
    std::cout << naive_mul(A, diag);
    return EXIT_SUCCESS;
}
