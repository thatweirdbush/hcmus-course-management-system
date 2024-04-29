/**************************************************************
* Implement map class template using dynamic array
* Define map class template - Map.h
***************************************************************/
#ifndef _H_MAP_H
#define _H_MAP_H

#include <exception>

/*****************************************
// Define Class: Map
******************************************/
template <class K, class V>
class Map
{
private:
	K* key;
	V* value;
	int capacity;
	int length;

private:
	// Default reserve constant
	static const int RESERVE_DEFAULT = 10;

public:
	Map();
	Map(const Map<K, V>& other);
	~Map();

public:
	Map<K, V>& operator=(const Map<K, V>& other);
	V& operator[](const K& key);
	const V& operator[](const K& key) const;
	void insert(const K& key, const V& value);
	int size() const;
	bool isEmpty() const;
	void erase(const K& key);
	void clear();
	bool contains(const K& key) const;

private:
	// Reserve memory for the map
	void reserve(int new_capacity);
};

/*****************************************
// Implementation Class: Set
******************************************/
// Constructor
template <class K, class V>
Map<K, V>::Map()
{
	capacity = 0;
	length = 0;
	key = nullptr;
	value = nullptr;
}

// Copy constructor
template <class K, class V>
Map<K, V>::Map(const Map<K, V>& other)
{
	capacity = other.capacity;
	length = other.length;
	key = new K[capacity];
	value = new V[capacity];

	for (int i = 0; i < length; i++)
	{
		key[i] = other.key[i];
		value[i] = other.value[i];
	}
}

// Destructor
template <class K, class V>
Map<K, V>::~Map()
{
	delete[] key;
	delete[] value;
	key = nullptr;
	value = nullptr;
}

// Assignment operator
template <class K, class V>
Map<K, V>& Map<K, V>::operator=(const Map<K, V>& other)
{
	if (this != &other)
	{
		reserve(other.capacity);
		length = other.length;

		for (int i = 0; i < length; i++)
		{
			key[i] = other.key[i];
			value[i] = other.value[i];
		}
	}
	return *this;
}

// Get the element at index using operator []
template <class K, class V>
V& Map<K, V>::operator[](const K& key)
{
	for (int i = 0; i < length; i++)
	{
		if (this->key[i] == key)
		{
			return value[i];
		}
	}
	throw std::exception("Key not found");
}

// Get the element at index using operator [] const
template <class K, class V>
const V& Map<K, V>::operator[](const K& key) const
{
	for (int i = 0; i < length; i++)
	{
		if (this->key[i] == key)
		{
			return value[i];
		}
	}
	throw std::exception("Key not found");
}

// Insert a new key-value pair
template <class K, class V>
void Map<K, V>::insert(const K& key, const V& value)
{
	if (length == capacity)
	{
		reserve(capacity + RESERVE_DEFAULT);
	}

	this->key[length] = key;
	this->value[length] = value;
	length++;
}

// Get the size of the map
template <class K, class V>
int Map<K, V>::size() const
{
	return length;
}

// Check if the map is empty
template <class K, class V>
bool Map<K, V>::isEmpty() const
{
	return length == 0;
}

// Erase a key-value pair
template <class K, class V>
void Map<K, V>::erase(const K& key)
{
	for (int i = 0; i < length; i++)
	{
		if (this->key[i] == key)
		{
			for (int j = i; j < length - 1; j++)
			{
				this->key[j] = this->key[j + 1];
				this->value[j] = this->value[j + 1];
			}
			length--;
			return;
		}
	}
}

// Clear the map
template <class K, class V>
void Map<K, V>::clear()
{
	length = 0;
}

// Check if the map contains a key
template <class K, class V>
bool Map<K, V>::contains(const K& key) const
{
	for (int i = 0; i < length; i++)
	{
		if (this->key[i] == key)
		{
			return true;
		}
	}
	return false;
}

// Reserve memory for the map
template <class K, class V>
void Map<K, V>::reserve(int new_capacity)
{
	K* new_key = new K[new_capacity];
	V* new_value = new V[new_capacity];

	for (int i = 0; i < length; i++)
	{
		new_key[i] = key[i];
		new_value[i] = value[i];
	}

	delete[] key;
	delete[] value;

	key = new_key;
	value = new_value;
	capacity = new_capacity;
}
/*****************************************/
#endif // !_H_MAP_H
