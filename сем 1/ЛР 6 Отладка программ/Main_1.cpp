#include <iostream>

int main()
{
    using namespace std;
    setlocale(LC_CTYPE, "Russian");
    float f = -125e-6, y = 1.7, t = 1, c, d;
    while (t <= 3)
    {
        t = t + 0.1;
        c = 2 * sin(f / 2) + log(t);
        if (c >= 3) {
            d = y * exp(-2 * t) + f;
            
        }
        else if (c < 3) {
            d = y - pow(y, 3);
            
        }
        cout << "t = " << t << endl;
        cout << "d = " << d << endl;
    }
    return 0;
}