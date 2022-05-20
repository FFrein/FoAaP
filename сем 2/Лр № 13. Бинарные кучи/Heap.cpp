#include "heap.h" 
#include <iostream> 
#include <iomanip> 
namespace heap
{

	int Heap::left(int ix) // левый дочерний элемент
	{
		return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);

	}

	int Heap::right(int ix) // правый дочерний элемент 
	{
		return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);

	}

	void* Heap::extractMax()
	{
		void* rc = nullptr;
		if (!isEmpty()) // если не пустая 
		{
			rc = storage[0]; // то рк равно первому элементу массива 
			storage[0] = storage[size - 1]; // удаляем его
			size--; // уменьшаем сайз на 1
			heapify(0); //балансируем дерево с нуля 
		} return rc; // возвращаем рк 
	}

	int Heap::parent(int ix) //родительский элемент
	{
		return (ix + 1) / 2 - 1; //родительский элемент
	}

	void Heap::swap(int i, int j) //функция свап, которая принимает два интовых значения
	{
		void* buf = storage[i];
		storage[i] = storage[j];
		storage[j] = buf; // меняет их местами
	}

	void Heap::heapify(int ix) // балансировка кучи
	{
		int l = left(ix); 
		int r = right(ix);
		int irl = ix;
		if (l > 0) // если левая больше нуля 
		{
			if (isGreat(storage[l], storage[ix])) // если левая больше
				irl = l; // присваиваем левое 
			if (r > 0 && isGreat(storage[r], storage[irl])) // если правая больше и больше индекса, то 
				irl = r; // присваиваем правое
			if (irl != ix) // если не сошлось ( то есть мы что то поменяли и куча неправильная) 
			{
				swap(ix, irl); //свапаем местами
				heapify(irl); // повторяем процедуру, пока не станет норм 
			}
		}
	}

	void Heap::deleteHeap() // удаляем кучу 
	{
		if (!isEmpty())
		{
			size = 0; 
			this->~Heap();
		}
	}

	Heap create(int maxsize, CMP(*f)(void*, void*)) //функция создания кучи
	{
		return *(new Heap(maxsize, f)); // возвращает кучу по адресу
	}

	void Heap::scan(int i) const     //Вывод значений элементов на экран
	{
		int probel = 20;
		int z = 3;
		std::cout << '\n';
		if (size == 0)
			std::cout << "Êó÷à ïóñòà";
		for (int u = 0, y = 0; u < size; u++)
		{
			std::cout << std::setw(probel + 10) << std::setfill(' ');
			((AAA*)storage[u])->print();
			if (u == y)
			{
				std::cout << '\n';
				if (y == 0)
					y = 2;
				else
				{

					y = y + z;
					z++;
				}

			}
			probel /= 2;
		}
		std::cout << '\n';
	}

	int Heap::findMin()
	{
		int min = 0;
		for (int i = 1; i < size; i++)
		{
			if (((AAA*)storage[i])->getPriority() < ((AAA*)storage[min])->getPriority())
				min = i;
		}
		return min;
	}



	void* Heap::extractI(int ix)
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[ix]; // рк равно первому элементу массива
			storage[ix] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}

	void* Heap::extractMin() // удаляет минимальный
	{
		int min = findMin();
		return extractI(min);
	}

	void Heap::insert(void* x) // функция вставки 
	{
		int i; 
		if (!isFull())
		{
			storage[i = ++size - 1] = x;
			while (i > 0 && isLess(storage[parent(i)], storage[i])) // пока и больше нуля и родительский элемент меньше текущего 
			{
				swap(parent(i), i); // свапаем родительский элемент 
				i = parent(i); // и присваиваем родительский элемент 
			}
		}
	}
}

void AAA::print() // выводит все данные 
{
	std::cout << x;
}

int AAA::getPriority() const
{
	return x;
}