#include <stdio.h>
#include <cstring>
#include <string>
#include <string.h>
#include <sstream>
#include <iostream>
#include <windows.h>
using namespace std;
void func(string str, string s, int poz, int dl)
{
	str.assign(s, poz - 1, dl); // пишем слово

	cout << "\nВыделенная часть: " << str;
}

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int k = 0, n = 0, rez, poz, dl;
	setlocale(LC_CTYPE, "Russian");
	string s, str;
	SetConsoleTextAttribute(hConsole, 14);
	cout << "Предложение: " << endl;

	getline(cin, s);

	cout << "позиция: " << endl;
	cin >> poz;
	cout << "длина: " << endl;
	cin >> dl;
	SetConsoleTextAttribute(hConsole, 13);
	func(str, s, poz, dl);
	SetConsoleTextAttribute(hConsole, 15);
}
