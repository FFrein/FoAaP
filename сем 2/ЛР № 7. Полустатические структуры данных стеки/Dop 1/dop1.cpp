// dop1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
struct Stack
{
	char data;            
	Stack* head;   
	Stack* next;   
};
void show(Stack* myStk);             
void push(char x, Stack* myStk);
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	char str[20];
	int dl;
	Stack* myStk = new Stack; //выделение памяти для стека
	myStk->head = NULL;       //инициализация первого элемента 

		cout << "Строка с четным количеством символов " << endl;
		cin >> str;
	
	dl = strlen(str);
	for (int i = (dl / 2); i < dl; i++) {
		push(str[i], myStk);
	}
	for (int i = 0; i < (dl / 2); i++) {
		push(str[i], myStk);
	}
	show(myStk);
}

void push(char x, Stack* myStk)   //Добавление элемента х в стек 
{
	Stack* e = new Stack;    //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле v 
	e->next = myStk->head;   //перенос вершины на следующий элемент 
	myStk->head = e;         //сдвиг вершины на позицию вперед
}
void show(Stack* myStk)    //Вывод стека
{
	Stack* e = myStk->head;    //объявляется указатель на вершину стека
	char a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data;          //запись значения в переменную a 
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}

