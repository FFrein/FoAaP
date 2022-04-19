//Ф.И.О. работника, образование, специальность, подразделение, должность, оклад, дата поступления на пред-приятие

#include <iostream>  
#include<fstream>
using namespace std;
struct peple
	{
		char name[256];
		char aducation[256];
		char spec[256];
		char podr[256];
		int oklad;
		char dolg[256];
		unsigned  data : 25;
	};
struct peple inform[256];

enum dolgnost
{
	engineer=1, mathematician, teacher
} prof;
int kol;
int l;
int  choose;
peple b[15] ;
float sp[3];
int zn[15];
void vvod() {
	

	cout << "Введите количество работников: ";
	cin >> kol;
	for (int i = 0; i < kol; i++) {
		cout << "\n\nСотрудник номер " << i + 1;
		cout << "\nВведите ФИО сотрудника: ";
		cin >> inform[i].name;
		cout << "Введите образование сотрудника: ";
		cin >> inform[i].aducation;
		cout << "Введите специальность сотрудника: ";
		cin >> inform[i].spec;
		cout << "Введите подразделение сотрудника: ";
		cin >> inform[i].podr;
		cout << "Введите оклад сотрудника: ";
		cin >> inform[i].oklad;
		cout << "\nВыберите должность, если инжинер введиту 1, если математик -2, учитель -3\n ";
		cin >> zn[i];
		if (zn[i] == engineer) {
			cout << "\nВыбранная должность: инжинер\n ";
		}

		if (zn[i] == mathematician)
			cout << "\nВыбранная должность: математик \n";
		if (zn[i] == teacher)
			cout << "\nВыбранная должность: учитель\n ";
		cout << "Введите дату: ";
		cin >> l;
		b[i].data = l;
	}
}
void putout() {
	for (int i = 0; i < kol; i++) {
		cout << "\n\nСотрудник номер " << i + 1;
		cout << "\nФио сотрудника  " << inform[i].name;
		cout << "\nОбразование сотрудника " << inform[i].aducation;
		cout<<"\n специальность сотрудника  "<< inform[i].spec;
		cout<<"\n  подразделение сотрудника  "<< inform[i].podr;
		cout<<"\n оклад сотрудника "<< inform[i].oklad;
		if (zn[i] == engineer) {
			cout << "\nдолжность: инжинер ";
		}
		if (zn[i] == mathematician)
			cout << "\nдолжность: математик ";
		if (zn[i] == teacher)
			cout << "\nдолжность: учитель ";
		cout << "\nДата " << b[i].data;
	
	}
}
void delit() {
	int c;
	cout << "Информацию о каком сотрудниике хотите удалить ";
	cin >> c;
	int i = c- 1;
	for (i; i < kol; i++)
		inform[i] = inform[i + 1];
	kol = kol - 1;
}
void poisk() {
	int i, c;
	cout << "Информацию о каком сотруднике нужно получить? ";
	cin >> c;
	i = c - 1;
		cout << "\n\nСотрудник номер " << c ;
		cout << "\nФио сотрудника  " << inform[i].name;
		cout << "\nОбразование сотрудника " << inform[i].aducation;
		cout << "\n специальность сотрудника  " << inform[i].spec;
		cout << "\n  подразделение сотрудника  " << inform[i].podr;
		cout << "\n оклад сотрудника " << inform[i].oklad;
		if (zn[i] == engineer) {
			cout << "\nдолжность: инжинер ";
		}
		if (zn[i] == mathematician)
			cout << "\nдолжность: математик ";
		if (zn[i] == teacher)
			cout << "\nдолжность: учитель ";
		cout << "\nДата " << l;
}


int main() {
	setlocale(LC_CTYPE, "ru");
	const int SIZE = 7;

	do {
		cout << "\nВыберите, что сделать:\n1 — Ввод информации ;\n2 — вывести в консоль информацию о сотруднике;\n3 — удалить информацию о сотруднике;\n4 — поиск информации.\n 5-выход из программы\n";
		cin >> choose;
		switch (choose)
		{
		case 1: vvod() ; break;
		case 2: putout(); break;
		case 3:delit(); break;
		case 4:poisk(); break;
		case 5: break;
		}
	} while (choose != 5);
}