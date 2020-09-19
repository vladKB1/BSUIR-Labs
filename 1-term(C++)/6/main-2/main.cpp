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

bool check(char (&t)[111], char (&ans)[111][111], int stn, int len) {
    for (int i = 1; i <= stn; i++) {
        if (ans[i][0] != len) continue;

        for (int j = 1; j <= len; j++) if (ans[i][j] == t[j]) return 1;
    }

    return 0;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char s[111], t[111], ans[111][111];
    gets(s);

    int n = strlen(s), len = 0, stn = 0;
    for (int i = 0; i < n; i++) {
            if (!(s[i] >= 'A' && s[i] <= 'Z') && !(s[i] >= 'a' && s[i] <= 'z')) {
            if (t[1] == t[len] && !check(t, ans, stn, len)) {
                ans[++stn][0] = len;
                for (int j = 1; j <= len; j++) ans[stn][j] = t[j];
            }

            len = 0;

            continue;
        }

        t[++len] = s[i];
    }

    if (len != 0) {
        if (t[1] == t[len] && !check(t, ans, stn, len)) {
            ans[++stn][0] = len;
            for (int j = 1; j <= len; j++) ans[stn][j] = t[j];
        }

        len = 0;
    }

    for (int i = 1; i <= stn; i++) {
        for (int j = 1; j <= int(ans[i][0]); j++) cout << ans[i][j];
        cout << endl;
    }

    return 0;
}
