#include <iostream>

int main()
{
    using namespace std;
    setlocale(LC_CTYPE, "Russian");
    int a, b, c, r, s, t;
    cout << "Введите высоту коробки 1 = "; cin >> a;
    cout << "Введите ширины коробки 1 = "; cin >> b;
    cout << "Введите длинну коробки 1 = "; cin >> c;
    cout << "Введите высоту коробки 2 = "; cin >> r;
    cout << "Введите ширину коробки 2 = "; cin >> s;
    cout << "Введите длинну коробки 2 = "; cin >> t;
    if (a > r) {
        if (b > s) {
            if (c > t) {
                cout << "Коробка помещается";
                return 0;
            }
            else {
                cout << "Коробка не помещается";
                return 0;
            }
        }
        else if (b > t) {
            if (c > s) {
                cout << "Коробка помещается";
                return 0;
            }
            else {
                cout << "Коробка не помещается";
                return 0;
            }
        }
        else {
            cout << "Коробка не помещается";
            return 0;
        }
    }
    else if (a > s) {
        if (b > r) {
            if (c > t) {
                cout << "Коробка помещается";
                return 0;
            }
            else {
                cout << "Коробка не помещается";
                return 0;
            }
        }
        else if (b > t) {
            if (c > r) {
                cout << "Коробка помещается";
                return 0;
            }
            else {
                cout << "Коробка не помещается";
                return 0;
            }
        }
        else {
            cout << "Коробка не помещается";
            return 0;
        }
    }
    else if (a > t) {
        if (b > r) {
            if (c > s) {
                cout << "Коробка помещается";
                return 0;
            }
            else {
                cout << "Коробка не помещается";
                return 0;
            }
        }
        else if (b > s) {
            if (c > r) {
                cout << "Коробка помещается";
                return 0;
            }
        }
        else {
            cout << "Коробка не помещается";
            return 0;
        }
    }
    else {
        cout << "Коробка не помещается";
            return 0;
    }
}