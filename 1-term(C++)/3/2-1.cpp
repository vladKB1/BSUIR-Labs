#include <iostream>
#include <math.h>

#define endl "\n"
#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)
#define M_PI acos(-1)


using namespace std;

int main() {
    int n, m;

    cout << "n, m: ";
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        double x;
        cout << "x = ";
        cin >> x;

        double s = 0, y = 0;
        for (int j = 1; j <= n; j++)
            s += pow(-1,j+1) * pow(x,2*j) / (2*j * (2*j - 1));

        y = x * atan(x) - log(sqrt(1 + sqr(x)));

        cout << "S(x) = " << s << " Y(x) = " << y << endl << endl;
    }

    return 0;
}
