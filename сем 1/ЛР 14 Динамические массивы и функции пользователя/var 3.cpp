#include <iostream>
#include <windows.h> /*���������� ��� ��������� ����� �������*/

int function_1() {
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int* A;
	int n, proizv = 1, sum = 0;

	SetConsoleTextAttribute(hConsole, 20);
	cout << "Quest 1" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	/*������� ������� ������� � �������� ��������*/
	SetConsoleTextAttribute(hConsole, 14);
	cout << "Enter size = ";
	cin >> n;
	SetConsoleTextAttribute(hConsole, 15);
	A = new int[n];
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) {
		A[i] = 5 - rand() % 10;
		cout << "A[" << i << "]" << " = " << A[i] << endl;

		/*����� ������������� ������ � ���������� �� ������������*/
			if (A[i] < 0) {
				proizv = proizv * A[i];
			}

		/*����� ������������� ������ � ���������� �� �����*/
			if (A[i] > 0) {
				sum += A[i];
			}
	}
	cout << "proizv = " << proizv << endl;
	cout << "Sum = " << sum << endl;
	return 0;
}

int function_2() {
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int i = 4, j = 4, rownumb = -1, min1 = 11, min2 = 11, max1 = -11, max2 = -11;
	int** A; /* ���� * ����� ������ �������, ��� * ����� �������, ��� * ����� ��������������*/

	SetConsoleTextAttribute(hConsole, 20);
	cout << "Quest 2" << endl;
	SetConsoleTextAttribute(hConsole, 15);

	/*�������� ����������� �������*/
	SetConsoleTextAttribute(hConsole, 14);
	cout << "Rows = " << i << endl;
	cout << "Colums = " << j << endl;;
	SetConsoleTextAttribute(hConsole, 15);

	/*���������� �������� �������*/
	srand((unsigned)time(NULL));
	A = new int* [i];
	for (int numb = 0; numb < i; numb++) {
		A[numb] = new int[j];
		for (int numb2 = 0; numb2 < j; numb2++) {
			A[numb][numb2] = 1 - rand() % 10;
			cout << A[numb][numb2] << " ";
		}
		cout << endl;
	}

	/*����� �����*/
	for (int numb = 0; numb < i; numb++) {
		for (int numb2 = 0; numb2 < j; numb2++) {
			if (numb == 1 && min1 > A[numb][numb2]) {
				min1 = A[numb][numb2];
			}
			if (numb == 2 && max1 < A[numb][numb2]) {
				max1 = A[numb][numb2];
			}

			if (numb == 3 && min2 > A[numb][numb2]) {
				min2 = A[numb][numb2];
			}
			if (numb == 4 && max2 < A[numb][numb2]) {
				max2 = A[numb][numb2];
			}
		}
	}
	/*�����*/
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Sum min = " << min1 + min2 << endl;
	cout << "Sum max = " << max1 + max2 << endl;
	SetConsoleTextAttribute(hConsole, 15);
	return 0;
}

int main() {
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	/*����������� switch case*/
	int casenumb;
	cout << "�������� �������(1 ��� 2)" << endl;
	cin >> casenumb;
	switch (casenumb) {
	case 1:
		function_1();
	case 2:
		function_2();
	}
}
	