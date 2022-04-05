#include <iostream>
#include <ctime>
int main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	const int N = 100;
	int i, size, Massive[N];
	int rmn = 0, rmx = 99, T = 0;
	cout << "Введите размер массива от " << rmn << " до " << rmx << endl;
	cin >> size;
	if (size > rmx) {
		return 0;
	}
	if (size < rmn) {
		return 0; }
	/*присваивание массиву чисела*/
	srand((unsigned)time(NULL));
	for (i = 0; i < size; i++)
	{
		Massive[i] = (int)(((double)rand() /
			(double)RAND_MAX) * (rmx - rmn) + rmn);
	}
	/*find min*/
	for (i = 0; i < size; i++) {
		if (Massive[i] < Massive[T]) {
			T = i;
		}
	}
	cout << "Min = " << T << endl;
	/*Проверка деления на 2 и замена*/
	for (i = 0; i < size; i++) {
		if (Massive[i] % 2 == 0) {
			Massive[i] = T;
			cout << Massive[i] << endl;
		}
		else {
			cout << Massive[i] << endl;
		}
	}
	return 0;
}
