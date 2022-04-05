#include <iostream> 
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");

	int A, B, p, n;
	char tmp[33];

	cout << "Вариант 11\n\n";
	cout << "Задание №1" << endl;
	cout << "Введите число: ";
	cin >> A;

	if ((A & 15) == 0) {
		cout << "Число кратно 16\n\n";
	}
	else {
		cout << "Число не кратно 16\n\n";
	}

	cout << "Задание №2\n";
	cout << "А: "; cin >> A;
	cout << "Введите начальную позицию p: "; cin >> p;
	cout << "Введите количество изменяющихся битов n: "; cin >> n;

	if (p == 0) {
		cout << "p не может равняться нулю!\n\n";
	}
	else {
		_itoa_s(A, tmp, 2);
		cout << tmp << " - ";

		int b = A - ((A >> p) << p);
		int c = (A >> (p + n)) << (p + n);
		int rev = ((A - c - b) >> p);
		int xor_num = 0;

		for (int i = 0; i < n; i++) {
			xor_num += pow(2, i);
		}

		int k = xor_num ^ rev;
		_itoa_s(k, tmp, 2);
		cout << tmp << endl;

		cout << "В: "; cin >> B;
		cout << "Введите начальную позицию p: "; cin >> p;

		if (p == 0) {
			cout << "Начальная позиция не может быть равной нулю!";
		}
		else {
			_itoa_s(B, tmp, 2);
			cout << tmp << endl;
			b = B - ((B >> (p - 1)) << (p - 1));
			c = (B >> (p - 1 + n)) << (p - 1 + n);

			c >>= (p - 1);
			c += k;
			c <<= (p - 1);
			c += b;

			_itoa_s(c, tmp, 2);
			cout << tmp << "\n\n";
		}
	}
	return 0;
}