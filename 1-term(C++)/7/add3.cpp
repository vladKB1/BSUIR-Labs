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

ll i, n;

int main() {
//    freopen("INPUT.TXT", "r", stdin);
//    freopen("OUTPUT.TXT", "w", stdout);

    while (cin >> n) {
        ll x = n;
        ll a[n];
        string s = "";
        while (x != 0) {
            s = char(x%3+48) + s;
            x /= 3;
        }

        //cout << s << endl;

        for (int i = 0; i < s.size()-1; i++) {
            if (s[i] == '1' && s[i+1] == '0') {
                s[i] = '0';
                s[i+1] = '3';
                if (i != 0) i -= 2;
                continue;
            }
            if (s[i] == '2' && s[i+1] == '0') {
                s[i] = '1';
                s[i+1] = '3';
            }
            if (s[i] == '3' && s[i+1] == '0') {
                s[i] = '2';
                s[i+1] = '3';
            }
        }

        for (ll i = 0; i < s.size(); i++) if (s[i] != '0') cout << s[i];
        cout << endl;
    }


    return 0;
}
