struct Stack
{
	int data;             //�������������� �������
	Stack* head;		 //������� ����� 
	Stack* next;		 //��������� �� ��������� �������
};

void show(Stack* myStk, Stack* myStk2, Stack* myStk3);         //��������
int pop(Stack* myStk);           //��������
void push(int x, Stack* myStk);  //��������
void sort(Stack* myStk, Stack* myStk2, Stack* myStk3);//��������
void clear(Stack* myStk, Stack* myStk2, Stack* myStk3);//��������
void insert(Stack*& p, double value);//��������
void toFile(Stack*& p);//��������
void fromFile(Stack*& p);//��������