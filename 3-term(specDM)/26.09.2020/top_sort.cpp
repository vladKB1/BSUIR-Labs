#include <bits/stdc++.h>


#define ll long long
#define pll pair <ll,ll>
#define fi first
#define se second
#define endl "\n"
#define sqr(b) (b)*(b)


using namespace std;

bool f[11111];
vector <int> ss[11111];
vector <int> a;

void dfs(int v) {
    if (f[v]) return;
    f[v] = 1;
    for (int j = 0; j < ss[v].size(); j++) {
        dfs(ss[v][j]);
    }
    a.push_back(v);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("", "r", stdin);
//    freopen("", "w", stdout);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ss[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) if (!f[i]) {
        dfs(i);
    }
    reverse(a.begin(), a.end());

    cout << "Topological sort:" << endl;
    for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}
