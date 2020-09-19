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



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char s[1111], t[1111];

    while (1) {
        gets(s);

        if (s[0] == '\0') break;

        int n = strlen(s), m = 0;
        s[n] = s[n+1] = '#';

        for (int i = 0; i < n; i++) {
            if (s[i] == 'c' || s[i] == 'C') {
                if (s[i+1] == 'e' || s[i+1] == 'E' || s[i+1] == 'i'
                || s[i+1] == 'I' || s[i+1] == 'y' || s[i+1] == 'Y')  t[++m] = isupper(s[i]) ? 'S' : 's'; else
                t[++m] = isupper(s[i]) ? 'K' : 'k';

                if (t[m-1] == t[m]) m--;
            } else
            if (s[i] == 'q' || s[i] == 'Q') {
                t[++m] = isupper(s[i]) ? 'K' : 'k';

                if (t[m-1] == t[m]) m--;

                if (s[i+1] == 'u') {
                    t[++m] = 'v';
                    i++;
                }
            } else
            if (s[i] == 'x' || s[i] == 'X') {
                t[++m] = isupper(s[i]) ? 'K' : 'k';

                if (t[m-1] == t[m]) m--;

                t[++m] = 's';
            } else
            if (s[i] == 'w' || s[i] == 'W') {
                t[++m] = isupper(s[i]) ? 'V' : 'v';
                if (t[m-1] == t[m]) m--;
            } else
            if ((s[i] == 'p' || s[i] == 'p') && (s[i+1] == 'h' || s[i+1] == 'H')) {
                t[++m] = isupper(s[i]) ? 'F' : 'f';
                if (t[m-1] == t[m]) m--;
                i++;
            } else
            if (((s[i] == 'y' || s[i] == 'Y') && (s[i+1] == 'o' || s[i+1] == 'O') && (s[i+2] == 'u' || s[i+2] == 'U'))) {
                t[++m] = isupper(s[i]) ? 'U' : 'u';
                if (t[m-1] == t[m]) m--;
                i += 2;
            } else
            if ((s[i] == 'o' || s[i] == 'O') && (s[i+1] == 'o' || s[i+1] == 'O')) {
                t[++m] = isupper(s[i]) ? 'U' : 'u';
                if (t[m-1] == t[m]) m--;
                i++;
            } else
            if ((s[i] == 'e' || s[i] == 'E') && (s[i+1] == 'e' || s[i+1] == 'E')) {
                t[++m] = isupper(s[i]) ? 'I' : 'i';
                if (t[m-1] == t[m]) m--;
                i++;
            } else
            if ((s[i] == 't' || s[i] == 'T') && (s[i+1] == 'h' || s[i+1] == 'H')) {
                t[++m] = isupper(s[i]) ? 'Z' : 'z';
                if (t[m-1] == t[m]) m--;
                i++;
            } else {
                t[++m] = s[i];
                if (t[m-1] == t[m]) m--;
            }
        }

        for (int i = 1; i <= m; i++) cout << t[i];
        cout << endl;
    }

    return 0;
}
