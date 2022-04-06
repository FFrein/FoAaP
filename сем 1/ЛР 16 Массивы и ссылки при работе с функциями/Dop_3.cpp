// вар 6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

//
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
		case 3: break;
		}
	} while (c != 3);
}

void ch(int colum, int row, int* A) {
	int m = 0, p = 0;
	for (int i = 0; i < colum; i++) {
		cout << "\n";
		for (int j = 0; j < row; j++) {
			*(A + i * colum + j) = -5 + rand() % 13;
			if (*(A + i * colum + j) == 0 && m == 0) {
				m++;
			}
			cout << "A[" << i << "," << j << "] =" << *(A + i * colum + j) << "\t";
		}
		if (m != 0)
			p++;
		m = 0;
	}

	if (p == row) {
		cout << "Все строки содержат нулевой элемент";
	}

	else {
		cout << "\nНовая матрица:\n";
		int pol = 0;
		for (int i = 0; i < colum; i++) {
			cout << "\n";
			for (int j = 0; j < row; j++) {
				if (*(A + i * colum + j) < 0) {
					pol = *(A + i * colum + j);
					*(A + i * colum + j) = 0;
				}
				cout << "A[" << i << "," << j << "] =" << *(A + i * colum + j) << "\t";
			}
		}
	}
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
	ch(colum, row, A);
}

int as(int n, ...)
{
	int k = 2, t = 0, v = 0;
	int* p = &n;
	int sum = 0;
	for (int i = n / 2; i > 0; i--) {
		t = *(++p);
		v = *(++p);
		if (k % 2 == 0) {
			sum += t * v;
		}
		else {
			sum -= t * v;
		}
		k++;
	}
	return sum;
}

void posl()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Последовательность: 4, 5, 1, 2, 3, 7 \n";
	cout << "Результат: " << as(6, 4, 5, 1, 2, 3, 7) << endl;
	cout << "Последовательность: 1, 3, 4, 2, 10, 18, 2, 4 \n";
	cout << "Результат: " << as(8, 1, 3, 4, 2, 10, 18, 2, 4) << endl;
	cout << "Последовательность: 5, 1, 2, 3\n";
	cout << "Результат: " << as(4, 5, 1, 2, 3) << endl;
}
