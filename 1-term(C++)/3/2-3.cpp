#include <iostream>
#include <iomanip>
#include <math.h>

#define endl "\n"
#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)
#define M_PI acos(-1)


using namespace std;

int main() {
    cout << setw(3) << 'x' << setw(9) << "f(x)" << endl;

    for (int i = 60; i <= 390; i += 18)
        cout << setw(3) << (i >= 360 ? i-360 : i) << " " << 1./(1+sin(i*M_PI/180)) << endl;

    return 0;
}
