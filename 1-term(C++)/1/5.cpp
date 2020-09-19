//additional task, 4

#pragma hdrstop
#pragma argsused

#include <iostream>
#include <math.h>

#define endl '\n'

using namespace std;

int main() {

    double h, Time, a = 9.8;

    cout << "h = ";
    cin >> h;

    Time = pow(2*h / a, 1./2);
    cout << "Time = " << Time << endl;

    return 0;
}

