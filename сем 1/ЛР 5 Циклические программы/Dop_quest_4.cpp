#include <iostream>

int main()
{
    using namespace std;
    setlocale(LC_CTYPE, "Russian");
    int stoimost, ocenka = 0, age1 = 1, age2, obescenka;
    cout << "Конечный год = ";
    cin >> age2;
    while (age1 <= age2) {
        age1 = age1 + 1;
        cout << "Введите стоимость закупки = ";
        cin >> stoimost;
        ocenka = ocenka + stoimost;
    }
    cout << "Процент обесценивания (число) = ";
    cin >> obescenka;
    ocenka = ocenka - (ocenka * obescenka * 0.01);
    cout << ocenka;
    return 0;
}
