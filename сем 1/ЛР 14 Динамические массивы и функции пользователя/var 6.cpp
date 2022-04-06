#include <iostream>
#include <windows.h> /*библиотека для изменения цвета консоли*/

int function_1() {
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int* A;
	int n, rmx = 10, min = rmx + 1, numbEl = 0, sumabs = 0, chek = 0;

	SetConsoleTextAttribute(hConsole, 20);
	cout << "Quest 1" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	/*Задание массиву размера и придание значений*/
	SetConsoleTextAttribute(hConsole, 14);
	cout << "Enter size = ";
	cin >> n;
	SetConsoleTextAttribute(hConsole, 15);
	A = new int[n];
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) {
		A[i] = 5 - rand() % rmx;
		cout << "A[" << i << "]" << " = " << A[i] << endl;

		/*Поиск номера минимального элемента по модулю*/
		if (abs(A[i]) < min) {
			min = abs(A[i]);
			numbEl = i;
		}

		/*Сумма модулей после первого отриц*/
		if (chek == 1) {
			sumabs += abs(A[i]);
		}
		/*Проверка на первое отриц*/
		if (A[i] < 0) {
			chek = 1;
		}
	}
	cout << "numb of el = " << numbEl << endl;
	cout << "Sum abs = " << sumabs << endl;
	return 0;
}

int function_2() {
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int rmx = 10, i = 4, j = i, rownumb = -1, proizv = 1, chek = 0, sum = 0, summax = 0;
	int** A; /* одна * когда массив простой, две * когда матрица, три * когад параллелепипед*/

	SetConsoleTextAttribute(hConsole, 20);
	cout << "Quest 2" << endl;
	SetConsoleTextAttribute(hConsole, 15);

	/*Указание размерности массива*/
	SetConsoleTextAttribute(hConsole, 14);
	cout << "Rows = " << i << endl;
	cout << "Colums = " << j << endl;;
	SetConsoleTextAttribute(hConsole, 15);

	/*Присвоение значений массиву*/
	srand((unsigned)time(NULL));
	A = new int* [i];
	for (int numb = 0; numb < i; numb++) {
		A[numb] = new int[j];
		for (int numb2 = 0; numb2 < j; numb2++) {
			A[numb][numb2] = rmx / 2 - rand() % rmx;
			cout << A[numb][numb2] << " ";
		}
		cout << endl;
	}

	/*Поиск чисел*/
	for (int numb = 0; numb < i; numb++) {
		for (int numb2 = 0; numb2 < j; numb2++) {
			if (A[numb][numb2] < 0) {
				chek = 1;
			}
		}
		if (chek == 0) {
			for (int numb2 = 0; numb2 < j; numb2++) {
				proizv *= A[numb][numb2];
			}
			cout << "row = " << numb << endl;
			cout << "proizv = " << proizv << endl;
			chek = 0;
		}
	}

	/*diagonali*/

	for (int numb = 0; numb < i; numb++) {
		for (int numb2 = j; numb2 > 0; numb2--) {
			


			sum += A[numb][numb2];

				if (sum > summax) {
					summax = sum;
			}
		}
	}

	/*Вывод*/
	SetConsoleTextAttribute(hConsole, 10);
	cout << "summax diagonali = " << summax << endl;
	SetConsoleTextAttribute(hConsole, 15);
	return 0;
}

int main() {
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	/*конструкция switch case*/
	int casenumb;
	cout << "Выберите задание(1 или 2)" << endl;
	cin >> casenumb;
	switch (casenumb) {
	case 1:
		function_1();
	case 2:
		function_2();
	}
}
