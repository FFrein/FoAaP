#include <iostream>

int main()
{
    using namespace std;
    setlocale(LC_CTYPE, "Russian");
    const int N = 10;
    int A[N], kol=0, i;
    /*Присвоение массиву с колл. значений N, значения до N*/
    srand((unsigned)time(NULL));
    for (i = 0; i < N; i++)
    {
        A[i] = rand() % N;
    }
    /*Получившийся массив*/
    for (i = 0; i < N; i++)
    {
        cout << A[i] << endl;
    }

    for (i = 0; i < N; i++) {
        if (A[i] == A[i + 1]) {
            kol += 1;
        }
    }
    cout << "Результат = " << kol;
    return 0;
}
