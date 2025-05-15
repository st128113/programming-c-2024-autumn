#include <iostream>

class Matrix
{
private:
    double** d;
    int r;
    int c;

    double** CD(int r, int c);
    void FD(double** d, int r);

public:
    Matrix();
    Matrix(int d);
    Matrix(int r, int c);
    Matrix(const Matrix& m);
    ~Matrix();

    Matrix& operator=(const Matrix& o);

    double get(int rr, int cc) const;
    void set(int rr, int cc, double v);
    int getR() const;
    int getC() const;

    void print() const;
    void multBy(double k);
    void addTo(const Matrix& m);
    void transpose();

    double det() const;
    Matrix minor(int rr, int cc) const;

    friend Matrix add(const Matrix& m1, const Matrix& m2);
    friend Matrix transpose(const Matrix& m);
    friend Matrix subtr(const Matrix& m1, const Matrix& m2);
    friend Matrix mult(const Matrix& m1, const Matrix& m2);
    friend Matrix reverse(const Matrix& m);
    friend Matrix solve(const Matrix& A, const Matrix& B);
};

double** Matrix::CD(int r, int c)
{
    if (r <= 0 || c <= 0) {
        std::cout << "Error" << std::endl;
        return nullptr;
    }

    double** d = new double* [r];
    for (int i = 0; i < r; ++i) {
        d[i] = new double[c];
        for (int j = 0; j < c; ++j) {
            d[i][j] = 0.0;
        }
    }
    return d;
}

void Matrix::FD(double** d, int r)
{
    if (d == nullptr) {
        return;
    }

    if (r > 0) {
        for (int i = 0; i < r; ++i) {
            if (d[i] != nullptr) {
                delete[] d[i];
                d[i] = nullptr;
            }
        }
    }
    delete[] d;
    d = nullptr;
}

Matrix::Matrix() : d(nullptr), r(0), c(0)
{
}

Matrix::Matrix(int dim) : d(nullptr), r(dim), c(dim)
{
    if (dim <= 0) {
        std::cout << "Error" << std::endl;
        this->r = this->c = 0;
        d = nullptr;
    }
    else {
        d = CD(this->r, this->c);
    }
}

Matrix::Matrix(int r, int c) : d(nullptr), r(r), c(c)
{
    if (r <= 0 || c <= 0) {
        std::cout << "Error" << std::endl;
        this->r = this->c = 0;
        d = nullptr;
    }
    else {
        d = CD(this->r, this->c);
    }
}

Matrix::Matrix(const Matrix& o) : d(nullptr), r(o.r), c(o.c)
{
    if (o.d != nullptr && r > 0 && c > 0) {
        d = CD(r, c);
        if (d != nullptr) {
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    d[i][j] = o.d[i][j];
                }
            }
        }
        else {
            this->r = this->c = 0;
            this->d = nullptr;
            std::cout << "Error" << std::endl;
        }
    }
    else {
        this->r = this->c = 0;
        this->d = nullptr;
    }
}

Matrix::~Matrix()
{
    FD(d, r);
    d = nullptr;
    r = c = 0;
}

Matrix& Matrix::operator=(const Matrix& o)
{
    if (this == &o) {
        return *this;
    }

    FD(d, r);

    r = o.r;
    c = o.c;

    d = nullptr;
    if (o.d != nullptr && r > 0 && c > 0) {
        d = CD(r, c);
        if (d != nullptr) {
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    d[i][j] = o.d[i][j];
                }
            }
        }
        else {
            this->r = this->c = 0;
            this->d = nullptr;
            std::cout << "Error" << std::endl;
        }
    }
    else {
        this->r = this->c = 0;
        this->d = nullptr;
    }

    return *this;
}

double Matrix::get(int rr, int cc) const
{
    if (d == nullptr || rr < 0 || rr >= r || cc < 0 || cc >= c) {
        std::cout << "Error" << std::endl;
        return 0.0;
    }
    return d[rr][cc];
}

void Matrix::set(int rr, int cc, double v)
{
    if (d == nullptr || rr < 0 || rr >= r || cc < 0 || cc >= c) {
        std::cout << "Error" << std::endl;
        return;
    }
    d[rr][cc] = v;
}

int Matrix::getR() const
{
    return r;
}

int Matrix::getC() const
{
    return c;
}

void Matrix::print() const
{
    if (r == 0 || c == 0 || d == nullptr) {
        std::cout << "Пустая матрица" << std::endl;
        return;
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            std::cout << d[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void Matrix::multBy(double k)
{
    if (r == 0 || c == 0 || d == nullptr) {
        return;
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            d[i][j] *= k;
        }
    }
}

void Matrix::addTo(const Matrix& m)
{
    if (r != m.r || c != m.c || d == nullptr || m.d == nullptr) {
        std::cout << "Error" << std::endl;
        return;
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            d[i][j] += m.d[i][j];
        }
    }
}

void Matrix::transpose()
{
    if (r == 0 || c == 0 || d == nullptr) {
        return;
    }

    int nr = c;
    int nc = r;
    double** nd = CD(nr, nc);

    if (nd == nullptr) {
        std::cout << "Error" << std::endl;
        return;
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            nd[j][i] = d[i][j];
        }
    }

    FD(d, r);

    d = nd;
    r = nr;
    c = nc;
}

