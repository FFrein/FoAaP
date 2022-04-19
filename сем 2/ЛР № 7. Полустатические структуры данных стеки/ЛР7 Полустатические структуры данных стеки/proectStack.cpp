// proectStack.cpp: определяет точку входа для консольного приложения.
#include "stdafx.h"
#include <iostream>
#include <TCHAR.h>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	int choice;
	Stack* myStk = new Stack; //выделение памяти для стека
	Stack* myStk2 = new Stack;
	Stack* myStk3 = new Stack;
	myStk->head = NULL;  //инициализация первого элемента
	myStk2->head = NULL;
	myStk3->head = NULL;	
	for (;;)
	{
		cout << "Выберите команду:" << endl;
		cout << "1 - Добавление элемента в стек" << endl;
		cout << "2 - Извлечение элемента из стека" << endl;
		cout << "3 - Сортировка" << endl;
		cout << "4 - Вывод стека" << endl;
		cout << "5 - Удаление" << endl;
		cout << "6 - Запись в файл" << endl;
		cout << "7 - Чтение из файла" << endl;
		cout << "8 - Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите элемент: " << endl;
			cin >> choice;
			push(choice, myStk);
			break;
		case 2: choice = pop(myStk);
			if (choice != -1)
				cout << "Извлеченный элемент: " << choice << endl;
			break;
		case 3: cout << "Сортировка: " << endl;
			sort(myStk, myStk2, myStk3);
			break;
		case 4: cout << "Весь стек: " << endl;
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