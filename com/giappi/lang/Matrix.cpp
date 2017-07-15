/*
* File:   Matrix.cpp
* Author: Giappi
*
* Created on 24/06/2017, 18:00 PM
*/

#include "Matrix.h"
#include <algorithm>



template<class T>
Matrix<T>::Matrix(ui32 rows, ui32 cols, T fill_value)
{
    m_rows = rows;
    m_cols = cols;
    m_matrix = new T*[rows];
    for (auto i = rows; i--;)
    {
        m_matrix[i] = new T[cols];
        for (auto j = cols; j--;)
        {
            m_matrix[i][j] = fill_value;
        }
    }
}

template<class T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> lists) : m_rows(0), m_cols(0)
{
    m_matrix = new T*[lists.size()];
    for (auto list : lists)
    {
        m_matrix[m_rows] = new T[list.size()];
        ui32 m = 0;
        for (auto e : list)
        {
            m_matrix[m_rows][m++] = e;
            if (m > m_cols)
            {
                m_cols = m;
            }
        }
        ++m_rows;
    }
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& matrix)
{
    m_rows = matrix.getWidth();
    m_cols = matrix.getHeight();
    m_matrix = new T*[m_rows];
    for (auto i = m_rows; i--;)
    {
        m_matrix[i] = new T[m_cols];
        for (auto j = m_cols; j--;)
        {
            m_matrix[i][j] = matrix.getElementAt(i, j);
        }
    }
}

template<class T>
T    Matrix<T>::getElementAt(ui32 row_index, ui32 col_index) const
{
    return m_matrix[row_index][col_index];
}

template<class T>
T    Matrix<T>::getElementAtOr(ui32 row_index, ui32 col_index, T default_value) const
{
    return (row_index < m_rows && col_index < m_cols) ? m_matrix[row_index][col_index] : default_value;
}

template<class T>
void Matrix<T>::setElementAt(ui32 row_index, ui32 col_index, T element)
{
    m_matrix[row_index][col_index] = element;
}

template<class T>
const T*    Matrix<T>::operator[](ui32 index) const
{
    return m_matrix[index];
}

template<class T>
T*    Matrix<T>::operator[](ui32 index)
{
    return m_matrix[index];
}

template<class T>
Matrix<T> Matrix<T>::operator+(Matrix<T> matrix1)
{
    Matrix<T> matrix3 = Matrix<T>(m_rows, m_cols, 0);
    for (auto i = m_rows; i--;)
    {
        for (auto j = m_cols; j--;)
        {
            //  size of matrix1 may be difference from this
            matrix3.m_matrix[i][j] = m_matrix[i][j] + matrix1.getElementAtOr(i, j, 0);
        }
    }
    return matrix3;
}

template<class T>
Matrix<T> Matrix<T>::operator-(Matrix<T> matrix1)
{
    // copy size of this
    Matrix<T> matrix3 = Matrix<T>(m_rows, m_cols, 0);
    for (auto i = m_rows; i--;)
    {
        for (auto j = m_cols; j--;)
        {
            matrix3.m_matrix[i][j] = m_matrix[i][j] - matrix1.getElementAtOr(i, j, 0);
        }
    }
    return matrix3;
}

template<class T>
Matrix<T> Matrix<T>::operator*(Matrix<T> matrix1)
{
    // check if matrix A(m x p) and B(p x n)
    if (m_cols != matrix1.m_rows)
    {
        return Matrix<T>({ {} });
    }
    Matrix<T> matrix3 = Matrix<T>(m_rows, matrix1.m_cols, 0);
    for (auto i = matrix3.m_rows; i--;)
    {
        for (auto j = matrix3.m_cols; j--;)
        {
            ui32 t = 0;
            for (auto k = 0; k < m_cols; k++)
            {
                t += m_matrix[i][k] * matrix1.m_matrix[k][j];
            }
            matrix3.m_matrix[i][j] = t;
        }
    }
    return matrix3;
}

