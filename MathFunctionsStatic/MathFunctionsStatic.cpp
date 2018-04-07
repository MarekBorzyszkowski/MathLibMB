#define PI 3.14159265359
#include <cmath>
#include <iostream>
#include <ctgmath>
#include <vector>
#include <utility>
#include <cstring>
#include <string>
#include "MathFunctionsStatic.h"

using namespace std;

//calculates area of regular polygon, by it's circumradius
double areaOfRegularPolygon(double R, double angle) {
	double area = 0.5*angle*R*R*sin(2 * PI / angle);
	cout << "Area of " << angle << " polygon is: ";
	return area;
}

/////////////////////////////////////////////////////////////////

//calculates matrix determinant of 3x3 complex matrix
pair<double, double> matrixDeterminantThreeOfComplex(double complex[3][3][2]) {
	pair<double, double> matrixPair;
	double real = 0, imagine = 0;

	//calculate real matrix determinant

	for (int i = 0; i < 3; i++)
	{
		real += complex[i][0][0] * complex[(i + 1) % 3][1][0] * complex[(i + 2) % 3][2][0];
	}
	for (int i = 0; i < 3; i++)
	{
		real -= complex[i][2][0] * complex[(i + 1) % 3][1][0] * complex[(i + 2) % 3][0][0];
	}

	//calculate imagine matrix determinant

	for (int i = 0; i < 3; i++)
	{
		imagine += complex[i][0][1] * complex[(i + 1) % 3][1][1] * complex[(i + 2) % 3][2][1];
	}
	for (int i = 0; i < 3; i++)
	{
		imagine -= complex[i][2][1] * complex[(i + 1) % 3][1][1] * complex[(i + 2) % 3][0][1];
	}
	matrixPair = make_pair(real, imagine);
	return matrixPair;
}

/////////////////////////////////////////////////////////////////

//calculates root of complex numbers, using trigonometry
vector<pair<double, double>> rootComplex(double real, double imagine, int index) {
	vector<pair<double, double>> result;
	double modulus = sqrt(real*real + imagine * imagine); // modulus of complex num
	double fi = atan2(imagine, real); // calculates arg of complex num
	double realResoult, imagineResoult;
	//calculates solutions for root
	for (int i = 0; i < index; i++) {
		realResoult = modulus * cos((fi + 2 * i * 180) / index);
		imagineResoult = modulus * sin((fi + 2 * i * 180) / index);
		result.push_back(make_pair(realResoult, imagineResoult));
	}
	return result;
}

/////////////////////////////////////////////////////////////////

//adds big number, changing some value it can be bigger than 100 digits ;)
char* add100Digit(char* num1, char* num2)
{
	//prepering
	bool bigger = 0;
	if (strlen(num1) > strlen(num2))
		bigger = 1;
	char* result = new char[103];
	memset(result, 0, 103);
	char* numb1 = new char[strlen(num1)];
	char* numb2 = new char[strlen(num2)];
	memset(numb1, -1, strlen(num1));
	memset(numb2, -1, strlen(num2));
	//transforming to proper form
	for (int i = 0; i < strlen(num1); i++)
	{
		numb1[i] = num1[strlen(num1) - i - 1] - 48;
	}
	for (int i = 0; i < strlen(num2); i++)
	{
		numb2[i] = num2[strlen(num2) - i - 1] - 48;
	}
	// adding
	if (bigger)
	{
		for (int i = 0; i < strlen(num2); i++)
		{
			result[i] += numb1[i] + numb2[i];
			if (result[i] > 9) {
				result[i + 1]++;
				result[i] -= 10;
			}
		}
		for (int i = strlen(num2); i < strlen(num1); i++)
		{
			result[i] += numb1[i];
			if (result[i] > 9) {
				result[i + 1]++;
				result[i] -= 10;
			}
		}
	}
	else
	{
		for (int i = 0; i < strlen(num1); i++)
		{
			result[i] += numb1[i] + numb2[i];
			if (result[i] > 9) {
				result[i + 1]++;
				result[i] -= 10;
			}
		}
		for (int i = strlen(num1); i < strlen(num2); i++)
		{
			result[i] += numb2[i];
			if (result[i] > 9) {
				result[i + 1]++;
				result[i] -= 10;
			}
		}
	}
	return result;
}
// shows resoults, which eg. should look like 123, but is encode as 321
void showResoultOfAdding(char* resoult)
{
	int lenghr = 0;
	for (int i = 100; i >= 0; i--)
	{
		if (resoult[i] != 0)
		{
			lenghr = i + 1;
			break;
		}
	}

	for (int i = 0; i < lenghr; i++)
	{
		cout << (int)resoult[lenghr - i - 1];
	}
	cout << endl;
}

/////////////////////////////////////////////////////////////////

//calculates 3 unknowns: x y z using matrix
vector<double> matrixDeterminantThreeUnknowns(double equation[3][4])
{
	double detMain, detX, detY, detZ;
	vector<double> result;

	// calculate main matrix determinants
	for (int i = 0; i < 3; i++)
	{
		detMain = equation[i][0] * equation[(i + 1) % 3][1] * equation[(i + 2) % 3][2];
	}
	for (int i = 0; i < 3; i++)
	{
		detMain -= equation[i][2] * equation[(i + 1) % 3][1] * equation[(i + 2) % 3][0];
	}

	// calculate x matrix determinants

	for (int i = 0; i < 3; i++)
	{
		detX = equation[i][3] * equation[(i + 1) % 3][1] * equation[(i + 2) % 3][2];
	}
	for (int i = 0; i < 3; i++)
	{
		detX -= equation[i][2] * equation[(i + 1) % 3][1] * equation[(i + 2) % 3][3];
	}

	// calculate y matrix determinants

	for (int i = 0; i < 3; i++)
	{
		detY = equation[i][0] * equation[(i + 1) % 3][3] * equation[(i + 2) % 3][2];
	}
	for (int i = 0; i < 3; i++)
	{
		detY -= equation[i][2] * equation[(i + 1) % 3][3] * equation[(i + 2) % 3][0];
	}

	// calculate z matrix determinants

	for (int i = 0; i < 3; i++)
	{
		detZ = equation[i][0] * equation[(i + 1) % 3][1] * equation[(i + 2) % 3][3];
	}
	for (int i = 0; i < 3; i++)
	{
		detZ -= equation[i][3] * equation[(i + 1) % 3][1] * equation[(i + 2) % 3][0];
	}

	// solutions

	if (detMain == 0 && detX == 0 && detY == 0 && detZ == 0)
	{
		cout << "Infinity number of solutions.";
		result.push_back(detMain);
		return result;
	}
	else if (detMain == 0 && (detX != 0 || detY != 0 || detZ != 0))
	{

		cout << "No solutions.";
		result.push_back(detMain);
		return result;

	}
	else
	{
		double x, y, z;
		x = detX / detMain;
		y = detY / detMain;
		z = detZ / detMain;
		result.push_back(x);
		result.push_back(y);
		result.push_back(z);
		cout << "x = " << x << " y = " << y << " z = " << z << endl;
		return result;
	}
}