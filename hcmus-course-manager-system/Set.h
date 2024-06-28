/**************************************************************
* Implement set class template using dynamic array
* Define set class template - Set.h
***************************************************************/
#ifndef _SET_H_
#define _SET_H_

#include <exception>
#include <stdexcept>

/*****************************************
// Define Class: Set
******************************************/
template <class T>
class Set
{
private:
	T* data;
	int capacity;
	int length;

private:
	// Default reserve constant
	static const int RESERVE_DEFAULT = 10;

public:
	Set();
	Set(const Set<T>& other);
	~Set();

public:
	Set<T>& operator=(const Set<T>& other);
	T& operator[](int index);
	const T& operator[](int index) const;
    void insert(T& value);
	int size() const;
	bool isEmpty() const;
	void erase(int index);
	void clear();
    bool contains(T& value);
    T& back();

private:
	// Reserve memory for the set
	void reserve(int new_capacity);
};

/*****************************************
// Implementation Class: Set
******************************************/
// Constructor
template <class T>
Set<T>::Set()
{
	capacity = 0;
	length = 0;
	data = nullptr;
}

// Copy constructor
template <class T>
Set<T>::Set(const Set<T>& other)
{
	capacity = other.capacity;
	length = other.length;
	data = new T[capacity];

	for (int i = 0; i < length; i++) {
		data[i] = other.data[i];
	}
}

// Destructor
template <class T>
Set<T>::~Set()
{
	delete[] data;
	data = nullptr;
}

// Assignment operator
template <class T>
Set<T>& Set<T>::operator=(const Set<T>& other)
{
	if (this != &other) {
		delete[] data;

		capacity = other.capacity;
		length = other.length;
		data = new T[capacity];

		for (int i = 0; i < length; i++) {
			data[i] = other.data[i];
		}
	}
	return *this;
}

// Get the element at index using operator []
template <class T>
T& Set<T>::operator[](int index)
{
	if (index < 0 || index > length) {
        // std::cerr << "Index out of range" << std::endl;
		throw std::out_of_range("Index out of range");
	}
	return data[index];
}

// Get the element at index using operator [] const
template <class T>
const T& Set<T>::operator[](int index) const
{
	if (index < 0 || index > length) {
        // std::cerr << "Index out of range" << endl;
		throw std::out_of_range("Index out of range");
	}
	return data[index];
}

// Add an element to the end of the set, set stay unchanged if the value is not unique
template <class T>
void Set<T>::insert(T& value)
{
    if (contains(value))
        return;

	if (length == capacity)
		reserve(capacity + RESERVE_DEFAULT);

	data[length++] = value;	
}

// Check if the value is not unique in the set
template <class T>
bool Set<T>::contains(T& value)
{
	for (int i = 0; i < length; i++) 
		if (data[i] == value)
			return true;

	return false;
}

// Get the size of the set
template <class T>
int Set<T>::size() const
{
	return length;
}

// Check if the set is empty
template <class T>
bool Set<T>::isEmpty() const
{
	return length == 0;
}

// Erase an element at index
template <class T>
void Set<T>::erase(int index)
{
	if (index < 0 || index >= length) {
        // std::cerr << "Index out of range" << endl;
		throw std::out_of_range("Index out of range");
	}
	for (int i = index; i < length - 1; i++) {
		data[i] = data[i + 1];
	}
	length--;
}

// Clear the set
template <class T>
void Set<T>::clear()
{
	length = 0;
}

// Reserve memory for the set
template <class T>
void Set<T>::reserve(int new_capacity)
{
	T* new_data = new T[new_capacity];
	for (int i = 0; i < length; i++) {
		new_data[i] = data[i];
	}
	delete[] data;
	data = new_data;
	capacity = new_capacity;
}

// Get the newest element in the set
template <class T>
T& Set<T>::back()
{
    return data[length - 1];
}

/*****************************************/
#endif // !_SET_H_
