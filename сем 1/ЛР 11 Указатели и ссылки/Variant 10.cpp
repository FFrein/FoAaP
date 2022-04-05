#include <iostream>

int main() {
	using namespace std;
	setlocale(LC_CTYPE, "Russian");

	const int sz = 10, rmx = 20;
	int massiv_A[sz], massiv_B[sz], min = (rmx + 1), proverka, *ukazatel;

	ukazatel = &min;

	srand((unsigned)time(NULL));

	for (int i = 0; i < sz; i++) {
		massiv_A[i] = rand() % rmx;
		massiv_B[i] = rand() % rmx;
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
	for (int i = 0; i < sz; i++) {

		proverka = massiv_A[i];

		for (int b = 0; b < sz; b++) {

			if (proverka == massiv_B[b]) {
				proverka = sz + 1;
			}
		}

		if (proverka != (sz + 1) && massiv_A[i] < min) {
			*ukazatel = massiv_A[i];
		}

		proverka = 0;

		}

	cout << min;
}