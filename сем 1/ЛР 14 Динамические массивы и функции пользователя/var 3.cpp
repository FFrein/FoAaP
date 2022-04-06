#include <iostream>
#include <windows.h> /*библиотека для изменения цвета консоли*/

int function_1() {
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int* A;
	int n, proizv = 1, sum = 0;

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
		A[i] = 5 - rand() % 10;
		cout << "A[" << i << "]" << " = " << A[i] << endl;

		/*Поиск отрицательных числел и вычисление их произведения*/
			if (A[i] < 0) {
				proizv = proizv * A[i];
			}

		/*Поиск воложительных числел и вычисление их суммы*/
			if (A[i] > 0) {
				sum += A[i];
			}
	}
	cout << "proizv = " << proizv << endl;
	cout << "Sum = " << sum << endl;
	return 0;
}

int function_2() {
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int i = 4, j = 4, rownumb = -1, min1 = 11, min2 = 11, max1 = -11, max2 = -11;
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
			A[numb][numb2] = 1 - rand() % 10;
			cout << A[numb][numb2] << " ";
		}
		cout << endl;
	}

	/*Поиск чисел*/
	for (int numb = 0; numb < i; numb++) {
		for (int numb2 = 0; numb2 < j; numb2++) {
			if (numb == 1 && min1 > A[numb][numb2]) {
				min1 = A[numb][numb2];
			}
			if (numb == 2 && max1 < A[numb][numb2]) {
				max1 = A[numb][numb2];
			}

			if (numb == 3 && min2 > A[numb][numb2]) {
				min2 = A[numb][numb2];
			}
			if (numb == 4 && max2 < A[numb][numb2]) {
				max2 = A[numb][numb2];
			}
		}
	}
	/*Вывод*/
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Sum min = " << min1 + min2 << endl;
	cout << "Sum max = " << max1 + max2 << endl;
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
	