#include <iostream>
#include <windows.h>
using namespace std;
void first();
void sec();
void posl();

int main(void)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	setlocale(LC_CTYPE, "Russian");
	int c;
	do
		{
		SetConsoleTextAttribute(hConsole, 14);
		cout << endl;
		cout << endl;
		cout << "Choose" << endl;
		cout << "1-quest 1 1" << endl;
		cout << "2-quest 1 2" << endl;
		cout << "3-quest 2" << endl;
		cout << "4-выход" << endl;

		cin >> c;
		SetConsoleTextAttribute(hConsole, 13);
		switch (c)

		{
		case 1: first(); break;
		case 2: sec(); break;
		case 3: posl(); break;
		case 4: break;
		}
		SetConsoleTextAttribute(hConsole, 15);
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

	cout << "предел: a " << endl;

	cin >> a;

	cout << "предел: b " << endl;

	cin >> b;
	h = 0.0001;

	printf("\n\tМетод дихотомии: ");

	metodiox(f, a, b, h);

}

void sec() {

	setlocale(LC_CTYPE, "Russian");

	float z, a, b, h, x;

	cout << "предел: a " << endl;

	cin >> a;

	cout << "предел: b " << endl;

	cin >> b;
	h = 0.0001;

	printf("\n\tМетод дихотомии: ");

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

	cout << "Последовательность:6, 4, 5, 1, 2, 3, 7 \n";

	cout << "Минимальное число: " << fmin(6, 4, 5, 1, 2, 3, 7) << endl;

	cout << "Последовательность:2, 34, 4445\n";

	cout << "Минимальное число: " << fmin(2, 34, 4445) << endl;

	cout << "Последовательность:7, 6, 25, -5, 6\n";

	cout << "Минимальное число: " << fmin(7, 6, 25, -5, 6);

}