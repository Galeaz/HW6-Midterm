//provided by professor Quach. Thank you, professor!
//date: 3/30/2021
//description: contains all information relation to mybag class.
#pragma once
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
		// constructors
		MyBag(): array(nullptr),size(0), capacity(0)
		{}

		MyBag(int newCapacity)
		{
			array = new int[newCapacity];
			size = 0;
			capacity = newCapacity;
		}

		// destructor
		~MyBag()
		{
			delete[] array;
		}

		// empty the bag
		void clear()
		{
			for (int i = 0; i < size; i++)
				array[i] = 0;
			size = 0;
		}

		// insert a new element
		void insert(int element)
		{
			if (size < capacity)
			{
				array[size] = element;
				size++;
			}
			else
				cout << "\n\tERROR: Bag is full.\n";
		}

		// serch an element in the bag
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

		// sorts elements
		void sort()
		{
			std::sort(array, array + size);
		}

		// overload << operator for display of mybag object
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

		// checks if the bag is empty
		bool empty() const
		{
			if (size == 0)
				return true;
			else
				return false;
		}

		// removes one element from mybag
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