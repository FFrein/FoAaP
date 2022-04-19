// LABA12_DOP3.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//������� ������ � ������-������� ���������. ����������� �������� �������� ��� ������-������ �������. � ������-������ 
//������ ����� ���� �� ����� � ���������� �����, ���������� ����������� ���������� ������� ������.

#include <iostream>
#include <windows.h>
#include <io.h>
#include <fcntl.h>

using namespace std;
#define max 100
struct Tree          //������
{
	int key;         //����
	int number;
	char color;
	Tree* Left, * Right;
};
bool color_check = 0;
Tree* Root = NULL; 	//��������� �����
int RB_Counter = 0;
int min_R = max;
Tree* found_min_R = NULL;


Tree* makeTree(Tree* Root, int& left, int& right);       //�������� ������
Tree* list(int i, int s);       //�������� ������ ��������
Tree* insertElem(Tree* Root, int key, int s, int& left, int& right);  //���������� ������ ��������
Tree* search(Tree* n, int key);   //����� �������� �� ����� 
Tree* delet(Tree* Root, int key); //�������� �������� �� �����
void view(Tree* t, int level);    //����� ������ 
Tree* count(Tree* t);  //������� ���������� ����
void delAll(Tree* t);       //������� ������


void main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	int key, choice, left_count = 0, right_count = 0;
	Tree* rc; int s, letter, k = 0;
	for (;;)
	{
		/*printf("\n\
				  |||||||||||||||||||||||\n\
				  | ||| |   | || | ||  ||\n\
				  |  |  | ||| || | | || |\n\
 - - - - - - * * * * * * * *  | | | |   |    |    | |  * * * * * * * * - - - - - - \n\
|			      | ||| | ||| || | | || |                             |\n\
|	   	              | ||| |   | || | ||  ||                             |\n\
|			      |||||||||||||||||||||||                             |\n");*/
/*cout << "|1 -	      �������� ������	                                                  |\n";
cout << "|2 -	      ���������� ��������	                                          |\n";
cout << "|3 -	      ����� �� �����	                                                  |\n";
cout << "|4 -	      �������� ��������	                                                  |\n";
cout << "|5 -	      ����� ������	                                                  |\n";
cout << "|6 -	      ���� �� ����� �� ����� � ����������� ���-��� ������� �����	  |\n";
cout << "|7 -	      ������� ������	                                                  |\n";
cout << "|8 -	      �����	                                                          |\n";
cout << "|- * - * - * - * - * - * - * - * - *��� �����?* - * - * - * - * - * - * - * - * - |\n";*/
		cout << "1 -�������� ������\n";
		cout << "2 - ���������� ��������\n";
		cout << "3 -����� �� �����\n";
		cout << "4 -�������� ��������\n";
		cout << "5 -����� ������\n";
		cout << "6 -���� �� ����� �� ����� � ����������� ���-��� ������� �����\n";
		cout << "7 -������� ������\n";
		cout << "8 -�����\n";
		cout << "��� �����?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:  Root = makeTree(Root, left_count, right_count);	break;
		case 2:  cout << "\n������� ����: "; cin >> key;
			cout << "������� �����: "; cin >> s;
			insertElem(Root, key, s, left_count, right_count); break;
		case 3:  cout << "\n������� ����: ";  cin >> key;
			rc = search(Root, key);
			if (rc != NULL)
			{
				cout << "��������� �����= ";
				cout << rc->number << endl;
			}break;
		case 4:  cout << "\n������� ��������� ����: "; cin >> key;
			Root = delet(Root, key);  break;
		case 5:  if (Root != NULL)
		{
			cout << "������ ��������� �� 90 ����. �����" << endl;
			view(Root, 0);
		}
			  else cout << "������ ������\n"; break;
		case 6:
			found_min_R = count(Root);
			cout << "�������, �� �������� ���������� ������ ���������� ���������� ������� �����:" << found_min_R->key << " - " << found_min_R->number << " - " << found_min_R->color << endl;
		case 7:  delAll(Root); Root = NULL; break;
		case 8:  exit(0);
		}
	}
}

