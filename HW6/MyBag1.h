//Names: Andrew Thompson, Lincoln Nguyen, Gia Minh Hoang 
//date due: 4/5/2021
//description: A headerfile containing a class and functions provided by Professor Quach, with a few added functions for option 1

#include<iostream>
#include <algorithm>
using namespace std;
namespace NON_TEMPLATE_MYBAG
{
	class MyBag
	{
	private:
		int* array;
		int size;
		int capacity;
	public:
		//Precondition: N/A
		//Postcondition: creates a default mybag object
		MyBag(): array(nullptr),size(0), capacity(0)
		{}
		//Precondition:	a new capacity
		//Postcondition: creates a mybag object with capacity set to newCapacity
		MyBag(int newCapacity)
		{
			array = new int[newCapacity];
			size = 0;
			capacity = newCapacity;
		}
		//Precondition: a my bag object
		//Postcondition: deallocates the dynamic array within the bag
		~MyBag()
		{
			delete[] array;
		}
		//Precondition: a mybag object
		//Postcondition: clears the object, and sets its size to 0
		void clear()
		{
			for (int i = 0; i < size; i++)
				array[i] = 0;
			size = 0;
		}
		//Precondition:A mybag object and an element
		//Postcondition: inserts the element at size. if bag is full, displays an error and does nothing 
		void insert(int element)
		{
			if (size < capacity)
			{
				array[size] = element;
				size++;
			}
			else
			{
				cout << "ERROR: bag full!";
			}
			
		}
		//Precondition: a my bag object
		//Postcondition: searches the bag for <element> returns true if found, and also returns the index at which the item was found, or -1 if it is not.
		bool search(int element, int& index) const
		{
			index = -1;
			for (int i = 0; i < size; i++)
			{
				if (array[i] == element)
				{
					index = i;
					return true;
				}
			}
			return false;
		}
		//Precondition: a mybag object
		//Postcondition: sorts the bag
		void sort()
		{
			std::sort(array, array + size);
		}
		//Precondition: a mybag object
		//Postcondition: displays the bag
		friend ostream& operator <<(ostream& out, const MyBag& obj)
		{
			if (obj.empty())
			{
				out << "\n\tEmpty.";
			}
			else
			{
				for (int i = 0; i < obj.size; i++)
					out << "\t\t[" << i << "]:" << obj.array[i] << '\n';
			}
			
			return out;
		}

		
		//Precondition: a my bag object
		//Postcondition: if the bag is empty, returns true. else, return false
		bool empty() const
		{
			if (size == 0)
				return true;
			else
				return false;
		}
		//Precondition: a mybag object
		//Postcondition: removes an item at an entered index, then shifts the array.
		void remove()
		{
			if (empty())
			{
				cout << "\n\tERROR: The bag is empty\n";
				return;
			}
			else
			{
				int index = inputInteger("Enter the index of the item you want removed: ", 0, size - 1);
				int holder = array[index];
				array[index] = 0;
				size = size - 1;
				for (int i = index; i < size; i++)
					array[i] = array[i + 1];
				cout << "\nThe value " << holder << " has been removed from the array\n";
			}

		}
	};
}