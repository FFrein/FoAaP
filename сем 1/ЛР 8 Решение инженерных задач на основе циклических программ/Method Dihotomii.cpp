#include <iostream>

double function(double x) {
    x = exp(x) + 2 * x * x - 3;
    return x;
}

int main()
{
    using namespace std;
    double a=3, b=6, e=0.0001, x;
    do {
        x = (a + b) / 2;
        if (function(x) * function(a) <= 0) {
            b = x;
        }
        else {
            a = -x;
        }
    } while (abs(a - b) < 2 * e);
       cout << x;
}