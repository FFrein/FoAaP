//Ввести с клавиатуры строку символов, состоящую из слов, разделенных пробелами, и записать ее в файл. Прочитать из файла данные и вывести все слова, которые содержат букву «х».
#include <iostream>
#include <unordered_set>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
int main() {
	setlocale(LC_ALL, "RUS");
	FILE* F1;
	int i = 0;
	char str[255];
	errno_t err;
	err = fopen_s(&F1, "FILE1.txt", "w");
	fflush(stdin);
	printf("Введите строку: \n");
	gets_s(str);
	fputs(str, F1);
	fputs("\n", F1);
	fclose(F1);
	err = fopen_s(&F1, "FILE1.txt", "r");
	char c = 'x';
	char S[255];
	fgets(S, 255, F1);
	istringstream ist(S);
	string tmp;
	while (ist >> tmp) {
		i = 0;
		while (tmp[i]) {
			if (tmp[i] == c) {
				cout << tmp << endl;
				break;
			}
			i++;
		}

	}
}

