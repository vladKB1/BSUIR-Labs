#include <bits/stdc++.h>
#include <windows.h>

#define ll long long
#define pll pair <ll,ll>
#define fi first
#define se second
#define endl "\n"
#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)
#define M_PI acos(-1)


using namespace std;

typedef int (__stdcall *ptr1) (int);
typedef int (__stdcall *ptr2) (int, int);

ptr1 take;
ptr2 add;

int main() {
    HINSTANCE load;
    load = LoadLibrary("DynLib.dll");

    take = (ptr1)GetProcAddress(load, "take");
    add = (ptr2)GetProcAddress(load, "add");


    int n;
    cout << "n = ";
    cin >> n;

    int **a = new int *[n];
    int **b = new int *[n];
    int **c = new int *[n];

    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        b[i] = new int[n];
        c[i] = new int[n];

        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            b[i][j] = take(a[i][j]);
            c[i][j] = add(a[i][j],b[i][j]);
        }
    }

    cout << "B:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << b[i][j] << " ";
        cout << endl;
    }

    cout << "C:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << c[i][j] << " ";
        cout << endl;
    }



    for (int i = 0; i < n; i++) {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;

    FreeLibrary(load);

    return 0;
}
