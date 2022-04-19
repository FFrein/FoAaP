#include <iostream>
#include <fstream>

using namespace std;

struct list
{
	char symbol;
	list* next;
};

void insert(list*& p, char value); //���������� ������� � ������ ������
void del(list*& p);
void printList(list* p);       //����� ������ 
void toFile(list*& p);         //������ � ����
void fromFile(list*& p);       //���������� �� �����
void menu(void);//����� ���� 
void search(list*& p);

int main()
{
	setlocale(LC_CTYPE, "Russian");
	list* first = nullptr;
	int choice; char value;
	menu();    // ������� ���� 
	cout << " ? ";
	cin >> choice;
	while (choice != 6)
	{
		switch (choice)
		{
		case 1:  	cout << "������� ������ ";
			cin >> value;
			insert(first, value);
			printList(first);
			break;
		case 2:    del(first);
			break;
		case 3:    search(first);
			break;
		case 4:    toFile(first);
			break;
		case 5:    fromFile(first);
			break;
		default:   cout << "������������ �����" << endl;
			menu(); break;
		}
		cout << "?  ";
		cin >> choice;
	}
	return 0;
}

void insert(list*& p, char value) //���������� ������� � ������ ������
{
	list* newP = new list;
	if (newP != NULL)     //���� �� �����?  
	{
		newP->symbol = value;
		newP->next = p;
		p = newP;
	}
	else
		cout << "�������� ���������� �� ���������" << endl;
}

void del(list*& p) {
	list* temp = p;
	list* prev = NULL;
	int cd;
	cout << "����� ���������� - "; cin >> cd;
	for (int i = 0; i < cd; i++) {
		prev = temp;
		temp = temp->next;
	}
	if (cd == 0) {
		p = p->next;
	}
		prev->next = temp->next;
		free(temp);
	}

void printList(list* p)  //����� ������ 
{
	if (p == NULL)
		cout << "������ ����" << endl;
	else
	{
		cout << "������:" << endl;
		while (p != NULL)
		{
			cout << "-->" << p->symbol;
			p = p->next;
		}
		cout << "-->NULL" << endl;
	}
}

void toFile(list*& p)
{
	list* temp = p;
	list buf;
	ofstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	while (temp)
	{
		buf = *temp;
		frm.write((char*)&buf, sizeof(list));
		temp = temp->next;
	}
	frm.close();
	cout << "������ ������� � ���� mList.dat\n";
}

void fromFile(list*& p)          //���������� �� �����
{
	list buf, * first = nullptr;
	ifstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	frm.read((char*)&buf, sizeof(list));
	while (!frm.eof())
	{
		insert(first, buf.symbol);
		cout << "-->" << buf.symbol;
		frm.read((char*)&buf, sizeof(list));
	}
	cout << "-->NULL" << endl;
	frm.close();
	p = first;
	cout << "\n������ ������ �� ����� mList.dat\n";
}

void search(list*& p) {
	char sy, sym;
	cout << "\n������� ������ - "; cin >> sy;
	while (p != NULL) {
		if (p->symbol == sy) {
			cout <<endl << p->symbol << " � " << sym << endl;
			return;
		}
		else {
			sym = p->symbol;
			p = p->next;
		}
	}
	cout << "\n������ �� ������.\n";
}

void menu(void)     //����� ���� 
{
	cout << "�������� �����:" << endl;
	cout << " 1 - ���� �������" << endl;
	cout << " 2 - �������� �������" << endl;
	cout << " 2 - ����� ����������" << endl;
	cout << " 4 - ������ ������ � ����" << endl;
	cout << " 5 - ������ ������ �� �����" << endl;
	cout << " 6 - �����" << endl;
}
