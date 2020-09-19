#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <math.h>

#define endl '\n'

using namespace std;

int main() {
    int a, b;

    cout << "a= ";
    cin >> a;

    cout << "b= ";
    cin >> b;

    cout << "0: a = " << a << "; b = " << b << endl;
    a = a + b;

    cout << "1: a = " << a << "; b = " << b << endl;
    b = a - b;

    cout << "2: a = " << a << "; b = " << b << endl;
    a = a - b;

    cout << "3: a = " << a << "; b = " << b << endl;

    getch();

    return 0;
}
