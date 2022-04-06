#include <iostream>

using namespace std;

int f2() {
	int m[32][32];
	int n;
	cout << "Введите n - ";
	cin >> n;
	cout << endl << "Матрица - " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//задание значений
			m[i][j] = 1 + (j + 1 + i + 1) % n;
			//Вывод
			cout << " " << *(*(m + i) + j);
			if (j == n - 1)
				printf("\n");
		}
	}
	return 1;
}

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	cout << "Доп 2";
	cout << endl;
	f2();
}