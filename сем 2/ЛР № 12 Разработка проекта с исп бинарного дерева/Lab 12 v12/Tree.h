#pragma once
#include <iostream>
namespace btree
{
	enum CMP
	{
		LESS = -1, EQUAL = 0, GREAT = 1
	};
	struct Node
	{
		Node* parent;            // óêàçàòåëü íà ðîäèòåëÿ  
		Node* left;              // óêàçàòåëü íà ëåâóþ âåòâü
		Node* right;             // óêàçàòåëü íà ïðàâóþ âåòâü
		void* data;              //  äàííûå    
		Node(Node* p, Node* l, Node* r, void* d) // êîíñòðóêòîð
		{
			parent = p;
			left = l;
			right = r;
			data = d;
		}
		Node* next();              // ñëåäóþùèé ïî êëþ÷ó
		//Node* prev();              // ïðåäûäóùèé ïî êëþ÷ó
		Node* min();               // ìèíèìóì â ïîääåðåâå
		//Node* max();               // ìàêñèìóì â ïîääåðåâå  
		void scanDown(void(*f)(void* n));    // îáõîä ïîääåðåâà ñâåðõó âíèç     
		void scanDownKLP(void(*f)(void* n));    // îáõîä ïîääåðåâà ñâåðõó âíèç     
		void scanDownLKP(void(*f)(void* n)); //îáõîä ïîääåðåâà áðàòíûé
		void scan(int(*f)(void* n));
		void scanLevel(void(*f)(void* n), int);
		int getLevel();
		void scanByLevel(void(*f)(void* n));
	};
	struct Object         // Èíòåðôåéñ áèíàðíîãî äåðåâà 
	{
		Node* Root;                    // óêàçàòåëü íà êîðåíü
		CMP(*compare)(void*, void*);   // ôóíêöèÿ ñðàâíåíèÿ	
		Object(CMP(*f)(void*, void*))
		{
			Root = NULL;
			compare = f;
		};
		bool isLess(void* x1, void* x2)	const
		{
			return compare(x1, x2) == LESS;
		};
		bool isGreat(void* x1, void* x2)const
		{
			return compare(x1, x2) == GREAT;
		};
		bool isEqual(void* x1, void* x2)const
		{
			return compare(x1, x2) == EQUAL;
		};
		bool insert(void* data);           // äîáàâèòü ýëåìåíò
		Node* search(void* d, Node* n);    // íàéòè ýëåìåíò
		Node* search(void* d)
		{
			return search(d, Root);
		};
		bool deleteByNode(Node* e);         // óäàëèòü ïî àäðåñó ýëåìåíòà 
		bool deleteByData(void* data)       // óäàëèòü ïî êëþ÷ó
		{
			return deleteByNode(search(data));
		};
		int chet(Node* t);

		int maxDepth(Node* root);

		int minDepth(Node* root);

		int isBalanced(Node* root);
	};
	Object create(CMP(*f)(void*, void*));      // Ñîçäàòü áèíàðíîå äåðåâî    
};