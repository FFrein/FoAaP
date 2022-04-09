#include <iostream>
#include <windows.h>
using namespace std;

void input(int size);
void output();
void find(char lastName[]);

typedef struct Exams
{
	char surname[16];
	char name[16];
	char secondname[16];
	char count[3];
	float mark;
} STUD;
int number, markplus = 0, markminus = 0; float per = 0; FILE* f; errno_t err;

int main()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
	int choice; char surname[16];
	do
	{
		SetConsoleTextAttribute(console, 3);
		cout << "1. Ввод данных с клавиатуры и запись в файл\n";
		cout << "2. Вывод данных из файла\n";
		cout << "3. Поиск по фамилии\n";
		cout << "4. Процент учащихся со средним баллом от 4\n";
		cout << "0. Выход из программы\n\n";
		cout << "Введите номер операции: ";
		SetConsoleTextAttribute(console, 12);
		cin >> choice;
		SetConsoleTextAttribute(console, 15);
		switch (choice)
		{
		case 1: cout << "Введите количество студентов, данные о которых хотите ввести: ";
			cin >> number;
			input(number);
			markplus = 0; markminus = 0;
			cout << endl; system("pause");			system("cls");	 break;
		case 2: markplus = 0; markminus = 0;
			output(); break;
		case 3: {  cout << "Введите фамилию: ";
			cin >> surname;
			find(surname);  system("pause");			system("cls");  break;
		}
		case 4: { per = (float)markplus / (((float)markplus + (float)markminus)) * 100;
			cout << "На данный момент процент учащихся со средним баллов >= 4 - " << per << "%." << endl;
			system("pause");			system("cls");			break;
		}
		case 0: exit(0);  break;
		}
	} while (choice != 0);
}

void input(int size)
{
	STUD buf = { ' ', ' ' };
	if (!fopen_s(&f, "marks.txt", "ab"))
	{
		for (int p = 0; p < size; p++)
		{
			cout << "Фамилия: "; 	cin >> buf.surname;
			cout << "Имя: "; 	cin >> buf.name;
			cout << "Отчество: "; 	cin >> buf.secondname;
			cout << "Количество экзаменов: "; 	cin >> buf.count;
			cout << "Средний балл: "; 	cin >> buf.mark;
			cout << endl;
			if (buf.mark >= 4) { markplus++; }
			else { markminus++; };
			fwrite(&buf, sizeof(buf), 1, f);
		}
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		system("pause");			system("cls");			return;
	}
}

void output()
{
	STUD buf;
	if (!fopen_s(&f, "marks.txt", "rb"))
	{
		cout << "\nФамилия    Имя    Отчество    Количество экзаменов    Средний балл\n";
		fread(&buf, sizeof(buf), 1, f);
		while (!feof(f))
		{
			cout << buf.surname << "\t    " << buf.name << "\t  " << buf.secondname << "\t    " << buf.count << "\t \t       " << buf.mark << endl;
			fread(&buf, sizeof(buf), 1, f);
			if (buf.mark >= 4) { markplus++; }
			else { markminus++; };
		}
		cout << endl;
		fclose(f);
		system("pause");			system("cls");
	}
	else
	{
		cout << "Ошибка открытия файла";
		system("pause");			system("cls"); return;
	}
}

void find(char lastName[16])
{
	bool flag = false;  STUD buf;
	if (!fopen_s(&f, "marks.txt", "rb"))
	{
		markplus = 0; markminus = 0;
		while (!feof(f))
		{
			fread(&buf, sizeof(buf), 1, f);
			if (strcmp(lastName, buf.surname) == 0)   //сравнение строк
			{
				cout << "\nФамилия    Имя    Отчество    Количество экзаменов    Средний балл\n";
				cout << buf.surname << "\t    " << buf.name << "\t  " << buf.secondname << "\t    " << buf.count << "\t \t   " << buf.mark << endl;
				flag = true; break;
			}
		}
		fclose(f);
		if (!flag) cout << "Ничего не найдено\n";
	}
	else {cout << "Ошибка открытия файла"; return;}
}