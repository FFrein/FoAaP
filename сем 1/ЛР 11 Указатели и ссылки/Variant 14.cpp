#include <iostream>

int main() {
	using namespace std;
	setlocale(LC_CTYPE, "Russian");

	const int sz = 50, rmx = 20;
	int massiv_A[sz], massiv_B[sz], proverka, *ukazatel, col_par = 0;

	ukazatel = &col_par;

	srand((unsigned)time(NULL));

	for (int i = 0; i < sz; i++) {
		massiv_A[i] = rand() % rmx;
		massiv_B[i] = rand() % rmx;

		if (massiv_A[i] == massiv_B[i]) {
			col_par += 1;
		}
	}

	cout << "массив A  и B" << endl;
	for (int i = 0; i < sz; i++) {

		cout << massiv_A[i] << " " << massiv_B[i] << endl;
	}
	cout << "ќтвет" << endl;

	cout << *ukazatel;
}