#include <string>

class Matrix2d {
public:
    Matrix2d();
    Matrix2d(const int size);
    Matrix2d(const int cols, const int rows);
    Matrix2d(const Matrix2d& m);
    Matrix2d(const int * array, const int cols, const int rows);
    ~Matrix2d();

    Matrix2d operator= (const Matrix2d& m);

    std::string toString() const;
private:
    int * matrix = nullptr;
    int cols = 0;
    int rows = 0;

    void initWithNulls();
    void copyOrWat(const Matrix2d& m);
};