#include <iostream>
#include <iomanip>

void main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	double r, l;
	char a, space; space = ' ';
	cout << "Введите символ "; cin >> a;
	cout << setw(35) << setfill(space) << space;
	cout << setw(10) << setfill(a) << a << endl;
	cout << setw(35) << setfill(space) << space;
	cout << setw(11) << setfill(a) << a << endl;
	cout << setw(35) << setfill(space) << space;
	cout << setw(12) << setfill(a) << a << endl;
	cout << setw(35) << setfill(space) << space;
	cout << setw(13) << setfill(a) << a << endl;
	cout << "Введите длинну окружности = "; cin >> l;
	r = l / (2 * 3.14);
	r = r * r * 3.14;
	cout << "Площадь круга равна = " << r;
}