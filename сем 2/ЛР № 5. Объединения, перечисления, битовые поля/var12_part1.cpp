#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <string.h>

char globalbitbuffer[8], result[64];

struct byte22//объ€вление битов
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

void convertstring(char convertinfo[8]){
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

struct Notebook {
	char FIO[64], adress[30], work_or_study[30], mobile[30], birthday[264];
};

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

	Notebook notebook[4];

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	int const_size = 4;
	int rows = 0, size = const_size, choice, c = 0, string_longest, space = 0, symbol_counter = 0;
	char buff[256], buff2[50], search[30], conversionstring[8];
	bool learn_checker[5] = { false };

	std::ofstream fout;
	std::ifstream fin;
	for (;;) {
		system("pause");
		system("cls");
		SetConsoleTextAttribute(console, 3);
		std::cout << "Interface\n1)Input\n2)Deleting\n3)Save Information\n4)Read Information\n5)Find Information\n6)Exit" << std::endl;
		SetConsoleTextAttribute(console, 10);
		do {
			std::cin >> c;
			if (c > 6 || c < 0 || c == NULL) {
				std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
				std::cin.ignore(32767, '\n'); // удал€ем все
				SetConsoleTextAttribute(console, 12);
				std::cout << std::endl << "Input again" << std::endl;
				SetConsoleTextAttribute(console, 15);
				c = NULL;
			}
		} while (c == NULL);

		switch (c) {

		case 1:
			for (int i = 0; i < const_size; i++) {
				SetConsoleTextAttribute(console, 10);
				std::cout << "People Number: " << i + 1 << std::endl;
				SetConsoleTextAttribute(console, 15);
				std::cout << "Input FIO: "; std::cin >> notebook[i].FIO;
				std::cout << "Input adress: ";	std::cin >> notebook[i].adress;
				std::cout << "Input place of work or study : "; std::cin >> notebook[i].work_or_study;
				std::cout << "Input Mobile number: "; std::cin >> notebook[i].mobile;
				std::cout << "Input birthday: ";	std::cin >> conversionstring; convertstring(conversionstring); strncpy_s(notebook[i].birthday, result, 64);
			}
			break;

		case 2:
			do {
				std::cout << "What are we deleting? : ";
				std::cin >> choice;
				if (choice > const_size || choice == NULL) {
					std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
					std::cin.ignore(32767, '\n'); // удал€ем все
					SetConsoleTextAttribute(console, 12);
					std::cout << std::endl << "Input again" << std::endl;
					SetConsoleTextAttribute(console, 15);
					choice = NULL;
				}
				else {
					for (int de1 = (choice - 1); de1 < const_size; de1++)
						notebook[de1] = notebook[de1 + 1];
					size--;
				}
			} while (choice == NULL);	break;
			
		case 3:
			fout.open("FILE1.txt");
			for (int i = 0; i < size; i++) {
				fout << notebook[i].FIO << " " << notebook[i].adress << " " << notebook[i].work_or_study << " " << notebook[i].mobile << " " << notebook[i].birthday << '\n';
			}
			fout.close(); break;

		case 4:
			//плохой код
			fin.open("FILE1.txt");
			for (int i = 0; i < size; i++) {
				learn_checker[0] = false;
				learn_checker[1] = false;
				learn_checker[2] = false;
				learn_checker[3] = false;
				learn_checker[4] = false;
				fin.getline(buff, 256, '\n');
				string_longest = strlen(buff);
				for (int j = 0; j <= string_longest; j++) {
					if (buff[j] == ' ')
						space++;
					if (space == 1 && learn_checker[0] == false) {
						strncpy_s(notebook[i].FIO, &buff[j - symbol_counter], symbol_counter);
						symbol_counter = 0;
						learn_checker[0] = true;
						std::cout << notebook[i].FIO << " ";
					}
					if (space == 2 && learn_checker[1] == false) {
						strncpy_s(notebook[i].adress, &buff[j - symbol_counter + 1], symbol_counter);
						learn_checker[1] = true;
						symbol_counter = 0;
						std::cout << notebook[i].adress << " ";
					}
					if (space == 3 && learn_checker[2] == false) {
						strncpy_s(notebook[i].work_or_study, &buff[j - symbol_counter + 1], symbol_counter);
						learn_checker[2] = true;
						symbol_counter = 0;
						std::cout << notebook[i].work_or_study << " ";
					}
					if (space == 4 && learn_checker[3] == false) {
						strncpy_s(notebook[i].mobile, &buff[j - symbol_counter + 1], symbol_counter);
						learn_checker[3] = true;
						symbol_counter = 0;
						std::cout << notebook[i].mobile << " ";
					}
					if (buff[j] == '\0' && learn_checker[4] == false) {
						strncpy_s(notebook[i].birthday, &buff[j - symbol_counter + 1], symbol_counter);
						learn_checker[4] = true;
						symbol_counter = 0;
						std::cout << notebook[i].birthday << std::endl;
					}
					symbol_counter++;
				}
				symbol_counter = 0;
				space = 0;
			}
			fin.close();	break;

		case 5:
			fin.open("FILE1.txt");
			std::cout << "Input info: ";
			std::cin >> search;
			for (int i = 0; i < size; i++) {
				fin.getline(buff, 256, '\n');
				if (checker_word(buff, search) == true) {
					std::cout << notebook[i].FIO << " ";
					std::cout << notebook[i].adress << " ";
					std::cout << notebook[i].work_or_study << " ";
					std::cout << notebook[i].mobile << " ";
					std::cout << notebook[i].birthday << std::endl;
				}
			}
			fin.close();
			break;

		case 6:
			exit(0);
		}
	}
}