���1
#include <iostream>
using namespace std;
void first();
void sec();
void posl();

int main(void)
{
	setlocale(LC_CTYPE, "Russian");
	int c;
	do

	{

		cout << endl;

		cout << "�������" << endl;

		cout << "1-������ �������, ����� 1" << endl;

		cout << "2-������ �������, ����� 2" << endl;

		cout << "3-������ �������" << endl;

		cout << "4-�����" << endl;

		cin >> c;

		switch (c)

		{

		case 1: first(); break;

		case 2: sec(); break;

		case 3: posl(); break;

		case 4: break;

		}

	} while (c != 4);

}

float f(int a, int b)

{

	float x;

	return x = (a + b) / 2;

}

void metodiox(float(*f) (int, int), float a, float b, float h) {

	do {

		if (((pow(f(a, b), 2) + 4 * f(a, b) - 2) * (pow(a, 2) + 4 * a - 2)) <= 0)

			b = f(a, b);

		else a = f(a, b);

	} while (abs(a - b) > 2 * 2.7182);

	cout << f(a, b);

}

void metodio(float(*f) (int, int), float a, float b, float h) {

	do {

		if (((sin(f(a, b)) + 0.1) * (sin(a) + 0.1)) <= 0)

			b = f(a, b);

		else a = f(a, b);

	} while (abs(a - b) > 2 * 2.7182);

	cout << f(a, b);

}

void first() {

	setlocale(LC_CTYPE, "Russian");

	float z, a, b, h, x;

	cout << "������: a " << endl;

	cin >> a;

	cout << "������: b " << endl;

	cin >> b;

	cout << "��������:" << endl;

	cin >> h;

	printf("\n\t����� ���������: ");

	metodiox(f, a, b, h);

}

void sec() {

	setlocale(LC_CTYPE, "Russian");

	float z, a, b, h, x;

	cout << "������: a " << endl;

	cin >> a;

	cout << "������: b " << endl;

	cin >> b;

	cout << "��������:" << endl;

	cin >> h;

	printf("\n\t����� ���������: ");

	metodio(f, a, b, h);

}

int fmin(int n, ...)

{

	int* p = &n;

	int min = 100;

	for (int i = 1; i <= n; i++) {

		if (min > *p) {

			min = *p;

		}

		*p++;

	}

	return min;

}

void posl()

{

	setlocale(LC_CTYPE, "Russian");

	cout << "������������������:6, 4, 5, 1, 2, 3, 7 \n";

	cout << "����������� �����: " << fmin(6, 4, 5, 1, 2, 3, 7) << endl;

	cout << "������������������:2, 34, 4445\n";

	cout << "����������� �����: " << fmin(2, 34, 4445) << endl;

	cout << "������������������:7, 6, 25, -5, 6\n";

	cout << "����������� �����: " << fmin(7, 6, 25, -5, 6);

}