#include <iostream>

void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	float y, z, b = 0.5, m = 8, a = 2.4, j = 1.8;
	while (j < 3) {
		y = (m - b) / (sin(a) - exp(a));
		if (a - (4 * j * b) <= 0) 
		{
			printf("Отрицаиельный корень\t\n");
				j = j + 0.5;
		}
		else {
			z = 3 * y + sqrt(a - (4 * j * b));
				cout << "j=" << j << "\t";
				cout << " z=" << z << endl;
				j = j + 0.5;
		}
	}
}
