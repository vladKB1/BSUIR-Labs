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

    int N, k;

    cout << "N, k: ";
    cin >> N >> k;

    N += k;
    cout << N;

    if (N >= 11 && N <= 19) {
        cout << " рублей" << endl;
        return 0;
    }

    int n = N % 10;

    switch (n) {
        case 0 :
            cout << " рублей" << endl;
            break;
        case 5 ... 9 :
            cout << " рублей" << endl;
            break;
        case 2 ... 4 :
            cout << " рубля" << endl;
            break;
        default :
            cout << " рубль";
            break;
    }

    return 0;
}
