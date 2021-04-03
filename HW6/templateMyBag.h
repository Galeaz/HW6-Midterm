#pragma once
#include<iostream>
#include <algorithm>
using namespace std;
#include "input.h"
namespace TEMPLATE_MYBAG
{
	template<class T>
	class MyBag
	{
	private:
		T* array;
		int size;
		int capacity;
	public:
		//Precondition: N/A
		//Postcondition: creates a default template myBag object
		MyBag();
		//Precondition: A desired capacity
		//Postcondition: creates a template mybag with its internal capacity set to newCapacity
		MyBag(int newCapacity);	
		//Precondition: A myBag object goes out of scope, or the program ends
		//Postcondition: deallocates allocated memory
		~MyBag();
		//Precondition: a mybag object.
		//Postcondition: sets all contents of the MyBag object to 0 and size to zero. (!!NOTE!! bags of type <string>) will have each space set to " " and bags of type char will be set to '0'
		void clear();
		//Precondition: a mybag object
		//Postcondition: inserts the element into the bag at the back of the array. 
		void insert(T element);
		//Precondition: a mybag object
		//Postcondition: seaches the bag for element, returning true if it finds it(also returns the index of that item) and false if it does not, as 
		bool search(T element, int& index) const;
		//Precondition: a mybag object
		//Postcondition: sorts the bag		
		void sort();
		//Precondition: a mybag object
		//Postcondition: displays the bags contents.	
		template<class T>
		friend ostream& operator <<(ostream& out, const MyBag<T>& obj);
		
		bool empty() const;

		void remove();
		void getSize() const;
	};



	template<class T>
	MyBag<T>::MyBag() : array(nullptr), size(0), capacity(0)
	{}
	template<class T>
	MyBag<T>::MyBag(int newCapacity)
	{
		array = new T[newCapacity];
		size = 0;
		capacity = newCapacity;
	}
	template<class T>
	MyBag<T>::~MyBag()
	{
		delete[] array;
	}
	template<class T>
	void MyBag<T>::clear()
	{
		for (int i = 0; i < size; i++)
			array[i] = 0;
		size = 0;
	}
	template<>
	void MyBag<char>::clear()
	{
		for (int i = 0; i < size; i++)
			array[i] = '0';
		size = 0;
	}
	template<>
	void MyBag<string>::clear()
	{
		for (int i = 0; i < size; i++)
			array[i] = " ";
		size = 0;
	}
	template<class T>
	void MyBag<T>::insert(T element)
	{
		if (size < capacity)
		{
			array[size] = element;
			size++;
		}

	}
	template<class T>
	bool MyBag<T>::search(T element, int& index) const
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
	template<class T>
	void MyBag<T>::sort()
	{
		std::sort(array, array + size);
	}
	template<class T>
	bool MyBag<T>::empty() const
	{
		if (size == 0)
			return true;
		else
			return false;
	}
	template<class T>
	void MyBag<T>::remove()
	{
		if (empty())
		{
			cout << "\nThe bag is empty\n";
			return;
		}
		else
		{
		
			int index = inputInteger("Enter the index of the item you want removed: ", 0, size-1);
			T holder = array[index];
			array[index] = 0;
			size = size - 1;
			for (int i = index; i < size; i++)
				array[i] = array[i+1];
			cout << "\nThe value " << holder << " has been removed from the array\n";
		}


	}
	template<class T>
	void MyBag<T>::getSize() const
	{
		return size;
	}

	template<class T>
	ostream& operator <<(ostream& out, const MyBag<T>& obj)
	{
		if (obj.empty())
		{
			out << "\nThe bag is empty\n";
			return out;
		}
		for (int i = 0; i < obj.size; i++)
			out <<'[' << i <<"]: " << obj.array[i] << '\n';
		return out;

	}


}