#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	char a, space; space = ' ';
	cout << "Введите символ "; cin >> a;
	cout << setw(35) << setfill(space) << space;
	cout << setw(10) << setfill(a) << a << endl;
	cout << setw(35) << setfill(space) << space;
	cout << setw(10) << setfill(a) << a << endl;
	cout << setw(35) << setfill(space) << space;
	cout << setw(10) << setfill(a) << a << endl;
	cout << setw(25) << setfill(space) << space;
	cout << setw(30) << setfill(a) << a << endl;
	cout << setw(25) << setfill(space) << space;
	cout << setw(30) << setfill(a) << a << endl;
	cout << setw(25) << setfill(space) << space;
	cout << setw(30) << setfill(a) << a << endl;
	cout << setw(35) << setfill(space) << space;
	cout << setw(10) << setfill(a) << a << endl;
	cout << setw(35) << setfill(space) << space;
	cout << setw(10) << setfill(a) << a << endl;
	cout << setw(35) << setfill(space) << space;
	cout << setw(10) << setfill(a) << a << endl;
}