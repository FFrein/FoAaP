#include <iostream>

using namespace std;

int f1() {
	int m[32][32];
	int n;
	int tmp[16][16];
	cout << "������� n - ";
	cin >> n;
	srand(time(NULL));
	cout << endl << "������� - " << endl;
	for (int i = 0; i < (2 * n); i++) {
		for (int j = 0; j < (2 * n); j++) {
			//������� ��������
			m[i][j] = rand() % 21 - 10;
			//���������� ��������� ����� � ������
			((i >= n) && (j >= n)) ? tmp[i - n][j - n] = m[i][j] : j = j;
			//�����
			cout << " " << *(*(m + i) + j);
			if (j == n - 1) printf(" | ");
			if (i == n - 1) printf("_");
			if (j == 2 * n - 1)
				printf("\n");
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//1->4
			m[2 * n - n + (i)][2 * n - n + (j)] = m[i][j];
			//4->1
			m[i][j] = tmp[i][j];
			//2 � �����
			tmp[i][j] = m[i][2 * n - n + (j)];
			//3->2
			m[i][2 * n - n + (j)] = m[2 * n - n + (i)][j];
			//2->3
			m[2 * n - n + (i)][j] = tmp[i][j];
		}
	}
	cout << endl << "��������� ������� - " << endl;
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			//�����
			cout << " " << *(*(m + i) + j);
			if (j == n - 1) printf("   |   ");
			if (i == n - 1) printf("_");
			if (j == 2 * n - 1)
				printf("\n");
		}
	}

	return 1;
}


int main() {
	setlocale(LC_ALL, "RUSSIAN");
	cout << "��� 1";
	cout << endl;
	f1();
}