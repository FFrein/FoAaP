#include <iostream>
#include <cmath>

using namespace std;

double sumCos(double x, int n)
{
    if (n == 1)
        return cos(x);
    else
        return sumCos(x, n - 1) + cos(n * x);
}

int main() {
    setlocale(LC_CTYPE, "rus");
    double x;
    cout << "������� �������� x: ";
    cin >> x;

    int n;
    cout << "������� n: ";
    cin >> n;

    double y = sumCos(x, n);
    cout << "y = " << y << endl;
}