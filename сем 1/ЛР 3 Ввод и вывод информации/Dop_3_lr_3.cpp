#include <iostream>
#include <iomanip>

void main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	char a, space; space = ' ';
	float m, b, c, d;
	cout << "1)������� ������ "; cin >> a;
	cout << setw(35) << setfill(space) << space;
	cout << setw(5) << setfill(a) << a << endl;
	cout << setw(34) << setfill(space) << space;
	cout << setw(7) << setfill(a) << a << endl;
	cout << setw(33) << setfill(space) << space;
	cout << setw(9) << setfill(a) << a << endl;
	cout << setw(33) << setfill(space) << space;
	cout << setw(9) << setfill(a) << a << endl;
	cout << setw(33) << setfill(space) << space;
	cout << setw(9) << setfill(a) << a << endl;
	cout << setw(34) << setfill(space) << space;
	cout << setw(7) << setfill(a) << a << endl;
	cout << setw(35) << setfill(space) << space;
	cout << setw(5) << setfill(a) << a << endl;

	cout << "1)������� ����� m = "; cin >> m;
	m = m - 5;
	b = m / 2;
	d = b + 5;
	cout << "����� 1 = " << b << endl;
	cout << "����� 2 = " << d;
}