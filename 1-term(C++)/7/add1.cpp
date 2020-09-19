#include <bits/stdc++.h>
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

string convers(ll x) {
    string ans = "";

    while (x != 0) {
        ans = char((x & 1) + 48) + ans;
        x = x >> 1;
    }

    return ans;
}

bool great(const string &s1,const string &s2) {
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] < s2[i]) return 0;
        if (s1[i] > s2[i]) return 1;
    }
    return 1;
}

string edit(string s) {
    int i = 0;
    while (s[i] == '0' && i < s.size()) i++;
    return s.substr(i);
}

string sub(string s1, string s2) {
    string ans = "";
    int x = 0;

    while (s2.size() < s1.size()) s2 = '0' + s2;

    for (int i = s1.size()-1; i >= 0; i--) {
        x = (s1[i]-48)-(s2[i]-48);
        if (x < 0) {
            int j = i-1;
             while (s1[j] == '0' && j >= 0) {
                s1[j] = '1';
                j--;
            }
            x += 2;
            s1[j]--;
        }

        ans = char(x+48) + ans;
    }

    return edit(ans);
}

bool check(string s, string d) {
    int i = 0;
    string t = "";

    while (i < s.size()) {
        t = edit(t);
        t += s[i];
        if (t.size() < d.size()) {
            i++;
            continue;
        } else
        if (t.size() == d.size() && !great(t,d)) {
            i++;
            continue;
        }

        //cout << t << " " << d << " " << i << endl;
        t = sub(t,d);
        //cout << "t after sub = " << t << endl;
        i++;
    }

    t = edit(t);
    if (t != "") return 0; else return 1;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ll x;
    cout << "¬ведите делимое: ";
    cin >> x;
    string s = convers(x);

    //cout << s << endl;

    cout << "¬водите числа на которые будем провер€ть деление (-1 дл€ завершени€): " << endl;
    while (1) {
        ll y;
        cin >> y;
        if (y == -1) break;

        string t = convers(y);
        //cout << "t = " << t << endl;

        if (check(s,t)) cout << "YES" << endl; else cout << "NO" << endl;
    }

    return 0;
}
