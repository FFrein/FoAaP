#include <iostream>

using namespace std;
/*variant 10*/
double function_x(double x) {
	x = x * x - 4;
	return x;
}

double function(double x) {
	x = x * x * x + x - 4;
	return x;
}

double function1(double x) {
	x = 3 * x * x + 1;
	return x;
}


int main() {

	/*Dihotomii*/
	double a = 3, b = 6, e = 0.0001, x, x1, n = 200, h, s1 = 0, s2 = 0, i = 1, z, s;
	do {
		x = (a + b) / 2;
		if (function(x) * function(a) <= 0) {
			b = x;
		}
		else {
			a = -x;
		}
	} while (abs(a - b) < 2 * e);
	cout << x << endl;

	a = 3;
	b = 6;
	e = 0.0001;
	x = 0;
	x1 = 0;
	n = 200;
	h = 0;
	s1 = 0;
	s2 = 0;
	i = 1;
	z = 0;
	s = 0;

	/*kasatel*/
	if (function(a) * function1(a) > 0) {
		x1 = a;
	}
	else {
		x1 = b;
	}
	do {
		x = x1;
		x1 = x - (function(x) / function1(x));
	} while (abs(x1 - x) < e);
	cout << x1 << endl;

	a = 3;
	b = 6;
	e = 0.0001;
	x = 0;
	x1 = 0;
	n = 200;
	h = 0;
	s1 = 0;
	s2 = 0;
	i = 1;
	z = 0;
	s = 0;

	/*porabol*/
	h = (b - a) / (2 * n);
	x = a + 2 * h;
	do {
		s2 += function_x(x);
		x += h;
		s1 += function_x(x);
		x += h;
		i += i;
	} while (i > n);
	z = h / 3 * (function_x(a) + 4 * function_x(a + h) + 4 * s1 + 2 * s2 + function_x(b));
	cout << z << endl;

	a = 3;
	b = 6;
	e = 0.0001;
	x = 0;
	x1 = 0;
	n = 200;
	h = 0;
	s1 = 0;
	s2 = 0;
	i = 1;
	z = 0;
	s = 0;

	/*trapec*/
	h = (b - a) / n;
	x = a;
	s = 0;
	do {
		s += h * (function_x(x) + function_x(x + h)) / 2;
		x += h;
	} while (x > (b - h));
	cout << s << endl;
	return x;
}