Tree* makeTree(Tree* Root, int& left, int& right)    //�������� ������
{
	int key; int s;
	cout << "����� ����� - ������������� �����\n\n";
	if (Root == NULL)	// ���� ������ �� �������
	{
		cout << "������� ���� �����: "; cin >> key;
		cout << "������� ����� �����: "; cin >> s;
		Root = list(key, s);// ��������� ��������� �� ������
		Root->color = 'B';
	}
	while (1)                //���������� ���������
	{
		cout << "\n������� ����: ";  cin >> key;
		if (key < 0) break;       //������� ������ (���� < 0)   
		cout << "������� �����: ";  cin >> s;
		insertElem(Root, key, s, left, right);
	}
	return Root;
}


Tree* list(int i, int s)     //�������� ������ ��������
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = i;
	t->number = s;
	t->Left = t->Right = NULL;
	return t;
}


Tree* insertElem(Tree* t, int key, int s, int& left, int& right)  //���������� ������ ��������
{
	Tree* Prev = NULL;	     // Prev - ������� ����� �������
	int find = 0;  // ������� ������  
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
			find = 1;	   //����� ������ ���� ���������
		else
			if (key < t->key) t = t->Left;
			else t = t->Right;
	}

	if (!find)
	{
		t = list(key, s);
		if (key < Prev->key)
		{
			if (Prev->color == 'B') t->color = 'R';
			else t->color = 'B';
			Prev->Left = t;
			left++;
		}
		else
		{
			if (Prev->color == 'B') t->color = 'R';
			else t->color = 'B';
			Prev->Right = t;
			right++;
		}
	}
	return t;
}


Tree* delet(Tree* Root, int key)  //�������� �������� �� �����
{	// Del, Prev_Del - ��������� ������� � ��� ���������� ;
	// R, Prev_R - �������, �� ������� ���������� ���������, � ��� ��������; 
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//����� �������� � ��� �������� 
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL)              // ������� �� ������
	{
		puts("\n��� ������ �����");
		return Root;
	}
	if (Del->Right == NULL) // ����� �������� R ��� ������
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; //����� ������ ������� �������� � ����� ���������
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // ������ ������� ��� ������ R � ��� �������� Prev_R 
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//�������� ����� � ������ ��� �� R
	else
		// ��������� R �������������� � �������� ���������� ����
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; // �� ����� ����� 
		else
			Prev_Del->Right = R;	// �� ������ �����
	int tmp = Del->key;
	cout << "\n������ ������� � ������ " << tmp << endl;
	delete Del;
	return Root;
}


Tree* search(Tree* n, int key)  //����� �������� �� ����� 
{
	Tree* rc = n;
	if (rc != NULL)
	{
		if (key < n->key)
			rc = search(n->Left, key);
		else
			if (key > n->key)
				rc = search(n->Right, key);
	}
	else
		cout << "��� ������ ��������\n";
	return rc;
}

Tree* count(Tree* t)
{
	if (t == NULL) { return NULL; }
	if (t->color == 'R') RB_Counter++;
	if (t->Right == NULL && t->Left == NULL)
	{
		if (min_R > RB_Counter)
		{
			min_R = RB_Counter;
			found_min_R = t;
		}
		if (t->color == 'R')RB_Counter--;
		return found_min_R;
	}
	else
	{
		count(t->Right);
		count(t->Left);
		if (t->color == 'R') RB_Counter--;
	}
	return found_min_R;
}

void view(Tree* t, int level) //����� ������ 
{
	if (t == NULL)return;
	else
	{
		view(t->Left, ++level);
		for (int i = 0; i < level; i++)
			cout << "      ";
		int tm = t->key;
		cout << tm << "-" << t->number << "-" << t->color << endl;
		level--;
	}
	view(t->Right, ++level);
}


void delAll(Tree* t) //������� ������
{
	if (t != NULL)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
	}
}

// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"

// ������ �� ������ ������ 
//   1. � ���� ������������ ������� ����� ��������� ����� � ��������� ���.
//   2. � ���� Team Explorer ����� ������������ � ������� ���������� ��������.
//   3. � ���� "�������� ������" ����� ������������� �������� ������ ������ � ������ ���������.
//   4. � ���� "������ ������" ����� ������������� ������.
//   5. ��������������� �������� ������ ���� "������" > "�������� ����� �������", ����� ������� ����� ����, ��� "������" > "�������� ������������ �������", ����� �������� � ������ ������������ ����� ����.
//   6. ����� ����� ������� ���� ������ �����, �������� ������ ���� "����" > "�������" > "������" � �������� SLN-����.