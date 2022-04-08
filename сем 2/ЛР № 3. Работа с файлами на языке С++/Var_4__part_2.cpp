#include <fstream>
#include <iostream>
using namespace std;
void main()
{

    setlocale(LC_ALL, "rus");
    cout << "¬ведите строку: ";
    char buff[50], mx[50], max = 0;
    char S[255];
    ofstream fout("FILE1.txt");   
    cin.getline(S, 255); 
    fout << S << endl;
    fout.close();
    fout.close();
    ifstream fin("FILE1.txt");
    if (!fin.is_open())
        cout << "‘айл не может быть открыт!\n";
    else
    {
        cout << "—амое длинное слово: ";
        for (int i = 0; i < 7; i++) {
            fin.getline(buff, 50, ' ');
            if (i == 0 || max < strlen(buff)) {
                max = strlen(buff);
                for (int c = 0; c < strlen(buff); c++) {
                    mx[c] = buff[c];
                    cout << mx[c];
                }

            }


        }

        fin.close();


    }
}



