#include <stdio.h>
#include <cstring>
#include <iostream>
void main()
{
	using namespace std;
	char string[50];
	int i;
	char symbl;
	cout << "Input string:";
	cin >> string;
	/*�������� �� ���������, ���� ���� ������� ��������� 
	�������� ����������. �������� ����� ��������. ��� ��
	����� �� ������ � ������� ��������, �������� ����*/
	for (i = strlen(string); i >= 0;) /*���� �������� � �����*/
	{
		symbl = string[i];
		string[i] = string[i + 1];
		string[i + 1] = symbl;
		if (i <= 0) {
			break;
		}
		i -= 2;
	}


	cout << string;
}