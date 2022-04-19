#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <string.h>

char globalbitbuffer[8], result[64];

struct byte22//объявление битов
{
	unsigned a1 : 1;
	unsigned b1 : 1;
	unsigned c1 : 1;
	unsigned d1 : 1;
	unsigned e1 : 1;
	unsigned f1 : 1;
	unsigned g1 : 1;
	unsigned h1 : 1;
};

union bits
{
	char ch;
	struct byte22 bit;
} ascii;

void disp_bits(bits b)
{
	if (b.bit.h1) globalbitbuffer[7] = '1';  else globalbitbuffer[7] = '0';
	if (b.bit.g1) globalbitbuffer[6] = '1';  else globalbitbuffer[6] = '0';
	if (b.bit.f1) globalbitbuffer[5] = '1';  else globalbitbuffer[5] = '0';
	if (b.bit.e1) globalbitbuffer[4] = '1';  else globalbitbuffer[4] = '0';
	if (b.bit.d1) globalbitbuffer[3] = '1';  else globalbitbuffer[3] = '0';
	if (b.bit.c1) globalbitbuffer[2] = '1';  else globalbitbuffer[2] = '0';
	if (b.bit.b1) globalbitbuffer[1] = '1';  else globalbitbuffer[1] = '0';
	if (b.bit.a1) globalbitbuffer[0] = '1';  else globalbitbuffer[0] = '0';
}

void convertstring(char convertinfo[8]) {
	int count = 0;
	for (int i = 0; i < strlen(convertinfo); i++)
	{
		ascii.ch = convertinfo[i];
		disp_bits(ascii);

		for (int i = 0; i < 8; i++, count++) {
			result[count] = globalbitbuffer[i];
		}

		/*for (;;) {
			letter = 0;
			if (str[0] == '1') letter += 1;
			if (str[1] == '1') letter += 2;
			if (str[2] == '1') letter += 4;
			if (str[3] == '1') letter += 8;
			if (str[4] == '1') letter += 16;
			if (str[5] == '1') letter += 32;
			if (str[6] == '1') letter += 64;
			if (str[7] == '1') letter += 128;
			cout << letter << endl;
			break;
		}*/ //дишифратор
	}
}

struct lombard {
	char SecondName[64], productname[30], estimatedcost[30], amount[256], sell_date[256], storagedata[30];
};

enum specialties {
	speceal1 = 1, speceal2, speceal3
} specialti;

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

