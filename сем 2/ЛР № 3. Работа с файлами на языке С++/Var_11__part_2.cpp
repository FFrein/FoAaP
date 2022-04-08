#include <iostream>
#include <fstream>
#include<windows.h>
#include<string>

using namespace std;
void main()
{
    setlocale(LC_ALL, "rus");
    char* buff3 = new char[200];
    char* buff2 = new char[200];
    char* buff = new char[200];
    ofstream fout("t.txt");  

    for (int i = 0; i < 2; i++) {


        cout << "введите " << i + 1 << " строку" << endl;
        string a;
        getline(cin, a);;
        fout << a;
        if (i < 1) {
            fout << "\n";
        }
    }
    fout.close();

    ifstream fin("t.txt");   
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";


    int min_len = 9999, max_len = 0, now_len = 0, lenofstr = 0, glasn1 = 0, glasn = 0, numnum = 0;

    while (!fin.eof())
    {
        fin.getline(buff, 200, '\n');

        lenofstr = strlen(buff);

        cout << lenofstr << endl;

        if (numnum == 0) {

            for (int i = 0, z = 0, x = 0, c = 0; i <= lenofstr; i++) {

                if ((buff[i] != ' ') && (buff[i] != '\0') && (buff[i] != '\n')) {
                    z++;
                }

                if (z > 0) {
                    if ((buff[i] == ' ') || (buff[i] == '\0') || (buff[i] == '\n')) {
                        now_len = z;
                        x = z;
                        c = (i - z);
                        z = 0;
                        if (min_len > now_len) {
                            min_len = now_len;

                            for (; c <= i; c++, z++) {
                                buff2[z] = buff[c];
                                if (c == i) {
                                    z = z + 1;
                                    buff2[z] = '\0';
                                    z = 0;
                                }
                            }
                        }
                    }
                }
            }
        }


        if (numnum == 1) {
            for (int i = 0, z = 0, x = 0, c = 0; i <= lenofstr; i++) {
                if ((buff[i] != ' ') && (buff[i] != '\0') && (buff[i] != '\n')) {
                    z++;
                }

                if (z > 0) {
                    if ((buff[i] == ' ') || (buff[i] == '\0') || (buff[i] == '\n')) {
                        now_len = z;
                        x = z;
                        c = (i - z);
                        z = 0;
                        if (max_len < now_len) {
                            max_len = now_len;

                            for (; c <= i; c++, z++) {
                                buff3[z] = buff[c];
                                if (c == i) {
                                    z = z + 1;
                                    buff3[z] = '\0';
                                    z = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
        numnum = 1;
    }
    fin.close();

    char glasnyje[11] = { 'A','E','I','O','U','a','e','i','o','u','\0' };

    cout << "Cамое короткое слово " << endl;

    int lin1 = 0;
    lin1 = strlen(buff2);
    for (int k = 0; k < lin1; k++) {
        if (buff2[k] == '\0') { cout << endl; break; }
        cout << buff2[k];
    }
    for (int m = 0; m < 11; m++) {
        for (int n = 0; n < lin1; n++) {
            if (buff2[n] == glasnyje[m]) {
                glasn++;
            }
        }
    }
    cout << "КОл гласных = " << glasn << endl;



    int lin2 = 0;
    lin2 = strlen(buff3);
    cout << "Cамое длинное слово " << endl;
    for (int k = 0; k < lin2; k++) {
        if (buff3[k] == '\0') { cout << endl; break; }
        cout << buff3[k];
    }

    cout << endl;
    for (int m = 0; m < 11; m++) {
        for (int n = 0; n < lin2; n++) {
            if (buff3[n] == glasnyje[m]) {
                glasn1++;
            }
        }
    }
    cout << "Кол гласных = " << glasn1 << endl;

    delete[] buff;
    delete[] buff2;
    delete[] buff3;
}