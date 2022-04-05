#include <iostream> 
using namespace std;
/*замена битов на противоположные с 4 по 8*/
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int A = 170; char tmp[33];
	cout << "Вариант 12\n\n";
	cout << "Задание №1" << endl;
	_itoa_s(A, tmp, 2);
	cout << " Число А: " << tmp << endl;
	_itoa_s(0xF8, tmp, 2);
	cout << " Маска для замены бит: " << tmp << endl;
	_itoa_s(A ^ 0xF8, tmp, 2); /*0xF8 - 4 бит*/
	cout << " Результат: " << tmp << endl << endl;
}
