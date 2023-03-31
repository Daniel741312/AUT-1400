#include "hw1.h"

static inline void check_empty(std::initializer_list<Matrix> ilm) {
    for (auto it = ilm.begin(); it != ilm.end(); ++it) {
        if (it->empty()) {
            throw std::logic_error("matrix must be non-empty");
        }
    }
}

static inline void check_square(const Matrix& mat) {
    if (mat.size() != mat[0].size()) {
        throw std::logic_error("matrix must be square");
    }
}

static inline void check_size(size_t n, size_t m) {
    if (n == 0 || m == 0) {
        throw std::invalid_argument("size must be non-zero");
    }
}


namespace algebra {

Matrix zeros(size_t n, size_t m) {
    check_size(n, m);
    return Matrix(n, std::vector<double>(m, 0));
}

Matrix ones(size_t n, size_t m) {
    check_size(n, m);
    return Matrix(n, std::vector<double>(m, 1));
}

Matrix random(size_t n, size_t m, double min, double max) {
    check_size(n, m);
    Matrix mat = zeros(n, m);
    if (min >= max) {
        throw std::logic_error("interval left >= interval right");
    }
    std::default_random_engine e;
    std::uniform_real_distribution<double> u(min, max);
    for (auto& v : mat) {
        for (auto& elem : v) {
            elem = u(e);
        }
    }
    return mat;
}

void show(const Matrix& matrix) {
    check_empty({matrix});
    std::cout << std::showpoint << std::setprecision(3);
    for (auto& v : matrix) {
        for (auto& e : v) {
            std::cout << e << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::noshowpoint << std::setprecision(6);
}

Matrix multiply(const Matrix& matrix, double c) {
    check_empty({matrix});
    Matrix mat(matrix);
    for (auto& v : mat) {
        for(auto& e : v) {
            e *= c;
        }
    }
    return mat;
}

//naive implement, a more cache friendly version might be better
Matrix multiply(const Matrix& matrix1, const Matrix& matrix2) {
    if (matrix1.size() == 0) return matrix2;
    if (matrix2.size() == 0) return matrix1;

    int m1, n1, m2, n2;
    n1 = matrix1.size(), m1 = matrix1[0].size(), n2 = matrix2.size(), m2 = matrix2[0].size();
    if (m1 != n2) {
        throw std::logic_error("dimensions doesn't match");
    }
    Matrix mat = zeros(n1, m2);
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < m2; ++j) {
            for (int k = 0; k < m1; ++k) {
                mat[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return mat;
}

Matrix sum(const Matrix& matrix, double c) {
    if (matrix.size() == 0) return matrix;
    Matrix mat(matrix);
    for (auto& v : mat) {
        for (auto& elem : v) {
            elem += c;
        }
    }
    return mat;
}

Matrix sum(const Matrix& matrix1, const Matrix& matrix2) {
    int m1, n1, m2, n2;
    n1 = matrix1.size(), n2 = matrix2.size();
    if (n1 == 0 && n2 == 0) return matrix1;
    if (n1 != n2) {
        throw std::logic_error("dimensions doesn't match");
    }
    m1 = matrix1[0].size(), m2 = matrix2[0].size();
    if (m1 != m2) {
        throw std::logic_error("dimensions doesn't match");
    }
    Matrix mat(matrix1);
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < m1; ++j) {
            mat[i][j] += matrix2[i][j];
        }
    }
    return mat;
}

//native implement, a more cache friendly version might be better
Matrix transpose(const Matrix& matrix) {
    int n1, m1;
    n1 = matrix.size();
    if (n1 == 0) return matrix;
    m1 = matrix[0].size();
    Matrix mat = zeros(m1, n1);
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < m1; ++j) {
            mat[j][i] = matrix[i][j];
        }
    }
    return mat;
}


Matrix minor(const Matrix& matrix, size_t n, size_t m) {
    if (matrix.size() == 0) return matrix;
    check_square(matrix);
    int n1 = matrix.size();
    if (n >= n1 || m >= n1) {
        throw std::logic_error("indices out of bound");
    }
    Matrix mat = zeros(n1 - 1, n1 - 1);
    for (int i = 0; i < n1 - 1; ++i) {
        for (int j = 0; j < n1 - 1; ++j) {
            int ii = (i < n) ? i : i + 1;
            int jj = (j < m) ? j : j + 1;
            mat[i][j] = matrix[ii][jj];
        }
    }
    return mat;
}

static inline double det3(const Matrix& m) {
    return m[0][0] * m[1][1] * m[2][2] +
           m[0][1] * m[1][2] * m[2][0] +
           m[0][2] * m[1][0] * m[2][1] -
           m[0][2] * m[1][1] * m[2][0] -
           m[0][0] * m[1][2] * m[2][1] -
           m[0][1] * m[1][0] * m[2][2];
}

static inline double det2(const Matrix& m) {
    return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}

double determinant(const Matrix& matrix) {
    int n = matrix.size();
    if (n == 0) return 1;
    check_square(matrix);
    if (n == 1) return matrix[0][0];
    if (n == 2) return det2(matrix);
    if (n == 3) return det3(matrix);
    double res = 0;
    for (int i = 0; i < n; ++i) {
        Matrix m = minor(matrix, 0, i);
        int sign = (i & 1) ? -1 : 1;
        res += matrix[0][i] * sign * determinant(m);
    }
    return res;
}


static Matrix adjoint(const Matrix& matrix) {
    int n = matrix.size();
    Matrix mat = zeros(n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int sign = (i + j) & 1 ? -1 : 1;
            Matrix mr = minor(matrix, i, j);
            mat[i][j] = sign * determinant(mr);
        }
    }
    return transpose(mat);
}

