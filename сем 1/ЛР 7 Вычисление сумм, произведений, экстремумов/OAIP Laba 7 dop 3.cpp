#include <iostream>

int main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	float n, max, min, kol = 0, i = 0, x;
	cout << "Введите max = ";
	cin >> max;
	cout << "Введите min = ";
	cin >> min;
	cout << "Введите количесто чисел n = ";
	cin >> n;
	do {
		i += 1;
		cout << "Введитие число x" << i << " = ";
		cin >> x;
		if (x < max && x > min) {
			kol += 1;
		}
	} while (i != n);
	cout << "Количесто чисел между " << min << " и " << max << " = " << kol;
}

