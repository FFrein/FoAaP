#include <iostream>
int main()
{
	double i = -6, x = 4.5, z = 1.5 * 10e-6, d, f;
	d = tan(-x * i) / sqrt(x - z);
	f = sin(2 * d) / d;
	std::cout << "d=" << d << " ";
	std::cout << "f=" << f;
}