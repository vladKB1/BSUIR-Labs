#include "dll.h"
#include "windows.h"

extern "C" int __declspec(dllexport) __stdcall take(int a) {
    if (a >= 0) return a; else return 1;
}

extern "C" int __declspec(dllexport) __stdcall add(int a, int b) {
    return a+b;
}




