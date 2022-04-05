#include <iostream>
using namespace std;

void main()
{
    setlocale(LC_CTYPE, "Russian");

    cout << "Вариант 13\n\n";
    cout << "Задание №1" << endl;


	char tmp[33];
	int A, B, maskA = 124;
	int maskB = ~maskA >> 4;

	cout << "Вариант 13\n\n";

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

}
