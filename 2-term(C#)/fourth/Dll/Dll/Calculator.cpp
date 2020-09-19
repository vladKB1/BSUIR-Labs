#include "pch.h"
#include <utility>
#include <limits.h>
#include "Calculator.h"


int Add(int a, int b) {
	return a + b;
}

int Subtract(int a, int b) {
	return a - b;
}

int Multiply(int a, int b) {
	return a * b;
}

int Division(int a, int b) {
	return a / b;
}
 
int Gcd(int a, int b) {
	a = abs(a);
	b = abs(b);

	while (a != 0 && b != 0) {
		if (a > b) {
			a %= b;
		}
		else {
			b %= a;
		}
	}

	return a + b;
}

int BinPow(int a, int b) {
	int ans = 1;

	while (b != 0) {
		if (b % 2 == 1) {
			ans *= a;
		}
		a *= a;
		b >>= 1LL;
	}

	return ans;
}
