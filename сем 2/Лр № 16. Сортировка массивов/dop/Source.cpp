#include <iostream>
#include <ctime>
#include "Header.h"
using namespace std;

int main()
{
	short choose = 0;
	setlocale(LC_ALL, "ru");

	while (choose != 5)
	{
		cout << "\n========================================\n";
		cout << "\t   �������� �������:\n\t2 � 1 ��� (4 �������);\n\t3 � 2 ��� (5 �������);"
			"\n\t4 � 3 ��� (1 �������);\n\t5 � ����� �� ���������.";
		cout << "\n========================================\n";

		cin >> choose;
		switch (choose)
		{
		case 2: dop1(); break;
		case 3: dop2(); break;
		case 4: dop3(); break;
		case 5: cout << "\n�� ��������!\n"; exit(0);
		}
	}
}