// proectStack.cpp: ���������� ����� ����� ��� ����������� ����������.
#include "stdafx.h"
#include <iostream>
#include <TCHAR.h>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	int choice;
	Stack* myStk = new Stack; //��������� ������ ��� �����
	Stack* myStk2 = new Stack;
	Stack* myStk3 = new Stack;
	myStk->head = NULL;  //������������� ������� ��������
	myStk2->head = NULL;
	myStk3->head = NULL;	
	for (;;)
	{
		cout << "�������� �������:" << endl;
		cout << "1 - ���������� �������� � ����" << endl;
		cout << "2 - ���������� �������� �� �����" << endl;
		cout << "3 - ����������" << endl;
		cout << "4 - ����� �����" << endl;
		cout << "5 - ��������" << endl;
		cout << "6 - ������ � ����" << endl;
		cout << "7 - ������ �� �����" << endl;
		cout << "8 - �����" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "������� �������: " << endl;
			cin >> choice;
			push(choice, myStk);
			break;
		case 2: choice = pop(myStk);
			if (choice != -1)
				cout << "����������� �������: " << choice << endl;
			break;
		case 3: cout << "����������: " << endl;
			sort(myStk, myStk2, myStk3);
			break;
		case 4: cout << "���� ����: " << endl;
			show(myStk, myStk2, myStk3);
			break;
		case 5: 
			clear(myStk, myStk2, myStk3);
			break;
		case 6: 
			toFile(myStk);
			break;
		case 7: 
			fromFile(myStk);
			break;
		case 8: return 0;
			break;
		}

	}
	return 0;
}