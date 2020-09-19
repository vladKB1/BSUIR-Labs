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

int f[256];

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char s[111];
    gets(s);

    int n = strlen(s);
    for (int i = 0; i < n; i++) f[s[i]]++;

    cout << "{ -> " << f['{'] << endl;
    cout << "} -> " << f['}'] << endl;

    cout << "( -> " << f['('] << endl;
    cout << ") -> " << f[')'] << endl;

    cout << "[ -> " << f[')'] << endl;
    cout << "] -> " << f[')'] << endl;

    cout << "< -> " << f['<'] << endl;
    cout << "> -> " << f['>'] << endl;


    return 0;
}
