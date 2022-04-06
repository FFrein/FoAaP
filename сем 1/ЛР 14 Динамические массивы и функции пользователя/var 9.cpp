#include <ctime>
#include <iostream>
using namespace std;
void massiv();
void matrix();
int main(void)
{
	setlocale(LC_CTYPE, "Russian");
	int c;
	do
	{
		cout << endl;
		cout << "Введите" << endl;
		cout << "1-одномерный массив" << endl;
		cout << "2-работа с матрицей" << endl;
		cout << "3-выход" << endl;
		cin >> c;
		switch (c)
		{
		case 1: massiv(); break;
		case 2: matrix(); break;
		case 3: break;
		}
	} while (c != 3);
}
void massiv()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int size, i = 0;
	float* A, p = 1, sum = 0, min = 100, count = 0;
	cout << "Введите размер массива: ";
	cin >> size;
	A = new float[size];
	for (i = 0; i < size; i++)
	{
		A[i] = 0.01 * (rand() % 10000) - 65;
		cout << A[i] << endl;
		if (A[i] > 0)
		{
			p *= A[i];
		}
		if (A[i] < min)
		{
			min = A[i];
			count = i;
		}
	}
	for (i = 0; i < count; i++)
	{
		sum += A[i];
	}
	cout << "Произведение положительных элементов: " << p << "\n";
	cout << "Сумма элементов до минимального элемента: " << sum << "\n";
}

void matrix()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int i = 0, j = 0, ** A, sz = 4, count = 0, stroka = 0, sum = 0;
	A = new int* [sz];
	for (i = 0; i < 4; i++)
	{
		A[i] = new int[sz];
		for (j = 0; j < 4; j++)
		{
			A[i][j] = rand() % 99 - 25;
			cout << A[i][j] << "\t";
		}
		cout << "\n";
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (A[i][j] > 0)
			{
				count++;
				sum += A[i][j];
			}
		}
		if (count == 4)
		{
			stroka = ++i;
			break;
		}
		else
		{
			count = 0;
			sum = 0;
		}
	}
	cout << "Первая положительная строка: " << stroka << endl;
	cout << "Сумма элементов этой строки: " << sum << endl;
	cout << "Новая матрица, уменьшенная на эту сумму:\n";
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			cout << A[i][j] - sum << "\t";
		}
		cout << "\n";
	}
}