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
		cout << "�������" << endl;
		cout << "1-���������� ������" << endl;
		cout << "2-������ � ��������" << endl;
		cout << "3-�����" << endl;
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
	cout << "������� ������ ������� ";
	cin >> size;
	M = new float[size];
	for (i = 0; i < size; i++)
	{
		cout << "������� " << i + 1 << " ������� ";
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
	cout << "���������� ��������� ������� �������� ���������������=" << n;
	cout << endl;
	delete[] M;
}
void matrix()
{
	int** A, row, col, i, j, max;
	cout << "������� ����� ����� ������� "; cin >> row;
	cout << "������� ��c�� �������� "; cin >> col;
	A = new int* [row];
	for (int i = 0; i < row; i++)
		A[i] = new int[col];
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
		{
			cout << "������� A[" << i << "],[" << j << "]= ";
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
	cout << "���������� ����� �� ���������� �� ������ �������� �������� " << C << endl;
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
	cout << "������������ �� �����, ������������� ����� ������ ����: " << max << endl;
	for (int k = 0; k < row; k++)
		delete A[k];
	delete[] A;
}