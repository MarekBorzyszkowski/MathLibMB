// MathExample.cpp : Defines the entry point for the console application.
//
#include <iostream>

#include "MathFunctionsStatic.h"
#include "MathFunctionsDynamic.h"

using namespace std;

int main()
{
	cout << MathFunctionsDynamic::add(6, 3) << endl;
	cout << MathFunctionsStatic::div(6, 3) << endl;
	return 0;
}

