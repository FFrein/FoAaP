#include <iostream>

using namespace std;

void main(){
    setlocale(LC_CTYPE, "Russian");

    int massive = 25, massive2 = 28;
    int schet_one, schet_two = 0, chisla = 20;
    int* A;
    A = new int[massive];

    for(schet_one = 0; schet_one < massive; schet_one++)
    {
        A[schet_one] = rand() % massive;
    }

    cout << "Созданный массив: " << endl;

    for (schet_one = 0; schet_one < massive; schet_one++)
    {
        cout << A[schet_one] << endl;
    }

    for (schet_one = 0; schet_one < massive; schet_one++)
    {
        if (A[schet_one] % 2 != 0 && schet_two !=6) {
            A[schet_one] = 0;
            schet_two += 1;
        }
    }

    massive += 3;
    for (schet_one = (massive - 3); schet_one < massive; schet_one++)
    {
        A[schet_one] = 0;
    }
    
    cout << "Изменённый массив: " << endl;

    for (schet_one = 0; schet_one < massive; schet_one++)
    {
        cout << A[schet_one] << endl;
    }
}