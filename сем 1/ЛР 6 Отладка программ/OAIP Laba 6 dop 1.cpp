#include <iostream>

using namespace std;

int main(){
    setlocale(LC_CTYPE, "Russian");
    int tr3, tr2, tr1;
    float cor;
    for (int numb = 100; numb <= 1000; numb++)
    {
        tr3 = (numb % 1000) / 100;
        tr2 = (numb % 100) / 10;
        tr1 = (numb % 10);
        cor = sqrt(numb);
        if (tr3 < tr2 && tr2 < tr1) {
            if ((cor - sqrt(numb)) == 0) {
                cout << "число " << numb << " корень " << cor << endl;
            }
        }
        }
}