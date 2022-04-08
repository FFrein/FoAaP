#include <iostream>
#include <fstream>
#include<windows.h>


using namespace std;


void main()
{
    setlocale(LC_ALL, "rus");

    char* buff2 = new char[200];
    char* buff = new char[200];
    ofstream fout("FILE2.txt");   


    ifstream fin("FILE.txt");  
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";

    int num_slov = 0;
    while (!fin.eof())
    {


        fin.getline(buff, 200, '\n');

        for (int i = 0, b = 0, c = 0, d = 0; i < 200; i++) {
            if (b == 0) { if (buff[i] != ' ' && buff[i] != '\0' && buff[i] != '\n') { num_slov++; b = 1; } } //если строка начинается не на пробел то это первое слово

            if (buff[i] == ' ' && buff[i + 1] != ' ' && buff[i + 1] != '\0') // если n-ый символ пробел, а n+1-символ не равен пробелу или концу строки то 
            {
                num_slov++; b = 1;
            };

            if (buff[i] == '\0') { break; }

        }
        if (num_slov == 1) {
            fout << buff << endl; 
        }
        cout << num_slov << endl;
        num_slov = 0;
    }
    fin.close();



    ifstream fin2("FILE2.txt"); 
    if (!fin2.is_open())
        cout << "Файл не может быть открыт!\n";


    int b = 0, len_now = 0, len_before = 999, str_len = 0;
    while (!fin2.eof())
    {
        fin2.getline(buff, 200, '\n');
        str_len = strlen(buff);
        b = 0;
        for (int i = 0; i <= str_len; i++) {
            if (buff[i] != ' ' && buff[i] != '\0' && buff[i] != '\n') { b++; }
            if (b > 0) {
                if (buff[i] == '\0' || buff[i] == '\n' || buff[i] == ' ') {
                    len_now = b;
                    if (len_now < len_before) {
                        len_before = len_now;
                        for (int z = (i - b), l = 0; z <= i; z++, l++) {
                            b = 0;
                            buff2[l] = buff[z];
                            if (z == i) { buff2[z + 1] = '\0'; }
                        }
                        break;
                    }
                }
            }
        }
    }

    cout << "Cамое короткое слово: ";
    str_len = strlen(buff2);
    for (int k = 0; k < str_len; k++) {
        cout << buff2[k];
    }
    delete[] buff;
    delete[] buff2;
}