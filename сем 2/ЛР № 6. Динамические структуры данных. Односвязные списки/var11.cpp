#include <iostream>
#include <fstream>

using namespace std;

struct list
{
	char symbol;
	list* next;
};

void insert(list*& p, char value); //Добавление символа в начало списка
void del(list*& p);
void printList(list* p);       //Вывод списка 
void toFile(list*& p);         //Запись в файл
void fromFile(list*& p);       //Считывание из файла
void menu(void);//Вывод меню 
void search(list*& p);

int main()
{
	setlocale(LC_CTYPE, "Russian");
	list* first = nullptr;
	int choice; char value;
	menu();    // вывести меню 
	cout << " ? ";
	cin >> choice;
	while (choice != 6)
	{
		switch (choice)
		{
		case 1:  	cout << "Введите символ ";
			cin >> value;
			insert(first, value);
			printList(first);
			break;
		case 2:    del(first);
			break;
		case 3:    search(first);
			break;
		case 4:    toFile(first);
			break;
		case 5:    fromFile(first);
			break;
		default:   cout << "Неправильный выбор" << endl;
			menu(); break;
		}
		cout << "?  ";
		cin >> choice;
	}
	return 0;
}

void insert(list*& p, char value) //Добавление символа в начало списка
{
	list* newP = new list;
	if (newP != NULL)     //есть ли место?  
	{
		newP->symbol = value;
		newP->next = p;
		p = newP;
	}
	else
		cout << "Операция добавления не выполнена" << endl;
}

void del(list*& p) {
	list* temp = p;
	list* prev = NULL;
	int cd;
	cout << "Номер удаляемого - "; cin >> cd;
	for (int i = 0; i < cd; i++) {
		prev = temp;
		temp = temp->next;
	}
	if (cd == 0) {
		p = p->next;
	}
		prev->next = temp->next;
		free(temp);
	}

void printList(list* p)  //Вывод списка 
{
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		cout << "Список:" << endl;
		while (p != NULL)
		{
			cout << "-->" << p->symbol;
			p = p->next;
		}
		cout << "-->NULL" << endl;
	}
}

void toFile(list*& p)
{
	list* temp = p;
	list buf;
	ofstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (temp)
	{
		buf = *temp;
		frm.write((char*)&buf, sizeof(list));
		temp = temp->next;
	}
	frm.close();
	cout << "Список записан в файл mList.dat\n";
}

void fromFile(list*& p)          //Считывание из файла
{
	list buf, * first = nullptr;
	ifstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	frm.read((char*)&buf, sizeof(list));
	while (!frm.eof())
	{
		insert(first, buf.symbol);
		cout << "-->" << buf.symbol;
		frm.read((char*)&buf, sizeof(list));
	}
	cout << "-->NULL" << endl;
	frm.close();
	p = first;
	cout << "\nСписок считан из файла mList.dat\n";
}

void search(list*& p) {
	char sy, sym;
	cout << "\nИскомый символ - "; cin >> sy;
	while (p != NULL) {
		if (p->symbol == sy) {
			cout <<endl << p->symbol << " и " << sym << endl;
			return;
		}
		else {
			sym = p->symbol;
			p = p->next;
		}
	}
	cout << "\nСимвол не найден.\n";
}

void menu(void)     //Вывод меню 
{
	cout << "Сделайте выбор:" << endl;
	cout << " 1 - Ввод символа" << endl;
	cout << " 2 - Удаление символа" << endl;
	cout << " 2 - Поиск введенного" << endl;
	cout << " 4 - Запись списка в файл" << endl;
	cout << " 5 - Чтение списка из файла" << endl;
	cout << " 6 - Выход" << endl;
}
