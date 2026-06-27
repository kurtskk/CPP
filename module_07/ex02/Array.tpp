#include "Array.hpp"

template <typename T>
Array<T>::Array() : _ptrArray(NULL), _large(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _ptrArray(NULL), _large(n)
{
	
	_ptrArray = new T[n];
}

template <typename T>
Array<T>::Array(const Array& other)
{
	if (this != &other)
	{
		_large = other._large;
		_ptrArray = new T[other._large];
		for (unsigned int i = 0; i < other._large; i++)
			_ptrArray[i] = other._ptrArray[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		delete[] _ptrArray;
		_large = other._large;
		_ptrArray = new T[other._large];
		for (unsigned int i = 0; i < other._large; i++)
			_ptrArray[i] = other._ptrArray[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _ptrArray;
}


template <typename T>
unsigned int Array<T>::size() const
{
	return _large;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _large)
		throw std::exception();
	return _ptrArray[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _large)
		throw std::exception();
	return _ptrArray[index];
}
