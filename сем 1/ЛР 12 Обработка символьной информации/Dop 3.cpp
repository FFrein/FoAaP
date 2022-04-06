#include <iostream>
#include <windows.h>
using namespace std;

void main() {
	setlocale(LC_ALL, "RUS");
	char string[] = "HOW DO YOU DO";
	int word = 0, letter = 0;
	char string_with_change[25];
	for (int i = 0, letterNum = 0; i < strlen(string); i += letter + 1, letter = 0) {
		for (int j = i; ; j++) {
			letter++;
			if (string[j + 1] == ' ' || string[j + 1] == '\0') {
				word++;
				break;
			}
		}
		if (word % 2 == 1)
			continue;
		else
			for (int j = i + letter - 1; j >= i; j--, letterNum++) {
				string_with_change[letterNum] = string[j];
				if (letter - 1 == letterNum)
					string_with_change[++letterNum] = ' ';
			}
		if (word == 4) {
			string_with_change[letterNum] = '\0';
		}
	}
	cout << string_with_change;
}