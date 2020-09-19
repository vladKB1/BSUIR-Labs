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

    double R, P, Q;
    double A, B, c1, c2;

    cout << "������ R = ";
    cin >> R;

    cout << "������� ���� P = ";
    cin >> P;

    cout << "������ ���� ����� Q = ";
    cin >> Q;

    Q = Q / 2;
    A = P * sin(Q * M_PI / 180);
    B = P * cos(Q * M_PI / 180);

    c1 = sqrt(sqr(A) - sqr(R));
    c2 = sqrt(sqr(B) - sqr(R));

    if (c1 + c2 == P) {
        cout << "��� ������ ������" << endl;
    } else {
        cout << "��� �� ������ ������" << endl;
    }

    return 0;
}
