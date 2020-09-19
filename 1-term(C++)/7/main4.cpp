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

const char alph[17] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G'};
char f[256];
bool zn1 = 0, zn2 = 0;


bool great(string &s1, string &s2) {
    for (int i = 0; i < s1.size(); i++) {
        if (f[s1[i]] < f[s2[i]]) return 0;
        if (f[s1[i]] > f[s2[i]]) return 1;
    }
    return 0;
}

string sum(string s1, string s2) {
    string ans = "";

    int x = 0, t = 0;
    for (int i = s1.size()-1; i >= 0; i--) {
        t = f[s1[i]] + f[s2[i]] + x;
        ans = alph[t%17] + ans;
        x = t/17;
    }

    if (x != 0) ans = alph[x%17] + ans;

    return ans;
}

string sub(string s1, string s2) {
    string ans = "";

    if (!great(s1,s2)) swap(s1,s2);

    //cout << s1 << endl << s2 << endl;

    int t = 0;
    for (int i = s1.size()-1; i >= 0; i--) {
        t = f[s1[i]] - f[s2[i]];
        if (t < 0) {
            int j = i-1;
            while (s1[j] == '0' && j >= 0) {
                s1[j] = alph[16];
                j--;
            }
            t += 17;
            s1[j] = alph[f[s1[j]]-1];
        }

        ans = alph[t] + ans;
    }

    return ans;
}

string edit(string s) {
    int i = 0;
    while (s[i] == '0' && i < s.size()) i++;
    if (i == s.size()) i--;
    return s.substr(i);
}

int main() {
    for (int i = 0; i < 17; i++) f[alph[i]] = f[tolower(alph[i])] = i;


    string s1, s2;
    cin >> s1 >> s2;

    if (s1[0] == '-') {
        s1.erase(0,1);
        zn1 = 1;
    }
    if (s2[0] == '-') {
        s2.erase(0,1);
        zn2 = 1;
    }

    while (s1.size() < s2.size()) s1 = '0' + s1;
    while (s2.size() < s1.size()) s2 = '0' + s2;

    string s3, s4;

    if (zn1 == zn2) {
        s3 = edit(sum(s1,s2));
        if (zn1) s3 = '-' + s3;
    } else {
        s3 = edit(sub(s1,s2));
        if (great(s1,s2)) {
            if (zn1) s3 = '-' + s3;
        } else
        if (great(s2,s1)) {
            if (zn2) s3 = '-' + s3;
        }
    }

    zn2 = 1-zn2;
    if (zn1 == zn2) {
        s4 = edit(sum(s1,s2));
        if (zn1) s4 = '-' + s4;
    } else {
        s4 = edit(sub(s1,s2));
        if (great(s1,s2)) {
            if (zn1) s4 = '-' + s4;
        } else
        if (great(s2,s1)) {
            if (zn2) s4 = '-' + s4;
        }
    }

    cout << "Sum = " << s3 << endl;
    cout << "Sub = " << s4 << endl;

    return 0;
}


bool bigger(string a, string b)
{
    if (a[0] == '-') a.erase(0,1);
    if (b[0] == '-') b.erase(0,1);

    if (a.size() < b.size()) return 1;

    for (int i = a.size()-1; i > -1; i--)
        if (f[code[b[i]]] > f[code[a[i]]]) return 1;

    return 0;
}

string sub(string a, string b)
{
    string ans = "";

    bool zn = 0;
    if (a[0] == '-')
    {
        zn = 1;
        a.erase(0,1);
    }
    if (b[0] == '-') b.erase(0,1);

    while (b.size() < a.size()) b = '0' + b;

    int x = 0;
    for (i = a.size()-1; i > -1; i--)
    {
        x = f[a[i]]-f[b[i]];

        if (x < 0)
        {
            int j = i-1;
            while (a[j] == '0' && j > -1)
            {
                a[j] = code[13];
                j--;
            }

            x += 13;
            a[j] = code[f[a[j]-1];
        }

        ans = code[x%13] + ans;
    }

    if (zn) ans = '-' + ans;

    return ans;
}

string sum(string a, string b)
{
    string ans = "";

    bool zn = 0;
    if (a[0] == '-')
    {
        zn = 1;
        a.erase(0,1);
    }
    if (b[0] == '-') b.erase(0,1);

    int x = 0, t = 0;
    for (int i = a.size()-1; i > -1; i--)
    {
        t = f[a[i]] + f[b[i]] + x;
        ans = code[t%13] + ans;
        x = t/13;
    }

    if (x != 0) ans = code[x%17] + ans;

    if (zn) ans = '-' + ans;

    return ans;
}

