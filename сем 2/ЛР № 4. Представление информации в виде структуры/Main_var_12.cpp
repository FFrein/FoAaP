#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <string.h>

struct State {
	char presidentSecondName[30], capital[30], StateName[30], population[30], area[30];
};

void main() {

	State state[4];

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	const int const_size = 4;
	int rows = 0, size = const_size, choice, c = 0, string_longest, space = 0, symbol_counter = 0;
	char buff[256], buff2[50], search[30];
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
				std::cin.ignore(32767, '\n'); // удаляем все
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
				std::cout << "Country Number: " << i + 1 << std::endl;
				SetConsoleTextAttribute(console, 15);
				std::cout << "Input State Name: "; std::cin >> state[i].StateName;	
				std::cout << "Input Capital: ";	std::cin >> state[i].capital;
				std::cout << "Input President Second Name: "; std::cin >> state[i].presidentSecondName;
				std::cout << "Input State Population: "; std::cin >> state[i].population;
				std::cout << "Input State Area: ";	std::cin >> state[i].area;
			}
			break;

		case 2:
			do {
				std::cout << "What are we deleting? : ";
				std::cin >> choice;
				if (choice > const_size || choice == NULL) {
					std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
					std::cin.ignore(32767, '\n'); // удаляем все
					SetConsoleTextAttribute(console, 12);
					std::cout << std::endl << "Input again" << std::endl;
					SetConsoleTextAttribute(console, 15);
					choice = NULL;
				}
				else {
					for (int de1 = (choice - 1); de1 < const_size; de1++)
						state[de1] = state[de1 + 1];
					size--;
				}
			} while (choice == NULL);	break;

		case 3:
			fout.open("FILE1.txt");
			for (int i = 0; i < size; i++) {
				fout << state[i].presidentSecondName << " " << state[i].capital << " " << state[i].StateName << " " << state[i].population << " " << state[i].area << '\n';
			}
			fout.close(); break;

		case 4:
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
					if (space == 1 && learn_checker[0] == false){
						strncpy_s(state[i].presidentSecondName, &buff[j - symbol_counter], symbol_counter);
						symbol_counter = 0;
						learn_checker[0] = true;
						std::cout << state[i].presidentSecondName << " ";
					}
					if(space == 2 && learn_checker[1] == false){
						strncpy_s(state[i].capital, &buff[j - symbol_counter + 1], symbol_counter);
						learn_checker[1] = true;
						symbol_counter = 0;
						std::cout << state[i].capital << " ";
					}
					if(space == 3 && learn_checker[2] == false){
						strncpy_s(state[i].StateName, &buff[j - symbol_counter + 1], symbol_counter);
						learn_checker[2] = true;
						symbol_counter = 0;
						std::cout << state[i].StateName << " ";
					}
					if (space == 4 && learn_checker[3] == false) {
						strncpy_s(state[i].population, &buff[j - symbol_counter + 1], symbol_counter);
						learn_checker[3] = true;
						symbol_counter = 0;
						std::cout << state[i].population << " ";
					}
					if (buff[j] == '\0' && learn_checker[4] == false) {
						strncpy_s(state[i].area, &buff[j - symbol_counter + 1], symbol_counter);
						learn_checker[4] = true;
						symbol_counter = 0;
						std::cout << state[i].area << std::endl;
					}
					symbol_counter++;
				}
				symbol_counter = 0;
				space = 0;
			}
			fout.close();	break;

		case 5:
			std::cout << "Input SecondName: ";
			std::cin >> search;
			for (int i = 0; i < size; i++) {
				if (strcmp(state[i].presidentSecondName, search) == 0) {
					std::cout << state[i].presidentSecondName << " ";
					std::cout << state[i].capital << " ";
					std::cout << state[i].StateName << " ";
					std::cout << state[i].population << " ";
					std::cout << state[i].area << std::endl;
				}
			}
			break;

		case 6:
			exit(0);
		}
	}
}