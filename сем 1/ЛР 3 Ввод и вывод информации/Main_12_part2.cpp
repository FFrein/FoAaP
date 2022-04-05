#include <iostream>

int main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	int x, a, b, c;
	cout << "Введите трёхзначное целое число = ";
	cin >> x;
	if (x > 999) {
		cout << "Переиграл и уничтожил";
		return 0;
	}
	else if (x < 100) {
		cout << "Переиграл и уничтожил";
		return 0;
	}
	a = x / 100;
	b = (x%100) / 10;
	c = (x%10);
	cout << "Реверсное число " << c << b << a;
}