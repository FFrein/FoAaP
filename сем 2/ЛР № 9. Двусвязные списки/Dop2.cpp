#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
const unsigned int FNAME_SIZE = 30;
const unsigned int LNAME_SIZE = 30;
const unsigned int O_SIZE = 30;

char Predmets[5][20] = { "����������: ", "������: ", "����������� ����: ", "����������� ����: ", "������� ����: " };

struct List
{
	char firstname[FNAME_SIZE];
	char lastname[LNAME_SIZE];
	char O[O_SIZE];
	int year;
	int kurs;
	int number_group;
	int Predmet[5];
	List* next;
	List* prev;
};
//-----------------------------------------------------------
int menu(void)
{
	int c;
	cout << endl;
	cout << "1. ���� �����" << endl;
	cout << "2. ����� ������" << endl;
	cout << "3. ������� & �������" << endl;
	cout << "4. �����������" << endl;
	cout << "5. ������� ���� ������" << endl;
	cout << "6. �����" << endl;
	cout << endl;
	do
	{
		cout << "��� �����: ";
		cin >> c;
	} while (c < 0 || c > 8);
	return c;
}
//-----------------------------------------------------------
void insert(List* e, List** phead, List** plast) //���������� � ����� ������
{
	List* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
//-----------------------------------------------------------
List* setElement()      // �������� �������� � ���� ��� �������� � ���������� 
{
	List* temp = new  List();
	if (!temp)
	{
		cerr << "������ ��������� ������ ������";
		return NULL;
	}
	cout << "������� �������: ";
	cin.ignore(1);
	cin.getline(temp->lastname, LNAME_SIZE - 1, '\n');
	cout << "������� ���: ";
	cin.getline(temp->firstname, FNAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "������� �������: ";
	cin.getline(temp->O, O_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "��� ��������: ";
	cin >> temp->year;
	cout << "����: ";
	cin >> temp->kurs;
	cout << "����� ������: ";
	cin >> temp->number_group;
	cout << "\t������" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < sizeof(Predmets[i]); j++)
		{
			cout << Predmets[i][j];
		}
		cin >> temp->Predmet[i];
	}
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//-------------------------------------------------
void outputList(List** phead, List** plast)      //����� ������ �� �����
{
	int i = 1;
	List* t = *phead;
	while (t)
	{
		cout << i << ". " << endl << endl << "���: " << t->lastname << " " << t->firstname << " " << t->O << endl;
		cout << "��� ��������: " << t->year << endl;
		cout << "����: " << t->kurs << ", ������ - " << t->number_group << endl << endl;
		cout << "\t������" << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < sizeof(Predmets[i]); j++)
			{
				cout << Predmets[i][j];
			}
			cout << t->Predmet[i] << endl;
		}
		t = t->next;
		i++;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------
void mx_mn(List** phead)
{
	int min, max;

	List* t = *phead, * pn = *phead, * pm = *phead;
	min = t->year;
	max = t->year;
	t = t->next;
	while (t)
	{
		if (t->year < min)
		{
			min = t->year;
			pn = t;
		}
		if (t->year > max)
		{
			max = t->year;
			pm = t;
		}
		t = t->next;
	}
	cout << "����� ������� �������: " << pn->lastname << " " << pn->firstname << " " << pn->O << " --> " << pn->year << endl;
	cout << "����� ������� �������: " << pm->lastname << " " << pm->firstname << " " << pm->O << " --> " << pm->year << endl;
}
//-----------------------------------------------------------
void normalizing(List** phead)
{
	char ABC[] = "�����Ũ��������������������������";
	int Kurs[] = { 1, 2, 3, 4 }, i = 0;
	while (i < 4 && i >= 0)
	{
		for (List* t = *phead; t; t = t->next)
		{
			int f = 0;
			if (t->kurs == Kurs[i])
			{
				int k = 1;
				if (f == 0) { cout << "\t" << Kurs[i] << " ����" << endl; f = 1; }
				for (int j = 0; j < sizeof(ABC); j++)
				{
					for (List* p = *phead; p; p = p->next)
					{
						if (ABC[j] == p->lastname[0] && p->kurs == Kurs[i])
						{
							cout << k << ". " << p->lastname << " " << p->firstname << " " << p->O << endl;
							k++;
						}
					}
				}
			}i++;
		}
	}
}
//-----------------------------------------------------------
void sr_ball(List** phead)
{
	int Group[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, i = 0,
		sr_math, sr_phis, sr_bel, sr_in, sr_ru;
	while (i < 10 && i >= 0)
	{
		sr_math = 0;
		sr_phis = 0;
		sr_bel = 0;
		sr_in = 0;
		sr_ru = 0;
		int k = 0;
		for (List* t = *phead; t; t = t->next)
		{
			if (t->number_group == Group[i])
			{
				for (List* p = *phead; p && p->number_group == Group[i]; p = p->next)
				{
					int j = 0;
					k++;
					sr_math = sr_math + p->Predmet[j];
					j++;
					sr_phis = sr_phis + p->Predmet[j];
					j++;
					sr_bel = sr_bel + p->Predmet[j];
					j++;
					sr_in = sr_in + p->Predmet[j];
					j++;
					sr_ru = sr_ru + p->Predmet[j];
					j++;
				}
			}
			if (k != 0) {
				cout << endl << "������� ����� " << Group[i] << "-� ������" << endl;
				cout << "�� ����������: " << sr_math / k << endl;
				cout << "�� ������: " << sr_phis / k << endl;
				cout << "�� ������������ �����: " << sr_bel / k << endl;
				cout << "�� ������������ �����: " << sr_in / k << endl;
				cout << "�� �������� �����: " << sr_ru / k << endl << endl;
			};
			i++;

		}
	}

}
//-----------------------------------------------------------
int main()
{
	List* head = NULL;
	List* last = NULL;
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true)
	{
		switch (menu())
		{
		case 1:  insert(setElement(), &head, &last);
			break;
		case 2: outputList(&head, &last);
			break;
		case 3: mx_mn(&head);
			break;
		case 4: normalizing(&head);
			break;
		case 5: sr_ball(&head); break;
		case 6:exit(0);
		default: exit(1);
		}
	}
	return 0;
}