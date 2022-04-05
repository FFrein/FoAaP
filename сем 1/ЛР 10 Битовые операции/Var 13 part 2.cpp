#include <iostream> 
using namespace std;

void main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Вариант 13\n\n";
	cout << "Задание №1" << endl;

	
	char tmp[33], maskA[33];
	int A, B, maskB, maskC, numb_of_bit, cicle_bit;;
	cout << "Первое число A="; cin >> A;
	_itoa_s(A, tmp, 2); cout << tmp << endl;
	_itoa_s(A, maskA, 2); /*Запись числа A в маскуА в двоичном коде*/
	cout << "Второе число B="; cin >> B;
	_itoa_s(B, tmp, 2); cout << tmp << endl;
	cout << "Введите с какого бита "; cin >> numb_of_bit;
	numb_of_bit = numb_of_bit - 1;
	cout << "Введите сколько бит меняем "; cin >> cicle_bit;
	for (int i = 1; i <= cicle_bit; i++) {
		A = A | (0001 << numb_of_bit); /*Замена определённого бита на 1*/
		_itoa_s(A, tmp, 2); cout << tmp << endl;
		numb_of_bit += 1;
	}

}