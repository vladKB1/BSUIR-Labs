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

    int G;

    cout << "G: ";
    cin >> G;

    cout << G;

    if ((G >= 11 && G <= 19) || (G >= 111 && G <= 119)) {
        cout << " лет";
        return 0;
    }

    switch (G % 10) {
        case 0 :
            cout << " лет" << endl;
            break;
        case 5 ... 9 :
            cout << " лет" << endl;
            break;
        case 2 ... 4 :
            cout << " года" << endl;
            break;
        default :
            cout << " год";
            break;
    }

    return 0;
}
