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

struct receipt {
    string name, date;
    bool Ready = 0;
    int rate = 0, wait = 0, num = 0, int_date = 0;
    receipt *left, *right;
};

receipt *root, *I;
int stn, k;

void f1() {
    stn++;
    k++;
    if (stn > 1) {
        receipt *J = new receipt;
        J->left = I;
        I->right = J;
        I = J;
    } else {
        root = new receipt;
        I = root;
    }

    cout << "��������� �" << stn << ":" << endl;
    I->num = stn;

    cout << "������������ ������� - ";
    cin >> I->name;

    cout << "���� ����� � ������� ��.��.���� (���� ���� ����������� � ���������� ����������, �� �������� *) - ";
    cin >> I->date;
    if (I->date == "*") I->date = I->left->date;

    string t = I->date;
    int x = 0;
    x += (t[1]-48) + (t[0]-48)*10;
    x += (t[4]-48) + (t[3]-48)*10;
    x += (t[9]-48) + (t[8]-48)*10 + (t[7]-48)*100 + (t[6]-48)*1000;
    I->int_date = x;


    cout << "c������ ����������� - ";
    cin >> I->rate;

    cout << "��������� ����� �������� (���-�� ���� ������) - ";
    cin >> I->wait;

    cout << "��������� ���������� ������ (������, 1 - ��������, 0 - �� ��������) - ";
    cin >> I->Ready;
}

void f2() {
    if (k == 0) {
        cout << "��������� ��� :)" << endl;
        return;
    }

    I = root;
    int i = 1;

    while (i <= k) {
        cout << "��������� �" << I->num << ":" << endl;
        cout << "������������ ������� - " << I->name << endl;
        cout << "���� ����� - " << I->date << endl;
        cout << "c������ ����������� - " << I->rate << endl;
        cout << "��������� ����� �������� - " << I->wait << " �." << endl;
        cout << "C�������� ���������� ������ - " << (I->Ready ? "��������" : "�� ��������") << endl;
        cout << endl;

        i++;
        if (i > k) break;

        I = I->right;
    }
}

void f3() {
    if (k == 0) {
        cout << "��� �� ����� ��������� � ������" << endl;
        return;
    }

    bool f = 0;
    int i = 1;
    I = root;

    string finding;
    cout << "������� ������������ ��� ������ - ";
    cin >> finding;

    while (i <= k) {
        if (I->name == finding) {
            f = 1;
            break;
        }

        i++;
        if (i > k) break;

        I = I->right;
    }

    if (!f) {
        cout << "��������� �� ������� :(" << endl;
        return;
    } else {
        cout << "��������� �" << I->num << ":" << endl;
        cout << "������������ ������� - " << I->name << endl;
        cout << "���� ����� - " << I->date << endl;
        cout << "c������ ����������� - " << I->rate << endl;
        cout << "��������� ����� �������� - " << I->wait << " �." << endl;
        cout << "C�������� ���������� ������ - " << (I->Ready ? "��������" : "�� ��������") << endl;
        cout << endl;

    }
}

void f4() {
    if (k == 0) {
        cout << "��� �� ����� ��������� � ������" << endl;
        return;
    }

    string s;
    cout << "������� ����� ��� ������������ ��������� - ";
    cin >> s;

    bool f = 0;
    int i = 1;
    I = root;
    if (s[0] >= '0' && s[0] <= '9') {
        int x = 0;
        ll step = 1;
        for (int i = s.size()-1; i >= 0; i--) {
            x += (s[i]-48) * step;
            step *= 10;
        }

        while (i <= k) {
            if (I->num == x) {
                f = 1;
                break;
            }

            i++;
            if (i > k) break;

            I = I->right;
        }
    } else {
        while (i <= k) {
            if (I->name == s) {
                f = 1;
                break;
            }

            i++;
            if (i > k) break;

            I = I->right;
        }
    }

    if (!f) {
        cout << "��������� �� ������� :(" << endl;
        return;
    }


    if (i != k) I->left->right = I->right;
    if (i != 1) I->right->left = I->left;

    //delete I;
    k--;

    cout << "��������� ������� �������!" << endl;
}

