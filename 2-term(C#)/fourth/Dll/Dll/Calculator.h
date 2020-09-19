#pragma once

#ifdef DLL_EXPORTS
#define CALCULATOR_API __declspec(dllexport)
#else
#define CALCULATOR_API __declspec(dllimport)
#endif


extern "C" CALCULATOR_API int Add(int a, int b);
extern "C" CALCULATOR_API int Subtract(int a, int b);
extern "C" CALCULATOR_API int Multiply(int a, int b);
extern "C" CALCULATOR_API int Division(int a, int b);
extern "C" CALCULATOR_API int Gcd(int a, int b);
extern "C" CALCULATOR_API int BinPow(int a, int b);