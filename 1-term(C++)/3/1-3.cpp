#include <iostream>
#include <iomanip>
#include <math.h>

#define endl "\n"
#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)
#define M_PI acos(-1)


using namespace std;

int main() {
    double M = 20, B = 90, H = B/M;
    int i;

    cout << setw(5) << 'X' << setw(10) << 'Y' << endl;

    for (i = 0, x = 0; x <= B; i++, x = i * H) {
        double y = sin(x * M_PI/180) - cos(x * M_PI/180);
        cout << setw(5) << x << " " << setw(9) << y << endl;
    }

    return 0;
}
