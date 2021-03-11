#include "Matrix.hpp"

Matrix::~Matrix() { delete[](m_data); }

Matrix naive_mul(const Matrix &lhs, const Matrix &rhs) {
    if (lhs.getWidth() != rhs.getHeight()) {
        throw;
    }

    size_t n = lhs.getWidth();

    Matrix result(rhs.getWidth(), lhs.getHeight());

    for (size_t row = 0; row < lhs.getHeight(); row++)
    {
        for (size_t col = 0; col < rhs.getWidth(); col++)
        {
            result[row][col] = 0;
            for (size_t i = 0; i < n; i++)
            {
                result[row][col] += lhs[row][i] * rhs[i][col];
            }
        }
        
    }
    return result;
}

int* Matrix::operator [](size_t index) {
    return m_data + this->getWidth() * index;
}

const int* Matrix::operator [](size_t index) const {
    return m_data + this->getWidth() * index;
}

std::ostream& operator <<(std::ostream& os, const Matrix& m) {
    for (size_t h = 0; h < m.getHeight(); h++)
    {
        for (size_t w = 0; w < m.getWidth(); w++)
        {
            os << m[h][w];
            os << ' ';
        }
        os << '\n';
    }
    return os;
}

size_t Matrix::getWidth() const { return m_width; }
size_t Matrix::getHeight() const { return m_height; }
