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

    double x, fx, y, z, a, d;
    int Type;

    cout << "z, a, d: ";
    cin >> z >> a >> d;


    cout << "Выберите функцию: " << endl;
    cout << "f(x) = x*2 --> 1" << endl;
    cout << "f(x) = x*x --> 2" << endl;
    cout << "f(x) = x/3 --> 3" << endl;
    cout << "Type = ";
    cin >> Type;

    if (Type > 3) {
        cout << "Неверный тип функции" << endl;
        return 0;
    }

    cout << "Вычисления y проводилось с условием ";

    if (z > 0) {
        cout << "z > 0, ";
        x = -3 * z;
    } else {
        cout << "z <= 0, ";
        x = sqr(z);
    }

    cout << "используя функццию типа " << Type << " --> ";


      switch (Type) {
        case 1 :
            cout << "f(x) = x*2.";
            fx = 2 * x;
            break;
        case 2 :
            cout << "f(x) = x*x.";
            fx = sqr(x);
            break;
        default :
            cout << "f(x) = x/3.";
            fx = x / 3;
            break;
    }


    y = 2 * fx * (a * sin(x * M_PI / 180) + d * exp(-(x+3)));

    cout << endl << "y = " << y << endl;

    return 0;
}
