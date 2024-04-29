/**************************************************************
* Implement vector class template using dynamic array
* Define vector class template - vector.h
***************************************************************/
#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <string.h>
#include <iostream>
#include <exception>
using namespace std;

/*****************************************
// Define Class: Vector
******************************************/

// rewrite class vector
template <class T>
class Vector
{
private:
	T* data;
	int capacity;
	int length;

private:
	// Default reserve constant
	static const int RESERVE_DEFAULT = 10;

public:
	Vector();
	Vector(const Vector<T>&);
	~Vector();

public:
	Vector<T>& operator=(const Vector<T>& other);
	T& operator[](int index);
	const T& operator[](int index) const;
	void push_back(const T& value);
	void pop_back();
	int size() const;
	bool isEmpty() const;
	void insert(int index, const T& value);
	void erase(int index);
	void clear();

private:
	// Reserve memory for the vector
	void reserve(int new_capacity);
};

/*****************************************
// Implementation Class: Vector
******************************************/
// Constructor
template <class T>
Vector<T>::Vector()
{
	capacity = 0;
	length = 0;
	data = nullptr;
}

// Copy constructor
template <class T>
Vector<T>::Vector(const Vector<T>& other)
{
	capacity = other.capacity;
	length = other.length;
	data = new T[capacity];

	if (!data) {
		cerr << "Memory allocation error" << endl;
		throw bad_alloc();
	}
	for (int i = 0; i < length; i++)
		data[i] = other.data[i];
}

// Destructor
template <class T>
Vector<T>::~Vector()
{
	delete[] data;
	data = nullptr;
}

// Assign operator function
template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
	if (this != &v) {
		delete[] data;
		capacity = v.capacity;
		length = v.length;
		data = new T[capacity];

		for (int i = 0; i < length; i++)
			data[i] = v.data[i];
	}
	return *this;
}

// Get the element at index using operator []
template <class T>
T& Vector<T>::operator[](int index)
{
	if (index < 0 || index > length) {
		cerr << "Index out of range" << endl;
		throw out_of_range("Index out of range");
	}
	return data[index];
}

// Get the element at index using operator [] const
template <class T>
const T& Vector<T>::operator[](int index) const
{
	if (index < 0 || index > length) {
		cerr << "Index out of range" << endl;
		throw out_of_range("Index out of range");
	}
	return data[index];
}

// Add an element to the end of the vector
template <class T>
void Vector<T>::push_back(const T& value)
{
	if (length == capacity)
		reserve(capacity + RESERVE_DEFAULT);
	data[length++] = value;
}

// Remove the last element of the vector
template <class T>
void Vector<T>::pop_back()
{
	if (length > 0)
		length--;
}

// Get the size of the vector
template <class T>
int Vector<T>::size() const
{
	return length;
}

// Check if the vector is empty
template <class T>
bool Vector<T>::isEmpty() const
{
	return length == 0;
}

// Insert an element at index
template <class T>
void Vector<T>::insert(int index, const T& value)
{
	if (index < 0 || index > length) {
		cerr << "Index out of range" << endl;
		throw out_of_range("Index out of range");
	}
	if (length == capacity)
		reserve(capacity + RESERVE_DEFAULT);

	for (int i = length; i > index; i--)
		data[i] = data[i - 1];

	data[index] = value;
	length++;
}

// Remove an element at index
template <class T>
void Vector<T>::erase(int index)
{
	if (index < 0 || index >= length) {
		cerr << "Index out of range" << endl;
		throw out_of_range("Index out of range");
	}
	for (int i = index; i < length - 1; i++)
		data[i] = data[i + 1];

	length--;
}

// Clear everything from the vector
template <class T>
void Vector<T>::clear()
{
	length = 0;
}

// Reserve memory for the vector when overflow
template <class T>
void Vector<T>::reserve(int new_capacity)
{
	T* newData = new T[new_capacity];
	for (int i = 0; i < length; i++)
		newData[i] = data[i];

	delete[] data;
	data = newData;
	capacity = new_capacity;
}

/*****************************************/
#endif // !_VECTOR_H_
