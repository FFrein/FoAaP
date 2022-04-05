#include <iostream>

int main()
{
    using namespace std;
    setlocale(LC_CTYPE, "Russian");
    int a, b, p, q, r, s;
    cout << "Введите длинну участка = "; cin >> a;
    cout << "Введите ширину участка = "; cin >> b;
    cout << "Введите длинну 1 объекта = "; cin >> p;
    cout << "Введите ширину 1 объекта = "; cin >> q;
    cout << "Введите длинну 2 объекта = "; cin >> r;
    cout << "Введите ширину 2 объекта = "; cin >> s;
    a = a - p;
    b = b - q;
    if (a < r) {
        cout << "Недостаточный размер участка";
    }
    else if (b < s) {
        cout << "Недостаточный размер участка";
    }
    else
        cout << "Участока достаточно для постройки";
    return 0;
}

