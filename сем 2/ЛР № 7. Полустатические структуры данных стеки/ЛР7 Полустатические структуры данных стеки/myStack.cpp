#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;
void push(int x, Stack* myStk)   //���������� �������� � � ����	
{
	Stack* e = new Stack;    //��������� ������ ��� ������ ��������
	e->data = x;             //������ �������� x � ���� v 
	e->next = myStk->head;   //������� ������� �� ��������� ������� 
	myStk->head = e;         //����� ������� �� ������� ������
}

void sort(Stack* myStk, Stack* myStk2, Stack* myStk3)    //����� �����
{
	Stack* e = myStk->head;    //����������� ��������� �� ������� �����
	int a;
	if (e == NULL)
		cout << "���� ����!" << endl;
	while (e != NULL)
	{
		a = e->data;          //������ �������� � ���������� a 
		Stack* e2 = new Stack;
		if (a % 2 == 0)
		{
			e2->data = a;             //������ �������� x � ���� v 
			e2->next = myStk2->head;   //������� ������� �� ��������� ������� 
			myStk2->head = e2;         //����� ������� �� ������� ������
		};

		Stack* e3 = new Stack;
		if (a % 3 == 0)
		{
			e3->data = a;             //������ �������� x � ���� v 
			e3->next = myStk3->head;   //������� ������� �� ��������� ������� 
			myStk3->head = e3;         //����� ������� �� ������� ������
		};
		e = e->next;
	}
	cout << endl;



}

int pop(Stack* myStk)   //���������� (��������) �������� �� �����
{
	if (myStk->head == NULL)
	{
		cout << "���� ����!" << endl;
		return -1;               //���� ���� ���� - ������� -1 
	}
	else
	{
		Stack* e = myStk->head;   //� - ���������� ��� �������� ������ ��������
		int a = myStk->head->data;   //������ ����� �� ���� data � ���������� a 
		myStk->head = myStk->head->next; //������� �������
		delete e;                        //�������� ��������� ����������
		return a;                        //������� �������� ���������� ��������
	}
}
void show(Stack* myStk, Stack* myStk2, Stack* myStk3)    //����� �����
{
	Stack* e = myStk->head;    //����������� ��������� �� ������� �����
	int a;
	if (e == NULL)
		cout << "���� ����!" << endl;
	while (e != NULL)
	{
		a = e->data;          //������ �������� � ���������� a 
		cout << a << " ";
		e = e->next;
	}
	cout << endl;

	Stack* e2 = myStk2->head;    //����������� ��������� �� ������� �����
	int a2;
	if (e2 == NULL)
		cout << "���� ����!" << endl;
	while (e2 != NULL)
	{
		a2 = e2->data;          //������ �������� � ���������� a 
		cout << a2 << " ";
		e2 = e2->next;
	}
	cout << endl;

	Stack* e3 = myStk3->head;    //����������� ��������� �� ������� �����
	int a3;
	if (e3 == NULL)
		cout << "���� ����!" << endl;
	while (e3 != NULL)
	{
		a3 = e3->data;          //������ �������� � ���������� a 
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

void insert(Stack*& p, double value) //���������� ������� � ������ ������
{
	Stack* newP = new Stack;
	if (newP != NULL)     //���� �� �����?  
	{
		newP->data = value;
		newP->next = p;
		p = newP;
	}
	else
		cout << "�������� ���������� �� ���������" << endl;
}

void toFile(Stack*& p)
{
	Stack* temp = p->head;
	Stack buf;
	ofstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	while (temp)
	{
		buf = *temp;
		frm.write((char*)&buf, sizeof(Stack));
		temp = temp->next;
	}
	frm.close();
	cout << "������ ������� � ���� mList.dat\n";
}

void fromFile(Stack*& p)          //���������� �� �����
{
	Stack buf, * first = nullptr;
	ifstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n ������ �������� �����";
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
	cout << "\n������ ������ �� ����� mList.dat\n";
}