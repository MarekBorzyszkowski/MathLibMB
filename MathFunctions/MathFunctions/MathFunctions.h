#pragma once 

#ifdef MATHFUNCTIONS_EXPORTS  
#define MATHFUNCTIONS_API __declspec(dllexport)   
#else  
#define MATHFUNCTIONS_API __declspec(dllimport)   
#endif 


namespace MathFunctions
{
	MATHFUNCTIONS_API int add(int x, int y);
}
