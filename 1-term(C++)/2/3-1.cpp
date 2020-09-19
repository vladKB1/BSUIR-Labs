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

    double x, y, z;

    cout << "x, y, z : ";
    cin >> x >> y >> z;

    if (x + y > z && x + z > y && y + z > x) {
        cout << "Существует" << endl;
    } else {
        cout << "Не существует" << endl;
    }

    return 0;
}
