// variant 3

#include <iostream>
#include <math.h>
#include <windows.h>

#define endl '\n'
#define sqr(a) (a) * (a)
#define cub(a) (a) * (a) * (a)
#define M_PI acos(-1)

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double R, P, Q, r;

    cout << "Радиус R = ";
    cin >> R;

    cout << "Сторона роба P = ";
    cin >> P;

    cout << "Острый угол ромба Q = ";
    cin >> Q;

    r = P * sin(Q * M_PI / 180) / 2;

    if (R <= r) {
        cout << "Шар сможет пройти" << endl;
    } else {
        cout << "Шар не сможет пройти" << endl;
    }

    return 0;
}
