#include <iostream>

double function_x(double x) {
	x = exp(x) + 2;
	return x;
}

int main()
{
	using namespace std;
	double a, b, n=200, h, x, s1=0, s2=0, i=1, z;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	h = (b - a) / (2 * n);
	x = a + 2 * h;
	do {
		s2 += function_x(x);
		x += h;
		s1 += function_x(x);
		x += h;
		i += i;
	} while (i < n);
	z = h / 3 * (function_x(a) + 4 * function_x(a + h) + 4 * s1 + 2 * s2 + function_x(b));
	cout << z;
	return 0;
}

