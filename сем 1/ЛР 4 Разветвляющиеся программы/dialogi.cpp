#include <iostream>

int main()
{
	using namespace std;
	setlocale(LC_CTYPE, "RUSSIAN");
	int a;
	cout << "������" << endl;
	cout << "1) ������" << endl;
	cout << "2) �������" << endl;
	cout << "3) �������" << endl;
	cout << "4) �" << endl;
	cout << "5) �����" << endl;
	cin >> a;

	switch (a)
	{
		case 1 :
		{
			cout << "������" << endl;
				cout << "������" << endl;
				cout << "2) �������" << endl;
				cout << "3) �������" << endl;
				cout << "4) �" << endl;
				cout << "5) �����" << endl;
				cin >> a;
		}
		case 2:
		{
			cout << "������" << endl;
			cout << "������" << endl;
			cout << "1) ������" << endl;
			cout << "3) �������" << endl;
			cout << "4) �" << endl;
			cout << "5) �����" << endl;
			cin >> a;
		}
		case 3:
		{
			cout << "������" << endl;
			cout << "������" << endl;
			cout << "1) ������" << endl;
			cout << "2) �������" << endl;
			cout << "4) �" << endl;
			cout << "5) �����" << endl;
			cin >> a;
		}
		case 4:
		{
			cout << "������" << endl;
			cout << "������" << endl;
			cout << "1) ������" << endl;
			cout << "2) �������" << endl;
			cout << "3) �������" << endl;
			cout << "5) �����" << endl;
			cin >> a;
		}
		case 5:
		{
			cout << "������" << endl;
			cout << "������" << endl;
			cout << "1) ������" << endl;
			cout << "2) �������" << endl;
			cout << "3) �������" << endl;
			cout << "4) �" << endl;
			cin >> a;
		}
	}
	return 0;
}