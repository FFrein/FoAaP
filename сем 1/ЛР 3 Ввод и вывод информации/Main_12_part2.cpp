#include <iostream>

int main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	int x, a, b, c;
	cout << "������� ���������� ����� ����� = ";
	cin >> x;
	if (x > 999) {
		cout << "��������� � ���������";
		return 0;
	}
	else if (x < 100) {
		cout << "��������� � ���������";
		return 0;
	}
	a = x / 100;
	b = (x%100) / 10;
	c = (x%10);
	cout << "��������� ����� " << c << b << a;
}