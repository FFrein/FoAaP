// ����� 1.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.

//���� ������������� ������������� �������. ���������� ����� ������� �� ��������, ���������� ���� �� ���� ������� �������.6 7
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
	cout << "������� ������ �������: ";
	cin >> colum;
	cout << "������� ������ ������: ";
	cin >> row;
	int* A = new int[row * colum];
	cout << "\n�������� �������:\n";
	cout << "\n������� ��� �������: " << ch(colum, row, A);;
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
	cout << "������������������:6, 4, 5, 1, 2, 3, 7 \n";
	cout << "����������� �����: " << fmin(6, 4, 5, 1, 2, 3, 7) << endl;
	cout << "������������������:2, 34, 4445\n";
	cout << "����������� �����: " << fmin(2, 34, 4445) << endl;
	cout << "������������������:7, 6, 25, -5, 6\n";
	cout << "����������� �����: " << fmin(7, 6, 25, -5, 6);
}