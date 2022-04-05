#include <iostream>

int main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	float z, x, xtwo = 0, xsum = 0, y, i = 0;
	do {
		i = i + 1;
		cout << "Введите x" << i << "= ";
		cin >> x;
		xsum += x;
		if (x > xtwo) {
			xtwo = x;
			cout << "Максимальное число обновлено" << endl;
		}
		
	} while(i != 5);
	z = xtwo;
	y = z * xsum;
	cout << "y= " << y;
	return 0;
}
