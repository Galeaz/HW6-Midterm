//Names: Andrew Thompson, Lincoln Nguyen, Gia Minh Hoang 
//date due: 4/5/2021
//description: A templated version of MyBag, with some added functions and a bit of experimenting with template specialization.
#pragma once
#include<iostream>
#include <algorithm>
#include <cassert>
using namespace std;
#include "input.h"
#include <string>
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
		//Precondition: a mybag object.
		//Postcondition: sets the capacity of the object to newCapacity. NOTE: does not actually change the capacity of the bag.
		void setCapacity(int newCapacity);
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
		// Precondition:  a mybag object.
		// Postcondition: assign content of my bag to other content
		void operator =(const MyBag<T>& rhs);
		// Precondition:  a mybag object.
		// Postcondition: return content at index 
		T& at(int index);
		// Precondition:  a mybag object.
		// Postcondition: return content at index 
		T& operator[](int index) const;
		// Precondition: a mybag object.
		// Postcondition: return iterator to the first element;
		T* begin();
		// Precondition: a mybag object.
		// Postcondition: return iterator to the past-the-end element;
		T* end();
		// Precondition:  a mybag object.
		// Postcondition: remove the element value
		void remove(const T& value);
		// Precondition: a mybag object.
		// Postcondition: remove the element at index
		void removeAtIndex(int index);
		// Precondition: a mybag object.
		// Postcondition: return if bag is empty
		bool empty() const;
		
		// Precondition:  a mybag object.
		// Postcondition: provide ui for remove
		void remove();
		// Precondition : a mybag object.
		// Postcondition: return size of bag
		int getSize() const;
	};
	
	template <class T>
	T& MyBag<T>::at(int index){
		assert(index < size);
		/*cout << '\n' << array[index]<<'\n';*/
		return array[index];
	}
	template <class T>
	T* MyBag<T>::begin() {
		return array;
	}

	template <class T>
	T* MyBag<T>::end() {
		return array + size;
	}
	template <class T>
	void MyBag<T>::remove(const T& value) {
		auto oldEnd = array + size;
		auto newEnd = std::remove(array, array + size, value);
		assert(newEnd + 1 == oldEnd);
		size--;
	}
	template <class T>
	void MyBag<T>::removeAtIndex(int index) {
		auto oldEnd = array + size;
		auto newEnd = std::shift_left(array + index, array + size, 1);
		assert(newEnd + 1 == oldEnd);
		size--;
	}
	template<class T>
	inline T& MyBag<T>::operator[](int index) const 
	{
		return array[index];
	}
	template <class T>
	void MyBag<T>::setCapacity(int newCapacity)
	{
		capacity = newCapacity;
	}

	template<class T>
	MyBag<T>::MyBag()
	{
		capacity = 0;
		size = 0;
		array = nullptr;
	
	
	}
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
	inline void MyBag<char>::clear()
	{
		for (int i = 0; i < size; i++)
			array[i] = '0';
		size = 0;
	}
	template<>
	inline void MyBag<string>::clear()
	{
		for (int i = 0; i < size; i++)
			array[i] = " ";
		size = 0;
	}
	template<class T>
	void MyBag<T>::insert(T element)
	{
		if (array == nullptr)
		{
			capacity = 10;
			array = new T[capacity];
			array[size] = element;
			/*cout << array[size] << ' ';*/
			size++;
			return;
		}
		if (size < capacity)
		{
			array[size] = element;
			/*cout << array[size]<< ' ';*/
			size++;
			return;
		}
		else if (size >=capacity&& size!=0)
		{
			T* holder;
			capacity = capacity + capacity;
			holder = new T[capacity];
			for (int i = 0; i < size; i++)
				holder[i] = array[i];
			delete[] array;
			array = holder;
			array[size] = element;
			return;
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
	template<>
	inline bool MyBag<string>::search(string element, int& index) const
	{
		index = -1;
		for (int i = 0; i < size; i++)
		{
			string tocmp = array[i];
			if (!tocmp.compare(' '+element))
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
	int MyBag<T>::getSize() const
	{
		return size;
	}
	template <class T>
	void MyBag<T>::operator =(const MyBag<T>& rhs)
	{
		if (array == nullptr)
		{
			capacity = 10;
			array = new T[capacity];
			size = 0;

		}
		size=rhs.size;
		for (int i = 0; i < rhs.size; i++)
		{
			array[i] = rhs.array[i];
		}
	}
	template<class T>
	ostream& operator <<(ostream& out, const MyBag<T>& obj)
	{
		if (obj.empty())
		{
			out << "\nThe bag is empty\n";
			return out;
		}
		out << "\n";
		for (int i = 0; i < obj.size; i++)
			out <<'['<< i << "]:"<< obj.array[i] << '\n';
		return out;
	}
}