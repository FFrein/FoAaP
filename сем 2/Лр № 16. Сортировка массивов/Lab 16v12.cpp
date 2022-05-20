#include <iostream>
const int MAX = 30;
void selectSort(int A[], int size)
{
	int k, i, j;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1, k = i; j < size; j++)
			if (A[j] < A[k])
				k = j;
		int c = A[k];
		A[k] = A[i];
		A[i] = c;
	}
}

void BubbleSort1(int A[], int size) //Сортировка пузырьком (12 вариант)
{
	int i, j, count, key;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			key = j + 1;
			count = A[key];
			if (A[j] < A[key])
			{
				A[key] = A[j];
				A[j] = count;
			}
		}
	}
}
void bubbleSort(int B[], int size)
{
	int i, j, t;
	for (i = 1; i < size; i++)
		for (j = size - 1; j >= i; j--)
			if (B[j - 1] > B[j])
			{
				t = B[j - 1];
				B[j - 1] = B[j];
				B[j] = t;
			}
}


void insertSort(int* A, int size)
{
	int t, i, j;
	for (i = 1; i < size; i++)
	{
		t = A[i];
		for (j = i - 1; j >= 0 && A[j] > t; j--)
			A[j + 1] = A[j];
		A[j + 1] = t;
	}
}

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Russian");
	int n = 9, k = 0, s = 0;
	int* A = new int[n];
	cout << "Введите размер массива A ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите элемент: ";
		cin >> A[i];
		if (!(i % 2))
			k++;
	}
	cout << "Массив A -> ";
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	int* B = new int[k];
	for (int i = 0; i < n; i ++)
	{
		if (i % 2 == 0)
		{


			B[s] = A[i];
			s++;
		}
	}
	cout << "Массив B -> ";
	for (int i = 0; i < s; i++)
	{
		cout << B[i] << " ";
	}
	cout << endl;
	int c=1;
	
	
	while (c)
	{

		cout <<endl<< "1-выбором" << endl;
		cout << "2-пузырьком" << endl;
		cin >> c;
		switch (c)
		{

		case 1:
			selectSort(B, s);
			for (int i = 0; i < s; i++)
			{
				cout << B[i] << " ";
			}
			break;
		case 2:
			bubbleSort(B, s);
			for (int i = 0; i < s; i++)
			{
				cout << B[i] << " ";
			}
			break;
		default:
			break;
		}
	}
	

}