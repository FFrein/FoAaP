#include <iostream>

void main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	double x;
	int y;
	cout << "������� ���������: " << endl << "1) ����������" << endl << "2) ������" << endl << "3) �����������" << endl;
	cin >> y;
	cout << "������� ������ = ";
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
	cout << "������ � ������ = " << x;
}