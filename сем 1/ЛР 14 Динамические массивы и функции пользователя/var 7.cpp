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
	int size = 0, i, n;
	float* M, sum = 0, avar, mn;
	cout << "Введите размер массива ";
	cin >> size;
	M = new float[size];
	for (i = 0; i < size; i++)
	{
		cout << "Введите " << i + 1 << " элемент ";
		cin >>* (M + i);
		sum += *(M + i);
	}
	avar = sum / size;
	mn = abs(*M - avar);
	n = 0;
	for (i = 0; i < size; i++)
		if (*(M + i) > avar)
		{
			n = n + 1;
		}
	cout << "Количество элементов больших среднего арифметического=" << n;
	cout << endl;
	delete[] M;
}
void matrix()
{
	int** A, row, col, i, j, max;
	cout << "Введите число строк матрицы "; cin >> row;
	cout << "Введите чиcло столбцов "; cin >> col;
	A = new int* [row];
	for (int i = 0; i < row; i++)
		A[i] = new int[col];
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
		{
			cout << "Введите A[" << i << "],[" << j << "]= ";
			cin >>* (*(A + i) + j);
		}
	int C = 0;
	for (i = 0; i < row; i++) {
		int D = 0;
		for (j = 0; j < col; j++)
			if (*(*(A + i) + j) == 0)
			{
				D = D + 1;
			}
		if (D == 0)
			C = C + 1;
	}
	cout << "Количество строк не содержащих ни одного нулевого элемента " << C << endl;
	max = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			int c = 0;
			int e = *(*(A + i) + j);
			for (int k = 0; k < row; k++)
				for (int l = 0; l < col; l++)
					if (*(*(A + k) + l) == e)
						c = c + 1;
			if (c > 1)
				if (max < e) {
					max = e;
				}
		}
	}
	cout << "Максимальное из чисел, встречающееся болше одного раза: " << max << endl;
	for (int k = 0; k < row; k++)
		delete A[k];
	delete[] A;
}