#include <iostream>
#include <iomanip>

void main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	double b;
	char a, space; space = ' ';
	cout << "1)������� ������ "; cin >> a;
	cout << setw(35) << setfill(space) << space;
	cout << setw(5) << setfill(a) << a << endl;
	cout << setw(35) << setfill(space) << space;
	cout << setw(5) << setfill(a) << a << endl;
	cout << setw(35) << setfill(space) << space;
	cout << setw(5) << setfill(a) << a << endl;
	cout << "1)������� ������ ��������� �������� "; cin >> b;
	b = b * b / 2;
	cout << "������� �������� = " << b;
}