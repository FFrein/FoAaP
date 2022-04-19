#include <iostream>
#include<fstream>
#include <windows.h>
using namespace std;
struct list
{
	string name;
	int age;
	list* next;
	list* prev;
};
void input(int n, list** kon, list** slist)
{
	cout << "Введите элементы для вставки:" << endl;
	cout << "Имя:";
	list* end = *slist;
	for (int i = 0; i < n - 1; i++)
	{
		end = end->next;
	}
	n++;
	list* add = end;
	add->next = new list;
	add = add->next;
	cin >> add->name;
	cout << "Введите элемент для вставки:" << endl;
	cout << "Возраст:";
	cin >> add->age;
	add->next = NULL;
}
void del(list** slist)
{
	string p;
	cout << "Введите элемент имени для удаления:";
	cin >> p;
	list* del = *slist;
	if (del->name == p)
	{
		*slist = del->next;
		delete del;
		return;
	}
	list* del1 = del->next;

	while (del1)
	{
		if (del1->name == p)
		{
			del->next = del1->next;
			delete del1;
			return;
		}
		del = del1;
		del1 = del1->next;
	}

}
void vivod(list** slist)
{
	list* viv = *slist;
	while (viv)
	{
		cout << "Имя:";
		cout << viv->name << " ";
		cout << "Возраст:";
		cout << viv->age << endl;
		viv = viv->next;
	}
	cout << endl;
}
void search(list** slist)
{
	string p;
	cout << "Введите элемент для поиска:";
	cin >> p;
	bool find = false;
	list* search = *slist;
	while (search)
	{
		if (search->name == p)
		{
			find = true;
			cout << "Есть такой элемент" << endl;
			list* del = *slist;
			break;
		}
		search = search->next;
	}
	if (find == false)
	{
		cout << "Нет такого элемента" << endl;
	}
}
void deletes(list** slist)
{
	cout << "Сколько символов в двусвязном списке?" << endl;
	int f;
	cin >> f;
	list* del;
	for (int i = 0; i < f; i++)
	{
		del = *slist;
		*slist = del->next;
		delete del;
	}
}
void countLIST(list** slist)
{
	list* cou = *slist;
	int n = 0;
	while (cou)
	{
		n++;
		cou = cou->next;
	}
	cout << "Количество элементов:" << n << endl;
}
void outfile()
{
	char line[500];
	cout << "Содержимое файла:" << endl;
	ifstream out;
	out.open("file1.txt");
	while (!out.eof())
	{
		out.getline(line, 500);
		cout << line << endl;
	}
}
void infile(list** slist3)
{
	list* in = *slist3;
	ofstream file1;
	file1.open("file1.txt");
	cout << "Элементы в файле" << endl;
	while (in)
	{
		file1 << "Имя:";
		file1 << in->name << " ";
		file1 << "Город:";
		file1 << in->age << endl;
		in = in->next;
	}
	file1.close();
}
int main()
{
l1:
	setlocale(LC_ALL, "Russian");
	cout << "Введите число элементов: ";
	int n;
	cin >> n;
	int x;
	int i = 0;
	int sum = 0;
	ofstream file1;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	file1.open("file1.txt");
	file1 << n << endl;
	cout << "Введите элементы: " << endl;
	file1 << "элементы: " << endl;
	list* slist = nullptr;
	slist = new list;
	list* end = slist;
	cout << "Имя:";
	cin >> slist->name;
	cout << "Возраст:";
	cin >> slist->age;
	cout << endl;
	slist->next = NULL;
	slist->prev = NULL;
	for (i = 1; i < n; i++)
	{
		end->next = new list;
		end = end->next;
		cout << "Имя:";
		cin >> end->name;
		cout << "Возраст:";
		cin >> end->age;
		cout << endl;
		end->next = NULL;
	}
	list* kon = end;
	cout << endl;
	file1.close();
	cout << endl;
	cout << endl;
	do
	{
		cout << "//////////////////" << endl << endl;
		cout << "1. Добавление элемента" << endl;
		cout << "2. Удалить данные" << endl;
		cout << "3. Поиск информации" << endl;
		cout << "4. Вывод очереди в консольное окно" << endl;
		cout << "5. Очистка" << endl;
		cout << "6. Новая запись" << endl;
		cout << "7. Считывание списка из файла" << endl;
		cout << "8. Запись в файл" << endl;
		cout << "9. Выход" << endl;
		cout << "0. countLIST" << endl;
		cout << "Выберите команду: ";
		cin >> x;
		switch (x)
		{
		case 1:input(n, &kon, &slist); break;
		case 2: del(&slist); break;
		case 3:search(&slist); break;
		case 4: vivod(&slist); break;
		case 5:deletes(&slist); break;
		case 6:goto l1; break;
		case 7:outfile(); break;
		case 8:infile(&slist); break;
		case 9:return 0; break;
		case 0:countLIST(&slist);
			break;
		}
		cout << "//////////////////" << endl << endl;
	} while (x >= 0);
}