/* Assignment: 5 -template a
Author: Alice Aidlin, ID: 206448326 */
using namespace std;
//#define CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"Fraction.h"


template <class T>
void print_max(int size, T* arr)
{
	T max=arr[0];//at first the first object is the biggest
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	cout << "Max value: " << max << endl;
}


template <class T>
bool shown(T* arr, int size, T t)//know if the obj exist
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == t)
			return true;
	}
	return false;
}

template <class T>
void create_arr(int size)//alloc new arr with size from user
{
	T* arr = new T[size];
	T value;
	cout << "pleas enter values to arr" << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << "vulue #" << i + 1 << " :";
		cin >> arr[i];
		cout << "\n";
	}
	print_max(size, arr);//print the max
	cout << "\nplease enter value you want to check if exist in arry\n" << endl;
	cin >> value;
	if (shown(arr, size, value) == true)//if shown
		cout << "\nYES, value exist\n" << endl;
	else//not shown
		cout << "\nNO, value doesn't existe\n" << endl;
}



int main()
{
	int choice = 0;
	do
	{
		int size;
		cout << "\npleace enter your choic\n1.int\n2.float\n3.char\n4.string\n5.class Rational\n6.exit\n";
		cin >> choice;
		
		switch (choice)
		{
		case 1:
			cout << "\n";
			cout << "\nplease enter size of array" << endl;
			cin >> size;
			create_arr<int>(size);
			break;

		case 2:
			cout << "\n";
			cout << "\nplease enter size of array" << endl;
			cin >> size;
			create_arr<float>(size);
			break;

		case 3:
			cout << "\n";
			cout << "\nplease enter size of array" << endl;
			cin >> size;
			create_arr<char>(size);
			break;

			case 4:
			cout << "\n";
			cout << "\nplease enter size of array" << endl;
			cin >> size;
			create_arr<string>(size);
			break;

		case 5:
			cout << "\n";
			cout << "\nplease enter size of array" << endl;
			cin >> size;
			create_arr<Fraction>(size);
			break;
		case 6:
			cout << "\n";
			cout << "goodbye\n";
			break;
		default:
			cout << "bad input, please try again!\n";
			break;
		}
	} while (choice!=6);
	}