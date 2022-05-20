// ��������� ��� - ������� �� ���� ������������� ���������� �����, ����� �� ����������� � ������.������� ����������� �������
//���� �� �����.����������� ����� ���������� �����.��������� ��������� ��� ��������� ������������ ������� � �������� ���������� 
//���������.������� ��� �����, ������������ �� ��������� �����, �������� �������.

#include <iostream>
#include <fstream>

using namespace std;
typedef char T; // ��� ���������
typedef int hashTableIndex; // ������ � ���-�������
#define compEQ(a, b) (a == b)

typedef struct Node_ {
    T data;// ������, ���������� � �������
    struct Node_* next; // ��������� �������
} Node;

Node** hashTable;
int hashTableSize;
hashTableIndex myhash(T data);
Node* insertNode(T data);
void deleteNode(T data);
Node* findNode(T data);

int main() {
    setlocale(LC_CTYPE, "RU");
    int i, maxnum = 0;
    char* a = 0;
    int choice = 10;
    for (;;)
    {
        cout << "1.���� � �������" << endl;
        cout << "2.������ �� �����" << endl;
        cout << "3.����� ����������" << endl;
        cout << "4.�������� ���� �� 1 �����" << endl;
        cout << "0.�����" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
        {
            cout << "������� ���. ����.: ";
            cin >> maxnum;
            cout << "������� ������ ���-�������: ";
            cin >> hashTableSize;
            a = new char[maxnum];
            hashTable = new Node * [hashTableSize];
            for (i = 0; i < hashTableSize; i++)
                hashTable[i] = NULL;
            // ��������� �������
            for (i = 0; i < maxnum; i++)
            {
                a[i] = 'a' + rand() % 26;
                a[maxnum] = '\0';
            }
            // ���������� ���-������� ���������� ������
            for (i = 0; i < maxnum; i++) {
                insertNode(a[i]);
            }
            // ����� ��������� ������� � ���� List. txt
            ofstream out("List.txt");
            for (i = 0; i < maxnum; i++) {
                out << a[i];
                if (i < maxnum - 1) out << "\t";
            }

            out.close();
            // ���������� ���-������� � ���� HashTable. txt
            out.open("HashTable.txt");
            for (i = 0; i < hashTableSize; i++) {
                out << i;
                Node* Temp = hashTable[i];
                while (Temp) {
                    out << Temp->data;
                    Temp = Temp->next;
                }
            }
            out.close();
        }
        break;
        case 2:
        {
            // ����� ��������� ������� � ���� List. txt
            ofstream out("List.txt");
            for (i = 0; i < maxnum; i++) {
                cout << a[i];
                if (i < maxnum - 1) cout << "\t";
            }
            out.close();
            cout << endl;
            // ���������� ���-������� � ���� HashTable. txt
            out.open("HashTable.txt");
            for (i = 0; i < hashTableSize; i++) {
                cout << i << " : ";
                Node* Temp = hashTable[i];
                while (Temp) {
                    cout << Temp->data << " -> ";
                    Temp = Temp->next;
                }
                cout << endl;
            }out.close();
        }
        break;
        case 3:
        {
            int sear = 0;
            cout << "������� ����� �������� ���-������� (��.������): "; cin >> sear;
            cout << endl;
            // ����� ��������� ������� �� ���-�������
            for (i = 0; i < maxnum; i++) {
                if (i == sear)
                {
                    cout << "��������� �������:" << a[i - 1] << endl;
                }
            }
            break;
        }
        case 4:
        {
            char what;
            cout << "������� 1�� ����� �����, ������� ������ �������." << endl;
            cout << "���� ����� ������� �� 1 ����� - ��� ��������� ���������: "; cin >> what;
            char* b;
            b = new char[maxnum];
            hashTable = new Node * [hashTableSize];
            for (i = 0; i < hashTableSize; i++)
                hashTable[i] = NULL;
            // ��������� �������
            for (i = 0; i < maxnum; i++)
            {
                if (a[i] != what) {
                    b[i] = a[i];
                }
            }
            // ���������� ���-������� ���������� ������
            for (i = 0; i < maxnum; i++) {
                insertNode(b[i]);
            }
            // ����� ��������� ������� � ���� List. txt
            ofstream out("List.txt");
            for (i = 0; i < maxnum; i++) {
                out << b[i];
                if (i < maxnum - 1) out << "\t";
            }

            out.close();
            // ���������� ���-������� � ���� HashTable. txt
            out.open("HashTable.txt");
            for (i = 0; i < hashTableSize; i++) {
                out << i;
                Node* Temp = hashTable[i];
                while (Temp) {
                    out << Temp->data;
                    Temp = Temp->next;
                }
            }
            out.close();

            cout << "����� �������." << endl;
        }
        break;
        case 0:
        {
            exit(0);
        }
        }
    }
    return 0;


    // ����� ��������� ������� �� ���-�������
    for (i = maxnum - 1; i >= 0; i--) {
        findNode(a[i]);
    }


    // ������� ���-�������
    for (i = maxnum - 1; i >= 0; i--) {
        deleteNode(a[i]);
    }

    system("pause");
    return 0;
}

// ���-������� ���������� �������
hashTableIndex myhash(T data) {
    return (data % hashTableSize);
}

// ������� ������ �������������� � ������� ������� � �������
Node* insertNode(T data) {
    Node* p, * p0;
    hashTableIndex bucket;
    // ������� ������� � ������ ������
    bucket = myhash(data);
    if ((p = new Node) == 0) {
        fprintf(stderr, "�������� ������ (insertNode)\n");
        exit(1);
    }
    p0 = hashTable[bucket];
    hashTable[bucket] = p;
    p->next = p0;
    p->data = data;
    return p;
}

// ������� �������� ������� �� �������

void deleteNode(T data) {
    Node* p0, * p;
    hashTableIndex bucket;
    p0 = 0;
    bucket = myhash(data);
    p = hashTable[bucket];
    while (p && !compEQ(p->data, data)) {
        p0 = p;
        p = p->next;
    }
    if (!p) return;
    if (p0)
        p0->next = p->next;
    else
        hashTable[bucket] = p->next;
    free(p);
}

// ������� ������ ������� �� ��������� data
Node* findNode(T data) {
    Node* p;
    p = hashTable[myhash(data)];
    while (p && !compEQ(p->data, data))
        p = p->next;
    return p;
}