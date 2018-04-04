// MathExample.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "MathFunctionsStatic.h"
#include "MathFunctionsDynamic.h"

using namespace std;

int main()
{
	double complex[3][3][2];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 2; k++)
			{
				complex[i][j][k] = rand()%5;
			}
	//cout << MathFunctionsDynamic::add(6, 3) << endl;
	cout << MathFunctionsStatic::areaOfRegularPolygon(sqrt(2),4) << endl;
	MathFunctionsStatic::matrixDeterminantThreeOfComplex(complex);
	MathFunctionsStatic::sqrtComplex(1, 0, 4);
	return 0;
}

