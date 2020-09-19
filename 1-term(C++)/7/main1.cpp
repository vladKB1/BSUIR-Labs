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

const char alph[17] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G'};

int main() {
    ll x = 0;
    string s;
    cin >> s;

    ll step = 1;
    for (int i = s.size()-1; i >= 0; i--) {
        x += (s[i]-48)*step;
        step = step * 3;
    }

    //cout << x << endl;

    string t = "";
    while (x != 0) {
        t = alph[x%17] + t;
        x /= 17;
    }

    cout << t << endl;

    return 0;
}
