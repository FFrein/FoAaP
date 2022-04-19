#include "Tree.h"
#include <fstream>
#include <tchar.h>
using namespace std;
struct NodeTree
{
	int  key;
};
//-------------------------------
btree::CMP cmpfnc(void* x, void* y)    // Сравнение
{
	btree::CMP rc = btree::EQUAL;
	if (((NodeTree*)x)->key < ((NodeTree*)y)->key)
		rc = btree::LESS;
	else
		if (((NodeTree*)x)->key > ((NodeTree*)y)->key)
			rc = btree::GREAT;
	return rc;
}
//-------------------------------

void printNode(void* x)               // Вывод при обходе
{
	cout << ((NodeTree*)x)->key <<" "<< ends; //ends было
}
//-------------------------------
bool buildTree(char* FileName, btree::Object& tree) //Построение дерева из файла
{
	bool rc = true;
	FILE* inFile;
	fopen_s(&inFile, FileName, "r");
	if (inFile == NULL)
	{
		cout << "Ошибка открытия входного файла" << endl;
		rc = false; return rc;
	}
	while (!feof(inFile)) // заполнение дерева 
	{
		int num;
		fscanf_s(inFile, "%d", &num, 1);
		NodeTree* a = new NodeTree();
		a->key = num;
		tree.insert(a);
	}
	fclose(inFile);
	return rc;
}
FILE* outFile;
//-------------------------------
void saveToFile(void* x)              // Запись одного элемента в файл
{
	NodeTree* a = (NodeTree*)x;
	int q = a->key;
	cout << q << "\n";
	fprintf(outFile, "%d\n", q);
}
void inConsol(void* x)              // Вывол одного элемента в файл
{
	NodeTree* a = (NodeTree*)x;
	int q = a->key;
	cout << q << "\n";
}
/*int chet(void* x)
{
	NodeTree* a = (NodeTree*)x;
	int q = a->key;
	if (a)
	{
		chet(t->right);
		if ((int)(t->data) % 2 == 0)
			std::cout << "!!! " << t->data << " !!!!";
		chet(t->left);
	}
	return q;
}*/
//-------------------------------
void saveTree(btree::Object& tree, char* FileName)    //Сохранение дерева в файл 
{
	fopen_s(&outFile, FileName, "w");
	if (outFile == NULL)
	{
		cout << "Ошибка открытия выходного файла" << endl;
		return;
	}
	tree.Root->scanDown(saveToFile);
	fclose(outFile);
}
void inConsolAll(btree::Object& tree)    //Сохранение дерева в файл 
{
	tree.Root->scanDownKLP(inConsol);
}
void inConsolAll1(btree::Object& tree)    //Сохранение дерева в файл 
{
	tree.Root->scanDownLKP(inConsol);
}
/*
int maxDepth(Node* root) {
	if (!root) {
		return 0;
	}
	return  max(maxDepth(root->left), maxDepth(root->right));
}
int minDepth(Node* root) {
	if (!root) {
		return 0;
	}
	return  min(minDepth(root->left), minDepth(root->right));
}
void isBalanced(Node* root) {
	if (maxDepth(root) - minDepth(root) <= 1)
		f1 << "YES";
	else
		f1 << "NO";
}
*/
//-------------------------------

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "Russian");
	btree::Object demoTree = btree::create(cmpfnc);

	int k, choice, j = 0;
	char textfile[10] = "G.txt";
	NodeTree a1 = { 1 }, a2 = { 2 }, a3 = { 3 }, a4 = { 4 }, a5 = { 5 }, a6 = { 7};
	bool rc = demoTree.insert(&a4);   //           4(Root)  
	rc = demoTree.insert(&a1);        //   1             
	rc = demoTree.insert(&a6);        //                   6
	rc = demoTree.insert(&a2);        //      2     
	rc = demoTree.insert(&a3);        //         3
	rc = demoTree.insert(&a5);        //                 5	
	for (;;)
	{
		NodeTree* a = new NodeTree;
		cout << "1 - вывод дерева на экран" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - сохранить в файл" << endl;
		cout << "5 - загрузить из файла" << endl;
		cout << "6 - очистить дерево" << endl;
		cout << "7 - количество четных ключей" << endl;
		cout << "8 - Нисходящий обход" << endl;
		cout << "9 - Смешанный обход" << endl;
		cout << "10 - Проверка баланса" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl; cin >> choice;
		switch (choice)
		{
		case 0:   	exit(0);
		case 1:  cout << endl;
			if (demoTree.Root)
				demoTree.Root->scanByLevel(printNode);
			else
				cout << "Дерево пустое" << endl;
			break;
		case 2: 	cout << "введите ключ" << endl;  cin >> k;
			a->key = k;
			demoTree.insert(a);
			break;
		case 3:  	cout << "введите ключ" << endl;  cin >> k;
			a->key = k;
			demoTree.deleteByData(a);
			break;
		case 4:   	saveTree(demoTree, textfile);
			break;
		case 5:  	buildTree(textfile, demoTree);
			break;
		case 6:	while (demoTree.Root)
			demoTree.deleteByNode(demoTree.Root);
			break;
		case 7: cout << "Количество четных ключей: " << demoTree.chet(demoTree.Root)-1 << '\n'; break;
		case 8: cout << endl;  inConsolAll(demoTree); cout << endl; break;
		case 9:  cout << endl;  inConsolAll1(demoTree); cout << endl; break;
		case 10: if (demoTree.isBalanced(demoTree.Root)) cout << "Дерево сбалансировано\n";
			   else cout << "Дерево не сбалансировано\n"; break;
		}
	}
	return 0;
}