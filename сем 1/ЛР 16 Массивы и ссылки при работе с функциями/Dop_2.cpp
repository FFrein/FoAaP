// ���� 2.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.

//���� ������������� ������������� �������. ���������� ���������� �����, ���������� ���� �� ���� ������� �������.
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

int& ch(int colum, int row, int* A) {
	int m = 0, p = 0;
	for (int i = 0; i < colum; i++) {
		cout << "\n";
		for (int j = 0; j < row; j++) {
			*(A + i * colum + j) = -1 + rand() % 13;
			if (*(A + i * colum + j) == 0 && m == 0) {
				m++;
			}
			cout << "A[" << i << "," << j << "] =" << *(A + i * colum + j) << "\t";
		}

		if (m != 0)
			p++;
		m = 0;
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
	cout << "\n���������� �����: " << ch(colum, row, A);;
}

int sum(int n, ...)
{
	int k = 2, t = 0, v = 0;
	int* p = &n;
	int sum = 0;
	for (int i = n; i > 0; i--) {
		if (k % 2 == 0) {
			t = *(++p);
			v = *(++p);
			sum += t * v;
		}
		k++;
	}
	return sum;
}

void posl()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "������������������: 4, 5, 1, 2, 3, 7 \n";
	cout << "�����: " << sum(6, 4, 5, 1, 2, 3, 7) << endl;
	cout << "������������������: 1, 3, 4, 2, 10, 18, 2, 4 \n";
	cout << "�����: " << sum(8, 1, 3, 4, 2, 10, 18, 2, 4) << endl;
	cout << "������������������: 5, 1, 2, 3\n";
	cout << "�����: " << sum(4, 5, 1, 2, 3) << endl;
}
