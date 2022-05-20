#pragma once
#include "Lists.h"
namespace hashTC
{
	struct Object
	{
		int size; // ðàçìåð òàáëèöû
		int(*FunKey)(void*); //Ôóíêöèÿ ïîëó÷åíèÿ êëþ÷à
		listx::Object* Hash; // óêàçàòåëü òèïà Object ïðîñòðàíñòâà èìåí listx (ñïèñîê)

		Object(int Size, int(*f)(void*)) //êîíñòðóêòîð
		{
			size = Size;
			FunKey = f;
			Hash = new listx::Object[Size]; // ñîçäàíèå ìàññèâà Object èç size - 1 

		};
		int hashFunction(void* data);
		bool insert(void* data);
		listx::Element* search(void* data);
		bool deleteByData(void* data);
		void Scan();
	};
	Object create(int size, int(*f)(void*));
}