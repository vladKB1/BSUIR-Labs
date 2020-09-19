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



int main() {
    string s, t1, t2;
    cin >> s;

    bool f1 = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '.' || s[i] == ',') {
            f1 = 1;
            continue;
        }
        if (s[0] == '1') s[i] = s[i] == '0' ? '1' : '0';

        if (!f1) t1 += s[i]; else t2 += s[i];
    }

    double x1 = 0, x2 = 0;

    ll step = 1;
    for (int i = t1.size()-1; i >= 0; i--) {
        x1 += (t1[i]-'0')*step;
        step = step << 1LL;
    }

    step = 2;
    for (int i = 0; i < t2.size(); i++) {
        x2 += (t2[i]-'0')*(1./step);
        step = step << 1LL;
    }

    double x = x1+x2;
    if (s[0] == '1') x = -x;

    cout << x << endl;

    return 0;
}

