#include <bits/stdc++.h>
//#include <windows.h>


#define ll long long
#define pll pair <ll,ll>
#define fi first
#define se second
#define endl "\n"
#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)
#define M_PI acos(-1)


using namespace std;

vector <int> bin(ll x) {
    vector <int> ans;

    while (x != 0) {
        ans.push_back(x%2);
        x = x >> 1LL;
    }
    reverse(ans.begin(),ans.end());

    return ans;
}

pair <vector<int>,int> division(vector <int> v, int d) {
    pair <vector<int>,int> quot;

    ll x = 0;
    for (int i = 0; i < v.size(); i++) {
        if (x == 0) x = v[i]; else x = v[i] + x*10;

        if (x < d) {
            if (quot.fi.size() != 0) quot.fi.push_back(0);
            continue;
        }

        quot.fi.push_back(x/d);
        x = x - 2*(x/d);
    }
    quot.se = x;

    if (quot.fi.size() == 0) quot.fi.push_back(0);

    return quot;
}

vector <int> Vbin(vector <int> v) {
    vector <int> ans;

    while (v.size() != 1 || v[0] != 0) {
        pair <vector<int>,int> quot = division(v,2);
        ans.push_back(quot.se);
        v = quot.fi;
    }
    reverse(ans.begin(),ans.end());

    return ans;
}

int main() {
    ll n;
    cin >> n;

    ll x = 1, k = 0;
    while (x) {
        vector <int> v10 = bin(x);
        vector <int> v2 = Vbin(v10);

//        for (auto i : v10) cout << i;
//        cout << " ";
//        for (auto i : v2) cout << i;
//        cout << endl;

        bool f = 0;
        int i = v10.size()-1, j = v2.size()-1;
        while (i >= 0) {
            if (v10[i] != v2[j]) {
                f = 1;
                break;
            }
            i--;
            j--;
        }

        if (!f) k++;

        if (k == n) {
            for (auto i : v10) cout << i;
            cout << endl;
            return 0;
        }

        x++;
    }

    return 0;
}
