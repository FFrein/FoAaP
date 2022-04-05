#include <iostream>

void main()
{
    setlocale(LC_CTYPE, "Russian");
    float y, z, b = 0.5, m = 8, a = 2.4e-4, j;
    for (int n = 1; n <= 3; n++)
    {
        printf("Введите j = ");
        scanf_s("%f", &j);
        y = (m - b) / (sin(a) - exp(a));
        if ((a - (4 * j * b)) <= 0) {
            printf("Отрицательный корень\t\n");
        }
        else {
            z = 3 * y + sqrt(a - (4 * j * b));
            printf("j = %5.2f\t", j);
            printf("z = %5.2f\n", z);
        }
    }
}