void main() {

	setlocale(LC_CTYPE, "Russian");

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	int const_size = 4;
	int string_counter = 0, size, rows = 0, choice, c = 0, string_longest, space = 0, symbol_counter = 0;
	char buff[256], buff2[50], search[30], conversionstring[8];
	bool learn_checker[6] = { false };
	std::ofstream fout;
	std::ifstream fin;
	for (;;) {
		system("pause");
		system("cls");

		lombard scertificate[256];

		std::cout << "Меню\n1)Ввод\n2)Удаление\n3)Сохр файла\n4)Чтение файла\n5)Поиск по информации\n6)Выход" << std::endl;

		do {
			std::cin >> c;
			if (c > 6 || c < 0 || c == NULL) {
				std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
				std::cin.ignore(32767, '\n'); // удаляем все

				std::cout << std::endl << "Введите снова" << std::endl;

				c = NULL;
			}
		} while (c == NULL);

		switch (c) {

		case 1:

			std::cout << "Кол кол клиентов: " << std::endl;

			std::cin >> size;

			for (int i = 0; i < size; i++) {

				std::cout << "Название Фамилию: ";
				std::cin >> scertificate[i].SecondName;

				std::cout << "Введите товар: ";
				std::cin >> scertificate[i].productname;

				std::cout << "Введите оценочную стоимость : ";
				std::cin >> scertificate[i].estimatedcost;

				std::cout << "Введите выданную сумму : ";
				std::cin >> scertificate[i].amount;

				std::cout << "Введите дату сдачи : ";
				std::cin >> conversionstring;
				convertstring(conversionstring);
				strncpy_s(scertificate[i].sell_date, result, 64);

				std::cout << "Введите время хранения : ";
				std::cin >> scertificate[i].storagedata;
			}
			break;

		case 2:
			do {
				std::cout << "Номер удаляемой строки? : ";
				std::cin >> choice;
				if (choice > size || choice == NULL) {
					std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
					std::cin.ignore(32767, '\n'); // удаляем все
					std::cout << std::endl << "Введите снова" << std::endl;
					choice = NULL;
				}
				else {
					for (int de1 = (choice - 1); de1 < const_size; de1++)
						scertificate[de1] = scertificate[de1 + 1];
					size--;
				}
			} while (choice == NULL);	break;

		case 3:
			fout.open("FILE1.txt");
			for (int i = 0; i < size; i++) {
				fout << scertificate[i].SecondName << " " << scertificate[i].productname << " " << scertificate[i].estimatedcost << " " << scertificate[i].amount << " " << scertificate[i].sell_date << " " << scertificate[i].storagedata << '\n';
			}
			fout.close(); break;

		case 4:
			string_counter = 0; size = 0;
			fin.open("FILE1.txt");
			for (int i = 0;; i++) {
				learn_checker[0] = false;
				learn_checker[1] = false;
				learn_checker[2] = false;
				learn_checker[3] = false;
				learn_checker[4] = false;
				learn_checker[5] = false;
				fin.getline(buff, 256, '\n');
				string_longest = strlen(buff);
				if (strlen(buff) == 0)
					break;
				size++;
				for (int j = 0; j <= string_longest; j++) {
					if (buff[j] == ' ')
						space++;
					if (space == 1 && learn_checker[0] == false) {
						strncpy_s(scertificate[i].SecondName, &buff[j - symbol_counter], symbol_counter);
						symbol_counter = 0;
						learn_checker[0] = true;
						std::cout << "Фамилия : " << scertificate[i].SecondName << std::endl;
					}
					if (space == 2 && learn_checker[1] == false) {
						strncpy_s(scertificate[i].productname, &buff[j - symbol_counter + 1], symbol_counter);
						learn_checker[1] = true;
						symbol_counter = 0;
						std::cout << "Название товара : " << scertificate[i].productname << std::endl;
					}
					if (space == 3 && learn_checker[2] == false) {
						strncpy_s(scertificate[i].estimatedcost, &buff[j - symbol_counter + 1], symbol_counter);
						learn_checker[2] = true;
						symbol_counter = 0;
						std::cout << "Оценочная стоимость" << scertificate[i].estimatedcost << std::endl;
					}
					if (space == 4 && learn_checker[3] == false) {
						strncpy_s(scertificate[i].amount, &buff[j - symbol_counter + 1], symbol_counter);
						learn_checker[3] = true;
						symbol_counter = 0;
						std::cout << "Выданная сумма : " << scertificate[i].amount << std::endl;
					}
					if (space == 5 && learn_checker[4] == false) {
						strncpy_s(scertificate[i].sell_date, &buff[j - symbol_counter + 1], symbol_counter);
						learn_checker[4] = true;
						symbol_counter = 0;
						std::cout << "День сдачи : " << scertificate[i].sell_date << std::endl;
					}
					if (buff[j] == '\0' && learn_checker[8] == false) {
						strncpy_s(scertificate[i].storagedata, &buff[j - symbol_counter + 1], symbol_counter);
						learn_checker[8] = true;
						symbol_counter = 0;
						std::cout << "Время хранения : " << scertificate[i].storagedata << "\n" << std::endl;
					}
					symbol_counter++;
				}
				symbol_counter = 0;
				space = 0;
			}
			fin.close();	break;

		case 5:
			fin.open("FILE1.txt");
			std::cout << "Введите информацию: ";
			std::cin >> search;
			for (int i = 0; i < size; i++) {
				fin.getline(buff, 256, '\n');
				if (checker_word(buff, search) == true) {
					std::cout << scertificate[i].SecondName << std::endl;
					std::cout << scertificate[i].productname << std::endl;
					std::cout << scertificate[i].estimatedcost << std::endl;
					std::cout << scertificate[i].amount << std::endl;
					std::cout << scertificate[i].sell_date << std::endl;
					std::cout << scertificate[i].storagedata << std::endl;
				}
			}
			fin.close();
			break;

		case 6:
			exit(0);
		}
	}
}