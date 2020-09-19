#include "main2.h"
#include "pch.h"

using namespace std;

double calc(int l, int r, double *x) {
	int M = r - l + 1;
	if (M > 1) return calc(l, l + M / 2 - 1, x) * calc(l + M / 2, r, x); else
		return x[l] / (1 + l);
}
