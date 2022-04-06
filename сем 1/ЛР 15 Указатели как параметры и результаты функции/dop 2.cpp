#include <stdio.h>
#include <cstring>
#include <string>
#include <string.h>
#include <sstream>
#include <iostream>
#include <windows.h>
using namespace std;

//задан 1
float integ(float(*) (float), float, float, float);

float f(float);

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	setlocale(LC_CTYPE, "Russian");
	float z, a, b, h;
	SetConsoleTextAttribute(hConsole, 14);
	cout << "предел: a " << endl;
	cin >> a;
	cout << "предел: b " << endl;
	cin >> b;
	h = 0.0001;

	z = integ(f, (float)a, (float)b, (float)h);
	SetConsoleTextAttribute(hConsole, 13);
	std::cout << "Integral=" << z;
	SetConsoleTextAttribute(hConsole, 15);
}

float integ(float(*f) (float), float a, float b, float h)
{
	float x, s = 0.0;
	x = a + h;

	while (x <= b)
	{
		s += h * f(x);

		x = x + h;
	}

	return s / 2;
}

float f(float x)
{
	return (pow(x, 3) + x - 3);
}



