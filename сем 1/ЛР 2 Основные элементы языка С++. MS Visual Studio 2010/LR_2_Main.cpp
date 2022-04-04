#include <iostream>
int main()
{
	double k = 6, r = 5 * 10e-7, x = 0.095, t, u;
	t = tan(x) + r * (1 - log(x));
	u = t / (pow(x, 3) + 1) / (1 - exp(k - 4));
	std::cout << "u=" << u << " ";
	std::cout << "t=" << t;
}