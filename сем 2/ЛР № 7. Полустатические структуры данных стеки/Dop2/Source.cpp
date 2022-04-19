//2. ������� ���� � ������������� �������������� �����.
//��������� ��� ������� �����, ��������� �� �����.
//����������� �� ������ ���������� �����. ������� ����� � ����� ��������� ����� �������� ������ �����.

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

struct Stack
{
	int ind;
	Stack* next;
};

void length(Stack** el, int n)
{
	Stack* i = new Stack;
	i->ind = n;
	i->next = *el;
	*el = i;
}

void out(Stack* el)
{
	Stack* i = el;
	if (el == nullptr)
	{
		cout << "������ ����";
		return;
	}
	while (i != nullptr)
	{
		cout << i->ind << endl;
		i = i->next;
	}
}

int main()
{
	int min = 256, j = 0;
	setlocale(LC_CTYPE, "Russian");
	Stack* el = nullptr;
	ifstream file1("1.txt");
	char str[255];
	int n;
	while (!file1.eof())
	{
		file1.getline(str, 255);
		n = strlen(str);
		length(&el, n);
		if (n < min)
		{
			min = n;
			j++;
		}
	}
	file1.close();
	out(el);
	cout << endl;
	cout << "����� ����� ��������� ������:" << min << endl;
	cout << "Ÿ �����:" << j - 1 << endl;
	return 0;
}