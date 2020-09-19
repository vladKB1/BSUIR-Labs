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

ll t, i, L, m;
string s1, s2;

ll bin_pow(ll a, ll b) {
    ll res = 1;
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


        bool f1 = 0, f2 = 0;
        for (int i = 0; i < s1.size()-1; i++)
            if (s1[i] != s1[i+1]) f1 = 1;

        for (int i = 0; i < s2.size()-1; i++)
            if (s2[i] != s2[i+1]) f2 = 1;

        if (s1.size() + s2.size() == L && !f1 && !f2 && s1[0] == s2[0]) {
            cout << 1 % m << endl;
            continue;
        }

        if (s1.size() > L || s2.size() > L) {
            cout << 0 << endl;
            continue;
        }

        if (s1.size() + s2.size() <= L) {
            ll ans = bin_pow(26,L-s1.size()-s2.size());
            if (s1 != s2) ans = ans * 2 % m;


            bool f3 = 0;
            int j1 = s1.size(), j2 = s2.size();
            while (j2 >= 0) {
                if (s1[j1] == s2[j2]) {
                    j1--;
                    j2--;
                } else {
                    f3 = 1;
                    break;
                }
            }

            //cout << ans << endl;

            if (!f3 && L-2*s1.size() > 0) ans = ans - bin_pow(26,L-2*s1.size());
            if (!f1 && !f2 && s1[0] == s2[0]) ans--;

            if (ans < 0) ans += m;

            cout << ans % m << endl;
        } else {
            ll ans = 0;

            string k1 = s1;
            k1.resize(L);
            for (int o = s1.size(); o < L; o++) k1[o] = ' ';

            ll j1 = s2.size()-1, j2 = L-1;
            bool f1 = 0;

            while (j1 >= 0) {
                if (k1[j2] == ' ' || k1[j2] == s2[j1]) {
                    j1--;
                    j2--;
                } else {
                    f1 = 1;
                    break;
                }
            }

            if (!f1) ans++;

            string k2 = s2;
            k2.resize(L);
            for (int o = s2.size(); o < L; o++) k2[o] = ' ';

            j1 = s1.size()-1; j2 = L-1;
            bool f2 = 0;

            while (j1 >= 0) {
                if (k2[j2] == ' ' || k2[j2] == s1[j1]) {
                    j1--;
                    j2--;
                } else {
                    f2 = 1;
                    break;
                }
            }

            if (!f2) ans++;

            cout << ans % m << endl;
        }
    }

    return 0;
}
