/*
* File:   Main.cpp
* Author: Giappi
*
* Created on 24/06/2017, 18:14 PM
*/

#include <stdio.h>
#include "com/giappi/lang/Matrix.h"

int main()
{
	{
		/*
		Matrix<int> A = { { 1, 2, 3 }, { -4, 6, 10} };
		*/
		Matrix<int> A = Matrix<int>(2, 3);
		A[0][0] = 1;
		A[0][1] = 2;
		A[0][2] = 3;
		A[1][0] = -6;
		A[1][1] = 7;
		A[1][2] = 8;

		printf("columns: %d\n", A.getHeight());
		printf("rows   : %d\n", A.getWidth());
		printf("Matrix A:\n%s\n", A.toString().c_str());
		printf("Element at (1, 0) is %d\n", A[1][0]);

		printf("\n");

		Matrix<int> B = A.toTranspose();
		printf("Matrix B:\n%s\n", B.toString().c_str());
	}

	return 0;
}