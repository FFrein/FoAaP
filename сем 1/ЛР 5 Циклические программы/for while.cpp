#include <iostream>

void main()
{
    using namespace std;
    setlocale(LC_CTYPE, "Russian");
    float y, z, m, j = 2, a = 2.4e-4;
    for (float b = 2; b <= 3;)
    {
        cout << "b = " << b << endl;
        b = b + 0.5;
        cout << "Введите m = ";
        cin >> m;
        while (j <= 3) 
        {
            y = (m - b) / (sin(a) - exp(a));
            if (4 * j * b <= 0) {
                cout << "Отрицательный корень";
                j = j + 0.5;
            }
            else {
                z = 3 * y + sqrt(a - (4 * j * b));
                cout << "" << z << endl;
                j = j + 0.5;
            }
        }
        j = 2;
    }
}
