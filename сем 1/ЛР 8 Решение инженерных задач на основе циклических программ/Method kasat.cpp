#include <iostream>
double function(double x) {
	x = exp(x) + 2 * x * x - 3;
	return x;
}

double function1(double x) {
	x = exp(x) + 4 * x;
	return x;
}

int main()
{
	using namespace std;
	double a = 3, b = 6, e = 0.0001, x1, x;
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
	cout << x1;
}