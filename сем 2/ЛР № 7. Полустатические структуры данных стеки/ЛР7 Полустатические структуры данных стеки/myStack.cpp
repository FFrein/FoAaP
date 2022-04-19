#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;
void push(int x, Stack* myStk)   //Добавление элемента х в стек	
{
	Stack* e = new Stack;    //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле v 
	e->next = myStk->head;   //перенос вершины на следующий элемент 
	myStk->head = e;         //сдвиг вершины на позицию вперед
}

void sort(Stack* myStk, Stack* myStk2, Stack* myStk3)    //Вывод стека
{
	Stack* e = myStk->head;    //объявляется указатель на вершину стека
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data;          //запись значения в переменную a 
		Stack* e2 = new Stack;
		if (a % 2 == 0)
		{
			e2->data = a;             //запись элемента x в поле v 
			e2->next = myStk2->head;   //перенос вершины на следующий элемент 
			myStk2->head = e2;         //сдвиг вершины на позицию вперед
		};

		Stack* e3 = new Stack;
		if (a % 3 == 0)
		{
			e3->data = a;             //запись элемента x в поле v 
			e3->next = myStk3->head;   //перенос вершины на следующий элемент 
			myStk3->head = e3;         //сдвиг вершины на позицию вперед
		};
		e = e->next;
	}
	cout << endl;



}

int pop(Stack* myStk)   //Извлечение (удаление) элемента из стека
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;               //если стек пуст - возврат -1 
	}
	else
	{
		Stack* e = myStk->head;   //е - переменная для хранения адреса элемента
		int a = myStk->head->data;   //запись числа из поля data в переменную a 
		myStk->head = myStk->head->next; //перенос вершины
		delete e;                        //удаление временной переменной
		return a;                        //возврат значения удаляемого элемента
	}
}
void show(Stack* myStk, Stack* myStk2, Stack* myStk3)    //Вывод стека
{
	Stack* e = myStk->head;    //объявляется указатель на вершину стека
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data;          //запись значения в переменную a 
		cout << a << " ";
		e = e->next;
	}
	cout << endl;

	Stack* e2 = myStk2->head;    //объявляется указатель на вершину стека
	int a2;
	if (e2 == NULL)
		cout << "Стек пуст!" << endl;
	while (e2 != NULL)
	{
		a2 = e2->data;          //запись значения в переменную a 
		cout << a2 << " ";
		e2 = e2->next;
	}
	cout << endl;

	Stack* e3 = myStk3->head;    //объявляется указатель на вершину стека
	int a3;
	if (e3 == NULL)
		cout << "Стек пуст!" << endl;
	while (e3 != NULL)
	{
		a3 = e3->data;          //запись значения в переменную a 
		cout << a3 << " ";
		e3 = e3->next;
	}
	cout << endl;
}

void clear(Stack* myStk, Stack* myStk2, Stack* myStk3) {
	myStk->head = nullptr;
	myStk2->head = nullptr;
	myStk3->head = nullptr;
}

void insert(Stack*& p, double value) //Добавление символа в начало списка
{
	Stack* newP = new Stack;
	if (newP != NULL)     //есть ли место?  
	{
		newP->data = value;
		newP->next = p;
		p = newP;
	}
	else
		cout << "Операция добавления не выполнена" << endl;
}

void toFile(Stack*& p)
{
	Stack* temp = p->head;
	Stack buf;
	ofstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (temp)
	{
		buf = *temp;
		frm.write((char*)&buf, sizeof(Stack));
		temp = temp->next;
	}
	frm.close();
	cout << "Список записан в файл mList.dat\n";
}

void fromFile(Stack*& p)          //Считывание из файла
{
	Stack buf, * first = nullptr;
	ifstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	frm.read((char*)&buf, sizeof(Stack));
	while (!frm.eof())
	{
		push(buf.data, p);
		cout << "-->" << buf.data;
		frm.read((char*)&buf, sizeof(Stack));
	}
	cout << "-->NULL" << endl;
	frm.close();
	cout << "\nСписок считан из файла mList.dat\n";
}