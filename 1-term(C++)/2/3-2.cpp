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

    cout << "������ R = ";
    cin >> R;

    cout << "������� ���� P = ";
    cin >> P;

    cout << "������ ���� ����� Q = ";
    cin >> Q;

    r = P * sin(Q * M_PI / 180) / 2;

    if (R <= r) {
        cout << "��� ������ ������" << endl;
    } else {
        cout << "��� �� ������ ������" << endl;
    }

    return 0;
}
