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

    cout << "Квитанция №" << stn << ":" << endl;
    I->num = stn;

    cout << "Наименование изделия - ";
    cin >> I->name;

    cout << "Дата приёма в формате дд.мм.гггг (если дата повторяется с предыдущей квитанцией, то напишите *) - ";
    cin >> I->date;
    if (I->date == "*") I->date = I->left->date;

    string t = I->date;
    int x = 0;
    x += (t[1]-48) + (t[0]-48)*10;
    x += (t[4]-48) + (t[3]-48)*10;
    x += (t[9]-48) + (t[8]-48)*10 + (t[7]-48)*100 + (t[6]-48)*1000;
    I->int_date = x;


    cout << "cтепень повреждения - ";
    cin >> I->rate;

    cout << "Примерное время ожидания (кол-во дней числом) - ";
    cin >> I->wait;

    cout << "состояние готовности заказа (цифрой, 1 - выполнен, 0 - не выполнен) - ";
    cin >> I->Ready;
}

void f2() {
    if (k == 0) {
        cout << "Квитанций нет :)" << endl;
        return;
    }

    I = root;
    int i = 1;

    while (i <= k) {
        cout << "Квитанция №" << I->num << ":" << endl;
        cout << "Наименование изделия - " << I->name << endl;
        cout << "Дата приёма - " << I->date << endl;
        cout << "cтепень повреждения - " << I->rate << endl;
        cout << "Примерное время ожидания - " << I->wait << " д." << endl;
        cout << "Cостояние готовности заказа - " << (I->Ready ? "выполнен" : "не выполнен") << endl;
        cout << endl;

        i++;
        if (i > k) break;

        I = I->right;
    }
}

void f3() {
    if (k == 0) {
        cout << "Нет ни одной квитанции в списке" << endl;
        return;
    }

    bool f = 0;
    int i = 1;
    I = root;

    string finding;
    cout << "Введите наименование для пойска - ";
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
        cout << "Квитанция не найдена :(" << endl;
        return;
    } else {
        cout << "Квитанция №" << I->num << ":" << endl;
        cout << "Наименование изделия - " << I->name << endl;
        cout << "Дата приёма - " << I->date << endl;
        cout << "cтепень повреждения - " << I->rate << endl;
        cout << "Примерное время ожидания - " << I->wait << " д." << endl;
        cout << "Cостояние готовности заказа - " << (I->Ready ? "выполнен" : "не выполнен") << endl;
        cout << endl;

    }
}

void f4() {
    if (k == 0) {
        cout << "Нет ни одной квитанции в списке" << endl;
        return;
    }

    string s;
    cout << "Введите номер или наименование квитанции - ";
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
        cout << "Квитанция не найдена :(" << endl;
        return;
    }


    if (i != k) I->left->right = I->right;
    if (i != 1) I->right->left = I->left;

    //delete I;
    k--;

    cout << "Квитанция успешно удалена!" << endl;
}

void f5() {
    if (k == 0) {
        cout << "Нет ни одной квитанции в списке" << endl;
        return;
    }

    string s;
    cout << "Введите номер или наименование квитанции - ";
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
        cout << "Квитанция не найдена :(" << endl;
        return;
    }

    cout << "Если информация в поле не меняется введите *" << endl;

    string t;
    cout << "Наименование изделия - ";
    cin >> t;
    if (t != "*") I->name = t;

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

    int p;
    cout << "cтепень повреждения - ";
    cin >> p;
    if (char(p) != '*') I->rate = p;

    cout << "Примерное время ожидания (кол-во дней числом) - ";
    cin >> p;
    if (char(p) != '*') I->wait = p;

    cout << "состояние готовности заказа (цифрой, 1 - выполнен, 0 - не выполнен) - ";
    cin >> p;
    if (char(p) != '*') I->Ready = p;
}

void f6() {
    if (k == 0) {
        cout << "Нет ни одной квитанции в списке" << endl;
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
        cout << "Квитанция №" << I->num << ":" << endl;
        cout << "Наименование изделия - " << I->name << endl;
        cout << "Дата приёма - " << I->date << endl;
        cout << "cтепень повреждения - " << I->rate << endl;
        cout << "Примерное время ожидания - " << I->wait << " д." << endl;
        cout << "Cостояние готовности заказа - " << (I->Ready ? "выполнен" : "не выполнен") << endl;
        cout << endl;
    }
}

void f0() {
    exit(0);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("%*s\n",15,"Меню");
    printf("%s\n","1 - Добавить квитанцию");
    printf("%s\n","2 - Вывод информации обо всех квитанциях");
    printf("%s\n","3 - Поиск квитанции по наименованию");
    printf("%s\n","4 - Удаление квитанции");
    printf("%s\n","5 - Изменение информации о квитанции");
    printf("%s\n","6 - Информация об изделиях, ремонт которых еще не выполнен");
    printf("%s\n","0 - Закончить выполнение программы");
    printf("%s","\n");

    void (*func[7])() = {f0,f1,f2,f3,f4,f5,f6};

    while (1) {
        int Type;

        printf("%s","Введите необходимую цифру для выполнения операции: ");
        cin >> Type;

        func[Type]();
        cout << endl;
    }

    return 0;
}
