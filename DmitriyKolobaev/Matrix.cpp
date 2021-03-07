#include "Matrix.hpp"

Matrix::~Matrix() {
    delete[](m_data);
}

void Matrix::naive_mul(const Matrix& rhs) {
    if (m_height != rhs.getWidth()) {
        return; // TODO Exception
    }
    
    
}

size_t Matrix::getWidth() const {
    return m_width;
}
size_t Matrix::setHeight() const {
    return m_height;
}
