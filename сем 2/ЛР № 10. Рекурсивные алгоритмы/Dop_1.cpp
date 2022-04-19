#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int i, c, b = 0;

int func(int smth, int max, int* array) {
	if (!b) {
		while (i < max) {
			i++;
			b++;
		}
	}
	if (i <= smth) {
		array[c] = i;
		++i;
		c++;
		func(smth, max, array);
	}
	else {
		return c;
	}
}

int main(int argc, char* argv[])
{
	const int a = 256;
	int arr[a];

	int counter = 1;
	while (counter < a) {
		counter = counter * 10;
		cout << "count : " << counter << endl;
	}
	counter = counter / 10;
	cout << "after / " << counter << endl;
	int count = func(a, counter, arr);

	ofstream fout;
	
	fout.open("Dop_1.txt");

	for (int i = 0; i < count; i++) {
		fout << arr[i] << '\n';
		cout << arr[i] << endl;
	}
	fout.close();
	return 0;
}



/*#include <iostream>

using namespace std;

struct Chisla {
	int number;
	Chisla* next;
};

int rekursia() {
	return 0;
}

int main() {
	int count, size;
	int inputA, copyinput;
	// вводить максимум 5значное
		cin >> inputA;
		//прочесь размер числа и первое значение
		//не оптимальное чтени
		if (inputA >= 1) {
			size = 1;
		}
		if (inputA >= 10) {
			size = 2;
		}
		if (inputA >= 100) {
			size = 3;
		}
		if (inputA >= 1000) {
			size = 4;
		}
		if (inputA >= 10000) {
			size = 5;
		}
		copyinput = inputA;

	//Если число минус его десятки соти и т.д. кол цифр в числе не уменишьлось

	Chisla* plist = nullptr;   //указатель на начало списка
	Chisla* p;  int number;
	for (int counter_cicle; counter_cicle >= 9;)                 // создание списка
	{
		if (copyinput - 10 ^ size >= 10 ^ size) {
			number = 10 ^ size;
			copyinput -= 10 ^ size;
			counter_cicle++;
		}
		else {
			number = copyinput;
			counter_cicle++;
		}
		p = new Chisla;
		p->number = number;
		p->next = plist;
		plist = p;
		if (10 ^ size > copyinput && counter_cicle >= 3) {
			break;
		}
	}

	return 0;
}*/