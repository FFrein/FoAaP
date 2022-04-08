//Скопировать из файла FILE1 в файл FILE2 все строки, в которых содержится не менее двух одинако-вых слов. Определить номер слова, в котором больше всего цифр.
#include <iostream>
#include <unordered_set>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
int main()
{   //копирование из файла F1 в файл F2 строк, которые содержат не менее двух одинаковых слов
    setlocale(LC_ALL, "RUS");
    ifstream is("FILE1.txt");
    ofstream os("FILE2.txt");
    if (!is || !os) return 1;
    string str, word;
    unordered_set<string> uset;
    while (getline(is, str)) {
        uset.clear();
        stringstream ss(str);

        while (ss >> word) {
            if (!uset.insert(word).second) {
                os << str << '\n';
                break;
            }
        }
    }
    is.close();
    os.close();
    ifstream isss("FILE1.txt");
    string str1;
    while (getline(isss, str1)) {
        string s, word, mostDig, mostLet;
        int i, count_letters, count_digits, max_letters = 0, max_digits = 0;
        stringstream words(str1);
        while (isss >> word) {
            i = 0;
            count_letters = 0;
            count_digits = 0;
            while (word[i])
            {
                if (word[i] >= '0' && word[i] <= '9') count_digits++;
                if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')) count_letters++;
                i++;
            }
            if (count_digits > max_digits) { max_digits = count_digits; mostDig = word; }
            if (count_letters > max_letters) { max_letters = count_letters; mostLet = word; }
        }
        cout << "Слово с максимальным кол-во цифер: " << mostDig;
    }
    return 0;
}