#include <iostream>
#include <windows.h>

float function_one(float x) {
	x = (2 * x) + (x * x * x) - 3;
	return x;
}

float function_two(float x) {
	x = exp(x) + 2 * x;
	return x;
}

float Method_Dihotomii(float a, float b, float n, float e, int choise) {
	using namespace std;
	float x;
	/*создаю указатель на функцию*/
	float (*functOne)(float a);
		functOne = function_one;
	if (choise == 2) {
		functOne = function_two;
	}

	do {
		x = (a + b) / 2;
		if (functOne(x) * functOne(a) <= 0) {
			b = x;
		}
		else {
			a = x;
		}
	} while (abs(a - b) > 2 * e);
	cout << x << endl;
	return x;
}

int function2(int n, int* massiveB) {
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int numb = 0, n_alternativ;

	cout << endl;

	/*Поиск отрицательных, замена их на 0 и перенос в конец*/
	n_alternativ = n - 1;
	for (int i = 0; i < n; i++) {
		if (massiveB[i] < 0) {
			if (massiveB[n_alternativ] < 0) {
				n_alternativ -= 1;
			}
			numb = massiveB[n_alternativ];
			massiveB[i] = numb;
			massiveB[n_alternativ] = 0;
			n_alternativ -= 1;
		}
	}

	/*Вывод*/
	SetConsoleTextAttribute(hConsole, 13);
	for (int i = 0; i < n; i++) {
		cout << massiveB[i] << " ";
	}
	SetConsoleTextAttribute(hConsole, 15);

	cout << endl;
	return 0;
}

int main() {
	using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int c, i, j, n, choise = 1, a = 5, b = 11, n2 = 200, e = 0.0001;
	cout << "Choose quest = ";
	cin >> c;
	switch (c) {
	case 1:
		for (int numb = 0; numb < 2; numb++) {
			SetConsoleTextAttribute(hConsole, 20);
			cout << "Quest 1" << endl;
			SetConsoleTextAttribute(hConsole, 15);
			(*Method_Dihotomii)(a, b, n2, e, choise);
			choise += 1;
		}
	case 2:
		for (int numb = 0; numb < 3; numb++) {
			SetConsoleTextAttribute(hConsole, 20);
			cout << "Quest 2" << endl;
			SetConsoleTextAttribute(hConsole, 15);

			cout << "Massive size = ";
			cin >> n;

			/*Создание массива и присваивание ему значений*/

			int* massiveB;
			srand((unsigned)time(NULL));
			massiveB = new int[n];
			for (int i = 0; i < n; i++) {
				massiveB[i] = 8 - rand() % 10;
				cout << massiveB[i] << " ";
			}
			/*программа и так с переменным количеством вводных даннныхБ т.к.
			размер массива указывается здесь*/
			function2(n, massiveB);
		}
	}
	return 0;
}

