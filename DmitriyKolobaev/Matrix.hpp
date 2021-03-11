#pragma once
#include <cstdlib>
#include <ostream>

class Matrix {
    int *m_data;
    size_t m_width;
    size_t m_height;

  public:
    Matrix(size_t width, size_t height)
        : m_data(new int[width * height]), m_width(width), m_height(height){};
    ~Matrix();
    void naive_mul(const Matrix &);
    size_t getWidth() const;
    size_t getHeight() const;
    int* operator [](size_t);
    const int* operator [](size_t) const;
};

std::ostream& operator <<(std::ostream& os, const Matrix& m);
