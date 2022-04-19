// LABA12_DOP1.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//�������� ��������� ����� ����������� ���� ������ ���������, ���������� �������� � ���������, �� ���������� � 
//������������ �������, � ���� ��������� ������. ����������� ���������, ������� ������������ ��������� ������������ 
//���� ������ � ���� ��������� ������; ���������� ����� ���� ���� ������; ����� ��������� �� ������ ��������; 
//������� �������� �������������� ����� (�� ����������� ����� ���������).

#include<iostream>
#include<Windows.h>
using namespace std;
int numt, a[] = { 0,0,0 };
struct Sub
{
	int number;
	string name;
	string surname;
	int tarif;
	Sub* left, * right;
};
Sub* tree = nullptr;

void insert(int number, string name, string surname, int tarif, Sub** t)
{

	if ((*t) == NULL)
	{
		(*t) = new Sub;
		(*t)->number = number;
		(*t)->name = name;
		(*t)->surname = surname;
		(*t)->tarif = tarif;
		(*t)->right = (*t)->left = NULL;
		return;
	}
	if (number > (*t)->number)
		insert(number, name, surname, tarif, &(*t)->right);

	else
		insert(number, name, surname, tarif, &(*t)->left);

}

void print(Sub* t, int u)
{
	if (t == NULL) return;
	else
	{
		print(t->left, ++u);
		for (int i = 0; i < u; ++i)
			cout << "   ";
		cout << t->number << endl;
		u--;
	}
	print(t->right, ++u);
}

Sub* search(Sub* n, int num)
{
	Sub* rc = n;
	if (rc != NULL)
	{
		if (num < (num, n->number))
			rc = search(n->left, num);
		else
			if (num > (num, n->number))
				rc = search(n->right, num);
	}
	else
		cout << "��� ������ ��������\n";
	return rc;
}

int checkpopT(Sub* t)
{
	if (t == NULL) { return NULL; }
	if (t->tarif == 1)
	{
		a[0]++;
		return(checkpopT(t->right) + checkpopT(t->left));
	}
	else if (t->tarif == 2)
	{
		a[1]++;
		return(checkpopT(t->right) + checkpopT(t->left));
	}
	else if (t->tarif == 3)
	{
		a[2]++;
		return(checkpopT(t->right) + checkpopT(t->left));
	}

}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string name, surname;
	int number, tmp = 0, tarif, count;
	Sub* rc;
	cout << "������� ���-�� ���������: ";
	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		cout << "������� ���: "; cin >> name;
		cout << "������� �������: "; cin >> surname;
		cout << "������� �����: "; cin >> number;
		cout << "������� �����(1 - ��������, 2 - ������, 3 - �������): "; cin >> tarif;
		insert(number, name, surname, tarif, &tree);
	}
	print(tree, 0);
	cout << "\n������� �����: ";  cin >> numt;
	rc = search(tree, numt);
	cout << "���������� ���������� �� ������: " << endl;
	cout << "���: " << rc->name << endl;
	cout << "�������: " << rc->surname << endl;
	cout << "�����: " << rc->number << endl;
	cout << "�����: ";
	if (rc->tarif == 1)
		cout << "��������" << endl;
	else if (rc->tarif == 2)
		cout << "������" << endl;
	else
		cout << "�������" << endl;
	checkpopT(tree);
	for (int i = 0; i < 3; i++)
	{
		if (a[i] > tmp)
			tmp = a[i];
	}
	cout << "����� ��������� �����: ";
	if (tmp == a[0])
		cout << "��������" << endl;
	else if (tmp == a[1])
		cout << "������" << endl;
	else if (tmp == a[2])
		cout << "�������" << endl;
}

// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"

// ������ �� ������ ������ 
//   1. � ���� ������������ ������� ����� ��������� ����� � ��������� ���.
//   2. � ���� Team Explorer ����� ������������ � ������� ���������� ��������.
//   3. � ���� "�������� ������" ����� ������������� �������� ������ ������ � ������ ���������.
//   4. � ���� "������ ������" ����� ������������� ������.
//   5. ��������������� �������� ������ ���� "������" > "�������� ����� �������", ����� ������� ����� ����, ��� "������" > "�������� ������������ �������", ����� �������� � ������ ������������ ����� ����.
//   6. ����� ����� ������� ���� ������ �����, �������� ������ ���� "����" > "�������" > "������" � �������� SLN-����.