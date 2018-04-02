#pragma once 

#ifdef MATHFUNCTIONSDYNAMIC_EXPORTS  
#define MATHFUNCTIONSDYNAMIC_API __declspec(dllexport)   
#else  
#define MATHFUNCTIONSDYNAMIC_API __declspec(dllimport)   
#endif 


namespace MathFunctionsDynamic
{
	MATHFUNCTIONSDYNAMIC_API int add(int x, int y);
}
