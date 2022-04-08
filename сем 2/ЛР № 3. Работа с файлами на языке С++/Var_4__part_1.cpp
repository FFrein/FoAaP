#include <iostream>
#include <fstream>
#include<windows.h>

using namespace std;

void main()
{
    setlocale(LC_ALL, "rus");

    char* buff2 = new char[200];
    char* buff = new char[200];

    ofstream fout("FILE22.txt");   


    ifstream fin("FILE1.txt");   
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";

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


    fin.open("FILE2.txt");  
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";

    int num_slov = 0;
    while (!fin.eof())
    {

        fin.getline(buff, 10, '\n');

        for (int i = 0; i < 1; i++) {
            if (buff[i] == 'A' || buff[i] == 'a') {
                num_slov++;
            }
        }

    }
    cout << num_slov << " строк начинаются на а";
}