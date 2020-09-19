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
    string s;

    cin >> s;
    for (int i = 0; i < s.size(); i++) f[s[i]]++;

    ll fact[15];
    fact[0] = fact[1] = 1;
    for (ll i = 2; i <= 14; i++) fact[i] = fact[i-1] * i;

    ll ans = fact[s.size()];

    for (int i = 0; i < 256; i++) ans = ans / fact[f[i]];

    cout << ans << endl;

    return 0;
}
