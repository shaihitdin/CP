/*
 * WARNING
 *
 *     DO NOT TOUCH THIS FILE.
 */


#ifndef EP1_PROJ2_MATRIX_H
#define EP1_PROJ2_MATRIX_H

#include <list>



typedef struct Matrix {
    int numRows;
    int numCols;
    float* mat;
} Matrix;


Matrix* zeros(const int numRows, const int numCols);
Matrix* ones(const int numRows, const int numCols);
Matrix* rand(const int numRows, const int numCols);
Matrix* add(const Matrix* A, const Matrix* B);
Matrix* add(const Matrix* A, const Matrix* B, const Matrix* C);
Matrix* transpose(const Matrix* A);
Matrix* multiply(const Matrix* A, const Matrix* B);
Matrix* multiply(const Matrix* A, const Matrix* B, const Matrix* C);
Matrix* multiply(const Matrix* A, const float c);
Matrix* load(const char* fname);
Matrix* bload(const char* fname);
void save(const Matrix* A, const char* fname);
void bsave(const Matrix* A, const char* fname);
void show(const Matrix* A);
void del(const Matrix* mat);




typedef struct SparseElementTriplet {
    SparseElementTriplet(int _row, int _col, float _value) {
        row = _row;
        col = _col;
        value = _value;
    }
    int row;
    int col;
    float value;
} SparseElementTriplet;

typedef struct SparseMatrix {
    int numRows;
    int numCols;
    std::list<SparseElementTriplet> *mat;
} SparseMatrix;

SparseMatrix* spzeros(const int numRows, const int numCols);
SparseMatrix* spones(const int numRows, const int numCols);
SparseMatrix* sprand(const int numRows, const int numCols);
SparseMatrix* spadd(const SparseMatrix* A, const SparseMatrix* B);
SparseMatrix* spadd(const SparseMatrix* A, const SparseMatrix* B, const SparseMatrix* C);
SparseMatrix* transpose(const SparseMatrix* A);
SparseMatrix* spmultiply(const SparseMatrix* A, const SparseMatrix* B);
SparseMatrix* spmultiply(const SparseMatrix* A, const SparseMatrix* B, const SparseMatrix* C);
SparseMatrix* spmultiply(const SparseMatrix* A, const float c);
SparseMatrix* spload(const char* fname);
SparseMatrix* spbload(const char* fname);
void spsave(const SparseMatrix* A, const char* fname);
void spbsave(const SparseMatrix*A, const char* fname);
void spshow(const SparseMatrix* A);
void spdel(const SparseMatrix* mat);


#endif
