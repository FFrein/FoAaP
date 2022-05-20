// LABA17_dop1.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//��� ������ ����� �����, ���������� ��������� �������� ���� ������ � ����������. ����� ������������ ������� 
//������� � ��� �����, ��� �������, ��� ��� �������� ��������. ����� ����������� ������� �������.

#include<iostream>
using namespace std;

void bubbleSort(int a[], int n)
{
	int i, j, t;
	for (i = 1; i < n; i++)
		for (j = n - 1; j >= i; j--)
			if (a[j - 1] > a[j])
			{
				t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}
}



int main()
{
	setlocale(LC_ALL, "RUS");
	int n, min = 0, max = 0, minI = 0, maxI = 0;
	cout << "������� �����������: "; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = rand() % (20 + 20 + 1) - 20;
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
	bubbleSort(arr, n);
	for (int i = 0; i < 10; i++)
		cout << arr[i] << ' ';
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			minI = i;
		}
		if (arr[i] > max)
		{
			max = arr[i];
			maxI = i;
		}
	}
	cout << "������������ �������: " << max << " � ��� ������: " << maxI << endl;
	cout << "����������� �������: " << min << " � ��� ������: " << minI << endl;
}
