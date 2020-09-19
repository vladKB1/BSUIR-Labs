#include <iostream>
#include <math.h>

#define endl '\n'

using namespace std;

int main() {
    double a, b;

    cout << "a, b: ";
    cin >> a >> b;

    bool f = a >= b;

    cout << "max = " << (f ? a : b) << endl;

    return 0;
}
