// LABA12_DOP1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Оператор мобильной связи организовал базу данных абонентов, содержащую сведения о телефонах, их владельцах и 
//используемых тарифах, в виде бинарного дерева. Разработать программу, которая обеспечивает начальное формирование 
//базы данных в виде бинарного дерева; производит вывод всей базы данных; поиск владельца по номеру телефона; 
//выводит наиболее востребованный тариф (по наибольшему числу абонентов).

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
		cout << "Нет такого элемента\n";
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
	cout << "Введите кол-во абонентов: ";
	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		cout << "Введите имя: "; cin >> name;
		cout << "Введите фамилию: "; cin >> surname;
		cout << "Введите номер: "; cin >> number;
		cout << "Введите тариф(1 - Безлимит, 2 - Бизнес, 3 - Роуминг): "; cin >> tarif;
		insert(number, name, surname, tarif, &tree);
	}
	print(tree, 0);
	cout << "\nВведите номер: ";  cin >> numt;
	rc = search(tree, numt);
	cout << "Информация полученная по номеру: " << endl;
	cout << "Имя: " << rc->name << endl;
	cout << "Фамилия: " << rc->surname << endl;
	cout << "Номер: " << rc->number << endl;
	cout << "Тариф: ";
	if (rc->tarif == 1)
		cout << "Безлимит" << endl;
	else if (rc->tarif == 2)
		cout << "Бизнес" << endl;
	else
		cout << "Роуминг" << endl;
	checkpopT(tree);
	for (int i = 0; i < 3; i++)
	{
		if (a[i] > tmp)
			tmp = a[i];
	}
	cout << "Самый поплярный тариф: ";
	if (tmp == a[0])
		cout << "Безлимит" << endl;
	else if (tmp == a[1])
		cout << "Бизнес" << endl;
	else if (tmp == a[2])
		cout << "Роуминг" << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.