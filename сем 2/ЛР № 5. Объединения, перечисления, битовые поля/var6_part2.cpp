// zd1 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Преподаватели. Фамилия преподавателя, название экзамена, дата экзамена. Выбор по фамилии.

#include <iostream>
using namespace std;

void enter_new();
void out();
void  search();


int kol;
union forTeacher
{
	char str[20];
	int limb;
};

struct Teacher
{
	forTeacher fio;
	forTeacher exam;
	forTeacher date;
};

Teacher inform[256];
int choice;
int main()
{
	
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите число:" << endl;
	cout << "1-для ввода записи" << endl;
	cout << "2-для вывода записи" << endl;
	cout << "3-для поиска информации" << endl;
	cout << "4-для выхода" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  enter_new();	break;
		case 2:  out();  break;
		case 3:  search();	break;
		}
	} while (choice != 4);
}

void enter_new() {
	cout << "\nВведите колличество преподавателей  ";
	cin >> kol;
	for (int i = 0; i < kol; i++) {
		cout << "\nСтрока номер " << i + 1;
		cout << "\n Фамилия: ";
		cin >> inform[i].fio.str;
		cout << "\n Экзамен: ";
		cin >> inform[i].exam.str;
		cout << "\n Дата: ";
		cin >> inform[i].date.limb;
	}
	cout << "\nЧто дальше?" << endl;
	cin >> choice;
}

void out() {
	cout << "Вывод информации на экран: ";
	for (int i = 0; i < kol; i++) {
		cout << "\nСтрока номер\t " << i + 1;
		cout << "\n Фамилия: "<< inform[i].fio.str;
		cout << "\n Экзамен: " <<inform[i].exam.str;
		cout << "\n Дата: "<< inform[i].date.limb;
	}
	cout << "\nЧто дальше?" << endl;
	cin >> choice;
}

void  search() {
	char b[256];
	cout << "Введите фамилию преподавателя ";
	cin >> b;
	for (int i = 0; i < kol; i++) {
		if (strcmp(inform[i].fio.str, b) == 0) {
			cout << "\nСтрока номер\t " << i + 1;
			cout << "\n Фамилия: " << inform[i].fio.str;
			cout << "\n Экзамен: " << inform[i].exam.str;
			cout << "\n Дата: " << inform[i].date.limb;
		}
		
	}
	cout << "\nЧто дальше?" << endl;
	cin >> choice;

}