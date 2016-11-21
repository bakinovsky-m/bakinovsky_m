#include <string>
#include <ostream>
#include <istream>

class Matrix2d {
public:
    Matrix2d();
    Matrix2d(const int size);
    Matrix2d(const int cols, const int rows);
    Matrix2d(const Matrix2d& m);
    Matrix2d(const int * array, const int cols, const int rows);
    ~Matrix2d();

    // overrided operators
    Matrix2d operator= (const Matrix2d& m);
    bool operator== (const Matrix2d& m) const;
    bool operator!= (const Matrix2d& m) const;

    // std::ostream& serialize(std::ostream& ostrm);
    void serialize(std::ostream& ostrm);
    void deserialize(std::istream& istrm);

    std::string toString() const;
private:
    int * matrix = nullptr;
    int cols = 0;
    int rows = 0;

    void initWithNulls();
    void copyOrWat(const Matrix2d& m);
};