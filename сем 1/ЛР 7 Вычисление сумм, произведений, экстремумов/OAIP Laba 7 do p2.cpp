#include <iostream>

int main()
{
    using namespace std;
    setlocale(LC_CTYPE, "Russian");
    int n, i = 0, sum = 0, number = 0, first_otric, kol_chisel, k = 0;
    cout << "Введите количество чисел = ";
    cin >> kol_chisel;
    do {
        i += 1;
        cout << "Введите чило_" << i << " ";
        cin >> n;
        if (n < 0 && k == 0) {
            first_otric= n;
            number = i;
            k = 1;
        }
    } while (i < kol_chisel);
    cout << "Первое отрицательное= " << first_otric << endl;
    cout << "Его номер = " << number;
    if (k == 0) {
        cout << "Нету отрицательных";
    }
}

