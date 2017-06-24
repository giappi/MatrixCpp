/*
* File:   Matrix.cpp
* Author: Giappi
*
* Created on 24/06/2017, 18:00 PM
*/

#include "Matrix.h"
#include <algorithm>

// explicitly instantiate all the template instances
template class Matrix<char>;
template class Matrix<unsigned char>;
template class Matrix<int>;
template class Matrix<unsigned int>;
template class Matrix<long>;
template class Matrix<unsigned long>;
template class Matrix<long long>;
template class Matrix<unsigned long long>;
template class Matrix<float>;
template class Matrix<double>;


template<class T>
Matrix<T>::Matrix(ui32 rows, ui32 cols, T fill_value = 0)
{
    m_rows = rows;
    m_cols = cols;
    m_matrix = new T*[rows];
    for (int i = rows; i--;)
    {
        m_matrix[i] = new T[cols];
        for (int j = cols; j--;)
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
        int m = 0;
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
Matrix<T>::Matrix(Matrix<T>& matrix)
{
    m_rows = matrix.getWidth();
    m_cols = matrix.getHeight();
    m_matrix = new T*[m_rows];
    for (int i = m_rows; i--;)
    {
        m_matrix[i] = new T[m_cols];
        for (int j = m_cols; j--;)
        {
            m_matrix[i][j] = matrix.getElementAt(i, j);
        }
    }
}

template<class T>
T    Matrix<T>::getElementAt(ui32 row_index, ui32 col_index)
{
    return m_matrix[row_index][col_index];
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
ui32 Matrix<T>::getWidth()
{
    return m_rows;
}

template<class T>
ui32 Matrix<T>::getHeight()
{
    return m_cols;
}

template<class T>
std::string Matrix<T>::toString()
{
    std::string s = "";
    for (int i = 0; i < m_rows; ++i)
    {
        for (int j = 0; j < m_cols; ++j)
        {
            s += std::to_string(m_matrix[i][j]);
            j < m_cols - 1 && (s += "\t", 0);
        }
        i < m_rows -1 && (s += "\n", 0);
    }
    return s;
}

template<class T>
Matrix<T> Matrix<T>::toRotateLeft()
{
	// swap rows and cols
	Matrix<T> matrix_T = Matrix<T>(m_cols, m_rows);

	for (int i = m_rows; i--;)
	{
		for (int j = m_cols; j--;)
		{
			matrix_T[j][i] = m_matrix[i][m_cols - 1 -j];
		}
	}

	return matrix_T;
}

template<class T>
Matrix<T> Matrix<T>::toRotateRight()
{
	// swap rows and cols
	Matrix<T> matrix_T = Matrix<T>(m_cols, m_rows);

	for (int i = m_rows; i--;)
	{
		for (int j = m_cols; j--;)
		{
			matrix_T[j][i] = m_matrix[m_rows - 1 - i][j];
		}
	}

	return matrix_T;
}

template<class T>
Matrix<T> Matrix<T>::toTranspose()
{
    // swap rows and cols
    Matrix<T> matrix_T = Matrix<T>(m_cols, m_rows);

    for (int i = m_rows; i--;)
    {
        for (int j = m_cols; j--;)
        {
            matrix_T[j][i] = m_matrix[i][j];
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
