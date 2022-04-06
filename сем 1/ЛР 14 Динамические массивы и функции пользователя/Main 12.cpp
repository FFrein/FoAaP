#include <iostream>
#include <windows.h> /*���������� ��� ��������� ����� �������*/

int function_1() {
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int* A;
	int n, max = 0, povtorki = 0;

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
	for (int i = 0; i < n; i++){
		A[i] = rand() % 10;
		cout << "A[" << i << "]" << " = " << A[i] << endl;
	}

	/*����� ������������� �����*/
	for (int i = 0; i < n; i++) {
		if (A[i] > max) {
			max = A[i];
		}
	}

	/*����� ���������� ������������� �����*/
	for (int i = 0; i < n; i++) {
		if (A[i] == max) {
			povtorki += 1;
		}
	}



	/*������� ���� ���� � ������� | 10 - ������*/
	SetConsoleTextAttribute(hConsole, 10);

	/*�����*/
	cout << " max = " << max << endl << " povtor = " << povtorki << endl;

	/*������� ���� �� ����������� | 15 - �����*/

	SetConsoleTextAttribute(hConsole, 15);

	return max, povtorki;
}

int function_2() {
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int i, j, rownumb = -1;
	int** A; /* ���� * ����� ������ �������, ��� * ����� �������, ��� * ����� ��������������*/

	SetConsoleTextAttribute(hConsole, 20);
	cout << "Quest 2" << endl;
	SetConsoleTextAttribute(hConsole, 15);

	/*�������� ����������� �������*/
	SetConsoleTextAttribute(hConsole, 14);
	cout << "Rows = ";
	cin >> i;
	cout << "Colums = ";
	cin >> j;
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

	/*����� �������������� �����*/
	int stop = 0;
	for (int numb = 0; numb < i; numb++) {
		for (int numb2 = 0; numb2 < j; numb2++) {
			if (A[numb][numb2] > 0) {
				rownumb = numb;
				numb = i;
				numb2 = j;
			}
		}
	}
	/*�����*/
	SetConsoleTextAttribute(hConsole, 10);
	if (rownumb >= 0) {
		int rownumb2 = rownumb + 1;
		cout << "rownumb = " << rownumb2 << endl;
		if (rownumb != 0) {
			rownumb -= 1;
			cout << "������ ���������� ������ " << endl;
			for (int numb2 = 0; numb2 < j; numb2++) {
				A[rownumb][numb2] = -A[rownumb][numb2];
				cout << A[rownumb][numb2] << " ";
			}
		}
		else {
			SetConsoleTextAttribute(hConsole, 13);
			cout << "������ ���������� ������ ����������" << endl;
			SetConsoleTextAttribute(hConsole, 15);
		}
	}
	else {
		SetConsoleTextAttribute(hConsole, 13);
		cout << "����������� ������������� �����";
		SetConsoleTextAttribute(hConsole, 15);
	}
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