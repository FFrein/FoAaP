#include <iostream>

int main()
{
	using namespace std;
	setlocale(LC_CTYPE, "RUSSIAN");
	int a;
	cout << "Привет" << endl;
	cout << "1) Привет" << endl;
	cout << "2) Дратути" << endl;
	cout << "3) Здрасте" << endl;
	cout << "4) Ё" << endl;
	cout << "5) Салам" << endl;
	cin >> a;

	switch (a)
	{
		case 1 :
		{
			cout << "Привет" << endl;
				cout << "Привет" << endl;
				cout << "2) Дратути" << endl;
				cout << "3) Здрасте" << endl;
				cout << "4) Ё" << endl;
				cout << "5) Салам" << endl;
				cin >> a;
		}
		case 2:
		{
			cout << "Привет" << endl;
			cout << "Привет" << endl;
			cout << "1) Привет" << endl;
			cout << "3) Здрасте" << endl;
			cout << "4) Ё" << endl;
			cout << "5) Салам" << endl;
			cin >> a;
		}
		case 3:
		{
			cout << "Привет" << endl;
			cout << "Привет" << endl;
			cout << "1) Привет" << endl;
			cout << "2) Дратути" << endl;
			cout << "4) Ё" << endl;
			cout << "5) Салам" << endl;
			cin >> a;
		}
		case 4:
		{
			cout << "Привет" << endl;
			cout << "Привет" << endl;
			cout << "1) Привет" << endl;
			cout << "2) Дратути" << endl;
			cout << "3) Здрасте" << endl;
			cout << "5) Салам" << endl;
			cin >> a;
		}
		case 5:
		{
			cout << "Привет" << endl;
			cout << "Привет" << endl;
			cout << "1) Привет" << endl;
			cout << "2) Дратути" << endl;
			cout << "3) Здрасте" << endl;
			cout << "4) Ё" << endl;
			cin >> a;
		}
	}
	return 0;
}