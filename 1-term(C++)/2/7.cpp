#include <iostream>
#include <math.h>
#include <windows.h>

#define endl '\n'
#define sqr(a) (a) * (a)
#define cub(a) (a) * (a) * (a)

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double a, b, c;

    cout << "ax^4 + bx^2 + c = 0" << endl;
    cout << "a, b, c: ";
    cin >> a >> b >> c;


    if (a == 0 && b == 0) {
        if (c == 0)
            cout << "x ����������� R" << endl;
        else
            cout << "��� �������" << endl;

        return 0;
    }

    if (a == 0) {
        double x = (-c) / b;

        if (x < 0)
            cout << "��� �������" << endl;
        else if (x == 0)
            cout << "������ : " << 0 << endl;
        else
            cout << "����� : " << -sqrt(x) << " " << sqrt(x) << endl;

        return 0;
    }

    if (b == 0) {
        double x = (-c) / a;

        if (x < 0)
            cout << "��� �������" << endl;
        else if (x == 0)
            cout << "������ : " << 0 << endl;
        else
            cout << "����� : " << -sqrt(sqrt(x)) << " " << sqrt(sqrt(x)) << endl;

        return 0;
    }

    double D = sqr(b) - 4 * a * c;

    if (D < 0) {
        cout << "��� �������" << endl;
        return 0;
    }

    double t1 = (-b + sqrt(D)) / (2 * a);
    double t2 = (-b - sqrt(D)) / (2 * a);

    if (t1 < 0 && t2 < 0) {
        cout << "��� �������" << endl;
        return 0;
    }

    cout << "�����(������) : ";

    if (t1 >= 0) {
        if (t1 == 0)
            cout << 0 << endl;
        else
            cout << -sqrt(t1) << " " << sqrt(t1) << " ";
    }

    if (t2 >= 0 && t2 != t1) {
        if (t2 == 0)
            cout << 0 << endl;
        else
            cout << -sqrt(t2) << " " << sqrt(t2) << endl;
    }

    cout << c = (a > b ? 5 : 6) << endl;

    return 0;
}
