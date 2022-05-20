#include <iostream>
#include <ctime>
#include "Header.h"
using namespace std;

// ======================================  Ä Î Ï  1  ======================================
//лаба 4
void dop1()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int size, i, min = 21, j, sizeC = 0;
	int A[100], B[100], C[100];
	cout << "Введите колличество элементов: ";
	cin >> size;

	cout << "\nмассив А: | ";
	for (i = 0; i < size; i++)
	{
		A[i] = 1 + rand() % 20;
		cout << A[i] << " | ";
	}

	cout << "\nмассив B: | ";
	for (i = 0; i < size; i++)
	{
		B[i] = 1 + rand() % 20;
		cout << B[i] << " | ";
		if (B[i] < min) min = B[i];
	}

	cout << "\nМинимальное значение: " << min;

	cout << "\nмассив С: | ";
	for (i = 0; i < size; i++)
	{
		if (A[i] > min)
		{
			C[i] = A[i];
			sizeC++;
			cout << C[i] << " | ";
		}
	}

	cout << "\n\nШейкер: | ";
	shakerSort(C, sizeC);
	for (i = 0; i < sizeC; i++)
	{
		if (C[i] > 0) cout << C[i] << " | ";
	}

	cout << "\nШелл:    | ";
	Shell(C, sizeC);
	for (i = 0; i < sizeC; i++)
	{
		if (C[i] > 0) cout << C[i] << " | ";
	}
	cout << '\n';
}