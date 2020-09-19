//variant 4
#include <iostream>
#include <math.h>

#define endl "\n"
#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)
#define M_PI acos(-1)


using namespace std;

int main() {

    for (int i = 100; i <= 999; i++) {
        int a = i / 10, b = i % 10;
        if (sqr(a) - sqr(b) == i) cout << i << endl;
    }

    return 0;
}
