#include <iostream>
#include <algorithm>
#include <math.h>
#include <windows.h>

#define endl "\n"
#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)
#define M_PI acos(-1)


using namespace std;


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;

    cout << "n = ";
    cin >> n;

    int **a = new int *[n];
    int **b = new int *[n];

    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        b[i] = new int[n];

        for (int j = 0; j < n; j++) {
            a[i][j] = n-j;
            b[i][j] = n-i;
        }
    }

    cout << "Матрица строк: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << a[i][j] << " ";
        cout << endl;
    }

    cout << "Матрица столбцов: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << b[i][j] << " ";
        cout << endl;
    }

    return 0;
}
