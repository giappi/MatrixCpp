/*
* File:   Main.cpp
* Author: Giappi
*
* Created on 24/06/2017, 18:14 PM
*/

#include <stdio.h>
#include "com/giappi/lang/SquareMatrix.h"


void testCreate()
{
    printf("\n");
    printf("Initialize with list:\n");
    Matrix<int> A = { { 1, 2, 3 }, { -4, 6, 10} };
    printf("Matrix  A:\n%s\n", A.toString().c_str());
    printf("A.columns: %u\n", A.width);
    printf("A.rows   : %u\n", A.height);

    printf("\n");
    printf("Initialize with rows and columns:\n");
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
    printf("Initialize with rows and cols and fill value:\n");
    Matrix<int> C = Matrix<int>(3, 3, -1);
    printf("Matrix C:\n%s\n", C.toString().c_str());
    printf("\n");


}

void testTranspose()
{
    Matrix<int> A = { { 1, 2, 3 }, { -4, 6, 10 } };
    printf("Matrix  A:\n%s\n", A.toString().c_str());
    printf("A.columns: %u\n", A.getHeight());
    printf("A.rows   : %u\n", A.getWidth());

    printf("Transpose:\n");
    Matrix<int> B = A.toTranspose();
    printf("Matrix B:\n%s\n", B.toString().c_str());
    printf("Matrix A:\n%s\n", A.toString().c_str());
}

void testRotate()
{
    Matrix<int> A = { { 1, 2, 3, 0 }, { 4, 5, 6, 0 }, {7, 8, 9, 0} };
    printf("Matrix  A:\n%s\n", A.toString().c_str());
    printf("A.columns: %u\n", A.getHeight());
    printf("A.rows   : %u\n", A.getWidth());

    printf("Rotate Right:\n");
    Matrix<int> B = A.toRotateRight().toRotateLeft();
    printf("Matrix B:\n%s\n", B.toString().c_str());
    printf("Matrix A:\n%s\n", A.toString().c_str());
}

void testEquals()
{
    Matrix<int> A = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, -1, -2 } };
    Matrix<int> B = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, -1, -2 } };
    Matrix<int> C = { { 0, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, -1, -2 } };

    if (A.equals(B) == true && A.equals(C) == false)
    {
        printf("Passed!");
    }
    else
    {
        printf("Failed!");
    }
}

void testAdd()
{
    Matrix<int> A = { { 1, 2, 3, 0 }, { 4, 5, 6, 0 }, { 7, 8, 9,  0 } };
    Matrix<int> B = { { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1,  1 } };
    Matrix<int> T = { { 2, 3, 4, 1 }, { 5, 6, 7, 1 }, { 8, 9, 10, 1 } };

    Matrix<int> C = A + B;
    printf("+ Add two matrix: \n");
    printf("C = A + B:\n%s\n", C.toString().c_str());
    printf("Expected Result :\n%s\n", T.toString().c_str());
    if (C.equals(T))
    {
        printf("Passed!");
    }
    else
    {
        printf("Failed!");
    }
}

void testMinus()
{
    Matrix<int> A = { { 1, 2, 3, 0 }, { 4, 5, 6, 0 }, { 7, 8, 9, 0 } };
    Matrix<int> B = { { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 } };
    Matrix<int> T = { { 0, 1, 2, -1 }, { 3, 4, 5, -1 }, { 6, 7, 8, -1 } };

    Matrix<int> C = A - B;
    printf("+ Add two matrix: \n");
    printf("C = A + B:\n%s\n", C.toString().c_str());
    printf("Expected Result :\n%s\n", T.toString().c_str());
    if (C.equals(T))
    {
        printf("Passed!");
    }
    else
    {
        printf("Failed!");
    }
}

int square(int x)
{
    return x*x;
}

void testMap()
{
    Matrix<int> A = { { 1, 2, 3, 0 }, { 4, 5, 6, -1 }, { 7, 8, 9, 0 } };
    Matrix<int> B = A.map(square);
    //Matrix<int> B = A.map([](int e) -> int {return e*e; });
    printf("B = A.map(e => e*e):\n%s\n", B.toString().c_str());
    Matrix<int> T = { { 1, 4, 9, 0 }, { 16, 25, 36, 1 }, { 49, 64, 81, 0 } };
    if (T.equals(B))
    {
        printf("Passed!");
    }
    else
    {
        printf("Failed!");
    }

}

void testMultiply()
{
    Matrix<int> A = { { 1, 2, 3 }, { 4, 5, 6 }};
    Matrix<int> B = { { 7, 8 }, { 9, 10 }, { 11, 12 }, {13, 14} };
    Matrix<int> T = { {58, 64 }, {139, 154}};

    Matrix<int> C = A * B;
    printf("+ Multiply two matrix: \n");
    printf("C = A * B:\n%s\n", C.toString().c_str());
    printf("Expected Result :\n%s\n", T.toString().c_str());
    if (C.equals(T))
    {
        printf("Passed!");
    }
    else
    {
        printf("Failed!");
    }
}

int main()
{
    testMultiply();
    //SquareMatrix<int> a(3, 0);
    return 0;
}