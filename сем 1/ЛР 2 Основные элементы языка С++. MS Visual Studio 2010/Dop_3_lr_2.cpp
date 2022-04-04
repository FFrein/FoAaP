#include <iostream>
int main()
{
	double k = 4, x = 2 * 10e-4, a = 8.1, t, u;
	t = 2 * k / a + log(2 + x);
	u = sqrt(k - 1) / (t + 1);
	std::cout << "u=" << u << " ";
	std::cout << "t=" << t;
}