template<class T>
Matrix<T> Matrix<T>::operator-()
{
    Matrix<T> matrix1 = Matrix<T>(m_rows, m_cols, 0);
    for (auto i = m_rows; i--;)
    {
        for (auto j = m_cols; j--;)
        {
            matrix1.m_matrix[i][j] = -m_matrix[i][j];
        }
    }
    return matrix1;
}

template<class T>
boolean Matrix<T>::equals(Matrix<T> matrix1) const
{
    if (getWidth() != matrix1.getWidth() || getHeight() != matrix1.getHeight())
    {
        return false;
    }
    boolean result = true;
    for (auto i = m_rows; i--;)
    {
        for (auto j = m_cols; j--;)
        {
            result &= m_matrix[i][j] == matrix1.m_matrix[i][j];
        }
    }
    return result;
}

template<class T>
void Matrix<T>::fill(T value)
{
    for (auto i = m_rows; i--;)
    {
        for (auto j = m_cols; j--;)
        {
            m_matrix[i][j] = value;
        }
    }
    return;
}

template<class T>
ui32 Matrix<T>::getWidth() const
{
    return m_rows;
}

template<class T>
ui32 Matrix<T>::getHeight() const
{
    return m_cols;
}

template<class T>
Matrix<T> Matrix<T>::map(T(*function1)(T)) const
{
    Matrix<T> matrix1 = Matrix<T>(m_rows, m_cols, 0);
    for (auto i = m_rows; i--;)
    {
        for (auto j = m_cols; j--;)
        {
            matrix1.m_matrix[i][j] = function1(m_matrix[i][j]);
        }
    }
    return matrix1;
}

template<class T>
std::string Matrix<T>::toString() const
{
    std::string s = "";
    for (auto i = 0; i < m_rows; ++i)
    {
        for (auto j = 0; j < m_cols; ++j)
        {
            s += std::to_string(m_matrix[i][j]);
            j < m_cols - 1 && (s += "\t", 0);
        }
        i < m_rows -1 && (s += "\n", 0);
    }
    return !s.empty() ? s : "<empty>";
}


template<class T>
Matrix<T> Matrix<T>::toIdentity() const
{
    Matrix<T> matrix_T = Matrix<T>(m_cols, m_rows);
    matrix_T.fill((T)1);
    return matrix_T;
}

template<class T>
Matrix<T> Matrix<T>::toRotatedLeft() const
{
    // swap rows and cols
    Matrix<T> matrix_T = Matrix<T>(m_cols, m_rows);

    for (auto i = m_rows; i--;)
    {
        for (auto j = m_cols; j--;)
        {
            matrix_T.m_matrix[j][i] = m_matrix[i][m_cols - 1 -j];
        }
    }

    return matrix_T;
}

template<class T>
Matrix<T> Matrix<T>::toRotatedRight() const
{
    // swap rows and cols
    Matrix<T> matrix_T = Matrix<T>(m_cols, m_rows);

    for (auto i = m_rows; i--;)
    {
        for (auto j = m_cols; j--;)
        {
            matrix_T.m_matrix[j][i] = m_matrix[m_rows - 1 - i][j];
        }
    }

    return matrix_T;
}

template<class T>
Matrix<T> Matrix<T>::toTransposed() const
{
    // swap rows and cols
    Matrix<T> matrix_T = Matrix<T>(m_cols, m_rows);

    for (auto i = m_rows; i--;)
    {
        for (auto j = m_cols; j--;)
        {
            matrix_T.m_matrix[j][i] = m_matrix[i][j];
        }
    }

    return matrix_T;
}

template<class T>
Matrix<T>::~Matrix()
{
    while (m_rows)
    {
        delete[] m_matrix[--m_rows];
    }
    delete[] m_matrix;
    m_cols = 0;
}


// explicitly instantiate all the template instances
// important to put this at end of soure files (fix linker in clang compiler)
template class Matrix<char>;
//template class Matrix<unsigned char>;
template class Matrix<int>;
//template class Matrix<unsigned int>;
template class Matrix<long>;
//template class Matrix<unsigned long>;
template class Matrix<long long>;
//template class Matrix<unsigned long long>;
template class Matrix<float>;
template class Matrix<double>;
