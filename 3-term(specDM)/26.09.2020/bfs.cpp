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

void bfs(int i) {
    queue <int> q;

    q.push(i);
    while (!q.empty()) {
        int v = q.front();
        f[v] = 1;
        q.pop();

        for (int j = 0; j < ss[v].size(); j++) if (!f[ss[v][j]]) {
            q.push(ss[v][j]);
        }
    }
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
        ss[b].push_back(a);
    }

    int k = 0;
    for (int i = 1; i <= n; i++) if (!f[i]) {
        bfs(i);
        k++;
    }

    cout << "number of connectivity components: " << k << endl;

    return 0;
}
