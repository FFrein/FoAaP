#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

void insertionSort(int arr[], int n)
{   //���������� ������� ��������
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];   //���������
		j = i - 1;      //���������� ������� ��������������� �����
		while (j >= 0 && arr[j] > key) {  //����� ����� �������
			arr[j + 1] = arr[j];   //����� ��������
			j = j - 1;
		}
		arr[j + 1] = key;    //������� ���������� �� ����� ������� �������� ���
	}
}

void main()
{
	setlocale(LC_ALL, "rus");
	int A[15], B[15] = { -5,-4,-3,-2,-1,0,1,2,3,4,5 }, flag = 0, howmuch = 15;
	srand(time(NULL));
	cout << "����������� ������: ";
	for (int i = 0; i < 15; i++)
	{
		A[i] = -5 + rand() % 10;
		cout << A[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < 15; i++)
	{
		for (int k = 0; k < 15; k++)
		{
			if (B[i] == A[k]) {
				flag++;
				if (flag > 1) {
					A[k] = 6;
					howmuch--;
				}
			}

		}
		flag = 0;
	}
	cout << "\n������ � ���������� ����������: ";
	for (int i = 0; i < 15; i++)
	{
		if (A[i] != 6)
			cout << A[i] << " ";

	}
	cout << endl;
	insertionSort(A, 15);

	cout << "\n��������������� ������: ";
	for (int i = 0; i < howmuch; i++)
	{

		cout << A[i] << " ";

	}
}