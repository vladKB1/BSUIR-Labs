#include <iostream>
#include <math.h>

#define endl '\n'
#define sqr(a) (a) * (a)
#define cub(a) (a) * (a) * (a)

using namespace std;

int main() {
    double a, b, c, y;
    int N;

    cout << "a, b, c, N : ";
    cin >> a >> b >> c >> N;

    switch(N) {
        case 2 :
            y = b * c - sqr(a);
            break;
        case 3 :
            y = a - b * c;
            break;
        case 7 :
            y = sqr(a) + c;
            break;
        case 56 :
            y = b * c;
            break;
        default:
            y = cub(a + b);
            break;
    }

    cout << "y = " << y << endl;

    return 0;
}
