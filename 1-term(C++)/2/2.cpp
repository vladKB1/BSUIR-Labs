#include <iostream>
#include <math.h>
#include <windows.h>

#define endl '\n'

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char zn;
    double a, b, d;

    while (1) {
        bool flag = 0;

        cout << "a, b, zn: ";
        cin >> a >> b >> zn;

        if (zn == '+')
            d = a + b;
        else if (zn == '-')
            d = a - b;
        else if (zn == '*')
            d = a * b;
        else if (zn == '/')
            d = a / b;
        else  {
             cout << "������������ ����" << endl;
             flag = 1;
        }

        if (!flag)
            cout << "d = " << d << endl;

        cout << "������� Y ����� ��������� ���� ��� ������ �������, ����� ��������� ������ ���������" << endl;
        cin >> zn;
        if (zn != 'y' && zn != 'Y') break;
    }

    return 0;
}
