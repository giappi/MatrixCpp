/*
* File:   SquareMatrix.h
* Author: Giappi
*
* Created on 24/06/2017, 22:36 PM
*/

#pragma once
#include "Matrix.h"

template<class T>
class SquareMatrix: Matrix<T>
{
public:
	/* init matrix with size */
	SquareMatrix(ui32 size, T fill_value = 0);

	/* get determinant of square matrix */
	ui32 determinant();

	/* calculate trace of square matrix */
	ui32 trace();


};