Matrix inverse(const Matrix& matrix) {
    int n = matrix.size();
    if (n == 0) return matrix;
    check_square(matrix);
    double det = determinant(matrix);
    if (det == 0) {
        throw std::logic_error("singular matrices have no inverse");
    }
    Matrix mat = adjoint(matrix);
    return multiply(mat, 1 / det);
}

Matrix concatenate(const Matrix& matrix1, const Matrix& matrix2, int axis) {
    int n1, m1, n2, m2;
    n1 = matrix1.size();
    n2 = matrix2.size();
    if (n1 == 0) return matrix2;
    if (n2 == 0) return matrix1;
    Matrix mat;
    m1 = matrix1[0].size(), m2 = matrix2[0].size();
    if (axis == 0) {
        if (m1 != m2) {
            throw std::logic_error("column number doesn't match while axis = 0");
        }
        mat = zeros(n1 + n2, m1);
        for (int i = 0; i < n1 + n2; ++i) {
            for (int j = 0; j < m1; ++j) {
                mat[i][j] = i < n1 ? matrix1[i][j] : matrix2[i - n1][j];
            }
        }
    } else if (axis == 1) {
        if (n1 != n2) {
            throw std::logic_error("row number doesn't match while axis = 1");
        }
        mat = zeros(n1, m1 + m2);
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < m1 + m2; ++j) {
                mat[i][j] = j < m1 ? matrix1[i][j] : matrix2[i][j - m1];
            }
        }
    } else {
        throw std::invalid_argument("axis must be 0 or 1");
    }
    return mat;
}

Matrix ero_swap(const Matrix& matrix, size_t r1, size_t r2) {
    //check_empty({matrix});
    int n1 = matrix.size();
    if (n1 == 0) return matrix;
    if (r1 >= n1 || r2 >= n1) {
        throw std::logic_error("r1 or r2 is out of range");
    }
    Matrix mat(matrix);
    std::swap(mat[r1], mat[r2]);
    return mat;
}

Matrix ero_multiply(const Matrix& matrix, size_t r, double c) {
    int n1 = matrix.size();
    if (n1 == 0) return matrix;
    if (r >= n1) {
        throw std::logic_error("r is out of range");
    }
    Matrix mat(matrix);
    auto& v = mat[r];
    for (auto& elem : v) {
        elem *= c;
    }
    return mat;
}

Matrix ero_sum(const Matrix& matrix, size_t r1, double c, size_t r2) {
    int n1 = matrix.size();
    if (n1 == 0) return matrix;
    if (r1 >= n1 || r2 >= n1) {
        throw std::logic_error("r1 or r2 is out of range");
    }
    Matrix mat(matrix);
    auto& v1 = mat[r1];
    auto& v2 = mat[r2];
    for (int i = 0; i < v1.size(); ++i) {
        v2[i] += v1[i] * c;
    }
    return mat;
}

/*
* buggy for the last test case
*/
Matrix upper_triangular(const Matrix& matrix){
    int n = matrix.size();
    if (n == 0) return matrix;
    check_square(matrix);
    if (n == 1) return matrix;
    Matrix mat(matrix);
    for (int i = 0; i < n; ++i) {
       double diagonal_elem = mat[i][i];
        for (int j = i + 1; j < n; ++j) {
            double elem = mat[j][i];
            mat = ero_sum(mat, i, - elem / diagonal_elem, j);
        }
    }
    return mat;
}
}//namespace algebra