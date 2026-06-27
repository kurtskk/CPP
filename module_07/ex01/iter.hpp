#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T, typename F>
void iter(T* array, int const large, F f)
{
	for (int i = 0; i < large; i++)
		f(array[i]);
}

#endif