struct Stack
{
	int data;             //информационный элемент
	Stack* head;		 //вершина стека 
	Stack* next;		 //указатель на следующий элемент
};

void show(Stack* myStk, Stack* myStk2, Stack* myStk3);         //прототип
int pop(Stack* myStk);           //прототип
void push(int x, Stack* myStk);  //прототип
void sort(Stack* myStk, Stack* myStk2, Stack* myStk3);//прототип
void clear(Stack* myStk, Stack* myStk2, Stack* myStk3);//прототип
void insert(Stack*& p, double value);//прототип
void toFile(Stack*& p);//прототип
void fromFile(Stack*& p);//прототип