#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <string.h>

char globalbitbuffer[8], result[64];

union applicantscertificate {
	char NotU[64], adress[30], spec1[30], points1[256], spec2[30], points2[256];
	int money;
};

struct applicantscertificate_struct {
	char NotU[64], adress[30], spec1[30], points1[256], spec2[30], points2[256];
	int money;
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

	applicantscertificate scertificate[256];
	applicantscertificate_struct scertificate_struct[256];

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	int const_size = 4;
	int string_counter = 0, size, choice, c = 0, string_longest, space = 0, symbol_counter = 0, min = 999, checkint = 0;
	char buff[256], buff2[50], chartoint[256], search[50];
	bool learn_checker[9] = { false };
	std::ofstream fout;
	std::ifstream fin;
	for (;;) {
		system("pause");
		system("cls");

		std::cout << "Меню\n1)Ввод и Сохр файла\n2)Чтение файла\n3)Поиск по информации\n4)Выход" << std::endl;

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

			fout.open("FILE1.txt");

			std::cout << "Кол машин: " << std::endl;

			std::cin >> size;

			for (int i = 0; i < size; i++) {

				std::cout << "Марка автомобиля: ";
				std::cin >> scertificate[i].NotU;
				fout << scertificate[i].NotU << " ";

				std::cout << "Цвет: ";
				std::cin >> scertificate[i].adress;
				fout << scertificate[i].adress << " ";

				std::cout << "Заводской номер : ";
				std::cin >> scertificate[i].spec1;
				fout << scertificate[i].spec1 << " ";

				std::cout << "Владелец: ";
				std::cin >> scertificate[i].points1;
				fout << scertificate[i].points1 << " ";

				std::cout << "Тип кузова : ";
				std::cin >> scertificate[i].spec2;
				fout << scertificate[i].spec2 << " ";

				std::cout << "Дата последнего техосмотра : ";
				std::cin >> scertificate[i].points2;
				fout << scertificate[i].points2 << " ";

				std::cout << "Дата выпуска : ";
				std::cin >> scertificate[i].money;
				fout << scertificate[i].NotU << '\n';
			}

			fout.close(); break;

			break;

		case 2:

			string_counter = 0; size = 0;
			fin.open("FILE1.txt");
			for (int i = 0;; i++) {
				learn_checker[0] = false;
				learn_checker[1] = false;
				learn_checker[2] = false;
				learn_checker[3] = false;
				learn_checker[4] = false;
				learn_checker[5] = false;
				learn_checker[6] = false;
				learn_checker[7] = false;
				learn_checker[8] = false;
				fin.getline(buff, 256, '\n');
				string_longest = strlen(buff);
				if (strlen(buff) == 0)
					break;
				size++;
				for (int j = 0; j <= string_longest; j++) {
					if (buff[j] == ' ')
						space++;
					if (space == 1 && learn_checker[0] == false) {
						strncpy_s(scertificate[i].NotU, &buff[j - symbol_counter], symbol_counter);
						symbol_counter = 0;
						learn_checker[0] = true;
						std::cout << "Марка : " << scertificate[i].NotU << std::endl;
					}
					if (space == 2 && learn_checker[1] == false) {
						strncpy_s(scertificate[i].adress, &buff[j - symbol_counter + 1], symbol_counter);
						learn_checker[1] = true;
						symbol_counter = 0;
						std::cout << "Цвет : " << scertificate[i].adress << std::endl;
					}
					if (space == 3 && learn_checker[2] == false) {
						strncpy_s(scertificate[i].spec1, &buff[j - symbol_counter + 1], symbol_counter);
						learn_checker[2] = true;
						symbol_counter = 0;
						specialti = speceal1;
						std::cout << "Заводской номер " << specialti << " : " << scertificate[i].spec1 << std::endl;
					}
					if (space == 4 && learn_checker[3] == false) {
						strncpy_s(scertificate[i].points1, &buff[j - symbol_counter + 1], symbol_counter);
						learn_checker[3] = true;
						symbol_counter = 0;
						std::cout << "Владелец: " << scertificate[i].points1 << std::endl;
					}
					if (space == 5 && learn_checker[4] == false) {
						strncpy_s(scertificate[i].spec2, &buff[j - symbol_counter + 1], symbol_counter);
						learn_checker[4] = true;
						symbol_counter = 0;
						specialti = speceal2;
						std::cout << "Тип кузова : " << specialti << " : " << scertificate[i].spec2 << std::endl;
					}
					if (space == 6 && learn_checker[5] == false) {
						strncpy_s(scertificate[i].points2, &buff[j - symbol_counter + 1], symbol_counter);
						learn_checker[5] = true;
						symbol_counter = 0;
						std::cout << "Дата последнего техосмотра : " << scertificate[i].points2 << std::endl;
					}
					if (buff[j] == '\0' && learn_checker[8] == false) {
						strncpy_s(chartoint, &buff[j - symbol_counter + 1], symbol_counter);
						scertificate[i].money = atoi(chartoint);
						learn_checker[8] = true;
						symbol_counter = 0;
						std::cout << "Дата выпуска : " << scertificate[i].money << "\n" << std::endl;
					}
					symbol_counter++;
				}
				symbol_counter = 0;
				space = 0;
			}
			fin.close();	break;

		case 3:

			string_counter = 0; size = 0;
			fin.open("FILE1.txt");
			for (int i = 0;; i++) {
				learn_checker[0] = false;
				learn_checker[1] = false;
				learn_checker[2] = false;
				learn_checker[3] = false;
				learn_checker[4] = false;
				learn_checker[5] = false;
				learn_checker[6] = false;
				learn_checker[7] = false;
				learn_checker[8] = false;
				fin.getline(buff, 256, '\n');
				string_longest = strlen(buff);
				if (strlen(buff) == 0)
					break;
				size++;
				for (int j = 0; j <= string_longest; j++) {
					if (buff[j] == ' ')
						space++;
					if (space == 1 && learn_checker[0] == false) {
						strncpy_s(scertificate_struct[i].NotU, &buff[j - symbol_counter], symbol_counter);
						symbol_counter = 0;
						learn_checker[0] = true;
					}
					if (space == 2 && learn_checker[1] == false) {
						strncpy_s(scertificate_struct[i].adress, &buff[j - symbol_counter + 1], symbol_counter);
						learn_checker[1] = true;
						symbol_counter = 0;
					}
					if (space == 3 && learn_checker[2] == false) {
						strncpy_s(scertificate_struct[i].spec1, &buff[j - symbol_counter + 1], symbol_counter - 1);
						learn_checker[2] = true;
						symbol_counter = 0;
					}
					if (space == 4 && learn_checker[3] == false) {
						strncpy_s(scertificate_struct[i].points1, &buff[j - symbol_counter + 1], symbol_counter - 1);
						learn_checker[3] = true;
						symbol_counter = 0;
					}
					if (space == 5 && learn_checker[4] == false) {
						strncpy_s(scertificate_struct[i].spec2, &buff[j - symbol_counter + 1], symbol_counter - 1);
						learn_checker[4] = true;
						symbol_counter = 0;
					}
					if (space == 6 && learn_checker[5] == false) {
						strncpy_s(scertificate_struct[i].points2, &buff[j - symbol_counter + 1], symbol_counter - 1);
						learn_checker[5] = true;
						symbol_counter = 0;
					}

					if (buff[j] == '\0' && learn_checker[8] == false) {
						strncpy_s(chartoint, &buff[j - symbol_counter + 1], symbol_counter);
						scertificate_struct[i].money = atoi(chartoint);
						learn_checker[8] = true;
						symbol_counter = 0;
					}
					symbol_counter++;
				}
				symbol_counter = 0;
				space = 0;
			}
			fin.close();
			
			fin.open("FILE1.txt");
			std::cout << "Введите информацию: ";
			std::cin >> search;
			for (int i = 0; i < size; i++) {
				fin.getline(buff, 256, '\n');
				if (checker_word(buff, search) == true) {
					std::cout << scertificate_struct[i].NotU << std::endl;
					std::cout << scertificate_struct[i].adress << std::endl;
					std::cout << scertificate_struct[i].spec1 << std::endl;
					std::cout << scertificate_struct[i].points1 << std::endl;
					std::cout << scertificate_struct[i].spec2 << std::endl;
					std::cout << scertificate_struct[i].points2 << std::endl;
					std::cout << scertificate_struct[i].money << std::endl;
				}
			}
			fin.close();
			break;

		case 4:
			exit(0);
		}
	}
}