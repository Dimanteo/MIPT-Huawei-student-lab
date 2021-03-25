#include "Matrix.hpp"

#include <iostream>

int main() {
    Matrix diag(3, 3);
    diag.fill({{1, 0, 0}, {0, 2, 0}, {0, 0, 3}});
    asm("nop; nop; nop");
    diag[0][1];
    asm("nop; nop; nop;");
    std::cout << diag << '\n';
    Matrix A(5, 3);
    A.fill({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}, {1, 1, 1}, {1, 1, 1}});
    std::cout << A << '\n';

    Matrix result(5, 3);
    if (naiveMul(A, diag, &result) < 0) {
        fprintf(stderr, "naive_mul() error\n");
        return EXIT_FAILURE;
    }
    std::cout << result;
    return EXIT_SUCCESS;
}
