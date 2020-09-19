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


typedef double(*func) (double x);


using namespace std;


double integral1(double x){
    return (sqrt(2*x+1.7))/(2.4*x+sqrt(1.2*sqr(x)+0.6));
}

double integral2(double x) {
    return sin(0.6*sqr(x)+0.3)/(2.4+cos(x+0.5));
}

double integral3(double x) {
    return 1/sqrt(sqr(x)-1);
}

double integral4(double x) {
    return cos(sqr(x))/(x+1);
}

double f1(int n, double a, double b, func f) {
    double h = (b-a) / n;
    double ans = 0;

    for (int i = 0; i <= n-1; i++) ans += f(a + i*h);

    return ans*h;
}

double f2(int n, double a, double b, func f) {
    double h = (b-a) / n;
    double ans = 0;

    for (int i = 1; i <= n; i++) ans += f(a + i*h);

    return ans*h;
}

double f3(int n, double a, double b, func f) {
    double h = (b-a) / n;
    double ans = 0;

    for (int i = 0; i <= n-1; i++) ans += f(a + i*h+h/2);

    return ans*h;
}

double f4(int n, double a, double b, func f) {
    double h = (b-a) / n;
    double ans = 0;

    for (int i = 1; i <= n-1; i++) ans += f(a + i*h);
    ans += (f(a)+f(a+n*h))/2;

    return ans*h;
}


int main() {
    cout << fixed << setprecision(9);

    int n;
    cout << "n = ";
    cin >> n;

    cout << "First Integral: " << endl;
    cout << f1(n, 1.9, 2.6, integral1) << endl;
    cout << f2(n, 1.9, 2.6, integral1) << endl;
    cout << f3(n, 1.9, 2.6, integral1) << endl;
    cout << f4(n, 1.9, 2.6, integral1) << endl << endl;

    cout << "Second Integral: " << endl;
    cout << f1(n, 0.3, 1.1, integral2) << endl;
    cout << f2(n, 0.3, 1.1, integral2) << endl;
    cout << f3(n, 0.3, 1.1, integral2) << endl;
    cout << f4(n, 0.3, 1.1, integral2) << endl << endl;

    cout << "Third Integral: " << endl;
    cout << f1(n, 2, 3.5, integral3) << endl;
    cout << f2(n, 2, 3.5, integral3) << endl;
    cout << f3(n, 2, 3.5, integral3) << endl;
    cout << f4(n, 2, 3.5, integral3) << endl << endl;

    cout << "Fourth Integral: " << endl;
    cout << f1(n, 0.4, 1.2, integral4) << endl;
    cout << f2(n, 0.4, 1.2, integral4) << endl;
    cout << f3(n, 0.4, 1.2, integral4) << endl;
    cout << f4(n, 0.4, 1.2, integral4) << endl;

    return 0;
}

//(sqrt(2*x+1.7))/(2.4*x+sqrt(1.2*x^2+0.6)) 0.219231456764389
//sin(0.6*x^2+0.3)/(2.4+cos(x+0.5)) 0.171413160956516
// 1/sqrt(x^2-1) 0.607889403313597
//cos(x^2)/(x+1) 0.338317248425201
