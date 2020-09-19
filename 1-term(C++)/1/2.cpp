#pragma hdrstop
#pragma argsused

#include <iostream>
#include <conio.h>
#include <math.h>

#define endl '\n'

using namespace std;

int main() {
    float a, b;

    cout << "a= ";
    cin >> a;

    cout << "b= ";
    cin >> b;

    int y1 = a / b;
    float y2 = a / b;

    cout << "y1= " << y1 << endl;
    cout << "y2= " << y2 << endl;

    getch();

    return 0;
}