void f5() {
    if (k == 0) {
        cout << "��� �� ����� ��������� � ������" << endl;
        return;
    }

    string s;
    cout << "������� ����� ��� ������������ ��������� - ";
    cin >> s;

    bool f = 0;
    int i = 1;
    I = root;
    if (s[0] >= '0' && s[0] <= '9') {
        int x = 0;
        ll step = 1;
        for (int i = s.size()-1; i >= 0; i--) {
            x += (s[i]-48) * step;
            step *= 10;
        }

        while (i <= k) {
            if (I->num == x) {
                f = 1;
                break;
            }

            i++;
            if (i > k) break;

            I = I->right;
        }
    } else {
        while (i <= k) {
            if (I->name == s) {
                f = 1;
                break;
            }

            i++;
            if (i > k) break;

            I = I->right;
        }
    }

    if (!f) {
        cout << "��������� �� ������� :(" << endl;
        return;
    }

    cout << "���� ���������� � ���� �� �������� ������� *" << endl;

    string t;
    cout << "������������ ������� - ";
    cin >> t;
    if (t != "*") I->name = t;

    cout << "���� ����� � ������� ��.��.���� - ";
    cin >> t;
    if (t != "*") {
        I->date = t;

        int x = 0;
        x += (t[1]-48) + (t[0]-48)*10;
        x += (t[4]-48) + (t[3]-48)*10;
        x += (t[9]-48) + (t[8]-48)*10 + (t[7]-48)*100 + (t[6]-48)*1000;
        I->int_date = x;
    }

    int p;
    cout << "c������ ����������� - ";
    cin >> p;
    if (char(p) != '*') I->rate = p;

    cout << "��������� ����� �������� (���-�� ���� ������) - ";
    cin >> p;
    if (char(p) != '*') I->wait = p;

    cout << "��������� ���������� ������ (������, 1 - ��������, 0 - �� ��������) - ";
    cin >> p;
    if (char(p) != '*') I->Ready = p;
}

void f6() {
    if (k == 0) {
        cout << "��� �� ����� ��������� � ������" << endl;
        return;
    }

    int SIZE = 0;

    int i = 1;
    I = root;

    while (i <= k) {
        if (I->Ready) SIZE++;
        i++;
        if (i > k) break;
        I = I->right;
    }

    receipt *a[SIZE];

    SIZE = 0;
    i = 1;
    I = root;

    while (i <= k) {
        if (!I->Ready) a[SIZE++] = I;
        i++;
        if (i > k) break;
        I = I->right;
    }

    for (int i = 0; i < SIZE; i++)
        for (int j = i+1; j < SIZE; j++)
        if (a[i]->int_date < a[j]->int_date) swap(a[i],a[j]);

    for (int i = 0; i < SIZE; i++) {
        I = a[i];
        cout << "��������� �" << I->num << ":" << endl;
        cout << "������������ ������� - " << I->name << endl;
        cout << "���� ����� - " << I->date << endl;
        cout << "c������ ����������� - " << I->rate << endl;
        cout << "��������� ����� �������� - " << I->wait << " �." << endl;
        cout << "C�������� ���������� ������ - " << (I->Ready ? "��������" : "�� ��������") << endl;
        cout << endl;
    }
}

void f0() {
    exit(0);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("%*s\n",15,"����");
    printf("%s\n","1 - �������� ���������");
    printf("%s\n","2 - ����� ���������� ��� ���� ����������");
    printf("%s\n","3 - ����� ��������� �� ������������");
    printf("%s\n","4 - �������� ���������");
    printf("%s\n","5 - ��������� ���������� � ���������");
    printf("%s\n","6 - ���������� �� ��������, ������ ������� ��� �� ��������");
    printf("%s\n","0 - ��������� ���������� ���������");
    printf("%s","\n");

    void (*func[7])() = {f0,f1,f2,f3,f4,f5,f6};

    while (1) {
        int Type;

        printf("%s","������� ����������� ����� ��� ���������� ��������: ");
        cin >> Type;

        func[Type]();
        cout << endl;
    }

    return 0;
}
