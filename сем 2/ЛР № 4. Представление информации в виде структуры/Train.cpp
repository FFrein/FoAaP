#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

typedef struct Train
{
	char city[16], num[16], date[16];
	int dateh, datem;
};
int number;

typedef struct Buffer_List
{
	char buff[256];
};

char first_buffer[256], datebuffer[5];
int list_counter = 1, string_longest;

int checker_word(char buff[256], char word[256]) {
	int checker = 1, checkpoint = strlen(word);
	for (int a = 1, b = 1; a < 256; a++) {
		if (word[b] == buff[a]) {
			checker++;
			b++;
		}
		if (buff[a] != word[b - 1] and a > 1) {
			b = 1;
		}
		if (checker == checkpoint) {
			return true;
		}
		else if (a == strlen(buff)) {
			return false;
		}

	}
}

void input(int size)
{
	list_counter = 1;
	Buffer_List buffer[256];
	ifstream fin; //чтение
	cout << "\nВведите данные в формате:\n Название рейса номер рейса время рейса\n (Гродно-Минск_000_00:00)\n";

	fin.open("train.txt");

	for (;; list_counter++) {
		fin.getline(first_buffer, 256, '\n');
		string_longest = strlen(first_buffer);
		if (string_longest == 0)
			break;
		strncpy_s(buffer[list_counter].buff, first_buffer, string_longest);
	}

	for (int i = 1; i <= size; list_counter++, i++) {
		cin >> buffer[list_counter].buff;
	}

	fin.close();

	//фильтрация по алфавиту 
	for (int i = 1; i < list_counter; i++) {
		for (int j = 1; j < list_counter; j++) {
			if (strcmp(buffer[i].buff, buffer[j].buff) < 0)
				swap(buffer[i].buff, buffer[j].buff);
		}
	}


	ofstream fout;
	fout.open("train.txt");

	for (int i = 1; i < list_counter; i++) {
		fout << buffer[i].buff << '\n';
	}

	fout.close();

}

void output()
{
	ifstream fin;
	fin.open("train.txt");
	cout << "\nПункт назначения    Номер рейса    Время отправления\n";
	for (;; list_counter++) {
		fin.getline(first_buffer, 256, '\n');
		string_longest = strlen(first_buffer);
		if (string_longest == 0)
			break;
		cout << first_buffer << endl;
	}
	fin.close();
}

void finds()//поиск по месту
{
	ifstream fin;

	fin.open("train.txt");
	for (;; list_counter++) {
		fin.getline(first_buffer, 256, '\n');
		string_longest = strlen(first_buffer);
		if (string_longest == 0)
			break;
	}
	fin.close();

	fin.open("train.txt");
	char city[16];
	cin >> city;
	for (int i = 1; i < list_counter; i++) {
		fin.getline(first_buffer, 256, '\n');
		if (checker_word(first_buffer, city) == true) {
			cout << first_buffer << endl;
		}
	}
	fin.close();
}

void findh()//поиск по времени
{
	char date[6], checkdate[5];
	ifstream fin;
	fin.open("train.txt");
	cin >> date;
	date[5] = '\0';
	for (;;) {
		fin.getline(first_buffer, 256, '\n');
		string_longest = strlen(first_buffer);
			for (int i = 5; i > 0; i--) {
				checkdate[5 - i] = first_buffer[string_longest - i];
			}
		//checkdate = first_buffer[string_longest];
		if (string_longest <= 0)
			break;
		//strncpy_s(checkdate, datebuffer, 5);
		if (strcmp(date, checkdate) < 0) {
			cout << first_buffer << endl;
		}
	}
	fin.close();
}


int main()
{
	//стереть // снизу если файл отсутствует, потом закоментить и перезапустить
	//ofstream fout;	fout.open("train.txt");	fout.close();

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
	int choice; char city[16];
	do
	{

		cout << "\n1. Ввод данных с клавиатуры и запись в файл\n";
		cout << "2. Вывод данных из файла\n";
		cout << "3. Поиск по пункту назначения\n";
		cout << "4. Поиск позже определенного времени отправления\n";
		cout << "0. Выход из программы\n\n";
		cout << "Введите номер операции: ";

		cin >> choice;

		switch (choice)
		{
		case 1: 
			cout << "Введите количество рейсов, информацию о которых вы хотите ввести: ";
			cin >> number;
			input(number);
			cout << endl; 
			system("pause");			
			system("cls"); break;

		case 2: 
			output(); 
			system("pause");			
			system("cls"); break;

		case 3:  
			cout << "Введите пункт назначения: ";
			finds();
			system("pause");			
			system("cls"); break;

		case 4: 
			cout << "Введите время отправления (00:00): ";
			findh();
			system("pause");			
			system("cls"); 
			break;

		case 0: 
			exit(0);  
			break;
		}
	} while (choice != 0);
}