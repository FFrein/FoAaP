#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_CTYPE, "Russian");

	char tmp[33];
	int A, maskA = 126, p, n;

	cout << "Вариант 10\n\n";
	cout << "Задание №1" << endl;
	cout << "Введите число А: ";
	cin >> A;

	_itoa_s(A, tmp, 2);
	cout << "A: " << tmp << endl;
	_itoa_s((A & maskA) >> 1, tmp, 2);
	cout << "Выделенные биты: " << tmp << endl << endl << "Задание №2\n";
	cout << "Введите число А: "; cin >> A;
	cout << "Введите начальную позицию p: "; cin >> p;
	cout << "Введите количество изменяющихся битов n: "; cin >> n;

	if (p == 0) {
		cout << "p не может равняться нулю!\n\n";
	}
	else {
		_itoa_s(A, tmp, 2);
		cout << tmp << endl;

		int b = A - ((A >> p) << p);
		int c = (A >> (p + n)) << (p + n);
		int rev = ((A - c - b) >> p);
		int xor_num = 0;

		for (int i = 0; i < n; i++) {
			xor_num += pow(2, i);
		}

		int k = xor_num ^ rev;

		c >>= p;
		c += k;
		c <<= p;
		c += b;

		_itoa_s(c, tmp, 2);
		cout << tmp << endl << endl;
	}
	return 0;
}