#include "Matrix.hpp"

Matrix::~Matrix() { delete[](m_data); }

static int arg_verify(const Matrix &lhs, const Matrix &rhs, Matrix *res) {
    if (res == nullptr)
        return -1;
    if (lhs.getWidth() != rhs.getHeight())
        return -1;
    if (res->getHeight() != lhs.getHeight())
        return -1;
    if (res->getWidth() != rhs.getWidth())
        return -1;
    return 0;
}

int naive_mul(const Matrix &lhs, const Matrix &rhs, Matrix *res) {
    if (arg_verify(lhs, rhs, res) < 0)
        return -1;

    size_t n = lhs.getWidth();

    for (size_t row = 0; row < lhs.getHeight(); row++) {
        for (size_t col = 0; col < rhs.getWidth(); col++) {
            (*res)[row][col] = 0;
            for (size_t i = 0; i < n; i++) {
                (*res)[row][col] += lhs[row][i] * rhs[i][col];
            }
        }
    }
    return 0;
}

int opt_mul(const Matrix &lhs, const Matrix &rhs, Matrix *res) {
    if (arg_verify < 0)
        return -1;

    // TODO cache-friendly algorithm
    return 0;
}

void Matrix::fill(const std::vector<std::vector<int>> &data) {
    for (size_t row = 0; row < getHeight(); row++) {
        int *cur_row = m_data + row * getWidth();
        for (size_t col = 0; col < getWidth(); col++) {
            cur_row[col] = data[row][col];
        }
    }
}

int *Matrix::operator[](size_t index) {
    return m_data + this->getWidth() * index;
}

const int *Matrix::operator[](size_t index) const {
    return m_data + this->getWidth() * index;
}

std::ostream &operator<<(std::ostream &os, const Matrix &m) {
    for (size_t h = 0; h < m.getHeight(); h++) {
        for (size_t w = 0; w < m.getWidth(); w++) {
            os << m[h][w];
            os << ' ';
        }
        os << '\n';
    }
    return os;
}

size_t Matrix::getWidth() const { return m_width; }
size_t Matrix::getHeight() const { return m_height; }
