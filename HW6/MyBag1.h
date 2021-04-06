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
		//Precondition
		//Postcondition
		MyBag(): array(nullptr),size(0), capacity(0)
		{}

		MyBag(int newCapacity)
		{
			array = new int[newCapacity];
			size = 0;
			capacity = newCapacity;
		}

		~MyBag()
		{
			delete[] array;
		}

		void clear()
		{
			for (int i = 0; i < size; i++)
				array[i] = 0;
			size = 0;
		}

		void insert(int element)
		{
			if (size < capacity)
			{
				array[size] = element;
				size++;
			}
			
		}
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
		void sort()
		{
			std::sort(array, array + size);
		}

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
		bool empty() const
		{
			if (size == 0)
				return true;
			else
				return false;
		}
		void remove()
		{
			if (empty())
			{
				cout << "\nThe bag is empty\n";
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