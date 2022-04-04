#include <iostream>
int main()
{
	double n = 2, b = -0.12, x = 1.3 * 10e-4, z, y;
	z = 1 / (x - 1) + sin(x) - sqrt(n);
	y = (exp(b) + 1) / 2 * z;
	std::cout << "z=" << z << " ";
	std::cout << "y=" << y;
}