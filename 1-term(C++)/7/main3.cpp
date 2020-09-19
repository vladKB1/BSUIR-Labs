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

string revrs(string s) {
    if (s[0] == '-') {
        s[0] = 0;
        while (s.size() < 31) s = '0' + s;
        s = '1' + s;

        for (int i = 1; i < s.size(); i++) s[i] = s[i] == '1' ? '0' : '1';
    } else while (s.size() < 32) s = '0' + s;

    return s;
}

string sum(string s1, string s2) {
    string ans = "";

    if (s1.size() < s2.size()) swap(s1,s2);
    while (s2.size() < s1.size()) s2 = '0' + s2;

    int i = s1.size()-1;
    bool f = 0;
    while (i >= 0) {
        if (s1[i] == '1' && s2[i] == '1') {
            if (!f) {
                ans = '0' + ans;
                f = 1;
            } else ans = '1' + ans;
        }  else
        if (s1[i] == '0' && s2[i] == '0') {
            if (f) {
                ans = '1' + ans;
                f = 0;
            } else ans = '0' + ans;
        } else {
            if (f) ans = '0' + ans; else
            ans = '1' + ans;
        }

        i--;
    }

    if (f) ans = sum(ans,"1");

    return ans;
}

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2;
    if (s1.size() < s2.size()) swap(s1,s2);

    if (s1[0] == '-') {
        while(s2.size() < s1.size()-1)
           if (s2[0] == '-') s2.insert(1,"0"); else s2 = '0' + s2;
    } else {
        while (s2.size() < s1.size())
            if (s2[0] == '-') s2.insert(1,"0"); else s2 = '0' + s2;

        if (s2[0] == '-') s2.insert(1,"0");
    }

    s1 = revrs(s1);
    s2 = revrs(s2);

   // cout << s1 << endl << s2 << endl;

    s3 = sum(s1,s2);



    if (s3[0] == '1') {
        for (int i = 1; i < s3.size(); i++) s3[i] = s3[i] == '1' ? '0' : '1';
        while (s3[1] == '0' && s3.size() > 2) s3.erase(1,1);

        //cout << s3 << endl;
        if (s3.size() == 2 && s3[1] == '0') s3 = "0"; else
        s3[0] = '-';

    }

    int i;
    for (i = 0; i < s3.size()-1; i++) if (s3[i] != '0') break;
    for (; i < s3.size(); i++) cout << s3[i];
    cout << endl;

    return 0;
}
