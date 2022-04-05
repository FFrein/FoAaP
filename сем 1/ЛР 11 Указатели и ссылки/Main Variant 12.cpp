#include <iostream>

int main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");

	const int sz = 10, rmx = 10;
	int massiv_A[sz], massiv_B[sz], col_raveno = 0, col_bolshe = 0, col_menshe = 0, one = 1;
	int *ukazatel;

	ukazatel = &one;

	srand((unsigned)time(NULL));

	for (int i = 0; i < sz; i++) {
		massiv_B[i] = rand() % rmx;
		massiv_A[i] = rand() % rmx;

		if (massiv_A[i] == massiv_B[i]) {
			col_raveno += *ukazatel;
		}

		if (massiv_A[i] > massiv_B[i]) {
			col_bolshe += *ukazatel;
		}

		if (massiv_A[i] < massiv_B[i]) {
			col_menshe += *ukazatel;
		}
	}
	cout << "Первый массив" << endl;
	for (int i = 0; i < sz; i++) {

		cout << massiv_A[i] << endl;
	}

	cout << "Второй массив" << endl;
	for (int i = 0; i < sz; i++) {

		cout << massiv_B[i] << endl;
	}
	cout << "Ответ" << endl;

	cout << "равных = " << col_raveno << endl;
	cout << "больших = " << col_bolshe << endl;
	cout << "меньших = " << col_menshe << endl;
}