#include "Matrix.hpp"

Matrix::~Matrix() { delete[](m_data); }

void Matrix::naive_mul(const Matrix &rhs) {
    if (m_height != rhs.getWidth()) {
        return; // TODO Exception
    }
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
