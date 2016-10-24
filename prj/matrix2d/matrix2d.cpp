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
    // for (int i = 0; i < rows; i++){
        // for (int j = 0; j < cols; j++){
        //     matrix[i*j + j] = array[i*j + j];
        // }
    // }
    for (int i = 0; i < cols*rows; i++){
        matrix[i] = array[i];
    }
}

Matrix2d::Matrix2d(const Matrix2d& m){
    cols = m.cols;
    rows = m.rows;
    matrix = new int[cols * rows];
    copyOrWat(m);
}

void Matrix2d::copyOrWat(const Matrix2d& m){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            matrix[i*j + j] = m.matrix[i*j + j];
        }
    }
}

Matrix2d Matrix2d::operator= (const Matrix2d& m){
    cols = m.cols;
    rows = m.rows;
    matrix = new int[cols * rows];
    copyOrWat(m);
}

Matrix2d::~Matrix2d(){
    delete [] matrix;
}


// other methods
std::string Matrix2d::toString() const{
    std::string str = "";
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            str += std::to_string(matrix[i*cols + j]);
        }
        str += "\n";
    }
    return str;
}

void Matrix2d::initWithNulls(){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            matrix[i*j + i] = 0;
        }
    }
}