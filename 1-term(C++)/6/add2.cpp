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

ll t, i, L, m, ans;
string s1, s2;

ll bin_pow(ll a, ll b) {
    ll res = 1;

    if (b < 0) return 0;

    while (b > 0) {
        if (b % 2) res = res * a % m;
        a = a * a % m;
        b = b / 2;
    }

    return res;
}

int main() {
    cin >> t;

    for (i = 1; i <= t; i++) {
        cin >> L >> m;
        cin >> s1 >> s2;
        if (s1.size() < s2.size()) swap(s1,s2);

        ans = 0;

        if (s1.size() > L || s2.size() > L) {
            cout << 0 << endl;
            continue;
        }

        if (s1.size() + s2.size() == L) {
            if (s1 + s2 == s2 + s1) ans = 1; else ans = 2;
        } else
        if (s1.size() + s2.size() > L) {
            ll k = s1.size() + s2.size() - L;
            string str = "";

            if (s1.substr(s1.size()-k,k) == s2.substr(0,k)) {
                ans++;
                str = s1 + s2.substr(k,s2.size());
            }

            if (s2.substr(s2.size()-k,k) == s1.substr(0,k))
            if (!(ans == 1 && s2 + s1.substr(k,s1.size()) == str)) ans++;
        } else {
            ans = bin_pow(26,L-s1.size()-s2.size());
            ll step = -1;

            if (s1.substr(0,s2.size()) == s2 && s2 == s1.substr(s1.size()-s2.size(),s2.size())) {
                step = L - 2*s1.size();
                if (step < 0 && s1.substr(0,abs(step)) == s1.substr(s1.size()-abs(step),abs(step))) step = 0;
            }

            if (s1 != s2) {
                ans = ans * 2 % m;
                ans = ans - bin_pow(26,step);
                if (ans < 0) ans += m;
            }
        }

        cout << ans % m << endl;
    }

    return 0;
}

