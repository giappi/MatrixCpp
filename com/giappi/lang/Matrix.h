/*
* File:   Matrix.h
* Author: Giappi
*
* Created on 24/06/2017, 18:00 PM
*/

#pragma once
#include <string>
#include <initializer_list>


typedef unsigned int ui32;
typedef bool boolean;
#define null nullptr;

template<class T>
class Matrix
{
public:

    /* initialaze matrix with numbers of rows, numbers of comlumns, and fill with a value */
    Matrix(ui32 rows, ui32 cols, T fill_value = 0);
    /* init matrix with two dimensions array list */
    Matrix(std::initializer_list<std::initializer_list<T>> list);
    /* copy constructor */
    Matrix(const Matrix<T>& matrix);
    ~Matrix();

public:

    /* get element at @row_index and @col_index */
    T getElementAt(ui32 row_index, ui32 col_index) const;

    /* get element at @row_index and @col_index, if not exist, take default value */
    T getElementAtOr(ui32 row_index, ui32 col_index, T default_value) const;

    /* set element at @row_index and @col_index */
    void setElementAt(ui32 row_index, ui32 col_index, T element);

    /* to get element by operator [] */
    const T* operator [](ui32 index) const;
    /* to set element by operator [] */
    T* operator [](ui32 index);

    /* add two matrix with same size */
    Matrix<T> operator +(const Matrix<T> matrix2);
    /* subtract two matrix with same size */
    Matrix<T> operator -(const Matrix<T> matrix2);
    /* multiply matrix size (m x p) and size (p x n)  */
    Matrix<T> operator *(const Matrix<T> matrix2);
    /* negative matrix */
    Matrix<T> operator -();

    /* compare two matrix */
    boolean equals(Matrix<T> matrix2) const;

    /* fill all elements by @value */
    void fill(T value);

    /* get numbers of rows */
    ui32 getWidth() const;

    /* get numbers of columns */
    ui32 getHeight() const;

    /* map matrix by a function: y = f(x) */
    Matrix<T> map(T (*function1)(T)) const;

    /* get matrix as string that is printable */
    std::string toString() const;

    /* get identity matrix (fill matrix by number 1) */
    Matrix<T> toIdentity() const;

    /* return a rotated matrix of this matrix */
    Matrix<T> toRotateLeft() const;

    /* return a rotated matrix of this matrix */
    Matrix<T> toRotateRight() const;

    /* return a transpose matrix of this matrix */
    Matrix<T> toTranspose() const;

public:
    /* get numbers of rows */
    const ui32 &width;
    /* get numbers of columns */
    const ui32 &height;

protected:
    T** m_matrix = null;
    ui32 m_rows = 0;
    ui32 m_cols = 0;

};

