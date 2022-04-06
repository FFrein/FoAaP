#include <iostream>
#include <windows.h>

int function1(int i, int j) {
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int rownumb = -1;
	int* ukaz = &i;
	/*Присвоение значений массиву*/
	int** A; /* одна * когда массив простой, две * когда матрица, три * когад параллелепипед*/
	srand((unsigned)time(NULL));
	A = new int* [i];
	for (int numb = 0; numb < *ukaz; numb++) {
		A[numb] = new int[j];
		for (int numb2 = 0; numb2 < j; numb2++) {
			A[numb][numb2] = 8 - rand() % 10;
			cout << A[numb][numb2] << " ";
		}
		cout << endl;
	}

	/*поиск строки с отрицательной переменной*/
	for (int numb = 0; numb < i; numb++) {
		for (int numb2 = 0; numb2 < j; numb2++) {
			if (A[numb][numb2] < 0) {
				rownumb = numb;
			}
		}
	}

	cout << " " << endl;

	/*Все элементы столбца с таким же номером уменьшить вдвое */
	if (rownumb >= 0) {
		cout << "Rownumb = " << rownumb << endl;
		for (int numb = 0; numb < i; numb++) {
			if (A[numb][rownumb] != 0) {
				A[numb][rownumb] = A[numb][rownumb] / 2;
			}
		}
	}

	cout << " " << endl;

	/*Вывод*/
	SetConsoleTextAttribute(hConsole, 13);
	for (int numb = 0; numb < i; numb++) {
		for (int numb2 = 0; numb2 < j; numb2++) {
			cout << A[numb][numb2] << " ";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, 15);
	return 0;
}

int function2(int n, int *massiveB) {
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int numb = 0, n_alternativ;

	cout << endl;

	/*Поиск отрицательных, замена их на 0 и перенос в конец*/
	n_alternativ = n - 1;
	for (int i = 0; i < n; i++) {
		if (massiveB[i] < 0) {
			numb = massiveB[n_alternativ];
			massiveB[i] = numb;
			massiveB[n_alternativ] = 0;
			n_alternativ -= 1;
		}
	}

	/*Вывод*/
	SetConsoleTextAttribute(hConsole, 13);
	for (int i = 0; i < n; i++) {
			cout << massiveB[i] << " ";
	}
	SetConsoleTextAttribute(hConsole, 15);
	
	cout << endl;
	return 0;
}

int main() {
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int c, i, j, n;
	cout << "Choose quest = ";
	cin >> c;
	switch (c) {
	case 1:
		SetConsoleTextAttribute(hConsole, 20);
		cout << "Quest 1" << endl;
		SetConsoleTextAttribute(hConsole, 15);

		/*Указание размерности массива*/
		SetConsoleTextAttribute(hConsole, 14);
		cout << "Rows = ";
		cin >> i;
		cout << "Colums = ";
		cin >> j;
		SetConsoleTextAttribute(hConsole, 15);

		function1(i, j);

	case 2:
		for (int numb = 0; numb < 3; numb ++){
		SetConsoleTextAttribute(hConsole, 20);
		cout << "Quest 2" << endl;
		SetConsoleTextAttribute(hConsole, 15);

		cout << "Massive size = ";
		cin >> n;

		/*Создание массива и присваивание ему значений*/

		int* massiveB;
		srand((unsigned)time(NULL));
		massiveB = new int[n];
		for (int i = 0; i < n; i++) {
			massiveB[i] = 8 - rand() % 10;
			cout << massiveB[i] << " ";
		}

		function2(n, massiveB);
		}
	}
	return 0;
}