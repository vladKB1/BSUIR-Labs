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

struct List {
    string name, date, adrress;
    int num = 0, int_date = 0;
    List *left, *right;
};

List *root, *I;
int stn, k;

void f1() {
    stn++;
    k++;
    if (stn > 1) {
        List *J = new List;
        J->left = I;
        I->right = J;
        I = J;
    } else {
        root = new List;
        I = root;
    }

    //cout << "Запись №" << stn << ":" << endl;
    I->num = stn;

    //cout << "Ф.И.О. - ";
    getline(cin,I->name);
    getline(cin,I->name);

    //cout << "Адрес - ";
    getline(cin,I->adrress);

    //cout << "Дата приёма на учёт в формате дд.мм.гггг - ";
    cin >> I->date;

    string t = I->date;
    int x = 0;
    x += (t[1]-48) + (t[0]-48)*10;
    x += (t[4]-48) + (t[3]-48)*10;
    x += (t[9]-48) + (t[8]-48)*10 + (t[7]-48)*100 + (t[6]-48)*1000;
    I->int_date = x;
}

void f2() {
    if (k == 0) {
        cout << "Элементов нет :)" << endl;
        return;
    }

    I = root;
    int i = 1;

    while (i <= k) {
        cout << "Запись №" << I->num << ":" << endl;
        cout << "Ф.И.О. - " << I->name << endl;
        cout << "Адрес - " << I->adrress << endl;
        cout << "Дата приёма на учёт - " << I->date << endl;

        i++;
        if (i > k) break;

        I = I->right;
    }
}

void f3() {
    if (k == 0) {
        cout << "Нет ни одного элемента в списке" << endl;
        return;
    }

    string s;
    cout << "Введите Ф.И.О. или номер - ";
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
        cout << "Элемент не найден :(" << endl;
        return;
    }


    if (i != k) I->left->right = I->right;
    if (i != 1) I->right->left = I->left;

    //delete I;
    k--;

    cout << "Элемент успешно удален!" << endl;
}

void f4() {
    if (k == 0) {
        cout << "Нет ни одного элемента в списке" << endl;
        return;
    }

    string s;
    cout << "Введите Ф.И.О. или номер - ";
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
        cout << "Элемент не найден :(" << endl;
        return;
    }

    cout << "Если информация в поле не меняется введите *" << endl;

    string t;
    cout << "Ф.И.О. - ";
    cin >> t;
    if (t != "*") I->name = t;

    cout << "Адрес - ";
    cin >> t;
    if (t != "*") I->adrress = t;

    cout << "Дата приёма в формате дд.мм.гггг - ";
    cin >> t;
    if (t != "*") {
        I->date = t;

        int x = 0;
        x += (t[1]-48) + (t[0]-48)*10;
        x += (t[4]-48) + (t[3]-48)*10;
        x += (t[9]-48) + (t[8]-48)*10 + (t[7]-48)*100 + (t[6]-48)*1000;
        I->int_date = x;
    }
}

void f5() {
    if (k == 0) {
        cout << "Нет ни одного элемента в списке" << endl;
        return;
    }

    List *a[k];

    int SIZE = 0;
    int i = 1;
    I = root;

    while (i <= k) {
        a[SIZE++] = I;
        i++;
        if (i > k) break;
        I = I->right;
    }

    bool f[SIZE];
    for (int i = 0; i < SIZE; i++) f[i] = 0;

    for (int i = 0; i < SIZE; i++)
        for (int j = i+1; j < SIZE; j++)
        if (a[i]->name == a[j]->name && a[i]->adrress == a[j]->adrress) f[j] = 1;

    for (int i = 0; i < SIZE; i++) if (!f[i]) {
        I = a[i];
        cout << "Запись №" << I->num << ":" << endl;
        cout << "Ф.И.О. - " << I->name << endl;
        cout << "Адрес - " << I->adrress << endl;
        cout << "Дата приёма на учёт - " << I->date << endl;
        cout << endl;

        if (i != k) I->left->right = I->right;
        if (i != 1) I->right->left = I->left;

        //delete I;
        k--;
    }
}

void f0() {
    exit(0);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int q;
   // cout << "Кол-во первоначальных элементов в списке: ";
    cin >> q;
    for (int i = 1; i <= q; i++) f1();


    printf("%*s\n",15,"Меню");
    printf("%s\n","1 - Добавить в список");
    printf("%s\n","2 - Вывод информации о списке");
    printf("%s\n","3 - Удаление из списка");
    printf("%s\n","4 - Изменение информации в списке");
    printf("%s\n","5 - Удалить из списка все повторные записи с одинаковым Ф.И.О и адресом");
    printf("%s\n","0 - Закончить выполнение программы");
    printf("%s","\n");

    void (*func[6])() = {f0,f1,f2,f3,f4,f5};

    while (1) {
        int Type;

        printf("%s\n","Введите необходимую цифру для выполнения операции: ");
        cin >> Type;

        func[Type]();
        cout << endl;
    }

    return 0;
}
