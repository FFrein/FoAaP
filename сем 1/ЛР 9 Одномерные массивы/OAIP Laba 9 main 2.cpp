#include <iostream>
#include <ctime>
int main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	const int N = 100;
	int i, size, Massive[N];
	int rmn = 0, rmx = 99, T = 0, first, last;
	cout << "Введите размер массива от " << rmn << " до " << rmx << endl;
	cin >> size;
	if (size > rmx) {
		return 0;
	}
	if (size < rmn) {
		return 0;
	}
	/*присваивание массиву чисела*/
	srand((unsigned)time(NULL));
	for (i = 0; i < size; i++)
	{
		Massive[i] = (int)(((double)rand() / (double)RAND_MAX) * (rmx - rmn) + rmn);
	}
	/*find min*/
	for (i = 0; i < size; i++) {
		if (Massive[i] == 0) {
			if (T == 0) {
				first = i;
				T = 1;
			}
			last = i;
		}
	}
	if (T == 1) {
		cout << "Первый = " << first << " Последний = " << last;
	}
	else {
		cout << "Нету";
	}
	return 0;
}
