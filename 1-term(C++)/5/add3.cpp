#include <bits/stdc++.h>

#define ll long long
#define ull unsigned ll
#define pll pair <ll,ll>
#define fi first
#define se second
#define endl "\n"
#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)
#define M_PI acos(-1)


using namespace std;

ull bin_pow(ull a, ull b, ll m) {
    ull res = 1;

    while (b != 0) {
        if (b % 2) res = res * a % m;
        a = a * a % m;
        b = b >> 1LL;
    }

    return res;
}

main() {
    int o = 0;
    while (++o) {
        ull k, n;
        ll step, m = 1;

        cin >> k >> n >> step;
        if (k == 0 && n == 0 && step == 0) break;

        cout << "Case #" << o << ": ";

        for (int i = 1; i <= step; i++) m *= 10;

        cout << bin_pow(k,n,m) << endl;
    }

    return 0;
}





//ull n, k, i;
//
//ull f(ull n,ull r) {
//    if (n == 0 && r == 0) return 1; else
//    if (n > 0 && r >= 0 && r < n*(k-1)+1) {
//        ull ans = 0;
//        for (int j = 0; j < k-1; j++) ans += f(n-1,r-j);
//        return ans;
//    } else return 0;
//}
//
//int main() {
//
//    int o = 0;
//    while (1) {
//        ull x = 0;
//        ll step, m = 1;
//
//        cin >> k >> n >> step;
//        if (k == 0 && n == 0 && step == 0) break;
//
//        cout << "Case #" << ++o << ": ";
//
//        for (i = 1; i <= step; i++) m *= 10;
//
//
//        for (i = 0; i <= n*(k-1); i++) {
//            x += f(n,i);
//            x %= m;
//        }
//
//        cout << x << endl;
//    }
//
//    return 0;
//}
