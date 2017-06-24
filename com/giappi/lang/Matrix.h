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
    Matrix(Matrix<T>& matrix);
    ~Matrix();

public:

    /* get element at @row_index and @col_index */
    T getElementAt(ui32 row_index, ui32 col_index);

    /* get element at @row_index and @col_index */
    void setElementAt(ui32 row_index, ui32 col_index, T element);

    /* to get and set element by operator [] */
    const T* operator [](ui32 index) const;
    T* operator [](ui32 index);

    /* get numbers of rows */
    ui32 getWidth();

    /* get numbers of columns */
    ui32 getHeight();

    /* get matrix as string that is printable */
    std::string toString();

	/* return a rotated matrix of this matrix */
	Matrix<T> toRotateLeft();

	/* return a rotated matrix of this matrix */
	Matrix<T> toRotateRight();

    /* return a transpose matrix of this matrix */
    Matrix<T> toTranspose();

private:
    T** m_matrix = null;
    ui32 m_rows = 0;
    ui32 m_cols = 0;

};

