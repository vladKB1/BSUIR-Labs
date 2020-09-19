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

    int y = a * b;

    cout << "y= " << y << endl;

    getch();

    return 0;
}
