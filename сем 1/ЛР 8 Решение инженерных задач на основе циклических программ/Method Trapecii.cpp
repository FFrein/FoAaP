#include <iostream>

double function(double x) {
    x = exp(x);
    return x;
}

int main()
{
    using namespace std;
    double a = 3, b = 6, n = 200, h, s, x;
    h = (b - a) / n;
    x = a;
    s = 0;
    do{
    s += h * (function(x) + function(x + h)) / 2;
    x += h;
    }while (x > (b - h));
    cout << s;
    return 0;
}
