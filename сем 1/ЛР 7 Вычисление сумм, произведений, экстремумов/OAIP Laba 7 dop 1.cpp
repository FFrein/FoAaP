#include <iostream>

int main()
{
    using namespace std;
    setlocale(LC_CTYPE, "Russian");
    int n, i = 0, sum = 0, kol_chetnih = 0, kol_chisel;
    cout << "Введите количество чисел = ";
    cin >> kol_chisel;
    do {
        i += 1;
        cout << "Введите чило_" << i << " ";
        cin >> n;
        if (n % 2 == 0) {
            sum += n;
            kol_chetnih += 1;
        }
    } while (i < kol_chisel);
    cout << "Сумма чётных = " << sum << endl;
    cout << "Колличество чётных = " << kol_chetnih;
    return 0;
}

