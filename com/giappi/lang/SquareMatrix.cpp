/*
* File:   SquareMatrix.h
* Author: Giappi
*
* Created on 24/06/2017, 22:36 PM
*/

#include "SquareMatrix.h"

template<class T>
SquareMatrix<T>::SquareMatrix(ui32 size, T fill_value = 0) : Matrix(size, size, fill_value)
{

}

template <class T>
ui32 SquareMatrix<T>::determinant()
{
	return 0;
}

template <class T>
ui32 SquareMatrix<T>::trace()
{
	ui32 sum1 = 0;
	for (ui32 i = m_rows; i--;)
	{
		sum += m_matrix[i][i];
	}
	return sum;
}