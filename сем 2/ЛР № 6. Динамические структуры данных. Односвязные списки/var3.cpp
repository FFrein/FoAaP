// zd3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <fstream>
#include <iostream>
using namespace std;
struct list
{
    float number;
    list* next;
};

void insert(list*&, int); //функция добавления элемента, передается адрес списка и символ, который добавляется 
float del(list*&, int);   //функция удаления, передается адрес списка и символ, который удаляется 
int IsEmpty(list*);         //функция, которая проверяет, пуст ли список
void printList(list*);      //функция вывода
void menu(void);     //функция, показывающая меню
void sum7(list*);  //функция подсчета суммы чисел, больших 7  
void toFile(list*& p); //запись в файл 
void fromFile(list*& p);
void findInf(list*);

int main()
{
    setlocale(LC_CTYPE, "Russian");
    list* first = NULL;
    int choice;
    int value;
    menu();    // вывести меню 
    cout << " ? ";
    cin >> choice;
    while (choice != 4)
    {
        switch (choice)
        {
        case 1:  	cout << "Введите число "; // добавить число в список
            cin >> value;
            insert(first, value);
            printList(first);
            break;
        case 2:   if (!IsEmpty(first)) // удалить число из списка
        {
            cout << "Введите удаляемое число ";
            cin >> value;
            if (del(first, value))
            {
                cout << "Удалено число " << value << endl;
                printList(first);
            }
            else
                cout << "Число не найдено" << endl;
        }
              else
            cout << "Список пуст" << endl;
            break;
        case 3:   sum7(first);	// вычисление суммы	
            break;
        case 5: toFile(first);
            break;
        case 6: fromFile(first);
            break;
        case 7: findInf(first);
            break;
        default:  cout << "Неправильный выбор" << endl;
            menu();
            break;
        }
        cout << "?  ";
        cin >> choice;
    }
    cout << "Конец" << endl;
    return 0;
}

void menu(void)  //Вывод меню 
{
    cout << "Сделайте выбор:" << endl;
    cout << " 1 - Ввод числа" << endl;
    cout << " 2 - Удаление числа" << endl;
    cout << " 3 - Вычисление суммы положительных чисел, кратных 5" << endl;
    cout << " 4 - Выход" << endl;
    cout << " 5- Ввод чисел в файл" << endl;
    cout << " 6-вывод информации из файла" << endl;
    cout << " 7- поиск информации";
}

void toFile(list*& p)
{
    list* temp = p;
    list buf;
    ofstream frm("mList.txt");
    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    while (temp)
    {
        buf = *temp;
        frm << temp->number << " ";
        temp = temp->next;
    }
    frm.close();
    cout << "Список записан в файл mList.txt\n";
}

void fromFile(list*& p)          //Считывание из файла
{
    char buff[50];
    list buf, * first = nullptr;
    ifstream frm("mList.txt");
    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }

    while (!frm.eof())
    {
        frm.getline(buff, 50, ' ');
        cout << "-->" << buff;


    }
    cout << "-->NULL" << endl;
    frm.close();
    p = first;
    cout << "\nСписок считан из файла mList.txt\n";
}


void insert(list*& p, int value) //Добавление числа value в список 
{
    list* newP = new list;
    if (newP != NULL)     //есть ли место?  
    {
        newP->number = value;
        newP->next = p;
        p = newP;
    }
    else
        cout << "Операция добавления не выполнена" << endl;
}

float del(list*& p, int value)  // Удаление числа 
{
    list* previous, * current, * temp;
    if (value == p->number)
    {
        temp = p;
        p = p->next;    // отсоединить узел 
        delete temp;      //освободить отсоединенный узел 
        return value;
    }
    else
    {
        previous = p;
        current = p->next;
        while (current != NULL && current->number != value)
        {
            previous = current;
            current = current->next; // перейти к следующему 
        }
        if (current != NULL)
        {
            temp = current;
            previous->next = current->next;
            free(temp);
            return value;
        }
    }
    return 0;
}

int IsEmpty(list* p) //Список  пустой? (1-да, 0-нет) 
{
    return p == NULL;
}



void printList(list* p)  //Вывод списка 
{
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Список:" << endl;
        while (p != NULL)
        {
            cout << "-->" << p->number;
            p = p->next;
        }
        cout << "-->NULL" << endl;
    }
}

void sum7(list* p)  // Подсчет суммы чисел положительных
{
    float sm = 0;
    int kol = 0, a=0;
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        while (p != NULL)
        {
            a = p->number;
            if (a > 0 && a %5==0) {
                sm = sm + (p->number);
                kol++;
            }
               
            p = p->next;
        }
        if (kol!=0)
        cout << "Сумма = " << sm << endl;
        else  
            cout << "Таких чисел Нет "  << endl;
    }
}

void findInf(list* p)
{
    int kol = 1, nom;
    cout << "Введите номер элемента, который нужно найти ";
    cin >> nom;
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        while (p != NULL)
        {
            if (kol == nom) {
                cout << "\nЭто элемент " << p->number << endl;
            }
            kol++;
            p = p->next;
        }

    }
}
