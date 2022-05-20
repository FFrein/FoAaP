#include <iostream>
#include <ctime>
#include "Header.h"
using namespace std;

// ======================================  Ä Î Ï  2  ======================================
//лаба 5
void dop2()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int size, i, j = 0;
	int A[100], B[100], C[100];
	cout << "Введите колличество элементов: ";
	cin >> size;

	cout << "\nмассив А: | ";
	for (i = 0; i < size; i++)
	{
		A[i] = 1 + rand() % 20;
		cout << A[i] << " | ";

		if (A[i] % 2 == 0)
		{
			C[j] = A[i];
			j++;
		}
	}

	cout << "\nмассив B: | ";
	for (i = 0; i < size; i++)
	{
		B[i] = 1 + rand() % 20;
		cout << B[i] << " | ";
		if (B[i] % 2 != 0)
		{
			C[j] = B[i];
			j++;
		}
	}

	cout << "\nмассив C: | ";
	for (i = 0; i < j; i++) cout << C[i] << " | ";

	bubbleSortUp(C, j);
	cout << "\n\nПузырёк: | ";
	for (i = 0; i < j; i++) cout << C[i] << " | ";

	selectSort(C, j);
	cout << "\nВыбор:   | ";
	for (i = 0; i < j; i++) cout << C[i] << " | ";
	cout << '\n';
}