#include <iostream>

int main()
{
    using namespace std;
    setlocale(LC_CTYPE, "Russian");
    int tr6, tr5, tr4, tr3, tr2, tr1, sum, luckyticket1, luckyticket2;
    for (int ticket = 1; ticket <= 1000000; ticket++)
    {
        tr6 = ticket / 100000;
        tr5 = (ticket % 100000) / 10000;
        tr4 = (ticket % 10000) / 1000;
        tr3 = (ticket % 1000) / 100;
        tr2 = (ticket % 100) / 10;
        tr1 = (ticket % 10);
        sum = tr6 + tr5 + tr4 + tr3 + tr2 + tr1;
        if (sum % 7 == 0) {
            luckyticket1 = ticket;
            luckyticket2 = ticket + 1;
            tr6 = luckyticket2 / 100000;
            tr5 = (luckyticket2 % 100000) / 10000;
            tr4 = (luckyticket2 % 10000) / 1000;
            tr3 = (luckyticket2 % 1000) / 100;
            tr2 = (luckyticket2 % 100) / 10;
            tr1 = (luckyticket2 % 10);
            sum = tr6 + tr5 + tr4 + tr3 + tr2 + tr1;
            if (sum % 7 == 0) {
                cout << "Два подряд " << luckyticket1 << " " << luckyticket2 << endl;
            }
        }
    }
    return 0;
}
