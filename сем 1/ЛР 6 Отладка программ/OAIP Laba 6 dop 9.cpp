#include <iostream>
using namespace std;
int main() {
    int x, i = 1;
    cin >> x;
    while(i <= x) {
        if (x % i == 0) {
            cout << x << " / " << i << endl;
        }
        i = i + 1;
    }
}





/*
int kovk()
{
    using namespace std;
    int m, n, k = 1, g = 1;
    cout << "m = ";
    cin >> m;
    cout << "n = ";
    cin >> n;
    while (k <= n) {
        while (g <= n) {
            if (((g + k) * (g + k)) == m) {
                cout << "set " << g << " " << k << endl;
            }
            g = g + 1;
        }
            k = k + 1;
            g = k;
        }
    return 0;
}
*/