Matrix Matrix::minor(int rr, int cc) const
{
    if (d == nullptr || r <= 1 || c <= 1 || rr < 0 || rr >= r || cc < 0 || cc >= c) {
        std::cout << "Error" << std::endl;
        return Matrix();
    }

    int mr = r - 1;
    int mc = c - 1;
    Matrix res(mr, mc);

    int dr = 0;
    for (int i = 0; i < r; ++i) {
        if (i == rr) continue;

        int dc = 0;
        for (int j = 0; j < c; ++j) {
            if (j == cc) continue;

            res.d[dr][dc] = d[i][j];
            dc++;
        }
        dr++;
    }
    return res;
}

double Matrix::det() const
{
    if (d == nullptr || r != c) {
        std::cout << "Error" << std::endl;
        return 0.0;
    }

    if (r == 0) {
        return 1.0;
    }

    if (r == 1) {
        return d[0][0];
    }

    if (r == 2) {
        return d[0][0] * d[1][1] - d[0][1] * d[1][0];
    }

    double det = 0.0;
    int sgn = 1;

    for (int j = 0; j < c; ++j) {
        Matrix mm = minor(0, j);
        det += sgn * d[0][j] * mm.det();
        sgn = -sgn;
    }

    return det;
}

Matrix add(const Matrix& m1, const Matrix& m2)
{
    if (m1.r != m2.r || m1.c != m2.c || m1.d == nullptr || m2.d == nullptr) {
        std::cout << "Error" << std::endl;
        return Matrix();
    }

    Matrix res(m1.r, m1.c);
    for (int i = 0; i < m1.r; ++i) {
        for (int j = 0; j < m1.c; ++j) {
            res.d[i][j] = m1.d[i][j] + m2.d[i][j];
        }
    }
    return res;
}

Matrix transpose(const Matrix& m)
{
    if (m.r == 0 || m.c == 0 || m.d == nullptr) {
        std::cout << "Error" << std::endl;
        return Matrix();
    }

    Matrix res(m.c, m.r);
    for (int i = 0; i < m.r; ++i) {
        for (int j = 0; j < m.c; ++j) {
            res.d[j][i] = m.d[i][j];
        }
    }
    return res;
}

Matrix subtr(const Matrix& m1, const Matrix& m2)
{
    if (m1.r != m2.r || m1.c != m2.c || m1.d == nullptr || m2.d == nullptr) {
        std::cout << "Error" << std::endl;
        return Matrix();
    }

    Matrix res(m1.r, m1.c);
    for (int i = 0; i < m1.r; ++i) {
        for (int j = 0; j < m1.c; ++j) {
            res.d[i][j] = m1.d[i][j] - m2.d[i][j];
        }
    }
    return res;
}

Matrix mult(const Matrix& m1, const Matrix& m2)
{
    if (m1.c != m2.r || m1.d == nullptr || m2.d == nullptr) {
        std::cout << "Error" << std::endl;
        return Matrix();
    }

    Matrix res(m1.r, m2.c);

    for (int i = 0; i < m1.r; ++i) {
        for (int j = 0; j < m2.c; ++j) {
            double sm = 0.0;
            for (int k = 0; k < m1.c; ++k) {
                sm += m1.d[i][k] * m2.d[k][j];
            }
            res.d[i][j] = sm;
        }
    }
    return res;
}

Matrix reverse(const Matrix& m)
{
    if (m.d == nullptr || m.r != m.c) {
        std::cout << "Error" << std::endl;
        return Matrix();
    }

    double det = m.det();

    if (det == 0.0) {
        std::cout << "Error" << std::endl;
        return Matrix();
    }

    int n = m.r;

    if (n == 1) {
        Matrix res(1, 1);
        if (m.d[0][0] == 0.0) {
            std::cout << "Error" << std::endl;
            return Matrix();
        }
        res.d[0][0] = 1.0 / m.d[0][0];
        return res;
    }

    Matrix adj(n, n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            Matrix mm = m.minor(i, j);
            double mdet = mm.det();
            double cof = ((i + j) % 2 == 0) ? mdet : -mdet;
            adj.d[i][j] = cof;
        }
    }

    Matrix tadj = transpose(adj);
    tadj.multBy(1.0 / det);

    return tadj;
}

Matrix solve(const Matrix& A, const Matrix& B)
{
    if (A.d == nullptr || B.d == nullptr || A.r != A.c || A.r != B.r) {
        std::cout << "Error" << std::endl;
        return Matrix();
    }

    Matrix Ainv = reverse(A);

    if (Ainv.r == 0) {
        return Matrix();
    }

    Matrix X = mult(Ainv, B);

    return X;
}