#include <iostream>
#include <math.h>

#define endl "\n"
#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)

using namespace std;

int main() {
    int i = 1, N = 0;

    for (i = 1; i <= 30; i++) {
        double a, b;

        if (i % 2) {
            a = i;
            b = sqr(i);
        } else {
            a = i/2;
            b = cub(i);
        }

        N += sqr(a - b);
        cout << N << endl;
       // i++;
    }

    cout << "N = " << N << endl;


    return 0;
}
