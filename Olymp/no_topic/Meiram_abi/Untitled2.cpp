#include "matrix.h"
#include <bits/stdc++.h>

using namespace std;

Matrix* rand(const int numRows, const int numCols)
{
    Matrix * cur = new Matrix;
    cur -> numRows = numRows;
    cur -> numCols = numCols;
    cur -> mat = new float[numRows * numCols];
    for (int i = 0; i < numRows * numCols; ++ i)
        cur -> mat[i] = rand() % 100 + 1;
    return cur;
}
Matrix* ones(const int numRows, const int numCols)
{
    Matrix * cur = new Matrix;
    cur -> numRows = numRows;
    cur -> numCols = numCols;
    cur -> mat = new float[numRows * numCols];
    for (int i = 0; i < numRows * numCols; ++ i)
        cur -> mat[i] = 1;
    return cur;
}
Matrix* zeros(const int numRows, const int numCols)
{
    Matrix * cur = new Matrix;
    cur -> numRows = numRows;
    cur -> numCols = numCols;
    cur -> mat = new float[numRows * numCols];
    for (int i = 0; i < numRows * numCols; ++ i)
        cur -> mat[i] = 0;
    return cur;
}
Matrix* add(const Matrix* A, const Matrix* B)
{
    if (A -> numRows != B -> numRows || A -> numCols != B -> numCols)
        return NULL;
    Matrix * cur = new Matrix;
    cur -> numRows = A -> numRows;
    cur -> numCols = A -> numCols;
    cur -> mat = new float[(A -> numRows) * (A -> numCols)];
    for (int i = 0; i < (A -> numRows) * (A -> numCols); ++ i)
        cur -> mat[i] = A -> mat[i] + B -> mat[i];
    return cur;
}
Matrix* add(const Matrix* A, const Matrix* B, const Matrix* C)
{
    if (A -> numRows != B -> numRows || A -> numCols != B -> numCols || A -> numRows != C -> numRows || A -> numCols != C -> numCols)
        return NULL;
    Matrix * cur = new Matrix;
    cur -> numRows = A -> numRows;
    cur -> numCols = A -> numCols;
    cur -> mat = new float[(A -> numRows) * (A -> numCols)];
    for (int i = 0; i < (A -> numRows) * (A -> numCols); ++ i)
        cur -> mat[i] = A -> mat[i] + B -> mat[i] + C -> mat[i];
    return cur;
}
Matrix* transpose(const Matrix* A)
{
    Matrix * cur = new Matrix;
    cur -> numRows = A -> numRows;
    cur -> numCols = A -> numCols;
    cur -> mat = new float[(A -> numRows) * (A -> numCols)];
    for (int i = 0; i < (A -> numRows) * (A -> numCols); ++ i)
        cur -> mat[i] = A -> mat[i];
    return cur;
}
Matrix* multiply(const Matrix* A, const Matrix* B)
{
    if (A -> numCols != B -> numRows)
        return NULL;
    Matrix * cur = new Matrix;
    cur -> numRows = A -> numRows;
    cur -> numCols = B -> numCols;
    cur -> mat = new float[(cur -> numRows) * (cur -> numCols)];
    for (int i = 0; i < cur -> numRows; ++ i)
    {
        for (int j = 0; j < cur -> numCols; ++ j)
        {
            cur -> mat[i * cur -> numCols + j] = 0;
            for (int k = 0; k < A -> numCols; ++ k)
            {
                cur -> mat[i * cur -> numCols + j] += A -> mat[i * A -> numCols + k] * B -> mat[k * B -> numCols + j];
            }
        }
    }
    return cur;
}
int getTime(int A, int B, int C, int D)
{
    return A * B * D;
}
Matrix* multiply(const Matrix* A, const Matrix* B, const Matrix* C)
{
    if (A -> numCols != B -> numRows || B -> numCols != C -> numRows)
        return NULL;
    int RequiredTime1 = getTime(A -> numRows, A -> numCols, B -> numRows, B -> numCols) + getTime(A -> numRows, B -> numCols, C -> numRows, C -> numCols);
    int RequiredTime2 = getTime(B -> numRows, B -> numCols, C -> numRows, C -> numCols) + getTime(A -> numRows, A -> numCols, B -> numRows, C -> numCols);
    if (RequiredTime1 <= RequiredTime2)
    {
        Matrix * cur = multiply(A, B);
        return multiply(cur, C);
    }
    else
    {
        Matrix * cur = multiply(B, C);
        return multiply(A, cur);
    }
}
Matrix* multiply(const Matrix* A, const float c)
{
    if (A == NULL)
        return NULL;
    Matrix * cur = new Matrix;
    cur -> numRows = A -> numRows;
    cur -> numCols = A -> numCols;
    cur -> mat = new float[(A -> numRows) * (A -> numCols)];
    for (int i = 0; i < (A -> numRows) * (A -> numCols); ++ i)
        cur -> mat[i] = A -> mat[i] * c;
    return cur;
}
Matrix* load(const char* fname)
{
    ifstream InFile(fname);
    Matrix * cur = new Matrix;
    InFile >> cur -> numRows >> cur -> numCols;
    cur -> mat = new float[(cur -> numRows) * (cur -> numCols)];
    for (int i = 0; i < (cur -> numRows) * (cur -> numCols); ++ i)
        InFile >> cur -> mat[i];
    InFile.close();
    return cur;
}
Matrix* bload(const char* fname)
{
    ifstream InFile(fname, ios::binary);
    Matrix * cur = new Matrix;
    InFile >> cur -> numRows >> cur -> numCols;
    cur -> mat = new float[(cur -> numRows) * (cur -> numCols)];
    for (int i = 0; i < (cur -> numRows) * (cur -> numCols); ++ i)
        InFile >> cur -> mat[i];
    InFile.close();
    return cur;
}
void save(const Matrix* A, const char* fname)
{
    ofstream OutFile(fname);
    OutFile << A -> numRows << " " << A -> numCols << endl;
    for (int i = 0; i < (A -> numRows) * (A -> numCols); ++ i)
    {
        OutFile << A -> mat[i] << " ";
        if ((i + 1) % (A -> numCols) == 0) OutFile << "\n";
    }
    OutFile.close();
}
void bsave(const Matrix* A, const char* fname)
{
    ofstream OutFile(fname, ios::binary);
    OutFile << A -> numRows << " " << A -> numCols << endl;
    for (int i = 0; i < (A -> numRows) * (A -> numCols); ++ i)
    {
        OutFile << A -> mat[i] << " ";
        if ((i + 1) % (A -> numCols) == 0) OutFile << "\n";
    }
    OutFile.close();
}
void show(const Matrix* A)
{
    for (int i = 0; i < (int)A -> numRows * (int)A -> numCols; ++ i)
    {
        cout << A -> mat[i] << "   ";
        if ((i + 1) % A -> numCols == 0) cout << "\n";
    }
}
void del(const Matrix* A)
{
    if (A == NULL) return;
    delete A -> mat;
    delete A;
}
SparseMatrix* spzeros(const int numRows, const int numCols)
{
    SparseMatrix * cur = new SparseMatrix;
    cur -> numRows = numRows;
    cur -> numCols = numCols;
    cur -> mat = new list<SparseElementTriplet> ;
    return cur;
}
SparseMatrix* spones (const int numRows, const int numCols)
{
    SparseMatrix * cur = new SparseMatrix;
    cur -> numRows = numRows;
    cur -> numCols = numCols;
    cur -> mat = new list < SparseElementTriplet >;
    for (int i = 0; i < numRows; ++ i)
    {
        for (int j = 0; j < numCols; ++ j)
        {
            cur -> mat -> push_back (SparseElementTriplet(i, j, 1));
        }
    }
    return cur;
}
SparseMatrix* sprand(const int numRows, const int numCols)
{
    SparseMatrix * cur = new SparseMatrix;
    cur -> numRows = numRows;
    cur -> numCols = numCols;
    cur -> mat = new list<SparseElementTriplet>;
    for (int i = 0; i < numRows; ++ i)
    {
        for (int j = 0; j < numCols; ++ j)
        {
            float Value = rand() % 100 + 1;
            cur -> mat -> push_back(SparseElementTriplet(i, j, Value));
        }
    }
    return cur;
}
float GetValue(const SparseMatrix * A, int i, int j)
{
    list < SparseElementTriplet > :: iterator it;
    for (it = A -> mat -> begin(); it != A -> mat -> end(); ++it)
        if (it -> row == i && it -> col == j)
            return it -> value;
    return 0;
}
SparseMatrix* spadd(const SparseMatrix* A, const SparseMatrix* B)
{
    if (A -> numRows != B -> numRows || A -> numCols != B -> numCols)
        return NULL;
    SparseMatrix * cur = new SparseMatrix;
    cur -> numRows = A -> numRows;
    cur -> numCols = A -> numCols;
    cur -> mat = new list <SparseElementTriplet> ;
    for (int i = 0; i < cur -> numRows; ++ i)
    {
        for (int j = 0; j < cur -> numCols; ++ j)
        {
            float Value = GetValue(A, i, j) + GetValue(B, i, j);
            if (Value != 0.0)
                cur -> mat -> push_back(SparseElementTriplet(i, j, Value));
        }
    }
    return cur;
}
SparseMatrix* spadd(const SparseMatrix* A, const SparseMatrix* B, const SparseMatrix* C)
{
    if (A -> numRows != B -> numRows || A -> numCols != B -> numCols || A -> numRows != C -> numRows || A -> numCols != C -> numCols)
        return NULL;
    SparseMatrix * cur = new SparseMatrix;
    cur -> numRows = A -> numRows;
    cur -> numCols = A -> numCols;
    cur -> mat = new list <SparseElementTriplet> ;
    for (int i = 0; i < cur -> numRows; ++ i)
    {
        for (int j = 0; j < cur -> numCols; ++ j)
        {
            float Value = GetValue(A, i, j) + GetValue(B, i, j) + GetValue(C, i, j);
            if (Value != 0.0)
                cur -> mat -> push_back(SparseElementTriplet(i, j, Value));
        }
    }
    return cur;
}
SparseMatrix* transpose(const SparseMatrix* A)
{
    SparseMatrix * cur = new SparseMatrix;
    cur -> numRows = A -> numRows;
    cur -> numCols = A -> numCols;
    cur -> mat = new list <SparseElementTriplet> ;
    list <SparseElementTriplet> :: iterator it;
    for (it = A -> mat -> begin(); it != A -> mat -> end(); ++it)
        cur -> mat -> push_back(SparseElementTriplet(it -> row, it -> col, it -> value));
    return cur;
}
SparseMatrix* spmultiply(const SparseMatrix* A, const SparseMatrix* B)
{
    if (A -> numCols != B -> numRows)
        return NULL;
    SparseMatrix * cur = new SparseMatrix;
    cur -> numRows = A -> numRows;
    cur -> numCols = B -> numCols;
    cur -> mat = new list<SparseElementTriplet>;
    for (int i = 0; i < cur -> numRows; ++ i)
    {
        for (int j = 0; j < cur -> numCols; ++ j)
        {
            float Value = 0;
            for (int k = 0; k < A -> numCols; ++ k)
            {
                Value += GetValue(A, i, k) * GetValue(B, k, j);
            }
            if (Value != 0.0)
            {
                cur -> mat -> push_back(SparseElementTriplet(i, j, Value));
            }
        }
    }
    return cur;
}
SparseMatrix* spmultiply(const SparseMatrix* A, const SparseMatrix* B, const SparseMatrix* C)
{
    if (A -> numCols != B -> numRows || B -> numCols != C -> numRows)
        return NULL;
    int RequiredTime1 = getTime(A -> numRows, A -> numCols, B -> numRows, B -> numCols) + getTime(A -> numRows, B -> numCols, C -> numRows, C -> numCols);
    int RequiredTime2 = getTime(B -> numRows, B -> numCols, C -> numRows, C -> numCols) + getTime(A -> numRows, A -> numCols, B -> numRows, C -> numCols);
    if (RequiredTime1 <= RequiredTime2)
    {
        SparseMatrix * cur = spmultiply(A, B);
        return spmultiply(cur, C);
    }
    else
    {
        SparseMatrix * cur = spmultiply(B, C);
        return spmultiply(A, cur);
    }
}
SparseMatrix* spmultiply(const SparseMatrix* A, const float c)
{
    SparseMatrix * cur = new SparseMatrix;
    cur -> numRows = A -> numRows;
    cur -> numCols = A -> numCols;
    cur -> mat = new list <SparseElementTriplet> ;
    for (int i = 0; i < cur -> numRows; ++ i)
    {
        for (int j = 0; j < cur -> numCols; ++ j)
        {
            float Value = GetValue(A, i, j) * c;
            if (Value != 0.0)
                cur -> mat -> push_back(SparseElementTriplet(i, j, Value));
        }
    }
    return cur;
}
SparseMatrix* spload(const char* fname)
{
    ifstream InFile(fname);
    SparseMatrix * cur = new SparseMatrix;
    InFile >> cur -> numRows >> cur -> numCols;
    cur -> mat = new list <SparseElementTriplet>;
    int sz;
    InFile >> sz;
    for (int i = 1; i <= sz; ++ i)
    {
        int Row, Col;
        float Val;
        InFile >> Row >> Col >> Val;
        cur -> mat -> push_back(SparseElementTriplet(Row, Col, Val));
    }
    InFile.close();
    return cur;
}
SparseMatrix* spbload(const char* fname)
{
    ifstream InFile(fname, ios::binary);
    SparseMatrix * cur = new SparseMatrix;
    InFile >> cur -> numRows >> cur -> numCols;
    cur -> mat = new list <SparseElementTriplet>;
    int sz;
    InFile >> sz;
    for (int i = 1; i <= sz; ++ i)
    {
        int Row, Col;
        float Val;
        InFile >> Row >> Col >> Val;
        cur -> mat -> push_back(SparseElementTriplet(Row, Col, Val));
    }
    InFile.close();
    return cur;
}
void spsave(const SparseMatrix* A, const char* fname)
{
    ofstream OutFile(fname);
    OutFile << A -> numRows << " " << A -> numCols << endl;
    OutFile << A -> mat -> size() << endl;
    list <SparseElementTriplet> :: iterator it;
    for (it = A -> mat -> begin(); it != A -> mat -> end(); ++ it)
        OutFile << it -> row << " " << it -> col << " " << it -> value << endl;
    OutFile.close();
}
void spbsave(const SparseMatrix* A, const char* fname)
{
    ofstream OutFile(fname, ios::binary);
    OutFile << A -> numRows << " " << A -> numCols << endl;
    OutFile << A -> mat -> size() << endl;
    list <SparseElementTriplet> :: iterator it;
    for (it = A -> mat -> begin(); it != A -> mat -> end(); ++ it)
        OutFile << it -> row << " " << it -> col << " " << it -> value << endl;
    OutFile.close();
}
void spshow(const SparseMatrix* A)
{
    if (A == NULL)
        return;
    for (int i = 0; i < A -> numRows; ++ i)
    {
        for (int j = 0; j < A -> numCols; ++ j)
        {
            cout << GetValue(A, i, j) << "   ";
        }
        cout << "\n";
    }
}
void spdel(const SparseMatrix* mat)
{
    if (mat == NULL)
        return;
    delete mat -> mat;
    delete mat;
}