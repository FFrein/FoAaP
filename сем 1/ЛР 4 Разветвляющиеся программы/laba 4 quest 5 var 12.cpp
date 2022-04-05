#include <iostream>

void main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	double x;
	int y;
	cout << "Единицы измерения: " << endl << "1) Километрах" << endl << "2) Метрах" << endl << "3) Сантиметрах" << endl;
	cin >> y;
	cout << "Введите длинну = ";
	cin >> x;
	switch (y)
	{
	case 1: {
		x = x * 1000; 
		break;
	}
	case 3: {
		x = x / 100;
		break;
	}
	}
	cout << "Длинна в метрах = " << x;
}