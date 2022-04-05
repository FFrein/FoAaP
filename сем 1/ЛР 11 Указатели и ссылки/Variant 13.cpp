#include <iostream>

int main() {
	using namespace std;
	setlocale(LC_CTYPE, "Russian");

	const int n = 10, rmx = 10;
	int massiv_X[n], massive_Y[n], unikal = 0, schet = 0, proverka = 0, a = 1;
	int* ukazatel;
	ukazatel = &unikal;

	srand((unsigned)time(NULL));

	for (int i = 0; i < n; i++) {
		massiv_X[i] = rand() % rmx;
		massive_Y[i] = -1;
	}
	cout << "массив X" << endl;
	for (int i = 0; i < n; i++) {

		cout << massiv_X[i] << endl;
	}

	for (int i = 0; i < n; i++) {
		schet = massiv_X[i];
		for (int b = 0; b < n; b++) {
			if (schet == massive_Y[b]) {
				proverka = 1;
			}
		}

		if (proverka == 0) {
			massive_Y[i] = schet;
		}
		proverka = 0;

	}

	for (int i = 0; i < n; i++) {
		if (massive_Y[i] != -1) {
			*ukazatel += 1;
		}
	}
	cout << "Ответ" << endl;
	cout << unikal;
}