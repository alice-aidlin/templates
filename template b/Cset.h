#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
#include <string>
using namespace std;
#ifndef CSET_H
#define CSET_H

template<class T>
class Cset
{
public:
	Cset() {}//Ctor

	Cset(const Cset& c)//CCtor
	{
		if (c.size > 0)
		{
			this->arr = new T[c.size];
			for (int i = 0; i < c.size; ++i)
			{
				this->arr[i] = c.arr[i];
			}
			this->size = c.size;
		}
	}

	~Cset()//Dtor
	{
		if (size > 0)
		{
			delete[] arr;
			arr = NULL;
		}
	}
	//--------------------------------------------------------------------------------------------
	void operator=(const Cset& c)
	{
		delete[] arr;//in case we have values so delete 
		if (c.size > 0)
		{

			for (int i = 0; i < c.size; ++i)
				this->arr[i] = c.arr[i];

			this->size = c.size;
		}
	}

	void operator+=(const T& t)
	{
		if (this->size == 0)//if arr empty
		{
			++this->size;
			this->arr = new T[this->size];
			arr[0] = t;
		}
		else
		{
			if (find(t) == -1)//if not found
			{
				T* temp = new T[this->size +1];//alloc new arr
				for (int i = 0; i < this->size; ++i)
					temp[i] = this->arr[i];//copy
				temp[size] = t;
				++this->size;
				delete[]this->arr;
				this->arr = temp;

			}
		}
	}

	void operator-=(const T& t)
	{
		if (this->size > 0)
		{
			if (find(t) != -1)//if yes exsist
			{
				int index = find(t);
				T* temp = new T[this->size - 1];
				for (int i = 0; i < index; ++i)//copy until the index
					temp[i] = this->arr[i];
				for (int k = index; k < this->size; ++k)//copy to new arr without object in index
					temp[index] = this->arr[index + 1];
				--this->size;
				delete this->arr;
				this->arr = temp;
			}
		}
	}

	Cset<T> UNION(const Cset<T>& c)const
	{
		Cset new_group(*this);//CCtor 
		for (int i = 0; i < c.size; ++i)
			new_group += c.arr[i];//if object not found add him
		return new_group;
	}

	Cset<T> INTERSECT( Cset<T>& c)const
	{

		Cset new_group(*this);//CCtor
		for (int i = 0; i <new_group.size; ++i)
		{
			if (c.find(new_group.arr[i]) == -1)//if new_group.arr[i] not found in c arr
				new_group -= new_group.arr[i];//so sub this object new_group.arr[i]
		}
		return new_group;
	}

	Cset<T> operator-(const Cset<T>& c)const
	{
		Cset new_group(*this);
		for (int i = 0; i < c.size; ++i)
			new_group -= c.arr[i];//if found this obj sub him
		return new_group;
	}
	friend ostream& operator<<(ostream& os, const Cset<T>& c)
	{
		os << "{ ";
		for (int i = 0; i < c.size ; ++i)
			os << "  "<<c.arr[i] << "   ";
		os <<  " }";
		return os;
	}

	int get_size()const { return this->size; }


private:
	T* arr = NULL;
	int size = 0;
	int find(T t)// to know if obj exist
	{
		for (int i = 0; i < size; ++i)
		{
			if (arr[i] == t)
				return i;
		}
		return -1;
	}
	
};

#endif 
