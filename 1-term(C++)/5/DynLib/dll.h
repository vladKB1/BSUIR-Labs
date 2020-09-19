#ifndef _DLL_H_
#define _DLL_H_

#if BUILDING_DLL
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif

extern "C" int __declspec(dllexport) __stdcall take(int);
extern "C" int __declspec(dllexport) __stdcall add(int, int);

#endif
