#pragma once              //Çàãîëîâî÷íûé ôàéë Lists.h
#define LISTNIL (Element*)-1
namespace listx
{
	struct Element
	{
		Element* prev;
		Element* next;
		void* data;
		Element(Element* Prev, void* Data, Element* Next) // êîíñòðóêòîð
		{
			prev = Prev;
			data = Data;
			next = Next;
		}
		Element* getNext()
		{
			return next;
		};
		Element* getPrev()
		{
			return prev;
		};
	};
	static Element* NIL = nullptr; //
	struct Object
	{
		Element* head; //âåðøèíà ñïèñêà 
		Object() // êîíñòðóêòîð 
		{
			head = NIL; // ïåðâûé ýëåìåíò íóëåâîé
		};
		Element* getFirst()
		{
			return head;
		};
		Element* getLast();
		Element* search(void* data);
		bool insert(void* data);
		bool deleteByElement(Element* e);
		bool deleteByData(void* data);
		void scan();
	};
	Object create();
}
#undef LISTNIL 