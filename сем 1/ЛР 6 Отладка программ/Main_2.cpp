#include <iostream>
using namespace std;

int NOD(int n1, int n2, int n3, int n4)
{
    int div;
    if (n1 == n2) {
        if (n3 % n1 == 0) {
            cout << " " << endl;
            return n1;
        }
        else {
            n4 = n3;
            n3 = n2;
            n2 = n4;
            cout << NOD(n1, n2, n3, n4);
        }
    }
    int d = n1 - n2;
    if (d < 0)
    {
        d = -d;
        div = NOD(n1, d, n3, n4);
    }
    else
    {
        div = NOD(n2, d, n3, n4);
    }
    return div;
}
int main()
{
    int n1, n2, n3, n4 = 0;
    cout << "n1=";
    cin >> n1;
    cout << "n2=";
    cin >> n2;
    cout << "n3=";
    cin >> n3;
    cout << NOD(n1, n2, n3, n4);
    cin.get(); cin.get(); return 0;

}