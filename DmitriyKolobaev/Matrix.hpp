#pragma once
#include <cstdlib>
#include <ostream>
#include <vector>

class Matrix {
    int *m_data;
    size_t m_width;
    size_t m_height;

  public:
    Matrix(size_t width, size_t height)
        : m_data(new int[width * height]), m_width(width), m_height(height){};
    ~Matrix();
    void fill(const std::vector<std::vector<int>>& data);
    size_t getWidth() const;
    size_t getHeight() const;
    int* operator [](size_t);
    const int* operator [](size_t) const;
};

Matrix naive_mul(const Matrix&, const Matrix &);

std::ostream& operator <<(std::ostream& os, const Matrix& m);
