// ������ ������� ����� ����� ��������� � ��� ���� ������ ���������  //

#include <fstream>
#include <iostream>
using namespace std;
void main()
{
    setlocale(LC_ALL, "rus");
    char buff[50], sm[60];            
    char S[255];
    int len, smoll = 0;
    cout << "������� ����� ���� � �����: ";
    ofstream fout("File1.txt");   
    cin.getline(S, 255); 
    fout << S << endl;
    fout.close();
    ifstream fin("File1.txt");    
    if (!fin.is_open())
        cout << "���� �� ����� ���� ������!\n";
    else
    {
        for (int i = 0; i < 4; i++)
        {
            fin.getline(buff, 50, ' ');
            len = strlen(buff);
            if (i == 0)
                smoll = len;
            if (len < smoll) {
                smoll = len;
                cout << buff << endl;
            }

        }

        fin.close();
    }
}

