#include "Matrix.hpp"
#include <cstdlib>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

static int argVerify(const Matrix &lhs, const Matrix &rhs, Matrix *res);

static size_t getCacheLineSz();

Matrix::~Matrix() { delete[](m_data); }

int naiveMul(const Matrix &mlhs, const Matrix &mrhs, Matrix *mres) {
    if (argVerify(mlhs, mrhs, mres) < 0)
        return -1;

    size_t n = mlhs.getWidth();
    int *res = mres->getData();
    int *lhs = mlhs.getData();
    int *rhs = mrhs.getData();

    for (size_t row = 0; row < mlhs.getHeight(); row++) {
        for (size_t col = 0; col < mrhs.getWidth(); col++) {
            int sum = 0;
            for (size_t i = 0; i < n; i++) {
                sum += lhs[row * mrhs.getWidth() + i] * rhs[i * mrhs.getWidth() + col];
            }
            res[row * mrhs.getWidth() + col] = sum;
        }
    }
    return 0;
}

int optimalMul(const Matrix &mlhs, const Matrix &mrhs, Matrix *mres) {
    if (argVerify(mlhs, mrhs, mres) < 0)
        return -1;

    int *lhs = mlhs.getData();
    int *rhs = mrhs.getData();
    int *res = mres->getData();

    size_t lineSz = getCacheLineSz();
    size_t rowLen = mlhs.getHeight();
    
    
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
int* Matrix::getData() const { return m_data; }

static int argVerify(const Matrix &lhs, const Matrix &rhs, Matrix *res) {
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

static size_t getCacheLineSz() {
    const char *cacheInfoDir = "/sys/devices/system/cpu/cpu0/cache/index0/coherency_line_size";
    int fd = open(cacheInfoDir, O_RDONLY);
    if (fd < 0)
        return 0;
    char clSize[4] = "";
    int ret = read(fd, clSize, sizeof(clSize));
    if (ret < 0)
        return 0;
    return strtoul(clSize, NULL, 10);
}
