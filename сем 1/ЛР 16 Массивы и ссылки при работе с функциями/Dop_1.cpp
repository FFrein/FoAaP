// задан 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

//Дана целочисленная прямоугольная матрица. Определить номер первого из столбцов, содержащих хотя бы один нулевой элемент.6 7
#include <iostream>

using namespace std;
void posl();
void matrix();
int main(void)
{
	setlocale(LC_CTYPE, "Russian");
	int c;
	do
	{
		cout << endl;
		cout << "Choose quest" << endl;
		cout << "1-quest 1" << endl;
		cout << "2-quest 2" << endl;
		cin >> c;

		switch (c)
		{
		case 1: matrix(); break;

		case 2: posl(); break;

		default: break;
		}

	} while (c < 3);

}

int& ch(int colum, int row, int* A) {
	int m = 0, p = 0;
	for (int i = 0; i < colum; i++) {
		cout << "\n";
		for (int j = 0; j < row; j++) {
			*(A + i * colum + j) = -1 + rand() % 13;
			if (*(A + i * colum + j) == 0 && m == 0) {
				p = j;
				m++;
			}
			cout << "A[" << i << "," << j << "] =" << *(A + i * colum + j) << "\t";
		}
	}
	return p;
}

void matrix()
{
	setlocale(LC_CTYPE, "Russian");
	int colum, row;
	cout << "Введите размер столбца: ";
	cin >> colum;
	cout << "Введите размер строки: ";
	cin >> row;
	int* A = new int[row * colum];
	cout << "\nИсходная матрица:\n";
	cout << "\nСтолбец под номером: " << ch(colum, row, A);;
}

int fmin(int n, ...)
{
	int* p = &n;
	int min = 100;
	for (int i = 1; i <= n; i++) {
		if (min > *p) {
			min = *p;
		}
		*p++;
	}
	return min;
}

void posl()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Последовательность:6, 4, 5, 1, 2, 3, 7 \n";
	cout << "Минимальное число: " << fmin(6, 4, 5, 1, 2, 3, 7) << endl;
	cout << "Последовательность:2, 34, 4445\n";
	cout << "Минимальное число: " << fmin(2, 34, 4445) << endl;
	cout << "Последовательность:7, 6, 25, -5, 6\n";
	cout << "Минимальное число: " << fmin(7, 6, 25, -5, 6);
}