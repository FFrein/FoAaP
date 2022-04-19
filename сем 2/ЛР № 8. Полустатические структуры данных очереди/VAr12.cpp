#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

int maxSize, curSize = 0;

struct CHAR
{
    char info;
    CHAR* next;
};

void var12();

void create(CHAR** begin, CHAR** end, char p);
void view(CHAR* begin);
void Delete(CHAR** begin, CHAR** end, char p);
int amount(CHAR* begin);
void task(CHAR* begin, CHAR* end);

int main() {
    setlocale(LC_ALL, "rus");
    bool work = true;
    int choice;
    var12();
    return 0;
}

void var12() {
    bool work = true;
    CHAR* begin = NULL, * end = NULL;

    char p;
    int choice = 0;

    cout << "\nMax Size = ";
    cin >> maxSize;

    while (work)
    {
        cout << "\n1. Input \n2. Output\n3. Delete\n4.  task 12\n0. Exit\n(Default break) " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Input: ";
            cin >> p;
            create(&begin, &end, p);
            break;
        case 2:
            view(begin);
            break;
        case 3:
            cout << "Delete number: ";
            cin >> p;
            Delete(&begin, &end, p);
            break;
        case 4:
            task(begin, end);
            break;
        case 0:
            work = false;
            break;
        default:
            break;
        }
    }
}

void create(CHAR** begin, CHAR** end, char p) //создание части
{
    if (curSize != maxSize)
    {
        CHAR* t = new CHAR;
        t->next = NULL;
        if (*begin == NULL)
        {
            *begin = *end = t;
            t->info = p;
        }
        else
        {
            t->info = p;
            (*end)->next = t;
            *end = t;
        }
        curSize++;
    }
    else
    {
        cout << "Oversize!" << endl;
    }
}
void view(CHAR* begin) //Вывод всего
{
    CHAR* t = begin;
    int size = amount(t);

    if (t == NULL)
    {
        cout << "Пусто\n";
    }
    else
    {
        while (t != NULL)
        {
            cout << t->info << " --> ";
            t = t->next;
        }
        cout << "NULL" << endl;
    }
    cout << "Размер : " << size << endl;
}

void Delete(CHAR** begin, CHAR** end, char p) //Удаление элемента
{
    CHAR** prev = begin, ** cur = &(*begin)->next;
    if (prev == NULL)
    {
        cout << "Пусто\n";
    }
    else
    {
        if ((*prev)->info == p)
        {
            *begin = (*prev)->next;
            curSize--;
        }
        else
        {
            while (cur != NULL)
            {
                if ((*cur)->info == p)
                {
                    (*prev)->next = (*cur)->next;
                    if ((*prev)->next == NULL) *end = *prev;
                    curSize--;
                    break;
                }
                prev = cur;
                cur = &(*cur)->next;
            }
        }

    }
}

int amount(CHAR* begin)
{
    int x = 0;
    CHAR* t = begin;
    if (t == NULL)
    {
        return 0;
    }
    else
    {
        while (t != NULL)
        {
            t = t->next;
            x++;
        }
    }
    return x;
}

void task(CHAR* begin, CHAR* end)
{
    char letter;
    cout << endl << "Введите символ: ";
    cin >> letter;
    cout << endl;
    CHAR* t = begin;
    CHAR* hz = end;
    int num = amount(t);
    if (t == NULL)
    {
        cout << "Пусто\n";
    }
    else
    {

        t = begin;
        hz = end;
        char max = t->info;

        if (letter == max) {
            view(begin);
        }

        /*
        var 15
            char letter;
            cout << endl << "Введите эталонный символ: ";
            cin >> letter;
            cout << endl;
            CHAR* t = begin;
            CHAR* hz = end;
            int num = amount(t);
            if (t == NULL)
            {
                cout << "Пусто\n";
            }
            else
            {

                t = begin;
                hz = end;
                char max = t->info;

                CHAR* t = begin;
                int size = amount(t);

                if (t == NULL)
                {
                    cout << "Пусто\n";
                }
                else
                {
                    while (t != NULL)
                    {
                        cout << t->info << " --> ";
                        t = t->next;
                    }
                    cout << "NULL" << endl;
                }

        */
    }
}

/*#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

int maxSize, curSize = 0;

struct CHAR
{
    int info;
    CHAR* next;
};

void var7();

void create(CHAR** begin, CHAR** end, char p);
void view(CHAR* begin);
void Delete(CHAR** begin, CHAR** end, char p);
int amount(CHAR* begin);

int main() {
    setlocale(LC_ALL, "rus");
    bool work = true;
    int choice;
    var7();
    return 0;
}

void var7() {
    bool work = true;
    CHAR* begin0 = NULL, * end0 = NULL;
    CHAR* begin1 = NULL, * end1 = NULL;
    CHAR* begin2 = NULL, * end2 = NULL;
    int p;
    int choice = 0;

    cout << "\nMax Size = ";
    cin >> maxSize;

    while (work)
    {
        cout << "\n1. Input \n2. Output\n3. Delete\n0. Exit\n(Default break) " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Input: ";
            cin >> p;
            if(p > 0){ create(&begin0, &end0, p); }
            if (p == 0) { create(&begin1 , &end1, p); }
            if (p < 0) { create(&begin2, &end2, p); }
            break;
        case 2:
            view(begin0);
            view(begin1);
            view(begin2);
            break;
        case 3:
            cout << "Delete number: ";
            cin >> p;
            Delete(&begin0, &end0, p);
            Delete(&begin1, &end1, p);
            Delete(&begin2, &end2, p);
            break;
        case 0:
            work = false;
            break;
        default:
            break;
        }
    }
}

void create(CHAR** begin, CHAR** end, char p) //создание части
{
    if (curSize != maxSize)
    {
        CHAR* t = new CHAR;
        t->next = NULL;
        if (*begin == NULL)
        {
            *begin = *end = t;
            t->info = p;
        }
        else
        {
            t->info = p;
            (*end)->next = t;
            *end = t;
        }
        curSize++;
    }
    else
    {
        cout << "Oversize!" << endl;
    }
}
void view(CHAR* begin) //Вывод всего
{
    CHAR* t = begin;
    int size = amount(t);

    if (t == NULL)
    {
        cout << "Пусто\n";
    }
    else
    {
        while (t != NULL)
        {
            cout << t->info << " --> ";
            t = t->next;
        }
        cout << "NULL" << endl;
    }
    cout << "Размер : " << size << endl;
}

void Delete(CHAR** begin, CHAR** end, char p) //Удаление элемента
{
    CHAR** prev = begin, ** cur = &(*begin)->next;
    if (prev == NULL)
    {
        cout << "Пусто\n";
    }
    else
    {
        if ((*prev)->info == p)
        {
            *begin = (*prev)->next;
            curSize--;
        }
        else
        {
            while (cur != NULL)
            {
                if ((*cur)->info == p)
                {
                    (*prev)->next = (*cur)->next;
                    if ((*prev)->next == NULL) *end = *prev;
                    curSize--;
                    break;
                }
                prev = cur;
                cur = &(*cur)->next;
            }
        }

    }
}

int amount(CHAR* begin)
{
    int x = 0;
    CHAR* t = begin;
    if (t == NULL)
    {
        return 0;
    }
    else
    {
        while (t != NULL)
        {
            t = t->next;
            x++;
        }
    }
    return x;
}*/