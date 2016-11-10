#include "matrix2d.h"

// constuctors + destructor
Matrix2d::Matrix2d(){
    cols = 0;
    rows = 0;
    matrix = new int[cols * rows];
}

Matrix2d::Matrix2d(const int size){
    cols = rows = size;
    matrix = new int[cols*rows];
    initWithNulls();
}

Matrix2d::Matrix2d(const int cols_, const int rows_){
    cols = cols_;
    rows = rows_;
    matrix = new int[cols*rows];
    initWithNulls();
}

Matrix2d::Matrix2d(const int * array, const int cols_, const int rows_){
    cols = cols_;
    rows = rows_;
    matrix = new int[cols*rows];
    // for (std::ptrdiff_t i = 0; i < rows; i++){
    //     for (std::ptrdiff_t j = 0; j < cols; j++){
    //         matrix[i*cols + j] = array[i*cols + j];
    //     }
    // }
    for (std::ptrdiff_t i = 0; i < cols*rows; i++){
        matrix[i] = array[i];
    }
}

Matrix2d::~Matrix2d(){
    delete [] matrix;
}

Matrix2d::Matrix2d(const Matrix2d& m){
    cols = m.cols;
    rows = m.rows;
    matrix = new int[cols * rows];
    copyOrWat(m);
}

void Matrix2d::copyOrWat(const Matrix2d& m){
    // for (int i = 0; i < rows; i++){
    //     for (int j = 0; j < cols; j++){
    //         matrix[i*cols + j] = m.matrix[i*cols + j];
    //     }
    // }
    for (std::ptrdiff_t i = 0; i < rows*cols; i++){
        matrix[i] = m.matrix[i];
    }
}


// overrided operators
Matrix2d Matrix2d::operator= (const Matrix2d& m){
    cols = m.cols;
    rows = m.rows;
    matrix = new int[cols * rows];
    copyOrWat(m);
    return Matrix2d(matrix, cols, rows);
}

bool Matrix2d::operator== (const Matrix2d& m) const{
    for (std::ptrdiff_t i = 0; i < cols*rows; i++){
        if (matrix[i] != m.matrix[i]){
            return false;
        }
    }
    return true;
}

bool Matrix2d::operator!= (const Matrix2d& m) const{
    return (!operator==(m));
}

// other methods
std::string Matrix2d::toString() const{
    std::string str = "";
    for (std::ptrdiff_t i = 0; i < rows; i++){
        for (std::ptrdiff_t j = 0; j < cols; j++){
            str += std::to_string(matrix[i*cols + j]);
        }
        str += "\n";
    }
    return str;
}

void Matrix2d::initWithNulls(){
    // for (int i = 0; i < rows; i++){
    //     for (int j = 0; j < cols; j++){
    //         matrix[i*cols + i] = 0;
    //     }
    // }
    for(std::ptrdiff_t i = 0; i < rows*cols; i++){
        matrix[i] = 0;
    }
}