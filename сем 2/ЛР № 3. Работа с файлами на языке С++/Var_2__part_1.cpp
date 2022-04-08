#include <fstream>
#include <iostream>
using namespace std;
void main()
{
    int m = 0;
    setlocale(LC_ALL, "rus");
    cout << "Начальная строка:\n Работа с файлами в С++\n Франция Италия\n Антон и картошка\n Четыре не один\n Анархист в палатке\n  ";
    char buff[50], count[100];    
    ofstream fout("FILE1.txt");   
    fout << "Работа с файлами в С++\n Франция Италия\n Антон и картошка\n Четыре не один\n Анархист в палатке\n  "; 
    fout.close();
    ifstream fin("FILE1.txt");    
    ofstream FILE2("FILE2.txt");
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        ifstream f2("FILE2.txt");
        for (int i = 0; i < 2; i++) {
            fin.getline(buff, 50, 'А');
            fin.getline(buff, 50);
            FILE2 << "А" << buff << endl;
        }
        for (int i = 0; i < 50; i++) {
            f2.getline(count, 50);
            if ((count[i] == '\n') || (count[i] == ' '))
                m++;
        }
        cout << "\nКол слов в FILE2: " << m * 2;
        f2.close();
        fin.close();
        FILE2.close();
    }
}
