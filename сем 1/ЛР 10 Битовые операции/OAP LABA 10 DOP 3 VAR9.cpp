#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");

	char tmp[33];
	int A, B, maskA = 124;
	int maskB = ~maskA >> 2;

	cout << "Вариант 9\n\n";

	cout << "Задание №1\n";
	cout << "Первое число А="; cin >> A;
	cout << "Второе число В="; cin >> B;

	_itoa_s(A, tmp, 2);
	cout << "A=" << tmp << endl;
	_itoa_s(B, tmp, 2);
	cout << "B=" << tmp << endl;

	_itoa_s(maskA, tmp, 2);
	cout << "Маска для А: " << tmp << endl;
	_itoa_s((A & maskA) >> 2, tmp, 2);
	cout << "Выделенные биты А: " << tmp << endl;

	_itoa_s(maskB, tmp, 2);
	cout << "Маска для В: " << tmp << endl;
	_itoa_s(B & maskB, tmp, 2);
	cout << " Очищены биты в B: " << tmp << endl;

	_itoa_s(((B & maskB) | ((A & maskA) >> 1)), tmp, 2);
	cout << " Результат B=" << tmp << endl << endl;

	cout << "Задание №2\n";
	int n, num, p, k, b;
	cout << "Введите число: ";
	cin >> num;

	cout << "Введите начальную позицию p и количество изменяющихся битов n (p > n, p != 0): ";
	cin >> p >> n;

	if (p <= n && p == 0) {
		cout << "p должна быть большей за n и 0!";
		return 0;
	}

	_itoa_s(num, tmp, 2);

	cout << endl << tmp << endl;
	b = (num >> (p - 1)) << (p - 1);

	if (p - n - 1 == 0) {
		k = pow(2, (p - n - 1));
	}
	else {
		k = pow(2, (p - n - 1)) - 1;
	}

	if (p - n != 1) {
		b += k;
	}

	_itoa_s(num & b, tmp, 2);
	cout << tmp << endl << endl << "----------\n\n";

	return 0;
}

