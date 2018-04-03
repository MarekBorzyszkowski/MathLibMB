#define PI 3.14159265359
#include <cmath>
#include <iostream>
#include "MathFunctionsStatic.h"

using namespace std;

namespace MathFunctionsStatic
{

	double areaOfRegularPolygon(double R, double angle) {
		double area = 0.5*angle*R*R*sin(2 * PI/ angle);
		cout << "Area of " << angle << " polygon is: ";
		return area;
	}

	void matrixDeterminantThreeOfComplex(double complex[3][3][2]) {
		double real = 0,imagine = 0;
		for (int i = 0; i < 3; i++)
		{
			real += complex[i][0][0] * complex[(i + 1) % 3][1][0] * complex[(i + 2) % 3][2][0];
		}
		for (int i = 0; i < 3; i++)
		{
			real -= complex[i][2][0] * complex[(i + 1) % 3][1][0] * complex[(i + 2) % 3][0][0];
		}
		for (int i = 0; i < 3; i++)
		{
			imagine += complex[i][0][1] * complex[(i + 1) % 3][1][1] * complex[(i + 2) % 3][2][1];
		}
		for (int i = 0; i < 3; i++)
		{
			imagine -= complex[i][2][1] * complex[(i + 1) % 3][1][1] * complex[(i + 2) % 3][0][1];
		}
		cout << "Real part: " << real << " Imagine part: " << imagine << "i" << endl;
	}

}