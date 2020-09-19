#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
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

int f1[256], f2[256];

bool check() {
    for (int i = 0; i < 256; i++)
        if (f1[i] != f2[i]) return 0;

    return 1;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char s[111], t[111];

    gets(s);
    gets(t);

    int n = 0, m = 0;
    while (s[n] != '\0') {n++;}
    while (t[m] != '\0') {m++;}

    for (int i = 0; i < n; i++) f1[s[i]]++;
    for (int i = 0; i < m; i++) f2[t[i]]++;

    if (check()) cout << "YES" << endl; else
    cout << "NO" << endl;

    return 0;
}
