#include <iostream>
#include <fstream>
#include<windows.h>

using namespace std;


void main()
{
    setlocale(LC_ALL, "rus");

    char* buff2 = new char[200];
    char* buff = new char[200];// ���� ������ ������ 200��������. ����� ��� �������� ������������ �� ����� ������

    ofstream fout("file2.txt");   // �������� ������� fout ������ ofstream ��� ������ 
    //ofstream fout1("t.txt");   // �������� ������� fout ������ ofstream ��� ������ 
     //fout1.close();

    ifstream fin("file1.txt");    // �������� ������� fin ������ ifstream ��� ������ 
    if (!fin.is_open())
        cout << "���� �� ����� ���� ������!\n";

    while (!fin.eof())
    {
        int z = 0;

        fin.getline(buff, 200, '\n');

        for (int i = 0; i < 200; i++) {
            for (char a = '0'; a <= '9'; a++) {
                if (buff[i] == a) {
                    z = 1;
                    break;
                }
            }
            if (z == 1) { break; }
        }
        if (z == 0) { fout << buff << endl; }

        z = 0;
    }

    fin.close();
    fout.close();


    fin.open("file2.txt");    // ������� fin ������ ifstream ��� ������  
    if (!fin.is_open())
        cout << "���� �� ����� ���� ������!\n";

    int num_slov = 0;
    while (!fin.eof())
    {

        fin.getline(buff, 10);
        if (fin.eof()) {
            break;
        }
        for (int i = 0; i < 1; i++) {
            if (buff[i] == 'A' || buff[i] == 'a') {
                num_slov++;
            }
        }

    }
    cout << num_slov << " ����� ���������� �� �";
}