#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;
/*алгоритм проверки есть ли в строке 1 строка 2, если да выводит true*/
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
		else if(a == strlen(buff)) {
			return false;
		}
		
	}
}

int main() 
{
	using namespace std;
	setlocale(LC_ALL, "ru");
	ifstream fout; //открывает объекта fout для записи в файл
	fout.open("FILE1.txt"); // создание файла с названием FILE1.txt
	/*
	//Создание файла и вписывание информации
	ofstream fout; //создание объекта fout для записи в файл
	fout.open("FILE1.txt"); // создание файла с названием FILE1.txt
	if (!fout.is_open()) // если файл не открылся имеет значение false
		cout << "Ошибка открытия" << endl;
	else
		fout << "well hight low small\nhight low well\nlow well small\nmid light low"; //запись в файл 
	fout.close(); //закрытие файла
	*/

	/*Чтение информации из файла */
	char buff[256];
	ifstream fin; //создание объекта fcin для чтения файла
	fin.open("FILE1.txt"); //открытие файла для чтения
	if (!fin.is_open()) 
	{ 
		cout << "Ошибка открытия" << endl;
	}
	else
	{
		// Получение первого слова
		char first_word[80];
		int rows = 0 ;
		//cout << "Файл открыт!" << endl;
		fin >> first_word; // запись первого слова из файла
		cout << "first_word: " << first_word << endl;
		for (;;) { //подсчёт строк в файле
			fin.getline(buff, 256);
			rows++;
			if (fin.eof()) break;// алгоритм выключится, когда закончатся строки
		}
		fin.close(); //закрытие файла



		//алгоритм поиска слова в строках и подсчёт сколько гласных в последнем ряду
		fin.open("FILE1.txt");
		ofstream fout;
		fout.open("FILE2.txt");
		for (; fin;) {
			fin.getline(buff, 256);
			if (checker_word(buff, first_word) == true) {
				fout << buff << "\n";
				cout << buff << endl;
			}
		}

		//подсчёт согласных в строке
	
	}
	fin.close(); //закрытие файла 1
	fout.close(); //закрытие файла 2

	//подсчёт гласных в последней строке

	fin.open("FILE2.txt"); //открытие файла2 для чтения

	char buff2[256];
	int rows = 0;
	char massiv_glasnih[] = { 'q', 'w', 'r', 't', 'p', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c' ,'v' ,'b', 'n', 'm' };
	int cont_soglasnih = 0;
	int rows_checker = 1;
	for (;;) { //подсчёт строк в файле
		fin.getline(buff2, 256);
		if (fin.eof()) break;// алгоритм выключится, когда закончатся строки
		rows++;
	}

	fin.close(); //переоткрытие для перехода на новую стркоу(мне было в падлу делать нормально)
	fin.open("FILE2.txt");

	for (;;) {
		if (rows_checker > rows) {
			for (int letter = 0;; letter++) {
				for (int a = 0; a < 20; a++) {
					if (buff2[letter] == massiv_glasnih[a] || (int)buff2[letter] == ((int)massiv_glasnih[a] - 20)) {
						cont_soglasnih++;
					}
				}
				if (buff2[letter] == '\0') {
					break;
				}
			}
			cout << cont_soglasnih << endl;
			break;
		}
		fin.getline(buff2, 256);
		rows_checker++;
	}
	fin.close();
	return 0;
}