#include <bits/stdc++.h>

#define ll long long
#define pll pair <ll,ll>
#define fi first
#define se second
#define endl "\n"
#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)
#define M_PI acos(-1)


using namespace std;

char f(int x) {
    if (x < 10) return char(x+48);

    if (x == 10) return 'A';
    if (x == 11) return 'B';
    if (x == 12) return 'C';
    if (x == 13) return 'D';
    if (x == 14) return 'E';
    if (x == 15) return 'F';
    if (x == 16) return 'G';
}

int main() {
    ll x, y = 0;
    cin >> x;

    ll step = 1;
    while (x != 0) {
        y += x%10 * step;
        x /= 10;
        step = step * 3;
    }

    x = y;
    ll len = 0;
    while (x != 0) {
        x /= 17;
        len++;
    }

    //cout << len << endl;

    for (int i = len; i >= 1; i--) {
        ll len2 = 0;
        char ans;
        x = y;

        while (len2 < i) {
            ans = f(x%17);
            x /= 17;
            len2++;
        }

        cout << ans;
    }

    cout << endl;

    return 0;
}
