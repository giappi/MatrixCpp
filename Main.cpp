/*
* File:   Main.cpp
* Author: Giappi
*
* Created on 24/06/2017, 18:14 PM
*/

#include <stdio.h>
#include "com/giappi/lang/Matrix.h"


void testCreate()
{
	printf("\n");
	printf("Initialze with list:\n");
	Matrix<int> A = { { 1, 2, 3 }, { -4, 6, 10} };
	printf("Matrix  A:\n%s\n", A.toString().c_str());
	printf("A.columns: %d\n", A.getHeight());
	printf("A.rows   : %d\n", A.getWidth());

	printf("\n");
	printf("Initialze with rows and cols:\n");
	Matrix<int> B = Matrix<int>(2, 3);
	printf("Matrix B:\n%s\n", B.toString().c_str());
	printf("Set value for B:\n");
	B[0][0] = 1;
	B[0][1] = 2;
	B[0][2] = 3;
	B[1][0] = -6;
	B[1][1] = 7;
	B[1][2] = 8;
	printf("Matrix B:\n%s\n", B.toString().c_str());
	printf("Element at (1, 0) is %d\n", B[1][0]);

	printf("\n");
	printf("Initialze with rows and cols and fill value:\n");
	Matrix<int> C = Matrix<int>(3, 3, -1);
	printf("Matrix C:\n%s\n", C.toString().c_str());
	printf("\n");


}

void testTranspose()
{
	Matrix<int> A = { { 1, 2, 3 }, { -4, 6, 10 } };
	printf("Matrix  A:\n%s\n", A.toString().c_str());
	printf("A.columns: %d\n", A.getHeight());
	printf("A.rows   : %d\n", A.getWidth());

	printf("Transpose:\n");
	Matrix<int> B = A.toTranspose();
	printf("Matrix B:\n%s\n", B.toString().c_str());
	printf("Matrix A:\n%s\n", A.toString().c_str());
}

void testRotate()
{
	Matrix<int> A = { { 1, 2, 3, 0 }, { 4, 5, 6, 0 }, {7, 8, 9, 0} };
	printf("Matrix  A:\n%s\n", A.toString().c_str());
	printf("A.columns: %d\n", A.getHeight());
	printf("A.rows   : %d\n", A.getWidth());

	printf("Rotate Right:\n");
	Matrix<int> B = A.toRotateRight().toRotateLeft();
	printf("Matrix B:\n%s\n", B.toString().c_str());
	printf("Matrix A:\n%s\n", A.toString().c_str());
}

int main()
{
	testRotate();

    return 0;
}